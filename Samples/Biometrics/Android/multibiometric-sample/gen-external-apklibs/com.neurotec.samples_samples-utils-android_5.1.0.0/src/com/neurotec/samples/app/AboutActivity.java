package com.neurotec.samples.app;

import java.util.ArrayList;
import java.util.List;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;

import com.neurotec.devices.NDeviceManager;
import com.neurotec.lang.NModule;
import com.neurotec.plugins.NPlugin;
import com.neurotec.samples.R;
import com.neurotec.samples.util.ManifestData;
import com.neurotec.samples.widget.CustomItemAdapter;
import com.neurotec.samples.widget.HeaderItem;
import com.neurotec.samples.widget.ListItem;

public final class AboutActivity extends BaseListFragment {

	// ===========================================================
	// Private fields
	// ===========================================================
//	private ListView listView;
	private Bitmap mLogo;
	private String mAbout;

	// ===========================================================
	// Protected methods
	// ===========================================================

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		mLogo = BitmapFactory.decodeResource(getResources(), R.drawable.ic_neurotechnology_logo);
		mAbout = String.format(getString(R.string.msg_company_info), getString(R.string.msg_company_name), ManifestData.getApplicationVersion(getActivity()));
	}

	@Override
	public void onActivityCreated(Bundle savedInstanceState) {
		super.onActivityCreated(savedInstanceState);

		List<ListItem> items = new ArrayList<ListItem>();

		items.add(new ListItem(ManifestData.getApplicationName(getActivity()), mAbout, mLogo, true));
		items.add(new HeaderItem(getString(R.string.msg_loaded_modules)));

		if (NModule.getLoadedModules().length > 0) {
			for (NModule module : NModule.getLoadedModules()) {
				items.add(new ListItem(module.getName(), module.getTitle()));
			}
		} else {
			items.add(new ListItem(getString(R.string.msg_no_loaded_modules)));
		}

		items.add(new HeaderItem(getString(R.string.msg_plugins)));
		List<NPlugin> plugins = NDeviceManager.getPluginManager().getPlugins();

		if (plugins != null && plugins.size() > 0) {
			for (NPlugin plugin : plugins) {
				String status = "";
				if (plugin.getError() != null) {
					status = getString(R.string.msg_status_format, plugin.getError().getMessage());
				}
				items.add(new ListItem(plugin.getModule().getPluginName(), status));
			}
		} else {
			items.add(new ListItem(getString(R.string.msg_no_loaded_plugins)));
		}
		setListAdapter(new CustomItemAdapter(getActivity(), items));
	}
}
