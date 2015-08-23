package com.neurotec.samples.licensing;

import android.content.Context;
import android.os.Environment;
import android.preference.PreferenceManager;
import android.util.Log;

import com.neurotec.licensing.NLicensingService;
import com.neurotec.licensing.NLicensingServiceStatus;
import com.neurotec.samples.R;
import com.neurotec.samples.licensing.preference.LicensingServicePreferences;
import com.neurotec.samples.util.EnvironmentUtils;
import com.neurotec.samples.util.FileUtils;
import com.neurotec.samples.util.IOUtils;
import com.neurotec.samples.util.ResourceUtils;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public final class LicensingServiceManager {

	// ===========================================================
	// Private static fields
	// ===========================================================

	private static final String TAG = LicensingServiceManager.class.getSimpleName();
	private static LicensingServiceManager sInstance;

	// ===========================================================
	// Public static fields
	// ===========================================================

	public static final int REQUEST_CODE_LICENSING_PREFERENCES = 10;

	public static final LicensingMode DEFAULT_LICENSING_MODE = LicensingMode.getDefault();
	public static final String DEFAULT_SERVER_ADDRESS = "/local";
	public static final int DEFAULT_SERVER_PORT = 5000;

	public static final String EXTENSION_DEVICE_ID_FILE = ".id";
	public static final String EXTENSION_LICENSE_FILE = ".lic";
	public static final String EXTENSION_LICENSE_FILE_DEACTIVATED = ".bak";
	public static final String EXTENSION_SERIAL_NUMBER_FILE = ".sn";

	public static final String PG_LOG_FILE_NAME = "pgd.log";
	public static final String PG_CONF_FILE_NAME = "pgd.conf";

	public static final String LICENSES_DIRECTORY = EnvironmentUtils.getDataDirectory("Licenses").getAbsolutePath();
	public static final String PG_LOG_FILE = IOUtils.combinePath(LICENSES_DIRECTORY, PG_LOG_FILE_NAME);
	public static final String PG_CONF_FILE = IOUtils.combinePath(LICENSES_DIRECTORY, PG_CONF_FILE_NAME);

	// ===========================================================
	// Public static method
	// ===========================================================

	public static synchronized LicensingServiceManager getInstance() {
		if (sInstance == null) {
			sInstance = new LicensingServiceManager();
		}
		return sInstance;
	}

	public static LicensingMode getLicensingMode(Context context) {
		if (context == null) throw new NullPointerException("context");
		return LicensingMode.get(PreferenceManager.getDefaultSharedPreferences(context).getString(LicensingServicePreferences.LICENSING_MODE, DEFAULT_LICENSING_MODE.toString()));
	}

	public static String getServerAddress(Context context) {
		if (context == null) throw new NullPointerException("context");
		if (getLicensingMode(context).isServerConfigurable()) {
			return PreferenceManager.getDefaultSharedPreferences(context).getString(LicensingServicePreferences.LICENSING_SERVER_ADDRESS, DEFAULT_SERVER_ADDRESS);
		} else {
			return DEFAULT_SERVER_ADDRESS;
		}
	}

	public static int getServerPort(Context context) {
		if (context == null) throw new NullPointerException("context");
		if (getLicensingMode(context).isServerConfigurable()) {
			return Integer.parseInt(PreferenceManager.getDefaultSharedPreferences(context).getString(LicensingServicePreferences.LICENSING_SERVER_PORT, String.valueOf(DEFAULT_SERVER_PORT)));
		} else {
			return DEFAULT_SERVER_PORT;
		}
	}

	public static List<License> getLicenses() {
		String[] files = new File(LICENSES_DIRECTORY).list(FileUtils.getFilenameFilter(EXTENSION_LICENSE_FILE, EXTENSION_SERIAL_NUMBER_FILE));

		if (files == null || files.length == 0) return null;

		Set<License> licenses = new HashSet<License>();
		for (String file : files) {
			licenses.add(new License(LICENSES_DIRECTORY, FileUtils.removeExtension(file)));
		}
		List<License> sortedLicenses = new ArrayList<License>(licenses);
		Collections.sort(sortedLicenses, new Comparator<License>() {
			@Override
			public int compare(License o1, License o2) {
				if (o1.isActivated()) {
					return o2.isActivated() ? 0 : -1;
				} else {
					return o2.isActivated() ? 1 : 0;
				}
			}
		});
		return sortedLicenses;
	}

	public static void generateReport(Context context, String filePath) throws IOException {
		if (context == null) throw new NullPointerException("context");
		if (filePath == null) throw new NullPointerException("filePath");

		StringBuffer sb = new StringBuffer();
		String value;

		try {
			value = ResourceUtils.getEnum(context, NLicensingService.getStatus());
		} catch (Exception e) {
			value = context.getString(R.string.msg_unknown);
		}
		sb.append(context.getString(R.string.msg_format_status, value));
		sb.append(EnvironmentUtils.LINE_SEPARATOR);

		try {
			value = String.valueOf(NLicensingService.isTrial());
		} catch (Exception e) {
			value = context.getString(R.string.msg_unknown);
		}
		sb.append(context.getString(R.string.msg_format_trial, value));
		sb.append(EnvironmentUtils.LINE_SEPARATOR);

		if (EnvironmentUtils.isSdPresent()) {
			value = LicensingServiceManager.getInstance().getLog();
			sb.append(context.getString(R.string.msg_format_log, value != null ? value : ""));
			sb.append(EnvironmentUtils.LINE_SEPARATOR);
			value = LicensingServiceManager.getInstance().getConf();
			sb.append(context.getString(R.string.msg_format_configuration, value != null ? value : ""));
		} else {
			sb.append(context.getString(R.string.msg_sdcard_not_ready_for_reading));
		}

		sb.append(context.getString(R.string.msg_sdcard_not_ready_for_reading));
		FileUtils.write(filePath, sb.toString());
	}

	// ===========================================================
	// Private fields
	// ===========================================================

	private Configuration mConfig;

	// ===========================================================
	// Private constructor
	// ===========================================================

	private LicensingServiceManager() {
	}

	// ===========================================================
	// Public methods
	// ===========================================================

	public void start(Context context) throws IOException {
		start(getLicensingMode(context), getServerAddress(context), getServerPort(context));
	}

	public void start(LicensingMode mode, String address, int port) throws IOException {
		if (mode == null) throw new NullPointerException("mode");
		if (address == null) throw new NullPointerException("address");

		Configuration cfg = new Configuration(mode, address, port, getLicenses());
		mConfig = cfg;
		FileUtils.write(PG_CONF_FILE, mConfig.toString());

		NLicensingService.uninstall();
		NLicensingService.install(LICENSES_DIRECTORY, PG_CONF_FILE);

		if (!isRunning()) {
			NLicensingService.start();
		}
	}

	public void stop() {
		if (isRunning()) {
			NLicensingService.stop();
		}
	}

	public void restart(Context context) throws IOException {
		stop();
		start(context);
	}

	public boolean isOutdated(Context context) {
		Configuration cfg = new Configuration(getLicensingMode(context), getServerAddress(context), getServerPort(context), getLicenses());
		return !cfg.equals(mConfig);
	}

	public String getConf() {
		String confFile = null;
		String value = null;
		try {
			confFile = NLicensingService.getConfPath();
			value = FileUtils.readFileToString(confFile);
		} catch (IOException e) {
			Log.e(TAG, String.format("Configuration file %s not found", confFile));
		}
		return value;
	}

	public String getLog() {
		String value = null;
		try {
			value = FileUtils.readFileToString(PG_LOG_FILE);
		} catch (IOException e) {
			Log.e(TAG, String.format("Log file %s not found", PG_LOG_FILE));
		}
		return value;
	}

	public boolean isRunning() {
		return NLicensingService.getStatus() == NLicensingServiceStatus.RUNNING;
	}

	public LicensingMode getMode() {
		return mConfig != null ? mConfig.mMode : null;
	}

	public String getAddress() {
		return mConfig != null ? mConfig.mAddress : null;
	}

	public int getPort() {
		return mConfig != null ? mConfig.mPort : null;
	}

	// ===========================================================
	// Private inner class
	// ===========================================================

	private final class Configuration {

		// ===========================================================
		// Private static fields
		// ===========================================================

		private static final String SERVER_MODE = "Server";
		private static final String GATEWAY_MODE = "Gateway";

		// ===========================================================
		// Private fields
		// ===========================================================

		private LicensingMode mMode;
		private String mAddress;
		private String mStoragePath;
		private int mPort;
		private List<License> mLicenses;

		// ===========================================================
		// Package private constructors
		// ===========================================================

		Configuration(LicensingMode mode, String address, int port, List<License> licenses) {
			this.mMode = mode;
			this.mAddress = address;
			this.mPort = port;
			if (licenses != null) {
				mLicenses = new ArrayList<License>(licenses);
			}
			File externalStorageDirectory = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS);
			if (externalStorageDirectory != null) {
				mStoragePath = externalStorageDirectory.getAbsolutePath();
			}
		}

		// ===========================================================
		// Private methods
		// ===========================================================

		private LicensingServiceManager getOuterType() {
			return LicensingServiceManager.this;
		}

		// ===========================================================
		// Public methods
		// ===========================================================

		@Override
		public String toString() {
			StringBuilder builder = new StringBuilder();
			if (mMode.isPGRequired()) {
				builder.append(String.format("Mode = %s\n", SERVER_MODE));
			} else {
				builder.append(String.format("Mode = %s\n", GATEWAY_MODE));
				builder.append(String.format("Address = %s\n", mAddress));
				builder.append(String.format("Port = %s\n", mPort));
			}

			if (mStoragePath != null) {
				builder.append(String.format("StoragePath = %s\n", mStoragePath));
			}

			if (mMode == LicensingMode.FROM_FILE) {
				if (mLicenses != null) {
					for (License license : mLicenses) {
						if (license.isActivated()) {
							builder.append(String.format("LicenseFile = %s\n", license.getLicensePath()));
						}
					}
				}
			}
			return builder.toString();
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + ((mAddress == null) ? 0 : mAddress.hashCode());
			result = prime * result + ((mLicenses == null) ? 0 : mLicenses.hashCode());
			result = prime * result + ((mMode == null) ? 0 : mMode.hashCode());
			result = prime * result + mPort;
			result = prime * result + ((mStoragePath == null) ? 0 : mStoragePath.hashCode());
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj) return true;
			if (obj == null) return false;
			if (getClass() != obj.getClass()) return false;
			Configuration other = (Configuration) obj;
			if (!getOuterType().equals(other.getOuterType())) return false;
			if (mAddress == null) {
				if (other.mAddress != null) return false;
			} else if (!mAddress.equals(other.mAddress)) return false;
			if (mLicenses == null) {
				if (other.mLicenses != null) return false;
			} else if (!mLicenses.equals(other.mLicenses)) return false;
			if (mMode != other.mMode) return false;
			if (mPort != other.mPort) return false;
			if (mStoragePath == null) {
				if (other.mStoragePath != null) return false;
			} else if (!mStoragePath.equals(other.mStoragePath)) return false;
			return true;
		}
	}

}
