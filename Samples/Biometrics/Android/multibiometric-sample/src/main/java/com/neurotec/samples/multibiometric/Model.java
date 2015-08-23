package com.neurotec.samples.multibiometric;

import com.neurotec.biometrics.NSubject;
import com.neurotec.biometrics.client.NBiometricClient;
import com.neurotec.lang.NCore;
import com.neurotec.samples.multibiometric.fingers.preference.FingerPreferences;
import com.neurotec.samples.util.EnvironmentUtils;
import com.neurotec.samples.util.IOUtils;

public final class Model {

	// ===========================================================
	// Private static fields
	// ===========================================================

	private static Model sInstance;

	// ===========================================================
	// Public static methods
	// ===========================================================

	public static Model getInstance() {
		synchronized (Model.class) {
			if (sInstance == null) {
				sInstance = new Model();
			}
			return sInstance;
		}
	}

	// ===========================================================
	// Private fields
	// ===========================================================

	private NBiometricClient mClient;
	private NSubject mSubject;

	private NSubject[] mSubjects;

	// ===========================================================
	// Private constructor
	// ===========================================================

	private Model() {
		EnvironmentUtils.initDataFiles(BiometricApplication.SAMPLE_DATA_DIR);
		mClient = new NBiometricClient();
		mClient.setDatabaseConnectionToSQLite(IOUtils.combinePath(NCore.getContext().getFilesDir().getAbsolutePath(), "BiometricsV50.db"));
		mClient.setUseDeviceManager(true);
		mClient.initialize();
		mSubjects = new NSubject[]{};
		mSubject = new NSubject();
	}

	// ===========================================================
	// Public methods
	// ===========================================================

	public NBiometricClient getClient() {
		return mClient;
	}

	public NSubject getSubject() {
		return mSubject;
	}

	/**
	 * Subjects contain copy of subject list from biometric client
	 * so that list could be accessible while continuous tasks are being
	 * performed on biometric client like capturing from camera
	 */
	public NSubject[] getSubjects() {
		return mSubjects;
	}

	/**
	 * Subjects contain copy of subject list from biometric client
	 * so that list could be accessible while continuous tasks are being
	 * performed on biometric client like capturing from camera
	 */
	public void setSubjects(NSubject[] subjects) {
		this.mSubjects = subjects;
	}

	public void update() {
		FingerPreferences.updateClient(mClient, NCore.getContext());
	}

}
