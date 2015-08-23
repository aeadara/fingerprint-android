#ifndef WX_NVIEW_HPP_INCLUDED
#define WX_NVIEW_HPP_INCLUDED

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
#include <wx/scrolwin.h>
#include <wx/artprov.h>
#include <wx/menu.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <stdlib.h>

#include <Core/NObject.hpp>
#include <Gui/HandOpenCursor.xpm>
#include <Gui/HandClosedCursor.xpm>

namespace Neurotec { namespace Gui
{

wxDECLARE_EVENT(wxEVT_N_VIEW_ZOOM_CHANGED, wxCommandEvent);
wxDECLARE_EVENT(wxEVT_N_VIEW_ZOOM_TO_FIT_CHANGED, wxCommandEvent);

class wxNView : public wxScrolledWindow
{
public:
	wxNView(wxWindow *parent, wxWindowID winid = wxID_ANY)
		: wxScrolledWindow(parent, winid, wxDefaultPosition, wxDefaultSize, wxHSCROLL | wxVSCROLL | wxFULL_REPAINT_ON_RESIZE | wxBORDER_SIMPLE),
		m_handOpenCursor(wxImage(HandOpenCursor_xpm)),
		m_handClosedCursor(wxImage(HandClosedCursor_xpm))
	{
		m_zoomFactor = 1;
		m_zoomToFit = true;
		m_enableContextMenu = true;
		SetBackgroundStyle(wxBG_STYLE_CUSTOM);
		SetScrollRate(1, 1);

		m_contextMenu = new wxMenu();
		m_contextMenu->AppendCheckItem(ID_ZOOM_FIT, wxT("Zoom to fit"));
		m_contextMenu->Check(ID_ZOOM_FIT, true);
		m_contextMenu->Append(ID_ZOOM_50, wxT("Zoom 50%"));
		m_contextMenu->Append(ID_ZOOM_100, wxT("Zoom 100%"));
		m_contextMenu->Append(ID_ZOOM_200, wxT("Zoom 200%"));

		SetCursor(m_handOpenCursor);
		m_handToolActive = false;
	}

	virtual ~wxNView()
	{
		delete m_contextMenu;
	}

	void ZoomToFit()
	{
		wxSize clientSize = GetClientSize();

		if (m_viewSize.GetWidth() != 0
			&& clientSize.x != 0
			&& m_viewSize.GetHeight() != 0
			&& clientSize.y != 0)
		{
			double newZoomFactor = wxMin((double)(clientSize.x - 10) / (m_viewSize.GetWidth() + 10),
				(double)(clientSize.y - 10) / (m_viewSize.GetHeight() + 10));
			if (newZoomFactor != m_zoomFactor)
			{
				Zoom(newZoomFactor);
			}
		}
	}
	void SetZoom(double value)
	{
		if (m_zoomFactor != value)
		{
			Zoom(value);
		}
	}
	double GetZoom()
	{
		return GetZoomFactor();
	}
	void SetZoomToFit(bool value)
	{
		if (m_zoomToFit != value)
		{
			m_zoomToFit = value;
			if (value) ZoomToFit();
			Refresh();
			m_contextMenu->Check(ID_ZOOM_FIT, value);

			wxCommandEvent evt(wxEVT_N_VIEW_ZOOM_TO_FIT_CHANGED, GetId());
			wxPostEvent(this, evt);
		}
	}
	bool GetZoomToFit() { return m_zoomToFit; }
	void EnableContextMenu(bool value = true) { m_enableContextMenu = value; }
	bool IsContextMenuEnabled() { return m_enableContextMenu; }
protected:
	virtual void DoSetSize(int x, int y, int width,int height, int sizeFlags)
	{
		wxWindow::DoSetSize(x, y, width, height, sizeFlags);
		if (m_zoomToFit) ZoomToFit();
	}

	void SetViewSize(int viewWidth, int viewHeight)
	{
		wxRect oldImageRect = GetImageRect();

		m_viewSize = wxSize(viewWidth, viewHeight);
		if (m_zoomToFit && !(viewWidth == 1 && viewHeight == 1)) ZoomToFit();

		wxSize zoomedSize((int)(viewWidth * m_zoomFactor), (int)(viewHeight * m_zoomFactor));
		wxSize virtualSize = GetVirtualSize();
		if (virtualSize.x != zoomedSize.GetWidth() + 10
			|| virtualSize.y != zoomedSize.GetHeight() + 10)
		{
			SetVirtualSize(zoomedSize.GetWidth() + 10, zoomedSize.GetHeight() + 10);
		}

		wxRect imageRect = GetImageRect();
		imageRect = imageRect.Union(oldImageRect);

		Refresh(false, &imageRect);
	}

	wxRect GetImageRect()
	{
		wxSize imageSize(m_viewSize);
		imageSize.x = (int)((double)imageSize.x * m_zoomFactor);
		imageSize.y = (int)((double)imageSize.y * m_zoomFactor);

		wxSize clientSize = GetClientSize();
		wxRect imageRect(5, 5, imageSize.x, imageSize.y);
		if (imageSize.x + 10 < clientSize.x) imageRect.x = (clientSize.x - imageSize.x) / 2;
		if (imageSize.y + 10 < clientSize.y) imageRect.y = (clientSize.y - imageSize.y) / 2;

		int viewX, viewY;
		GetViewStart(&viewX, &viewY);
		imageRect.x -= viewX;
		imageRect.y -= viewY;

		return imageRect;
	}

	wxMenu* GetContextMenu()
	{
		return m_contextMenu;
	}
#if wxUSE_GRAPHICS_CONTEXT == 1
#if defined(N_CLANG)
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Woverloaded-virtual"
#endif
	virtual void OnDraw(wxGraphicsContext *gc) = 0;
#if defined(N_CLANG)
	#pragma clang diagnostic pop
#endif
#else
	virtual void OnDraw(wxDC&) = 0;
#endif

