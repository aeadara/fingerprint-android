#ifndef WX_FCVIEW_HPP_INCLUDED
#define WX_FCVIEW_HPP_INCLUDED

#include <math.h>

#include <Core/NError.hpp>
#include <Biometrics/Standards/FCRecord.hpp>
#include <Gui/wxNView.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards { namespace Gui
{

class wxFCView : public Neurotec::Gui::wxNView
{
public:
	wxFCView(wxWindow *parent, wxWindowID winid = wxID_ANY) :
		wxNView(parent, winid),
		m_record(NULL),
		m_w(0),
		m_h(0),
		m_bitmap(),
		m_imageError((::Neurotec::NError::HandleType)NULL),
		m_featureColor(wxColor(255, 0, 0))
	{
	}

	virtual ~wxFCView()
	{
	}

#if wxUSE_GRAPHICS_CONTEXT == 1
virtual void OnDraw(wxGraphicsContext *gc)
{
	if (m_bitmap.IsOk())
	{
		gc->DrawBitmap(m_bitmap, 0, 0, m_bitmap.GetWidth(), m_bitmap.GetHeight());
	}
	else if (!m_imageError.IsNull())
	{
		gc->SetBrush(*wxWHITE_BRUSH);
		gc->DrawRectangle(0, 0, m_w, m_h);

		gc->SetPen(*wxRED_PEN);
		gc->StrokeLine(0, 0, m_w - 1, m_h - 1);
		gc->StrokeLine(0, m_h - 1, m_w - 1, m_h - 1);

		gc->SetPen(*wxBLACK_PEN);
		gc->DrawText(m_imageError.GetMessage(), 0 , 0);
	}

	if (!m_record.IsNull())
	{
		const float FeatureWidth = 5;
		const float FeatureWidthHalf = FeatureWidth / 2;
		const float FeatureHeight = 5;
		const float FeatureHeightHalf = FeatureHeight / 2;
		wxBrush brush(m_featureColor);
		wxGraphicsBrush gb = gc->CreateBrush(brush);
		gc->SetBrush(gb);

		FcrFaceImage::FeaturePointCollection features = m_record.GetFeaturePoints();
		for (FcrFaceImage::FeaturePointCollection::iterator it = features.begin(); it != features.end(); it++)
		{
			if (it->Type == ::Neurotec::Biometrics::Standards::bffptPoint2D)
			{
				float cx = it->X;
				float cy = it->Y;
				gc->DrawEllipse(cx - FeatureWidthHalf, cy - FeatureHeightHalf, FeatureWidth, FeatureHeight);
			}
		}
	}
}
#else
virtual void OnDraw(wxDC& dc)
{
	if (m_bitmap.IsOk())
	{
		dc.DrawBitmap(m_bitmap, 0, 0);
	}
	else if (!m_imageError.IsNull())
	{
		dc.SetPen(wxPen(wxColor(255, 255, 255)));
		dc.SetBrush(*wxWHITE_BRUSH);
		dc.DrawRectangle(0, 0, m_w, m_h);
		
		dc.SetPen(*wxRED_PEN);
		dc.DrawLine(0, 0, m_w - 1, m_h - 1);
		dc.DrawLine(0, m_h - 1, m_w - 1, m_h - 1);
		dc.SetPen(*wxBLACK_PEN);
		dc.DrawText(m_imageError.GetMessage(), 0 , 0);
	}

	if (!m_record.IsNull())
	{
		const float FeatureWidth = 5;
		const float FeatureWidthHalf = FeatureWidth / 2;
		const float FeatureHeight = 5;
		const float FeatureHeightHalf = FeatureHeight / 2;
		wxBrush brush(m_featureColor);
		dc.SetBrush(brush);
		dc.SetPen(m_featureColor);

		FcrFaceImage::FeaturePointCollection features = m_record.GetFeaturePoints();
		for (FcrFaceImage::FeaturePointCollection::iterator it = features.begin(); it != features.end(); it++)
		{
			if (it->Type == ::Neurotec::Biometrics::Standards::bffptPoint2D)
			{
				float cx = it->X;
				float cy = it->Y;
				dc.DrawEllipse(cx - FeatureWidthHalf, cy - FeatureHeightHalf, FeatureWidth, FeatureHeight);
			}
		}
	}
}
#endif

::Neurotec::Biometrics::Standards::FcrFaceImage GetRecord() const
{
	return m_record;
}

void SetRecord(const ::Neurotec::Biometrics::Standards::FcrFaceImage & value)
{
	m_bitmap = wxNullImage;
	m_imageError = NULL;
	m_record = value;
	if (value.IsNull())
	{
		m_w = 0;
		m_h = 0;
	}
	else
	{
		m_w = value.GetWidth();
		m_h = value.GetHeight();
		try
		{
			::Neurotec::Images::NImage image = m_record.ToNImage();
			m_bitmap = image.ToBitmap();
		}
		catch (::Neurotec::NError & e)
		{
			m_imageError = e;
		}
	}
	SetViewSize(m_w, m_h);
}

wxColor GetFeatureColor() const
{
	return m_featureColor;
}

void SetFeatureColor(const wxColor & value)
{
	m_featureColor = value;
}

private:
	::Neurotec::Biometrics::Standards::FcrFaceImage m_record;
	::Neurotec::NInt m_w, m_h;
	wxImage m_bitmap;
	::Neurotec::NError m_imageError;
	wxColor m_featureColor;
};

}}}}

#endif // !WX_FCVIEW_HPP_INCLUDED
