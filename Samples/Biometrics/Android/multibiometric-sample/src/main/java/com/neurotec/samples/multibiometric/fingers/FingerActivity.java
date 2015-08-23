package com.neurotec.samples.multibiometric.fingers;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.text.TextUtils;
import android.util.Log;
import android.view.Gravity;
import android.widget.FrameLayout.LayoutParams;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.neurotec.biometrics.NBiometricStatus;
import com.neurotec.biometrics.NFinger;
import com.neurotec.biometrics.NSubject;
import com.neurotec.biometrics.client.NBiometricClient;
import com.neurotec.biometrics.standards.CBEFFBDBFormatIdentifiers;
import com.neurotec.biometrics.standards.CBEFFBiometricOrganizations;
import com.neurotec.biometrics.view.NFingerView;
import com.neurotec.biometrics.view.NFingerViewBase.ShownImage;
import com.neurotec.devices.NDevice;
import com.neurotec.devices.NDeviceType;
import com.neurotec.devices.NFScanner;
import com.neurotec.images.NImage;
import com.neurotec.samples.licensing.LicensingManager;
import com.neurotec.samples.multibiometric.BiometricActivity;
import com.neurotec.samples.multibiometric.R;
import com.neurotec.samples.multibiometric.fingers.preference.FingerPreferences;
import com.neurotec.samples.util.NImageUtils;
import com.neurotec.samples.util.ResourceUtils;

import java.util.Arrays;
import java.util.List;

public final class FingerActivity extends BiometricActivity {

	// ===========================================================
	// Private static fields
	// ===========================================================

	private static final String TAG = FingerActivity.class.getSimpleName();
	private static final String BUNDLE_KEY_STATUS = "status";
	private static final String MODALITY_ASSET_DIRECTORY = "fingers";

	// ===========================================================
	// Private fields
	// ===========================================================

	private NFingerView mFingerView;
	private Bitmap mDefaultBitmap;
	private TextView mStatus;

	// ===========================================================
	// Private methods
	// ===========================================================

	private NFScanner getScanner() {
		//TODO Read last used scanner from preferences
//		for (NPlugin plugin : NDeviceManager.getPluginManager().getPlugins()) {
//			Log.i("Model", String.format("Plugin name => %s, Error => %s", plugin.getModule().getName(), plugin.getError()));
		NDevice fingerDevice = null;
		for (NDevice device : client.getDeviceManager().getDevices()) {
//			Log.i("Device", String.format("Device name => %s", device.getDisplayName()));
			if (device.getDeviceType().contains(NDeviceType.FSCANNER)) {
				if (device.getId().equals(PreferenceManager.getDefaultSharedPreferences(this).getString(FingerPreferences.FINGER_CAPTURING_DEVICE, "None"))) {
					return (NFScanner) device;
				} else if (fingerDevice == null){
					fingerDevice = device;
				}
			}
		}
		return (NFScanner) fingerDevice;
	}

	//TODO: Try to load as image
	private NSubject createSubjectFromImage(Uri uri) throws Exception {
		NSubject subject = null;
		try {
			NImage image = NImageUtils.fromUri(this, uri);
			subject = new NSubject();
			NFinger finger = new NFinger();
			finger.setImage(image);
			subject.getFingers().add(finger);
			mFingerView.setFinger(finger);
		} catch (Exception e){
			Log.i(TAG, "Failed to load file as NImage");
		}
		return subject;
	}

	//TODO: Try to load as standard and detect type automatically
	private NSubject createSubjectFromStandard(Uri uri) throws Exception {
		NSubject subject = null;
		try {
			subject = NSubject.fromFile(uri.getPath(), CBEFFBiometricOrganizations.NOT_FOR_USE, (short) 0);
			if (subject != null && subject.getFingers() != null && !subject.getFingers().isEmpty()) {
				mFingerView.setFinger(subject.getFingers().get(0));
			}
		} catch (Exception e) {
			Log.i(TAG, "Failed to load file as Subject");
		}
		return subject;
	}

	//TODO: Try to load as FIRecord ansi
	private NSubject createsubjectFromFIRecordAnsi(Uri uri) throws Exception{
		NSubject subject = null;
		try {
			subject = NSubject.fromFile(uri.getPath(), CBEFFBiometricOrganizations.INCITS_TC_M1_BIOMETRICS, CBEFFBDBFormatIdentifiers.INCITS_TC_M1_BIOMETRICS_FINGER_IMAGE);
			if (subject != null && subject.getFingers() != null && !subject.getFingers().isEmpty()) {
				mFingerView.setFinger(subject.getFingers().get(0));
			}
		} catch (Exception e) {
			Log.i(TAG, "Failed to load file as FIRecord Ansi");
		}
		return subject;
	}

