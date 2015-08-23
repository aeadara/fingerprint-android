package com.neurotec.samples.app;

import android.app.ActionBar;
import android.app.ActionBar.Tab;
import android.os.Bundle;

import com.neurotec.samples.R;
import com.neurotec.samples.licensing.app.ActivationInfoActivity;

public final class InfoActivity extends BaseActivity {

	// ===========================================================
	// Protected methods
	// ===========================================================

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		ActionBar actionBar = getActionBar();
		actionBar.setNavigationMode(ActionBar.NAVIGATION_MODE_TABS);
		Tab tab1 = actionBar.newTab().setText(R.string.msg_about);
		Tab tab2 = actionBar.newTab().setText(R.string.msg_activation);
		Tab tab3 = actionBar.newTab().setText(R.string.msg_connection);

		tab1.setTabListener(new TabListener<AboutActivity>(this, AboutActivity.class));
		tab2.setTabListener(new TabListener<ActivationInfoActivity>(this, ActivationInfoActivity.class));
		tab3.setTabListener(new TabListener<ConnectionActivity>(this, ConnectionActivity.class));

		actionBar.addTab(tab1, true);
		actionBar.addTab(tab2);
		actionBar.addTab(tab3);
	}
}
