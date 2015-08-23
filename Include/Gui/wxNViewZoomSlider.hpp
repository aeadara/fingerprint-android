#ifndef WX_NVIEW_ZOOM_SLIDER_HPP_INCLUDED
#define WX_NVIEW_ZOOM_SLIDER_HPP_INCLUDED

#include <wx/window.h>
#include <wx/checkbox.h>
#include <wx/slider.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <Gui/wxNView.hpp>

namespace Neurotec { namespace Gui
{

class wxNViewZoomSlider : public wxWindow
{
public:
	explicit wxNViewZoomSlider(wxWindow * parent = NULL, int id = wxID_ANY, const wxPoint & position = wxDefaultPosition, const wxSize & size = wxDefaultSize)
		: wxWindow(parent, id, position, size)
	{
		m_view = NULL;
		CreateGui();
	}

	virtual ~wxNViewZoomSlider()
	{
		SetView(NULL);
	}

	void SetView(wxNView * view)
	{
		if (view != m_view)
		{
			if (m_view)
			{
				m_view->Unbind(wxEVT_N_VIEW_ZOOM_CHANGED, &wxNViewZoomSlider::OnViewZoomChanged, this);
				m_view->Unbind(wxEVT_N_VIEW_ZOOM_TO_FIT_CHANGED, &wxNViewZoomSlider::OnViewZoomToFitChanged, this);
			}
			m_view = view;
			if (m_view)
			{
				m_view->Bind(wxEVT_N_VIEW_ZOOM_CHANGED, &wxNViewZoomSlider::OnViewZoomChanged, this);
				m_view->Bind(wxEVT_N_VIEW_ZOOM_TO_FIT_CHANGED, &wxNViewZoomSlider::OnViewZoomToFitChanged, this);
			}
			UpdateValues();
		}
	}

	wxNView * GetView()
	{
		return m_view;
	}

private:
	void CreateGui()
	{
		wxFlexGridSizer* fgSizer1;
		fgSizer1 = new wxFlexGridSizer(0, 4, 0, 0);
		fgSizer1->AddGrowableCol(1);
		fgSizer1->SetFlexibleDirection(wxBOTH);
		fgSizer1->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

		m_chbZoomToFit = new wxCheckBox(this, wxID_ANY, wxT("Zoom to fit"), wxDefaultPosition, wxDefaultSize, 0);
		fgSizer1->Add(m_chbZoomToFit, 0, wxALL, 5);

		m_slider = new wxSlider(this, wxID_ANY, 100, 10, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL);
		fgSizer1->Add(m_slider, 0, wxALL | wxEXPAND, 5);

		m_spinCtrl = new wxSpinCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 10, 200, 100);
		m_spinCtrl->SetMaxSize(wxSize(55, -1));

		fgSizer1->Add(m_spinCtrl, 0, wxALL, 5);

		wxStaticText * m_staticText = new wxStaticText(this, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, 0);
		m_staticText->Wrap(-1);
		fgSizer1->Add(m_staticText, 0, wxALL, 5);

		this->SetSizer(fgSizer1);
		this->Layout();
	}

	void OnViewZoomChanged(wxCommandEvent & /*event*/)
	{
		UpdateValues();
	}

	void OnViewZoomToFitChanged(wxCommandEvent & /*event*/)
	{
		UpdateValues();
	}

	void OnSliderValueChanged(wxCommandEvent & /*event*/)
	{
		if (m_view)
		{
			m_view->SetZoom(m_slider->GetValue() / 100.0);
		}
	}

	void OnSpinValueChanged(wxSpinEvent & /*event*/)
	{
		if (m_view)
		{
			m_view->SetZoom(m_spinCtrl->GetValue() / 100.0);
		}
	}

	void OnChbZoomToFitChanged(wxCommandEvent & /*event*/)
	{
		if (m_view)
		{
			m_view->SetZoomToFit(m_chbZoomToFit->GetValue());
		}
	}

	void UpdateValues()
	{
		if (m_view)
		{
			int value = (int)(m_view->GetZoom() * 100);
			int max = m_slider->GetMax();
			int min = m_slider->GetMin();
			bool zoomToFit = m_view->GetZoomToFit();
			if (value < min) value = min;
			if (value > max) value = max;
			m_slider->SetValue(value);
			m_spinCtrl->SetValue(value);
			m_chbZoomToFit->SetValue(m_view->GetZoomToFit());
			m_slider->Enable(!zoomToFit);
			m_spinCtrl->Enable(!zoomToFit);
		}
	}

private:
	::Neurotec::Gui::wxNView * m_view;
	wxCheckBox * m_chbZoomToFit;
	wxSlider * m_slider;
	wxSpinCtrl * m_spinCtrl;

private:
	DECLARE_EVENT_TABLE();
};

}};

#endif
