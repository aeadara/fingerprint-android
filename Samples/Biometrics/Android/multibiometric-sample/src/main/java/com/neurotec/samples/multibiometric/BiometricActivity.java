package com.neurotec.samples.multibiometric;

import android.content.Intent;
import android.net.Uri;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.LinearLayout;

import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.util.EnumSet;
import java.util.List;

import com.neurotec.biometrics.NBiometric;
import com.neurotec.biometrics.NBiometricOperation;
import com.neurotec.biometrics.NBiometricStatus;
import com.neurotec.biometrics.NBiometricTask;
import com.neurotec.biometrics.NMatchingResult;
import com.neurotec.biometrics.NSubject;
import com.neurotec.biometrics.client.NBiometricClient;
import com.neurotec.lang.NCore;
import com.neurotec.samples.app.BaseActivity;
import com.neurotec.samples.app.InfoActivity;
import com.neurotec.samples.licensing.LicensingManager;
import com.neurotec.samples.licensing.preference.LicensingPreferences;
import com.neurotec.samples.multibiometric.view.EnrollmentDialogFragment;
import com.neurotec.samples.multibiometric.view.EnrollmentDialogFragment.EnrollmentDialogListener;
import com.neurotec.samples.multibiometric.view.SubjectListFragment;
import com.neurotec.samples.multibiometric.view.SubjectListFragment.SubjectSelectionListener;
import com.neurotec.samples.util.EnvironmentUtils;
import com.neurotec.samples.util.ResourceUtils;
import com.neurotec.util.concurrent.CompletionHandler;

public abstract class BiometricActivity extends BaseActivity implements EnrollmentDialogListener, SubjectSelectionListener {

	// ===========================================================
	// Private static fields
	// ===========================================================

	private static final int REQUEST_CODE_GET_FILE = 1;

	private static final String EXTRA_REQUEST_CODE = "request_code";
	private static final int VERIFICATION_REQUEST_CODE = 1;
	private static final int DATABASE_REQUEST_CODE = 2;

	private static final String TAG = BiometricActivity.class.getSimpleName();

	// ===========================================================
	// Private fields
	// ===========================================================

	private CompletionHandler<NSubject[], ? super NBiometricOperation> subjectListHandler = new CompletionHandler<NSubject[], NBiometricOperation>() {

		@Override
		public void completed(NSubject[] result, NBiometricOperation attachment) {
			Model.getInstance().setSubjects(result);
		}

		@Override
		public void failed(Throwable exc, NBiometricOperation attachment) {
			Log.e(TAG, exc.toString(), exc);
		}

	};

	private CompletionHandler<NBiometricTask, NBiometricOperation> completionHandler = new CompletionHandler<NBiometricTask, NBiometricOperation>() {
		@Override
		public void completed(NBiometricTask task, NBiometricOperation operation) {
			String message = null;
			NBiometricStatus status = task.getStatus();
			Log.i(TAG, String.format("Operation: %s, Status: %s", operation, status));

			onOperationCompleted(operation, task);

			if (status == NBiometricStatus.CANCELED) return;

			if (task.getError() != null) {
				showError(task.getError());
			} else {
				switch (operation) {
				case CAPTURE:
				case CREATE_TEMPLATE: {
					if (status == NBiometricStatus.OK) {
						message = getString(R.string.msg_extraction_succeeded);
					} else {
						message = getString(R.string.msg_extraction_failed, status.toString());
					}
				} break;
				case ENROLL:
				case ENROLL_WITH_DUPLICATE_CHECK: {
					if (status == NBiometricStatus.OK) {
						message = getString(R.string.msg_enrollment_succeeded);
					} else {
						message = getString(R.string.msg_enrollment_failed, status.toString());
					}
					client.list(NBiometricOperation.LIST, subjectListHandler);
				} break;
				case VERIFY: {
					if (status == NBiometricStatus.OK) {
						message = getString(R.string.msg_verification_succeeded);
					} else {
						message = getString(R.string.msg_verification_failed, status.toString());
					}
				} break;
				case IDENTIFY: {
					if (status == NBiometricStatus.OK) {
						StringBuilder sb = new StringBuilder();
						NSubject subject = task.getSubjects().get(0);
						for (NMatchingResult result : subject.getMatchingResults()) {
							sb.append(getString(R.string.msg_identification_results, result.getId())).append('\n');
						}
						message = sb.toString();
					} else {
						message = getString(R.string.msg_no_matches);
					}
				} break;
				default: {
					throw new AssertionError("Invalid NBiometricOperation");
				}
				}
				showInfo(message);
			}
		}

		@Override
		public void failed(Throwable th, NBiometricOperation operation) {
			onOperationCompleted(operation, null);
			showError(th);
		}
	};

