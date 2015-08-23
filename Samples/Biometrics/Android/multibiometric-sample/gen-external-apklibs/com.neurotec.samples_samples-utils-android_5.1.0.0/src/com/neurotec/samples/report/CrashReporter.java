package com.neurotec.samples.report;

import android.text.format.DateFormat;
import android.util.Log;

import com.neurotec.samples.util.EnvironmentUtils;

import java.io.File;
import java.io.PrintWriter;
import java.util.Date;

import org.acra.ReportField;
import org.acra.collector.CrashReportData;
import org.acra.sender.ReportSender;
import org.acra.sender.ReportSenderException;

public final class CrashReporter implements ReportSender {

	// ===========================================================
	// Private static fields
	// ===========================================================

	private static final String TAG = CrashReporter.class.getSimpleName();


	// ===========================================================
	// Public methods
	// ===========================================================

	@Override
	public void send(CrashReportData report) throws ReportSenderException {
		PrintWriter writer = null;
		try {
			File directory = new File(EnvironmentUtils.REPORTS_DIRECTORY_PATH);
			directory.mkdirs();
			String fileName = String.format("report_%s.txt", DateFormat.format(EnvironmentUtils.DATE_FORMAT, new Date()));
			File file = new File(directory, fileName);
			if (file != null) {
				writer = new PrintWriter(file);
				for (ReportField field : report.keySet()) {
					writer.println(field + ": " + report.getProperty(field));
				}
			}
		} catch (Exception e) {
			Log.e(TAG, "Exception", e);
		} finally {
			if (writer != null) {
				writer.close();
				writer = null;
			}
		}
	}
}
