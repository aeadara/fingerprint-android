#ifndef WX_NEVIEW_HPP_INCLUDED
#define WX_NEVIEW_HPP_INCLUDED

#include <Biometrics/Gui/wxNFView.hpp>
#include <Images/NImages.hpp>
#include <Biometrics/NEExtractor.hpp>

namespace Neurotec { namespace Biometrics { namespace Gui
{

#include <Core/NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(wxNIrisView) " instead") wxNEView: public Neurotec::Gui::wxNView
{
public:
	wxNEView(wxWindow *parent, wxWindowID winid = wxID_ANY)
		: wxNView(parent, winid)
	{
		m_details.OuterBoundaryAvailable = NFalse;
		m_details.InnerBoundaryAvailable = NFalse;
		m_outerBoundaryColor = wxColour(0, 255, 0);
		m_outerBoundaryWidth = 2;
		m_innerBoundaryColor = wxColour(255, 0, 0);
		m_innerBoundaryWidth = 2;
	}

	void Clear()
	{
		m_image = wxImage();
		m_bitmap = wxBitmap();
		m_details.OuterBoundaryAvailable = NFalse;
		m_details.InnerBoundaryAvailable = NFalse;
		SetViewSize(1, 1);
		Refresh(false);
	}

	void SetImage(const wxImage & image)
	{
		m_image = image;
		m_bitmap = wxBitmap(image);
		SetViewSize(image.GetWidth(), image.GetHeight());
	}

	wxImage GetImage()
	{
		return m_image;
	}

	void SetSegmentationDetails(const NeeSegmentationDetails & details)
	{
		m_details = details;
		Refresh(false);
	}

	const NeeSegmentationDetails & GetSegmentationDetails()
	{
		return m_details;
	}

	void SetOuterBoundaryColor(const wxColour & value)
	{
		m_outerBoundaryColor = value;
	}

	const wxColour & GetOuterBoundaryColor()
	{
		return m_outerBoundaryColor;
	}

	void SetOuterBoundaryWidth(int value)
	{
		m_outerBoundaryWidth = value;
	}

	int GetOuterBoundaryWidth()
	{
		return m_outerBoundaryWidth;
	}

	void SetInnerBoundaryWidth(int value)
	{
		m_innerBoundaryWidth = value;
	}

	int GetInnerBoundaryWidth()
	{
		return m_innerBoundaryWidth;
	}

	void SetInnerBoundaryColor(const wxColour & value)
	{
		m_innerBoundaryColor = value;
	}

	wxColour GetInnerBoundaryColor()
	{
		return m_innerBoundaryColor;
	}

#if wxUSE_GRAPHICS_CONTEXT == 1
	virtual void OnDraw(wxGraphicsContext *gc)
	{
		if (m_bitmap.GetRefData())
		{
			gc->DrawBitmap(m_bitmap, 0, 0, m_bitmap.GetWidth(), m_bitmap.GetHeight());
		}
		if (m_details.OuterBoundaryAvailable)
		{
			wxPen outerBoundaryPen(m_outerBoundaryColor, m_outerBoundaryWidth);
			gc->SetPen(outerBoundaryPen);
			wxGraphicsPath outerBoundaryPath = gc->CreatePath();
			::Neurotec::Geometry::NPoint *points = static_cast< ::Neurotec::Geometry::NPoint *>(&m_details.OuterBoundaryPoints[0]);
			outerBoundaryPath.MoveToPoint(points[NEE_BOUNDARY_POINT_COUNT - 1].X, points[NEE_BOUNDARY_POINT_COUNT - 1].Y);
			for (int i = 0; i < NEE_BOUNDARY_POINT_COUNT; ++i)
			{
				outerBoundaryPath.AddLineToPoint(points[i].X, points[i].Y);
			}
			gc->StrokePath(outerBoundaryPath);
			gc->SetPen(wxNullPen);
		}
		if (m_details.InnerBoundaryAvailable)
		{
			wxPen innerBoundaryPen(m_innerBoundaryColor, m_innerBoundaryWidth);
			gc->SetPen(innerBoundaryPen);
			wxGraphicsPath innerBoundaryPath = gc->CreatePath();
			::Neurotec::Geometry::NPoint *points = static_cast< ::Neurotec::Geometry::NPoint *>(&m_details.InnerBoundaryPoints[0]);
			innerBoundaryPath.MoveToPoint(points[NEE_BOUNDARY_POINT_COUNT - 1].X, points[NEE_BOUNDARY_POINT_COUNT - 1].Y);
			for (int i = 0; i < NEE_BOUNDARY_POINT_COUNT; ++i)
			{
				innerBoundaryPath.AddLineToPoint(points[i].X, points[i].Y);
			}
			gc->StrokePath(innerBoundaryPath);
			gc->SetPen(wxNullPen);
		}
	}
#else
	virtual void OnDraw(wxDC &dc)
	{
		if (m_bitmap.GetRefData())
		{
			dc.DrawBitmap(m_bitmap, 0, 0, false);
		}
		if (m_details.OuterBoundaryAvailable)
		{
			wxPen outerBoundaryPen(m_outerBoundaryColor, m_outerBoundaryWidth);
			dc.SetPen(outerBoundaryPen);
			::Neurotec::Geometry::NPoint *points = static_cast< ::Neurotec::Geometry::NPoint *>(&m_details.OuterBoundaryPoints[0]);
			for (int i = 1; i < NEE_BOUNDARY_POINT_COUNT; ++i)
			{
				dc.DrawLine(wxPoint(points[i - 1].X, points[i - 1].Y), wxPoint(points[i].X, points[i].Y));
			}
			dc.DrawLine(wxPoint(points[NEE_BOUNDARY_POINT_COUNT - 1].X, points[NEE_BOUNDARY_POINT_COUNT - 1].Y), wxPoint(points[0].X, points[0].Y));
			dc.SetPen(wxNullPen);
		}
		if (m_details.InnerBoundaryAvailable)
		{
			wxPen innerBoundaryPen(m_innerBoundaryColor, m_innerBoundaryWidth);
			dc.SetPen(innerBoundaryPen);
			::Neurotec::Geometry::NPoint *points = static_cast< ::Neurotec::Geometry::NPoint *>(&m_details.InnerBoundaryPoints[0]);
			for (int i = 1; i < NEE_BOUNDARY_POINT_COUNT; ++i)
			{
				dc.DrawLine(wxPoint(points[i - 1].X, points[i - 1].Y), wxPoint(points[i].X, points[i].Y));
			}
			dc.DrawLine(wxPoint(points[NEE_BOUNDARY_POINT_COUNT - 1].X, points[NEE_BOUNDARY_POINT_COUNT - 1].Y), wxPoint(points[0].X, points[0].Y));
			dc.SetPen(wxNullPen);
		}
	}
#endif

private:
	wxImage m_image;
	wxBitmap m_bitmap;
	NeeSegmentationDetails m_details;
	wxColour m_outerBoundaryColor;
	int m_outerBoundaryWidth;
	wxColour m_innerBoundaryColor;
	int m_innerBoundaryWidth;

};
#include <Core/NReDeprecate.h>

}}}

#endif // !WX_NEVIEW_HPP_INCLUDED