	virtual void OnLeftDown(wxMouseEvent& event)
	{
		GetViewStart(&m_viewX, &m_viewY);
		m_startPos = event.GetPosition();
		SetCursor(m_handClosedCursor);
		m_handToolActive = true;
	}

	virtual void OnLeftUp(wxMouseEvent& /*event*/)
	{
		SetCursor(m_handOpenCursor);
		m_handToolActive = false;
	}

	virtual void OnMouseMove(wxMouseEvent& event)
	{
		if (event.Dragging() && m_handToolActive)
		{
			wxPoint currentPos = event.GetPosition();
			Scroll(m_viewX - currentPos.x + m_startPos.x, m_viewY - currentPos.y + m_startPos.y);
		}
	}

	virtual void OnRightDown(wxMouseEvent& event)
	{
		if (m_enableContextMenu) PopupMenu(m_contextMenu, event.GetPosition());
	}

	void Zoom(double zoomFactor)
	{
		if (zoomFactor < 0.05)
		{
			zoomFactor = 0.05;
		}
		if (zoomFactor > 5)
		{
			zoomFactor = 5;
		}
		m_zoomFactor = zoomFactor;

		wxRect currentImageRect = GetImageRect();

		wxSize clientSize = GetClientSize();
		int scrollX = currentImageRect.width + 10 > clientSize.x ?
			(currentImageRect.width - clientSize.x) : 0;
		int scrollY = currentImageRect.height + 10 > clientSize.y ?
			(currentImageRect.height - clientSize.y) : 0;

		SetVirtualSize(currentImageRect.width + 10, currentImageRect.height + 10);
		Scroll(scrollX / 2, scrollY / 2);

		Refresh();

		wxCommandEvent evt(wxEVT_N_VIEW_ZOOM_CHANGED, GetId());
		wxPostEvent(this, evt);
	}

	double GetZoomFactor()
	{
		return m_zoomFactor;
	}

	enum
	{
		ID_ZOOM_FIT = wxID_HIGHEST + 1,
		ID_ZOOM_50,
		ID_ZOOM_100,
		ID_ZOOM_200,
		ID_WX_NVIEW_HIGHEST,
	};

private:
#if wxUSE_GRAPHICS_CONTEXT == 1
	void OnPaint(wxPaintEvent&)
	{
		wxAutoBufferedPaintDC dc(this);
		dc.SetBackground(wxBrush(this->GetBackgroundColour()));
		dc.Clear();
		dc.SetBackground(wxNullBrush);

		::std::auto_ptr<wxGraphicsContext> gc(wxGraphicsContext::Create(dc));

		wxRect imageRect = GetImageRect();

		wxGraphicsMatrix oldTransform = gc->GetTransform();

		gc->Translate(imageRect.x, imageRect.y);
		gc->Scale(m_zoomFactor, m_zoomFactor);

		wxFont font(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
		gc->SetFont(font, wxColour(0, 0, 0));

		OnDraw(gc.get());

		gc->SetTransform(oldTransform);
	}
#else
	void OnPaint(wxPaintEvent&)
	{
		wxAutoBufferedPaintDC dc(this);
		dc.SetBackground(wxBrush(this->GetBackgroundColour()));
		dc.Clear();
		dc.SetBackground(wxNullBrush);
		wxRect imageRect = GetImageRect();

		wxPoint origin = dc.GetDeviceOrigin();
		dc.SetDeviceOrigin(imageRect.x, imageRect.y);

		double oldScaleX, oldScaleY;
		dc.GetUserScale(&oldScaleX, &oldScaleY);
		dc.SetUserScale(m_zoomFactor, m_zoomFactor);

		OnDraw(dc);

		dc.SetUserScale(oldScaleX, oldScaleY);
		dc.SetDeviceOrigin(origin.x, origin.y);
	}
#endif

	void OnEraseBackGround(wxEraseEvent& /*event*/)
	{
	}

	void OnZoom(wxCommandEvent& event)
	{
		switch (event.GetId())
		{
		case ID_ZOOM_FIT:
			SetZoomToFit(m_contextMenu->IsChecked(ID_ZOOM_FIT));
			break;
		case ID_ZOOM_50:
			SetZoomToFit(false);
			SetZoom(0.5);
			break;
		case ID_ZOOM_100:
			SetZoomToFit(false);
			SetZoom(1);
			break;
		case ID_ZOOM_200:
			SetZoomToFit(false);
			SetZoom(2);
			break;
		}
		Refresh(false);
	}

	void OnMouseWheel(wxMouseEvent& event)
	{
		if (event.ControlDown() && !m_zoomToFit)
		{
			int wheelDelta = event.GetWheelDelta();
			if (event.GetWheelRotation() <= -wheelDelta)
			{
				Zoom(m_zoomFactor * (1 - 0.1));
			}
			else if (event.GetWheelRotation() >= wheelDelta)
			{
				Zoom(m_zoomFactor * (1 + 0.1));
			}
		}
		else
		{
			event.Skip();
		}
	}

	double m_zoomFactor;
	wxSize m_viewSize;
	int m_viewX;
	int m_viewY;
	wxPoint m_startPos;
	wxCursor m_handOpenCursor;
	wxCursor m_handClosedCursor;
	wxMenu *m_contextMenu;
	bool m_handToolActive;
	bool m_zoomToFit;
	bool m_enableContextMenu;

	DECLARE_EVENT_TABLE()
};

}}

#endif // !WX_NVIEW_HPP_INCLUDED