	//TODO: Try to load as FMRecord ansi
	private NSubject createsubjectFromFMRecordAnsi(Uri uri) throws Exception{
		NSubject subject = null;
		try {
			subject = NSubject.fromFile(uri.getPath(), CBEFFBiometricOrganizations.INCITS_TC_M1_BIOMETRICS, CBEFFBDBFormatIdentifiers.INCITS_TC_M1_BIOMETRICS_FINGER_MINUTIAE_N);
			if (subject != null && subject.getFingers() != null && !subject.getFingers().isEmpty()) {
				mFingerView.setFinger(subject.getFingers().get(0));
			}
		} catch (Exception e) {
			Log.i(TAG, "Failed to load file as FMRecord Ansi");
		}
		return subject;
	}

	// ===========================================================
	// Protected methods
	// ===========================================================

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		try {
			PreferenceManager.setDefaultValues(this, R.xml.finger_preferences, false);
			LinearLayout layout = ((LinearLayout) findViewById(R.id.biometric_layout));

			mFingerView = new NFingerView(this);
			layout.addView(mFingerView);

			mStatus = new TextView(this);
			mStatus.setText("Status");
			LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.WRAP_CONTENT);
			params.gravity = Gravity.CENTER;
			mStatus.setLayoutParams(params);
			layout.addView(mStatus);

			mDefaultBitmap = BitmapFactory.decodeResource(getResources(), R.drawable.hand);
			if (savedInstanceState == null) {
				NFinger finger = new NFinger();
				finger.setImage(NImage.fromBitmap(mDefaultBitmap));
				mFingerView.setFinger(finger);
			}
		} catch (Exception e) {
			showError(e);
		}
	}

	@Override
	protected void onSaveInstanceState(Bundle outState) {
		outState.putString(BUNDLE_KEY_STATUS, TextUtils.isEmpty(mStatus.getText()) ? "" : mStatus.getText().toString());
	}

	@Override
	protected List<String> getComponents() {
		return Arrays.asList(LicensingManager.LICENSE_FINGER_DETECTION,
			LicensingManager.LICENSE_FINGER_EXTRACTION,
			LicensingManager.LICENSE_FINGER_MATCHING,
			LicensingManager.LICENSE_FINGER_MATCHING_FAST,
			LicensingManager.LICENSE_FINGER_DEVICES_SCANNERS,
			LicensingManager.LICENSE_FINGER_WSQ,
			LicensingManager.LICENSE_FINGER_STANDARDS_FINGER_TEMPLATES,
			LicensingManager.LICENSE_FINGER_STANDARDS_FINGERS);
//			LicensingManager.LICENSE_FINGER_QUALITY_ASSESSMENT,
//			LicensingManager.LICENSE_FINGER_SEGMENTS_DETECTION);
	}

	@Override
	protected List<String> getMandatoryComponents() {
		return Arrays.asList(LicensingManager.LICENSE_FINGER_DETECTION,
				LicensingManager.LICENSE_FINGER_EXTRACTION,
				LicensingManager.LICENSE_FINGER_MATCHING,
				LicensingManager.LICENSE_FINGER_DEVICES_SCANNERS);
	}

	@Override
	protected Class<?> getPreferences() {
		return FingerPreferences.class;
	}

	@Override
	protected void updatePreferences(NBiometricClient client) {
		FingerPreferences.updateClient(client, this);
	}

	@Override
	protected boolean isCheckForDuplicates() {
		return FingerPreferences.isCheckForDuplicates(this);
	}

	@Override
	protected String getModalityAssetDirectory() {
		return MODALITY_ASSET_DIRECTORY;
	}

	@Override
	protected void onFileSelected(Uri uri) throws Exception {
		NSubject subject = null;
		mFingerView.setShownImage(FingerPreferences.isReturnProcessedImage(this) ? ShownImage.RESULT : ShownImage.ORIGINAL);
		subject = createSubjectFromImage(uri);

		if (subject == null) {
			subject = createSubjectFromStandard(uri);
		}

		if (subject == null) {
			subject = createsubjectFromFIRecordAnsi(uri);
		}

		if (subject == null) {
			subject = createsubjectFromFMRecordAnsi(uri);
		}

		if (subject != null) {
			extract(subject);
		} else {
			showInfo(R.string.msg_failed_to_load_image_or_standard);
		}
	}

	@Override
	protected void onStartCapturing() {
		NFScanner scanner = getScanner();
		if (scanner == null) {
			showError(R.string.msg_capturing_device_is_unavailable);
		} else {
			client.setFingerScanner(scanner);
			NSubject subject = new NSubject();
			NFinger finger = new NFinger();
			finger.addPropertyChangeListener(biometricPropertyChanged);
			mFingerView.setShownImage(FingerPreferences.isReturnProcessedImage(this) ? ShownImage.RESULT : ShownImage.ORIGINAL);
			mFingerView.setFinger(finger);
			subject.getFingers().add(finger);
			capture(subject);
		}
	}

	@Override
	protected void onStatusChanged(final NBiometricStatus value) {
		runOnUiThread(new Runnable() {
			@Override
			public void run() {
				mStatus.setText(value == null ? "" : ResourceUtils.getEnum(FingerActivity.this, value));
			}
		});
	}
}
