package com.neurotec.samples.licensing.preference;

import android.content.SharedPreferences;
import android.os.Bundle;
import android.preference.EditTextPreference;
import android.preference.ListPreference;
import android.preference.Preference;
import android.preference.PreferenceActivity;
import android.preference.PreferenceManager;
import android.preference.PreferenceScreen;
import android.support.v4.app.NavUtils;
import android.text.InputFilter;
import android.text.Spanned;
import android.text.TextUtils;
import android.view.MenuItem;

import com.neurotec.licensing.NLicensingService;
import com.neurotec.samples.R;
import com.neurotec.samples.licensing.LicensingMode;
import com.neurotec.samples.licensing.LicensingServiceManager;
import com.neurotec.samples.view.BasePreferenceFragment;

public class LicensingServicePreferences extends PreferenceActivity {

	// ===========================================================
	// Public static fields
	// ===========================================================

	public static final String LICENSING_MODE = "licensing_mode";
	public static final String LICENSING_SERVER_ADDRESS = "licensing_server_address";
	public static final String LICENSING_SERVER_PORT = "licensing_server_port";
	public static final String SET_DEFAULT_PREFERENCES = "set_default_preferences";

	// ===========================================================
	// Private fields
	// ===========================================================

	private EditTextPreference mServerAddress = null;
	private EditTextPreference mServerPort = null;

	// ===========================================================
	// Private methods
	// ===========================================================

	private void update() {
		SharedPreferences preferences = PreferenceManager.getDefaultSharedPreferences(this);
		LicensingMode mode = LicensingMode.valueOf(preferences.getString(LICENSING_MODE, LicensingMode.DIRECTLY.toString()));
		boolean value = mode.isServerConfigurable();
		mServerAddress.setEnabled(value);
		mServerAddress.setSelectable(value);
		mServerPort.setEnabled(value);
		mServerPort.setSelectable(value);
	}

	// ===========================================================
	// Public methods
	// ===========================================================

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		getActionBar().setDisplayHomeAsUpEnabled(true);
		getFragmentManager().beginTransaction().replace(android.R.id.content, new LicensingServicePreferencesFragment()).commit();
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
		case android.R.id.home:
			NavUtils.navigateUpFromSameTask(this);
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	private class LicensingServicePreferencesFragment extends BasePreferenceFragment {

		// ===========================================================
		// Public methods
		// ===========================================================

		@Override
		public void onCreate(Bundle savedInstanceState) {
			super.onCreate(savedInstanceState);
			addPreferencesFromResource(R.xml.licensing_service_preferences);
			ListPreference listPreference = (ListPreference) getPreferenceScreen().findPreference(LICENSING_MODE);
			if (!NLicensingService.isTrial()) {
				listPreference.setEntries(R.array.licensing_mode_names);
				listPreference.setEntryValues(R.array.licensing_mode_values);
			} else {
				listPreference.setEntries(R.array.trial_licensing_mode_names);
				listPreference.setEntryValues(R.array.trial_licensing_mode_values);
			}
			listPreference.setValue(LicensingServiceManager.getLicensingMode(this.getActivity()).toString());

			mServerAddress = (EditTextPreference) getPreferenceScreen().findPreference(LICENSING_SERVER_ADDRESS);
			mServerPort = (EditTextPreference) getPreferenceScreen().findPreference(LICENSING_SERVER_PORT);
			mServerPort.getEditText().setFilters(new InputFilter[] {new PortInputFilter()});
			update();
		}

		@Override
		public boolean onPreferenceTreeClick(PreferenceScreen preferenceScreen, Preference preference) {
			if (preference.getKey().equals(SET_DEFAULT_PREFERENCES)) {
				preferenceScreen.getEditor().clear().commit();
				getFragmentManager().beginTransaction().replace(android.R.id.content, new LicensingServicePreferencesFragment()).commit();
			}
			return super.onPreferenceTreeClick(preferenceScreen, preference);
		}

		@Override
		public void onSharedPreferenceChanged(SharedPreferences sharedPreferences, String key) {
			if (key.equals(LICENSING_MODE)) {
				update();
			}
			super.onSharedPreferenceChanged(sharedPreferences, key);
		}
	}

	// ===========================================================
	// Private inner classes
	// ===========================================================

	private class PortInputFilter implements InputFilter {
		@Override
		public CharSequence filter(CharSequence source, int start, int end, Spanned dest, int dstart, int dend) {
			try {
				if (end > start) {
					CharSequence strValue = TextUtils.concat(dest, source);
					if (strValue.length() > 5) {
						return "";
					}
					int value = Integer.parseInt(strValue.toString());
					if (value < 0 || value > 65535) {
						return "";
					}
				}
			} catch (Exception e) {
				return "";
			}
			return null;
		}
	}
}