	private LinearLayout captureControls;
	private LinearLayout stopControls;
	private LinearLayout successControls;

	private boolean mAppClosing = false;
	private InitializationTask mInitializationTask;

	// ===========================================================
	// Protected fields
	// ===========================================================

	protected NBiometricClient client = null;
	protected NSubject subject = null;
	protected final PropertyChangeListener biometricPropertyChanged = new PropertyChangeListener() {
		@Override
		public void propertyChange(PropertyChangeEvent evt) {
			if ("Status".equals(evt.getPropertyName())) {
				onStatusChanged(((NBiometric) evt.getSource()).getStatus());
			}
		}
	};

	// ===========================================================
	// Protected abstract methods
	// ===========================================================

	protected abstract Class<?> getPreferences();
	protected abstract void updatePreferences(NBiometricClient client);
	protected abstract boolean isCheckForDuplicates();
	protected abstract List<String> getComponents();
	protected abstract List<String> getMandatoryComponents();
	protected abstract String getModalityAssetDirectory();

	// ===========================================================
	// Protected methods
	// ===========================================================

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		NCore.setContext(this);
		try {
			getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
			setContentView(R.layout.main_biometric);
			captureControls = (LinearLayout) findViewById(R.id.capture_controls);
			successControls = (LinearLayout) findViewById(R.id.success_controls);
			stopControls = (LinearLayout) findViewById(R.id.stop_controls);
			Button mLoadButton = (Button) findViewById(R.id.button_load);
			mLoadButton.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					onLoad();
				}
			});
			Button mCaptureButton = (Button) findViewById(R.id.button_capture);
			mCaptureButton.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					onStartCapturing();
				}
			});
			Button mStopButton = (Button) findViewById(R.id.button_stop);
			mStopButton.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					onStopCapturing();
				}
			});
			Button mBackButton = (Button) findViewById(R.id.button_back);
			mBackButton.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					onBack();
				}
			});
			Button mEnrollButton = (Button) findViewById(R.id.button_enroll);
			mEnrollButton.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					onEnroll();
				}
			});
			Button mIdentifyButton = (Button) findViewById(R.id.button_identify);
			mIdentifyButton.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					onIdentify();
				}
			});
			Button mVerifyButton = (Button) findViewById(R.id.button_verify);
			mVerifyButton.setOnClickListener(new View.OnClickListener() {
				@Override
				public void onClick(View v) {
					onVerify();
				}
			});
			mInitializationTask = new InitializationTask();
			mInitializationTask.execute(savedInstanceState == null);
		} catch (Exception e) {
			showError(e);
		}
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		if (requestCode == REQUEST_CODE_GET_FILE) {
			if (resultCode == RESULT_OK) {
				try {
					onFileSelected(data.getData());
				} catch (Throwable th) {
					showError(th);
				}
			}
		}
	}

	protected void onStartCapturing() { }

	protected void onStopCapturing() {
		cancel();
	}

	protected void onOperationStarted(NBiometricOperation operation) {
		if (operation == NBiometricOperation.CAPTURE) {
			runOnUiThread(new Runnable() {
				@Override
				public void run() {
					if (isStopSupported()) {
						captureControls.setVisibility(View.GONE);
						stopControls.setVisibility(View.VISIBLE);
						successControls.setVisibility(View.GONE);
					}
				}
			});
		} else {
			if (isActive()) {
				showProgress(R.string.msg_processing);
			}
		}
	}

	protected void onOperationCompleted(final NBiometricOperation operation, final NBiometricTask task) {
		hideProgress();
		runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if (task != null && (task.getStatus() == NBiometricStatus.OK
						|| task.getOperations().contains(NBiometricOperation.IDENTIFY)
						|| task.getOperations().contains(NBiometricOperation.VERIFY)
						|| task.getOperations().contains(NBiometricOperation.ENROLL_WITH_DUPLICATE_CHECK)
						|| task.getOperations().contains(NBiometricOperation.ENROLL))) {
					captureControls.setVisibility(View.GONE);
					stopControls.setVisibility(View.GONE);
					successControls.setVisibility(View.VISIBLE);
				} else {
					stopControls.setVisibility(View.GONE);
					successControls.setVisibility(View.GONE);
					captureControls.setVisibility(View.VISIBLE);
				}
			}
		});
	}

	protected void onLicensesObtained() { }
	protected void onFileSelected(Uri uri) throws Exception { }

	protected final boolean isActive() {
		return client.getCurrentBiometric() != null || client.getCurrentSubject() != null;
	}

	protected boolean isStopSupported() {
		return true;
	}

	protected void stop() {
		client.force();
	}

	protected void cancel() {
		client.cancel();
	}

	protected void onLoad(){
		cancel();
		hideProgress();
		Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
		intent.setDataAndType(Uri.parse(EnvironmentUtils.NEUROTECHNOLOGY_DIRECTORY), "*/*");
		intent.addCategory(Intent.CATEGORY_OPENABLE);
		startActivityForResult(Intent.createChooser(intent, "Select a File"), REQUEST_CODE_GET_FILE);
	}

	protected void onBack() {
		runOnUiThread(new Runnable() {
			@Override
			public void run() {
				captureControls.setVisibility(View.VISIBLE);
				stopControls.setVisibility(View.GONE);
				successControls.setVisibility(View.GONE);
			}
		});
	}

	protected void onEnroll() {
		new EnrollmentDialogFragment().show(getFragmentManager(), "enrollment");
	}

	protected void onIdentify() {
		if (subject == null) throw new NullPointerException("subject");
		NBiometricTask task = client.createTask(EnumSet.of(NBiometricOperation.IDENTIFY), subject);
		client.performTask(task, NBiometricOperation.IDENTIFY, completionHandler);
		onOperationStarted(NBiometricOperation.IDENTIFY);
	}

	protected void onVerify() {
		Bundle bundle = new Bundle();
		bundle.putInt(EXTRA_REQUEST_CODE, VERIFICATION_REQUEST_CODE);
		SubjectListFragment.newInstance(Model.getInstance().getSubjects(), true, bundle).show(getFragmentManager(), "verification");
	}

	protected void onStatusChanged(final NBiometricStatus status) { }

	// ===========================================================
	// Public methods
	// ===========================================================

	@Override
	public void onBackPressed() {
		super.onBackPressed();
		mAppClosing = true;
	}

	@Override
	protected void onStop() {
		System.out.println("onStop");
		super.onStop();
		cancel();
		if (mAppClosing) {
			LicensingManager.getInstance().release(getComponents());
		}
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.options_menu, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
			case R.id.action_preferences: {
				startActivity(new Intent(this, getPreferences()));
				break;
			}
			case R.id.action_database: {
				Bundle bundle = new Bundle();
				bundle.putInt(EXTRA_REQUEST_CODE, DATABASE_REQUEST_CODE);
				SubjectListFragment.newInstance(Model.getInstance().getSubjects(), false, bundle).show(getFragmentManager(), "database");
				break;
			}
			case R.id.action_licensing: {
				startActivity(new Intent(this, LicensingPreferences.class));
				break;
			}
			case R.id.action_about: {
				startActivity(new Intent(this, InfoActivity.class));
				break;
			}
		}
		return true;
	}

	@Override
	public void onEnrollmentIDProvided(String id) {
		subject.setId(id);
		updatePreferences(client);
		NBiometricOperation operation = isCheckForDuplicates() ? NBiometricOperation.ENROLL_WITH_DUPLICATE_CHECK : NBiometricOperation.ENROLL;
		NBiometricTask task = client.createTask(EnumSet.of(operation), subject);
		client.performTask(task, NBiometricOperation.ENROLL, completionHandler);
		onOperationStarted(NBiometricOperation.ENROLL);
	}

	@Override
	public void onSubjectSelected(NSubject otherSubject, Bundle bundle) {
		if (bundle.getInt(EXTRA_REQUEST_CODE) == VERIFICATION_REQUEST_CODE) {
			subject.setId(otherSubject.getId());
			updatePreferences(client);
			NBiometricTask task = client.createTask(EnumSet.of(NBiometricOperation.VERIFY), subject);
			client.performTask(task, NBiometricOperation.VERIFY, completionHandler);
			onOperationStarted(NBiometricOperation.VERIFY);
		}
	}

	public void capture(NSubject subject) {
		if (subject == null) throw new NullPointerException("subject");
		this.subject = subject;
		updatePreferences(client);
		NBiometricTask task = client.createTask(EnumSet.of(NBiometricOperation.CREATE_TEMPLATE), subject);
		client.performTask(task, NBiometricOperation.CREATE_TEMPLATE, completionHandler);
		onOperationStarted(NBiometricOperation.CAPTURE);
	}

	public void extract(NBiometric biometric) {
		if (biometric == null) throw new NullPointerException("biometric");
		subject.clear();
		updatePreferences(client);
		NBiometricTask task = client.createTask(EnumSet.of(NBiometricOperation.CREATE_TEMPLATE), subject);
		task.setBiometric(biometric);
		client.performTask(task, NBiometricOperation.CREATE_TEMPLATE, completionHandler);
//		client.createTemplate(subject, NBiometricOperation.CREATE_TEMPLATE, completionHandler);
		onOperationStarted(NBiometricOperation.CREATE_TEMPLATE);
	}

	public void extract(NSubject subject) {
		if (subject == null) throw new NullPointerException("subject");
		this.subject = subject;
		updatePreferences(client);
		NBiometricTask task = client.createTask(EnumSet.of(NBiometricOperation.CREATE_TEMPLATE), subject);
		client.performTask(task, NBiometricOperation.CREATE_TEMPLATE, completionHandler);
		onOperationStarted(NBiometricOperation.CREATE_TEMPLATE);
	}

	final class InitializationTask extends AsyncTask<Boolean, Boolean, Boolean> {

		@Override
		protected void onPreExecute() {
			super.onPreExecute();
			showProgress(R.string.msg_initializing);
		}

		@Override
		protected Boolean doInBackground(Boolean... params) {
			if (params.length < 1) {
				throw new IllegalArgumentException("Missing parameter if to obtain license");
			}
			boolean obtainLicense = params[0];
			if (obtainLicense) {
				showProgress(R.string.msg_obtaining_licenses);
				if (LicensingManager.getInstance().obtain(BiometricActivity.this, getComponents())) {
					showToast(R.string.msg_licenses_obtained);
				} else {
					showToast(R.string.msg_licenses_not_obtained);
				}
			}

			showProgress(R.string.msg_copying_resources);

			try {
				if (EnvironmentUtils.isSdPresent()) {
					ResourceUtils.copyAssets(BiometricActivity.this, BiometricApplication.APP_NAME, BiometricApplication.SAMPLE_DATA_DIR);
				} else {
					Log.d(TAG, "Cannot access external storage. Skipping sample data copying from assets.");
				}
			} catch (Exception e) {
				Log.e(TAG, e.getMessage(), e);
			}

			showProgress(R.string.msg_initializing_client);

			try {
				client = Model.getInstance().getClient();
				subject = Model.getInstance().getSubject();
				mAppClosing = false;
				client.list(NBiometricOperation.LIST, subjectListHandler);
			} catch (Exception e) {
				Log.e(TAG, e.getMessage(), e);
				return false;
			}
			return true;
		}

		@Override
		protected void onPostExecute(Boolean result) {
			super.onPostExecute(result);
			hideProgress();
			onLicensesObtained();
		}
	}
}
