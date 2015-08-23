#ifndef N_BIOMETRIC_GUI_LIBRARY_CPP_INCLUDED
#define N_BIOMETRIC_GUI_LIBRARY_CPP_INCLUDED

#include <NGuiLibrary.cpp>
#include <NBiometricsLibrary.cpp>

#include <NBiometricGui.hpp>

namespace Neurotec { namespace Biometrics { namespace Gui
{

#ifdef N_FRAMEWORK_WX
	wxDEFINE_EVENT(wxEVT_MINUTIA_SELECTION_CHANGED, wxCommandEvent);
	wxDEFINE_EVENT(wxEVT_NFR_PROPERTY_CHANGED, wxCommandEvent);
	wxDEFINE_EVENT(wxEVT_IRIS_PROPERTY_CHANGED, wxCommandEvent);
	wxDEFINE_EVENT(wxEVT_FACE_OBJECT_COLLECTION_CHANGED, wxCommandEvent);
	wxDEFINE_EVENT(wxEVT_FACE_PROPERTY_CHANGED, wxCommandEvent);
	wxDEFINE_EVENT(wxEVT_VOICE_OBJECT_COLLECTION_CHANGED, wxCommandEvent);
	wxDEFINE_EVENT(wxEVT_VOICE_PROPERTY_CHANGED, wxCommandEvent);
	wxDEFINE_EVENT(wxEVT_NSATTRIBUTES_PROPERTY_CHANGED, wxCommandEvent);
#endif

}}}


#endif // !N_BIOMETRIC_GUI_LIBRARY_CPP_INCLUDED
