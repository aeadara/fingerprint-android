package com.neurotec.samples.licensing.preference;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.io.IOException;

import com.neurotec.licensing.NLicensingService;
import com.neurotec.samples.R;
import com.neurotec.samples.app.BaseActivity;
import com.neurotec.samples.app.BaseListFragment;
import com.neurotec.samples.licensing.LicensingManager;
import com.neurotec.samples.licensing.LicensingManager.LicensingStateCallback;
import com.neurotec.samples.licensing.LicensingServiceManager;
import com.neurotec.samples.licensing.LicensingState;
import com.neurotec.samples.licensing.app.ActivationActivity;
import com.neurotec.samples.licensing.app.ActivationActivity.OnLicenseStateModifiedListener;

public final class LicensingPreferences extends BaseActivity implements LicensingStateCallback, OnLicenseStateModifiedListener {

	// ===========================================================
	// Private static fields
	// ===========================================================

	private static final String TAG = LicensingPreferences.class.getSimpleName();
	private static final int REQUEST_CODE_LICENSE_SERVICE_PREFERENCES = 0;
	private static final String SERVICE = "Licensing service";
	private static final String ACTIVATION = "Activation";

	// ===========================================================
	// Public static fields
	// ===========================================================

	public static final boolean SHOW_SEEKBAR_MIN_MAX_VALUES = true;

	// ===========================================================
	// Protected methods
	// ===========================================================

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		getFragmentManager().beginTransaction().replace(android.R.id.content, new LicensingPreferencesFragment()).commit();
		//TODO: Move reobtaining to callback after LicensingServicePreferences is changed to fragment.
		if (LicensingServiceManager.getInstance().isOutdated(this)) {
			try {
				LicensingManager.getInstance().reobtain(this, this);
			} catch (IOException e) {
				Log.e(TAG, "Exception", e);
			}
		}
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		try {
			switch (requestCode) {
			case REQUEST_CODE_LICENSE_SERVICE_PREFERENCES:
				if (LicensingServiceManager.getInstance().isOutdated(this)) {
					LicensingManager.getInstance().reobtain(this, this);
				} break;
			default:
				break;
			}
		} catch (Exception e) {
			Log.e(TAG, "Exception", e);
		}
	}

	// ===========================================================
	// Public methods
	// ===========================================================

	@Override
	public void onLicensingStateChanged(LicensingState state) {
		switch (state) {
		case OBTAINING:
			showProgress(R.string.msg_obtaining_licenses);
			break;
		case OBTAINED:
			hideProgress();
			showToast(R.string.msg_licenses_obtained);
			break;
		case NOT_OBTAINED:
			hideProgress();
			showToast(R.string.msg_licenses_not_obtained);
			break;
		}
	}

	@Override
	public void onLicensesStateModified() {
		try {
			LicensingManager.getInstance().reobtain(this, this);
		} catch (Exception e) {
			Log.e(TAG, "Exception", e);
		}
	}

	private class LicensingPreferencesFragment extends BaseListFragment {

		@Override
		public void onCreate(Bundle savedInstanceState) {
			super.onCreate(savedInstanceState);
			try {
				String[] values = null;
				if (!NLicensingService.isTrial()) {
					values = new String[] {SERVICE, ACTIVATION};
				} else {
					values = new String[] {SERVICE};
				}
				setListAdapter(new ArrayAdapter<String>(getActivity(), android.R.layout.simple_list_item_1, values));
			} catch (Exception e) {
				showError(e);
			}
		}

		@Override
		public void onListItemClick(ListView l, View v, int position, long id) {
			String item = (String) getListAdapter().getItem(position);
			if (item.equals(SERVICE)) {
				getActivity().startActivityForResult(new Intent(getActivity(), LicensingServicePreferences.class), REQUEST_CODE_LICENSE_SERVICE_PREFERENCES);
			} else if (item.equals(ACTIVATION)) {
				getFragmentManager().beginTransaction().replace(android.R.id.content, new ActivationActivity(), "activation").addToBackStack(null).commit();
			}
		}

	}

}
