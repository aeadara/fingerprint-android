package com.neurotec.samples.widget;

import android.net.Uri;

public class FileListItem extends ListItem {

	// ===========================================================
	// Private fields
	// ===========================================================

	private Uri mUri;

	// ===========================================================
	// Public constructors
	// ===========================================================

	public FileListItem(String title, Uri uri) {
		super(title);
		mUri = uri;
	}

	public FileListItem(String title, String subtitle, Uri uri) {
		super(title, subtitle);
		mUri = uri;
	}

	public FileListItem(String title, String subtitle, Uri uri, boolean enabled) {
		super(title, subtitle, enabled);
		mUri = uri;
	}

	// ===========================================================
	// Public methods
	// ===========================================================

	public Uri getmUri() {
		return mUri;
	}

}
