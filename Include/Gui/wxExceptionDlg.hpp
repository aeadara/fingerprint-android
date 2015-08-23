#ifndef WX_EXCEPTION_DLG_INCLUDED
#define WX_EXCEPTION_DLG_INCLUDED

#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/artprov.h>
#include <stdlib.h>

#include <Core/NObject.hpp>

namespace Neurotec { namespace Gui
{

class wxExceptionDlg : public wxDialog
{
private:
	wxExceptionDlg(wxWindow* parent, const wxString& description, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 477,346 ), long style = wxDEFAULT_DIALOG_STYLE)
		: wxDialog(parent, id, title, pos, size, style)
	{
		this->SetSizeHints(wxDefaultSize, wxDefaultSize);

		wxBoxSizer* bSizer1;
		bSizer1 = new wxBoxSizer(wxVERTICAL);

		wxBoxSizer* bSizer2;
		bSizer2 = new wxBoxSizer(wxHORIZONTAL);

		m_staticBmp = new wxStaticBitmap(this, wxID_ANY, wxArtProvider::GetBitmap(wxART_ERROR, wxART_MESSAGE_BOX),
			wxDefaultPosition, wxDefaultSize, 0);
		bSizer2->Add(m_staticBmp, 0, wxALL, 5);

		m_txtDescription = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY);
		bSizer2->Add(m_txtDescription, 1, wxALL|wxEXPAND, 5);
		m_txtDescription->SetValue(description);

		bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

		wxBoxSizer* bSizer3;
		bSizer3 = new wxBoxSizer(wxHORIZONTAL);

		m_btnCopy = new wxButton(this, wxID_ANY, wxT("Copy"), wxDefaultPosition, wxDefaultSize, 0);
		bSizer3->Add(m_btnCopy, 0, wxALL, 5);

		bSizer3->Add(0, 0, 1, wxEXPAND, 5);

		m_btnContinue = new wxButton(this, wxID_ANY, wxT("Continue"), wxDefaultPosition, wxDefaultSize, 0);
		m_btnContinue->SetDefault();
		bSizer3->Add(m_btnContinue, 0, wxALL, 5);

		bSizer1->Add(bSizer3, 0, wxEXPAND, 5);

		this->SetSizer(bSizer1);
		this->Layout();

		// Connect Events
		m_btnCopy->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxExceptionDlg::OnCopyClick), NULL, this);
		m_btnContinue->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxExceptionDlg::OnContinueClick), NULL, this);
	}

	~wxExceptionDlg()
	{
		m_btnCopy->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxExceptionDlg::OnCopyClick), NULL, this);
		m_btnContinue->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxExceptionDlg::OnContinueClick), NULL, this);
	}

	wxStaticBitmap* m_staticBmp;
	wxTextCtrl* m_txtDescription;
	wxButton* m_btnCopy;
	wxButton* m_btnContinue;

	void OnCopyClick(wxCommandEvent&)
	{
		m_txtDescription->SelectAll();
		m_txtDescription->Copy();
	}

	void OnContinueClick(wxCommandEvent&)
	{
		EndModal(1);
	}

public:
	static void Show(Neurotec::NError error)
	{
		wxExceptionDlg dlg(NULL, error.ToString());
		dlg.ShowModal();
	}

	static void Show(const wxString& description)
	{
		wxExceptionDlg dlg(NULL, description);
		dlg.ShowModal();
	}
};

}}

#endif // !WX_EXCEPTION_DLG_INCLUDED
