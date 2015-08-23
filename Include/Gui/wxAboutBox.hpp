#ifndef ABOUT_BOX_H_INCLUDED
#define ABOUT_BOX_H_INCLUDED

#include <wx/bitmap.h>
#include <wx/combobox.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
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
#include <wx/listctrl.h>
#include <wx/tokenzr.h>

#include <vector>

#include <Gui/wxPluginManagerDlg.hpp>
#include <Core/NObject.hpp>
#include <Core/NModule.hpp>
#include <Plugins/NPluginModule.hpp>
#include <Gui/NeurotechnologyLogo.xpm>

#undef wxAboutBox_STYLE
#ifdef __WXMAC__
#define wxAboutBox_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxMAXIMIZE_BOX
#else
#define wxAboutBox_STYLE wxCAPTION | wxRESIZE_BORDER | wxSYSTEM_MENU | wxCLOSE_BOX
#endif

namespace Neurotec { namespace Gui
{

class wxAboutBox : public wxDialog
{
public:
	wxAboutBox(wxWindow *parent, wxWindowID id,
		const wxString& productNameString, const wxString& versionString, const wxString& copyrightString,
		const wxString &windowTitle = wxT("About"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
		long style = wxAboutBox_STYLE)
		: wxDialog(parent, id, windowTitle, pos, size, style)
	{
		InitGUI(productNameString, versionString, copyrightString);
		{
			using namespace ::Neurotec::Plugins;

			NArrayWrapper<NPluginManager> pluginManagers = NPluginManager::GetInstances();
			NArrayWrapper<NModule> loadedModules = ::Neurotec::NModule::GetLoadedModules();

			for (int i = 0; i < pluginManagers.GetCount(); i++)
			{
				cbPlugins->Insert(static_cast<wxString>(pluginManagers[i].GetInterfaceType()), i);
				managersList.push_back(pluginManagers[i]);

				for(int j = 0; j < pluginManagers[i].GetPlugins().GetCount(); j++)
				{
					NPlugin plugin = pluginManagers[i].GetPlugins().GetAll()[j];
					Neurotec::NModule module = plugin.GetModule();

					if(module.GetHandle())
					{
						for(int k = 0; k < loadedModules.GetCount(); k++)
						{
							if(module.Equals(loadedModules[k]))
							{
								loadedModules[k] = NULL;
								break;
							}
						}
					}
				}

				cbPlugins->SetSelection(0);
			}
			
			if(pluginManagers.GetCount() == 0)
			{
				cbPlugins->Disable();
				buttonOpen->Disable();
			}
			
			for(int i = 0; i < loadedModules.GetCount(); i++)
			{
				if(loadedModules[i].GetHandle() != NULL)
					moduleList.push_back(loadedModules[i]);
			}

			RefreshComponents();
		}
	}

	
	virtual ~wxAboutBox()
	{
		this->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxAboutBox::OnOpenClick), NULL, this);
		this->Disconnect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxCommandEventHandler(wxAboutBox::OnSelectedItemChanged), NULL, this);
		this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(wxAboutBox::OnClose), NULL, this);
	}

