package com.neurotec.samples.multibiometric.util;

import java.text.DecimalFormatSymbols;
import java.text.NumberFormat;
import java.text.ParseException;

public final class BiometricUtils {

	// ===========================================================
	// Public static methods
	// ===========================================================

	public static int qualityToPercent(byte value) {
		return (2 * value * 100 + 255) / (2 * 255);
	}

	public static byte qualityFromPercent(int value) {
		return (byte) ((2 * value * 255 + 100) / (2 * 100));
	}

	public static String getMatchingThresholdToString(int value) {
		double p = -value / 12.0;
		NumberFormat nf = NumberFormat.getPercentInstance();
		nf.setMaximumFractionDigits(Math.max(0, (int) Math.ceil(-p) - 2));
		nf.setMinimumIntegerDigits(1);
		return nf.format(Math.pow(10, p));
	}

	public static int getMatchingThresholdFromString(String value) throws ParseException {
		char percent = new DecimalFormatSymbols().getPercent();
		value = value.replace(percent, ' ');
		Number number = NumberFormat.getNumberInstance().parse(value);
		double parse = number.doubleValue();
		double p = Math.log10(Math.max(Double.MIN_VALUE, Math.min(1, parse / 100)));
		return Math.max(0, (int) Math.round(-12 * p));
	}

	public static boolean isMatchingThresholdEqual(int thresholdValue,	String percentString) throws ParseException {
		if (percentString == null) {
			return false;
		}
		int intVal = getMatchingThresholdFromString(percentString);
		return (intVal == thresholdValue);
	}

	public static int getMaximalRotationToDegrees(int value) {
		return (2 * value * 360 + 256) / (2 * 256);
	}

	public static int getMaximalRotationFromDegrees(int value) {
		return (2 * value * 256 + 360) / (2 * 360);
	}

	// ===========================================================
	// Private constructor
	// ===========================================================

	private BiometricUtils() {
	}

}
