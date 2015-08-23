Requirements to compile sample:
* Java SE JDK 6(or higher) (http://www.oracle.com/technetwork/java/javase/downloads/index.html).
* Android development environment (http://developer.android.com/sdk/installing.html). Android SDK v8 (Android OS v2.2).
* Maven 3.0.3 (http://maven.apache.org/download.html).
* Internet connection.

Environment settings:
* Set ANDROID_HOME environmnet variable to point to Android SDK home directory (e.g D:\Program Files\Android\android-sdk)
* Set JAVA_HOME environmnet variable to point to Android SDK home directory (e.g C:\Program Files\Java\jdk1.6.0_20)
* Set M2_HOME to point environmnet variable to Android SDK home directory (e.g C:\Program Files\Maven_3.0)
* Add %ANDROID_HOME%/bin;%JAVA_HOME%/bin;%M2_HOME%/bin to PATH environmnet variable.

Build Instructions:
(in command line)
* cd DISTRIBUTION_LOCATION/Samples
* mvn clean install

Deployment Instructions:
(in command line)
A) using maven
* connect device to PC via USB cable.
* install device drivers if applicable.
* cd DISTRIBUTION_LOCATION/Samples/Biometrics/Android/multibiometric-sample
* mvn android:deploy

B) deploy using Android SDK platform tools
* connect device to PC via USB cable.
* cd ANDROID_INSTALL_DIR/android-sdk/platform-tools
* adb install DISTRIBUTION_LOCATION/Bin/Android/multibiometric-sample.apk

C) 
* Copy DISTRIBUTION_LOCATION/Bin/Android/multibiometric-sample.apk to device internal storage.
* Locate and install file using Android OS tools.