private:
	void InitGUI(const wxString& productNameString, const wxString& versionString, const wxString& copyrightString)
	{
		sizer = new wxBoxSizer(wxVERTICAL);
		SetSizer(sizer);
		SetAutoLayout(true);

		// header
		headerSizer = new wxFlexGridSizer(3);

		logo = new wxStaticBitmap(this, wxID_ANY, wxBitmap(NeurotechnologyLogo_XPM));
		logo->Enable(false);
		headerSizer->Add(logo, 0, wxALIGN_LEFT | wxALL, 5);

		infoSizer = new wxBoxSizer(wxVERTICAL);
		title = new wxStaticText(this, wxID_ANY, productNameString);
		infoSizer->Add(title, 0, wxALIGN_LEFT | wxALL, 5);
		version = new wxStaticText(this, wxID_ANY,
			wxString::Format(wxT("Version %s"), versionString.c_str()));
		infoSizer->Add(version, 0, wxALIGN_LEFT | wxALL, 5);
		copyright = new wxStaticText(this, wxID_ANY, copyrightString);
		infoSizer->Add(copyright, 0, wxALIGN_LEFT | wxALL, 5);
		headerSizer->Add(infoSizer, 0, wxALIGN_LEFT | wxALL | wxEXPAND, 5);
		headerSizer->AddGrowableCol(1);

		sizer->Add(headerSizer, 0, wxALIGN_LEFT | wxALL | wxEXPAND, 5);

		sizerLeft = new wxBoxSizer(wxVERTICAL);

		txtModules = new wxStaticText(this, wxID_ANY, wxT("Modules:"));
		sizerLeft->Add(txtModules, 0, wxALIGN_LEFT | wxALL | wxEXPAND, 1);

		components = new wxListCtrl(this, ID_LIST_COMPONENTS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT/* | wxLC_HRULES*/);
		components->InsertColumn(0, wxT("Title"));
		components->InsertColumn(1, wxT("Version"), wxLIST_FORMAT_CENTER);
		components->InsertColumn(2, wxT("Copyright"));
		components->SetMinSize(wxSize(640, 240));
		sizerLeft->Add(components, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 1);

		sizerRight = new wxBoxSizer(wxVERTICAL);

		txtActivated = new wxStaticText(this, wxID_ANY, wxT("Activated:"));
		sizerRight->Add(txtActivated, 0, wxALIGN_LEFT | wxALL | wxEXPAND, 1);

		activated = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
		activated->InsertColumn(0, wxT("Component"));
		activated->InsertColumn(1, wxT("Value"), wxLIST_FORMAT_CENTER);
		sizerRight->Add(activated, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 1);

		sizerCenter = new wxBoxSizer(wxHORIZONTAL);
		sizerCenter->Add(sizerLeft, 3, wxALL | wxEXPAND, 1);
		sizerCenter->Add(sizerRight, 1, wxALL | wxEXPAND, 1);

		sizer->Add(sizerCenter, 1, wxALIGN_CENTER | wxALL | wxEXPAND, 5);

		sizerBottom = new wxBoxSizer(wxHORIZONTAL);

		txtPluginManagers = new wxStaticText(this, wxID_ANY, wxT("Plugin managers:"));
		sizerBottom->Add(txtPluginManagers, 0, wxALL | wxALIGN_LEFT, 5);

		cbPlugins = new wxComboBox(this, wxID_ANY);
		cbPlugins->SetEditable(false);
		sizerBottom->Add(cbPlugins, 0, wxALL | wxEXPAND, 5);

		buttonOpen = new wxButton(this, ID_BUTTON_OPEN, wxT("Open"));
		sizerBottom->Add(buttonOpen, 0, wxALL, 5);

		sizerBottom->AddStretchSpacer(1);

		buttonOK = new wxButton(this, wxID_OK, wxT("&OK"));
		sizerBottom->Add(buttonOK, 0, wxALIGN_RIGHT | wxALL, 5);

		sizer->Add(sizerBottom, 0, wxALL | wxEXPAND, 5);

		SetTitle(wxString::Format(wxT("%s %s"), wxT("About"), productNameString.c_str()));
		SetIcon(wxNullIcon);
		SetBackgroundColour(wxColour(255, 255, 255));
		GetSizer()->Layout();
		GetSizer()->Fit(this);
		GetSizer()->SetSizeHints(this);
		Center();

		this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(wxAboutBox::OnClose), NULL, this);
		this->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxAboutBox::OnOpenClick), NULL, this);
		this->Connect(wxEVT_COMMAND_LIST_ITEM_SELECTED, wxCommandEventHandler(wxAboutBox::OnSelectedItemChanged), NULL, this);
	}

	void RefreshComponents()
	{
		components->DeleteAllItems();

		for (int i = 0; i < (int)moduleList.size(); i++)
		{
			ShowModule(moduleList[i]);
		}

		components->SetColumnWidth(0, wxLIST_AUTOSIZE);
		components->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
		components->SetColumnWidth(2, wxLIST_AUTOSIZE);
	}

	void OnClose(wxCloseEvent&)
	{
		Destroy();
	}

	void ShowModule(const NModule module)
	{
		long index = components->InsertItem(components->GetItemCount(), wxString(module.GetTitle()));
		components->SetItem(index, 1, wxString::Format(wxT("%d.%d.%d.%d"), module.GetVersionMajor(), module.GetVersionMinor(), module.GetVersionBuild(), module.GetVersionRevision()));
		components->SetItem(index, 2, static_cast<wxString>(module.GetCopyright()));
	}

	void ShowComponents(const ::Neurotec::NModule module)
	{
		activated->DeleteAllItems();
		if(module.GetHandle())
		{
			long index;
			wxArrayString strings = wxStringTokenize(static_cast<wxString>(module.GetActivated()), wxT(":,"), wxTOKEN_STRTOK);
			for (size_t i = 0; i < strings.Count() / 2; ++i)
			{
				index = activated->InsertItem(activated->GetItemCount(), strings[i * 2].Trim(false));
				activated->SetItem(index, 1, strings[i * 2 + 1].Trim(false));
			}

			activated->SetColumnWidth(0, wxLIST_AUTOSIZE);
			activated->SetColumnWidth(1, wxLIST_AUTOSIZE_USEHEADER);
		}
	}
	void OnRefreshClick(wxCommandEvent&)
	{
		RefreshComponents();
	}

	void OnOpenClick(wxCommandEvent& event)
	{
		int id = event.GetId();
		if(id == wxID_OK)
			event.Skip();
		else if(id == ID_BUTTON_OPEN)
		{
			int item = cbPlugins->GetSelection();
			if(item >= 0 && item < (int)managersList.size())
			{
				wxPluginManagerDlg dialog(this, wxID_ANY, managersList.at(item), NULL);
				dialog.ShowModal();
			}
		}
	}
	void OnSelectedItemChanged(wxCommandEvent& event)
	{
		if(event.GetId() == ID_LIST_COMPONENTS)
		{
			long item = components->GetNextItem(-1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);
			if(item >= 0 && item < (long)moduleList.size())
			{
				ShowComponents(moduleList.at(item));
			}
			else
			{
				ShowComponents(NULL);
			}
		}
	}
private:
	std::vector< ::Neurotec::Plugins::NPluginManager> managersList;
	std::vector<NModule> moduleList;
	wxBoxSizer *sizer;
	wxBoxSizer *sizerLeft;
	wxBoxSizer *sizerRight;
	wxFlexGridSizer *headerSizer;
	wxBoxSizer *infoSizer;
	wxStaticBitmap *logo;
	wxStaticText *title;
	wxStaticText *version;
	wxStaticText *copyright;
	wxListCtrl *components;
	wxButton *buttonOK;

	wxComboBox *cbPlugins;
	wxBoxSizer *sizerBottom;
	wxBoxSizer *sizerCenter;
	wxButton *buttonOpen;
	wxStaticText *txtPluginManagers;
	wxStaticText *txtModules;
	wxStaticText *txtActivated;
	wxListCtrl *activated;

	enum
	{
		ID_BUTTON_REFRESH = 1000,
		ID_BUTTON_OPEN = 1001,
		ID_LIST_COMPONENTS,
	};
};

}}

#endif
