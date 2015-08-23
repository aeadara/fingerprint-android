Neurotechnology Biometric SDK Trial 5.1
ReadMe.txt
Updated March 02, 2015 by Neurotechnology
-----------------------------------------

WHAT IS NEUROTECHNOLOGY BIOMETRIC SDK?
======================================
Neurotechnology Biometric SDK unions MegaMatcher SDK, VeriEye SDK, VeriFinger SDK, VeriLook SDK
and VeriSpeak SDK and therefore does not provide any
biometric functionality by itself, rather by its parts.  

WHAT IS MEGAMATCHER SDK?
========================
MegaMatcher technology is intended for large-scale AFIS and multi-biometric systems developers. 
The technology ensures high reliability and speed of biometric identification even when using large
databases.

MegaMatcher is available as a software development kit that allows development of large-scale
fingerprint, face or multi-biometric face-fingerprint identification products for Microsoft Windows 
and Linux platforms. 

WHAT IS VERIEYE SDK?
====================
VeriEye iris identification technology is intended for biometric systems developers and integrators.
The technology includes many proprietary solutions that enable robust eye iris enrollment under various
conditions and fast iris matching in 1-to-1 and 1-to-many modes.

VeriEye is available as a software development kit that allows development of PC- and Web-based
solutions on Microsoft Windows, Linux and Mac OS X platforms.

WHAT IS VERIFINGER SDK?
========================
VeriFinger is a fingerprint identification technology intended for biometric systems developers 
and integrators. The technology assures system performance with fast, reliable fingerprint matching
in 1-to-1 and 1-to-many modes. 

VeriFinger is available as a software development kit that allows development of PC- and Web-based
solutions on Microsoft Windows, Linux and Mac OS X platforms.

WHAT IS VERILOOK SDK?
=====================
VeriLook facial identification technology is intended for biometric systems developers and integrators. 
The technology assures system performance and reliability with live face detection, simultaneous multiple 
face recognition and fast face matching in 1-to-1 and 1-to-many modes.

VeriLook is available as a software development kit that allows development of PC- and Web-based 
solutions on Microsoft Windows, Linux and Mac OS X platforms.

WHAT IS VERISPEAK SDK?
======================
VeriSpeak SDK is software development tool which can be used to develop biometric systems which require 
speech recognition. VeriSpeak SDK is available in two versions: Standard (for PC-based biometric 
application development) and Extended (for developing Web-based biometric systems).

HOW TO INSTALL AND ACTIVATE SDK?
================================
SDK installation consists of two steps:

    1. Extract the SDK archive to convenient location on local computer.
    2. Activate the licensing software, which is necessary for SDK to work correctly.

Installation on Windows:
On Windows both installation steps can be performed by running "Setup.exe".
The application will ask for destination location, copy the files and launch the Activation wizard.

Activation wizard can also be run separately (use ActivationWizard.exe from SDK "Bin/Win32_x86/Activation" or "Bin/Win64_x64/Activation" folder).
Neurotechnology provides various licensing schemes for products, the wizard can be used to guide through installation of appropriate license. More
information can be found in the "Activation.pdf" which is located in "Documentation" folder.

Installation on Linux:
On Linux the mentioned installation steps must be performed manually. First extract the SDK to location used for developing. 

To activate the SDK, use the tools from "Bin/Linux_x86/Activation" folder or "Bin/Linux_x86_64/Activation" folder, depending on your platform. Please consult the "Activation.pdf" located in "Documentation" folder,
for instructions on starting the activating service manually.

SYSTEM REQUIREMENTS
===================
System requirements for installation of the Server Components for Windows OS
	• PC with x86 compatible CPU (Pentium4 2GHz processor or better is recommended)
	• TCP/IP network support
	• Microsoft Windows 2000/2003/XP/Vista/7/8* OS
	• Oracle Database 10g, MySQL server 4.0, Microsoft SQL Server 2000/2005 or SQLite 
	  3.4 or newer versions of these servers or any other database that supports 
	  communication through ODBC.
	
System requirements for installation of the Server Components for Linux OS
	• PC with x86 compatible CPU
	• TCP/IP network support
	• Linux 2.6 or newer kernel, 32-bit or 64-bit. 32-bit platform are recommended for applications with fingerprint scanners, as most scanners have only 32-bit 
	support modules (Linux 3.0 is recommended to use).
	• glibc 2.7 or newer
	• wxWidgets 3.0.0 or newer libs and dev packages (to build and run SDK samples and applications based on them)
	• Qt 4.8 or newer libs, dev and qmake packages (to build and run SDK samples and applications based on them)
	• GStreamer with plugins 1.2.2 or newer with gst-plugin-base and gst-plugin-good (for capture from webcam/rtsp/video/audio support)
	• libgudev-1.0 164-3 or newer (for webcam and microphone usage)
	• libasound 1.0.x or newer (for voice capture)
	• GCC-4.0.x or newer (for application development)
	• GNU Make 3.81 or newer (for application development)
	• Sun Java 1.6 SDK or later (for application development with Java)
	• pkg-config-0.21 or newer (optional; only for Matching Server database support modules compilation)
	• Oracle Database 10g, MySQL server 4.0 or newer versions of these servers or
      any other database that supports communication through ODBC.
	
System requirements for installation and using of Client Components for Windows OS
	• PC with x86 compatible CPU (Pentium4 2GHz processor or better is recommended)
	• Microsoft Windows 2000/2003/XP/Vista/7/8*
	• Microsoft .NET framework 3.5 (for .NET components)
	• Microsoft Visual Studio 2008 SP1 or newer (for application development)
	
System requirements for installation and using of Client Components for Linux OS
	• Linux 2.6 or newer kernel, 32-bit or 64-bit. 32-bit platform are recommended for applications with fingerprint scanners, as most scanners have only 32-bit 
	support modules (Linux 3.0 is recommended to use).
	• glibc 2.7 or newer
	• wxWidgets 3.0.0 or newer libs and dev packages (to build and run SDK samples and applications based on them)
	• Qt 4.8 or newer libs, dev and qmake packages (to build and run SDK samples and applications based on them)
	• GStreamer with plugins 1.2.2 or newer with gst-plugin-base and gst-plugin-good (for capture from webcam/rtsp/video/audio support)
	• libgudev-1.0 164-3 or newer (for webcam and microphone usage)
	• libasound 1.0.x or newer (for voice capture)
	• GCC-4.0.x or newer (for application development)
	• GNU Make 3.81 or newer (for application development)
	• Sun Java 1.6 SDK or later (for application development with Java)
	• pkg-config-0.21 or newer (optional; only for Matching Server database support modules compilation)
	
WHERE TO GET MORE INFORMATION ABOUT NEUROTECHNOLOGY BIOMETRIC SDK?
==================================================================
Documentation:
For more information on how to use the Neurotechnology Biometric SDK read developer's guide. 
It is located within "Documentation" folder of SDK.

SUPPORT
=======
If you face any troubles with Biometric SDK, please contact Support Department:
<support@neurotechnology.com>.

Copyright © 2005-2015 Neurotechnology. All rights reserved.