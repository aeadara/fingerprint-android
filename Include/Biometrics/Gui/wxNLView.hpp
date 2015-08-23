#ifndef WX_NLVIEW_HPP_INCLUDED
#define WX_NLVIEW_HPP_INCLUDED

#include <Gui/wxNView.hpp>
#include <Biometrics/NLTemplate.hpp>
#include <Core/NTypes.hpp>

#include <wx/timer.h>

#define MAX_FPS_ENTRIES 30

namespace Neurotec { namespace Biometrics { namespace Gui
{

#include <Core/NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(wxNFaceView) " instead") wxNLView : public Neurotec::Gui::wxNView
{
public:
	wxNLView(wxWindow *parent, wxWindowID winid = wxID_ANY)
		: wxNView(parent, winid)
	{
		m_details = NULL;
		m_detailsCount = 0;
		m_lastTime = 0;
		m_frameCount = 0;
		m_currentFps = 0;
		m_showFps = false;
		m_faceRectangleColor = wxColour(0, 255, 0);
		m_faceRectangleWidth = 2;
		m_showEyes = true;
		m_showNose = true;
		m_showMouth = true;
		m_showNoseConfidence = false;
		m_showEyesConfidence = false;
		m_showMouthConfidence = false;
		m_showGender = true;
		m_showGenderConfidence = false;
		m_showExpression = true;
		m_showExpressionConfidence = false;
		m_showProperties = true;
		m_showPropertiesConfidence = false;
		m_showBaseFeaturePoints = true;
		m_featureWidth = 4;
		m_baseFeatureWidth = 2;
		SetScrollRate(1, 1);
		SetBackgroundColour(wxColour(0, 0, 0));
	}

	void Clear()
	{
		m_image = wxImage();
		m_bitmap = wxBitmap();
		m_details = NULL;
		m_detailsCount = 0;
		SetViewSize(1, 1);
		Refresh(false);
	}

	void SetImage(const wxImage & image)
	{
		if (GetShowFps())
		{
			UpdateFps();
		}

		m_image = image;
		m_bitmap = wxBitmap(image);
		SetViewSize(image.GetWidth(), image.GetHeight());
	}

	wxImage GetImage()
	{
		return m_image;
	}

	void SetDetectionDetails(NleDetectionDetails *details, int detailsCount)
	{
		m_details = details;
		m_detailsCount = detailsCount;
		Refresh(false);
	}

	NleDetectionDetails * GetDetectionDetails()
	{
		return m_details;
	}

	int GetDetectionDetailsCount()
	{
		return m_detailsCount;
	}

	void SetFaceRectangleColor(const wxColour & value)
	{
		m_faceRectangleColor = value;
	}

	const wxColour & GetFaceRectangleColor()
	{
		return m_faceRectangleColor;
	}

	void SetFaceRectangleWidth(int value)
	{
		m_faceRectangleWidth = value;
	}

	int GetFaceRectangleWidth()
	{
		return m_faceRectangleWidth;
	}

	N_DEPRECATED("function is deprecated, use SetShowFps instead")
	void SetDrawFps(bool value){ SetShowFps(value); }
	N_DEPRECATED("function is deprecated, use GetShowFps instead")
	bool GetDrawFps(){ return GetShowFps(); }
	void SetShowFps(bool value){ m_showFps = value; }
	bool GetShowFps(){ return m_showFps; }

	bool GetShowEyes(){ return m_showEyes; }
	void SetShowEyes(bool value){ m_showEyes = value; }
	bool GetShowNose(){ return m_showNose; }
	void SetShowNose(bool value){ m_showNose = value; }
	bool GetShowMouth(){ return m_showMouth; }
	void SetShowMouth(bool value){ m_showMouth = value; }
	bool GetShowMouthConfidence(){ return m_showMouthConfidence; }
	void SetShowMouthConfidence(bool value){ m_showMouthConfidence = value; }
	bool GetShowNoseConfidence(){ return m_showNoseConfidence; }
	void SetShowNoseConfidence(bool value){ m_showNoseConfidence = value; }
	bool GetShowEyesConfidence(){ return m_showEyesConfidence; }
	void SetShowEyesConfidence(bool value){ m_showEyesConfidence = value; }
	void SetShowGender(bool value){ m_showGender = value; }
	bool GetShowGender(){ return m_showGender; }
	void SetShowGenderConfidence(bool value){ m_showGenderConfidence = value; }
	bool GetShowGenderConfidence(){ return m_showGenderConfidence; }
	bool GetShowExpression() { return m_showExpression; }
	void SetShowExpression(bool value) { m_showExpression = value; }
	bool GetShowExpressionConfidence() { return m_showExpressionConfidence; }
	void SetShowExpressionConfidence(bool value) { m_showExpressionConfidence = value; }
	bool GetShowProperties() { return m_showProperties; }
	void SetShowProperties(bool value) { m_showProperties = value; }
	bool GetShowPropertiesConfidence() { return m_showPropertiesConfidence; }
	void SetShowPropertiesConfidence(bool value) { m_showPropertiesConfidence = value; }
	void SetShowBaseFeaturePoints(bool value){ m_showBaseFeaturePoints = value; }
	bool GetShowBaseFeaturePoints(){ return m_showBaseFeaturePoints; }
	int GetFeatureWidth(){ return m_featureWidth; }
	void SetFeatureWidth(int value){ m_featureWidth = value; }
	int GetBaseFeatureWidth(){ return m_baseFeatureWidth; }
	void SetBaseFeatureWidth(int value){ m_baseFeatureWidth = value; }
protected:
#if wxUSE_GRAPHICS_CONTEXT == 1
	virtual void OnDraw(wxGraphicsContext *gc)
	{
		if (m_bitmap.GetRefData())
		{
			gc->DrawBitmap(m_bitmap, 0, 0, m_bitmap.GetWidth(), m_bitmap.GetHeight());
		}

		gc->Clip(0, 0, m_bitmap.GetWidth(), m_bitmap.GetHeight());
		for (int i = 0; i < m_detailsCount; i++)
		{
			wxString faceNumber(wxString::Format(wxT("#%d"), i + 1));
			wxString faceConfidence;
			if (m_details[i].FaceAvailable)
			{
				faceConfidence = wxString::Format(wxT("%4.1f"), m_details[i].Face.Confidence);
			}

			DrawDetectionDetails(gc, &m_details[i], faceNumber, faceConfidence);
		}
		gc->ResetClip();

		if (m_showFps
			&& m_currentFps > 0.5f
			&& m_currentFps < 1000.0f)
		{
			wxBrush brush(wxColour(127, 127, 127));
			wxGraphicsBrush graphicsBrush = gc->CreateBrush(brush);
			gc->DrawText(wxString::Format(wxT("%4.1f"), m_currentFps), 5, 5, graphicsBrush);
		}
	}

	void DrawDetectionDetails(wxGraphicsContext *gc, NleDetectionDetails *details, const wxString& faceNumber, const wxString& faceConfidence)
	{
		wxPen pen(m_faceRectangleColor, m_faceRectangleWidth);
		wxBrush solidBrush(m_faceRectangleColor);
		gc->SetPen(pen);

		int half = m_baseFeatureWidth / 2;
		if(m_showBaseFeaturePoints)
		{
			gc->SetBrush(solidBrush);
			for(int i = 0; i < NLE_FEATURE_POINT_COUNT; i++)
			{
				if(details->Points[i].Confidence > 0)
				{
					gc->DrawEllipse(details->Points[i].X - half, details->Points[i].Y - half, m_baseFeatureWidth, m_baseFeatureWidth);
				}
			}
		}

		half = m_featureWidth / 2;
		if (m_showEyes && (IsConfidenceOk(details->LeftEyeCenter.Confidence) || IsConfidenceOk(details->RightEyeCenter.Confidence)))
		{
			if(IsConfidenceOk(details->LeftEyeCenter.Confidence) && IsConfidenceOk(details->RightEyeCenter.Confidence))
			{
				gc->StrokeLine(details->LeftEyeCenter.X, details->LeftEyeCenter.Y,
				details->RightEyeCenter.X, details->RightEyeCenter.Y);
			}
			gc->SetBrush(solidBrush);
			if(IsConfidenceOk(details->LeftEyeCenter.Confidence))
			{
				gc->DrawEllipse(details->LeftEyeCenter.X - half, details->LeftEyeCenter.Y - half, m_featureWidth, m_featureWidth);
			}
			if(IsConfidenceOk(details->RightEyeCenter.Confidence))
			{
				gc->DrawEllipse(details->RightEyeCenter.X - half, details->RightEyeCenter.Y - half, m_featureWidth, m_featureWidth);
			}
			gc->SetBrush(wxNullBrush);

			if(m_showEyesConfidence)
			{
				if(IsConfidenceOk(details->RightEyeCenter.Confidence))
				{
					gc->DrawText(wxString::Format(wxT("%d"), details->RightEyeCenter.Confidence),
						details->RightEyeCenter.X - m_featureWidth, details->RightEyeCenter.Y + m_featureWidth);
				}
				if(IsConfidenceOk(details->LeftEyeCenter.Confidence))
				{
					gc->DrawText(wxString::Format(wxT("%d"), details->LeftEyeCenter.Confidence),
						details->LeftEyeCenter.X - m_featureWidth, details->LeftEyeCenter.Y + m_featureWidth);
				}
			}
		}
		if(m_showNose && IsConfidenceOk(details->NoseTip.Confidence))
		{
			gc->SetBrush(solidBrush);
			gc->DrawEllipse(details->NoseTip.X - half, details->NoseTip.Y - half, m_featureWidth, m_featureWidth);

			if(m_showNoseConfidence)
			{
				gc->DrawText(wxString::Format(wxT("%d"), details->NoseTip.Confidence),
						details->NoseTip.X - m_featureWidth, details->NoseTip.Y + m_featureWidth);
			}
			gc->SetBrush(wxNullBrush);
		}
		if(m_showMouth && IsConfidenceOk(details->MouthCenter.Confidence))
		{
			gc->SetBrush(solidBrush);
			gc->DrawEllipse(details->MouthCenter.X - half, details->MouthCenter.Y - half, m_featureWidth, m_featureWidth);
			gc->SetBrush(wxNullBrush);

			if(m_showMouthConfidence)
			{
				gc->DrawText(wxString::Format(wxT("%d"), details->MouthCenter.Confidence),
					details->MouthCenter.X - m_featureWidth, details->MouthCenter.Y + m_featureWidth);
			}
		}

		gc->SetPen(wxNullPen);

		if (details->FaceAvailable)
		{
			wxPen penGreen(m_faceRectangleColor, m_faceRectangleWidth);
			penGreen.SetCap(wxCAP_PROJECTING);
			penGreen.SetJoin(wxJOIN_MITER);
			gc->SetPen(penGreen);

			wxGraphicsMatrix oldTransform = gc->GetTransform();

			wxGraphicsMatrix matrix = gc->CreateMatrix();
			matrix.Translate(details->Face.Rectangle.X + details->Face.Rectangle.Width / 2,
				details->Face.Rectangle.Y + details->Face.Rectangle.Height / 2);
			matrix.Rotate(details->Face.Rotation.Roll * M_PI / 180.0);
			matrix.Translate(-details->Face.Rectangle.Width / 2, -details->Face.Rectangle.Height / 2);
			gc->ConcatTransform(matrix);

			wxGraphicsPath path = gc->CreatePath();
			Neurotec::Geometry::NRect rect = details->Face.Rectangle;
			short yaw = details->Face.Rotation.Yaw;

			path.AddLineToPoint(rect.Width, 0);
			if(yaw < 0)
			{
				path.AddLineToPoint(rect.Width - (rect.Width / 5 * yaw / 45), rect.Height / 2);
			}
			path.AddLineToPoint(rect.Width, rect.Height);
			path.AddLineToPoint(0, rect.Height);
			if(yaw > 0)
			{
				path.AddLineToPoint(-(rect.Width / 5 * yaw / 45), rect.Height / 2);
			}
			path.AddLineToPoint(0, 0);
			path.CloseSubpath();
			gc->StrokePath(path);

			gc->SetPen(wxNullPen);

			wxBrush brush(wxColour(0, 255, 0));
			wxGraphicsBrush graphicsBrush = gc->CreateBrush(brush);
			if (!faceNumber.IsEmpty())
			{
				gc->DrawText(faceNumber, 0, rect.Height + 3, graphicsBrush);
			}
			if (!faceConfidence.IsEmpty())
			{
				double textWidth, textHeight, descent, externalLeading;
				gc->GetTextExtent(faceConfidence, &textWidth, &textHeight, &descent, &externalLeading);
				gc->DrawText(faceConfidence, rect.Width - textWidth,
					rect.Height + 3, graphicsBrush);
			}

			if (m_showGender || m_showProperties || m_showExpression)
			{
				wxString value = GetDetailsString(details);
				if (value != wxEmptyString)
				{
					double textWidth, textHeight, descent, externalLeading;
					double faceWidth = details->Face.Rectangle.Width;
					gc->GetTextExtent(value, &textWidth, &textHeight, &descent, &externalLeading);
					double offset = textWidth > faceWidth ? (textWidth - faceWidth) / 2 : 0;
					gc->DrawText(value, 0 - offset, 0 - textHeight - 1, graphicsBrush);
				}
			}

			gc->SetTransform(oldTransform);
		}
	}
#else
	virtual void OnDraw(wxDC& dc)
	{
		if (m_bitmap.GetRefData())
		{
			dc.DrawBitmap(m_bitmap, 0, 0, false);
		}
		for (int i = 0; i < m_detailsCount; i++)
		{
			wxString infoString(wxString::Format(wxT("#%d"), i + 1));
			if (m_details[i].FaceAvailable)
			{
				infoString.Append(wxString::Format(wxT("   %4.1f"), m_details[i].Face.Confidence));
			}
			DrawDetectionDetails(dc, &m_details[i], infoString);
		}
		if (m_showFps
			&& m_currentFps > 0.5f
			&& m_currentFps < 1000.0f)
		{
			dc.SetTextForeground(wxColour(0, 255, 0));
			dc.DrawText(wxString::Format(wxT("%4.1f"), m_currentFps), 5, 5);
		}
	}

	static inline void RotatePointAt(double x, double y, double centerX, double centerY, double angle, double *ox, double *oy)
	{
		*ox = centerX + cos(angle) * (x - centerX) - sin(angle) * (y - centerY);
		*oy = centerY + sin(angle) * (x - centerX) + cos(angle) * (y - centerY);
	}

	void DrawDetectionDetails(wxDC &dc, NleDetectionDetails *details, const wxString& info)
	{
		wxPen penGreen(m_faceRectangleColor, m_faceRectangleWidth);
		wxBrush solidBrush(m_faceRectangleColor);
		dc.SetPen(penGreen);

		int half = m_baseFeatureWidth / 2;
		if(m_showBaseFeaturePoints)
		{
			dc.SetBrush(solidBrush);
			for(int i = 0; i < NLE_FEATURE_POINT_COUNT; i++)
			{
				if(details->Points[i].Confidence > 0)
				{
					dc.DrawEllipse(details->Points[i].X - half, details->Points[i].Y - half, m_baseFeatureWidth, m_baseFeatureWidth);
				}
			}
		}

		half = m_featureWidth / 2;
		if(m_showEyes && (IsConfidenceOk(details->LeftEyeCenter.Confidence) || IsConfidenceOk(details->RightEyeCenter.Confidence)))
		{
			if(IsConfidenceOk(details->LeftEyeCenter.Confidence) && IsConfidenceOk(details->RightEyeCenter.Confidence))
			{
				wxPoint points[] =
				{
					wxPoint(details->LeftEyeCenter.X, details->LeftEyeCenter.Y),
					wxPoint(details->RightEyeCenter.X, details->RightEyeCenter.Y)
				};
				dc.DrawLines(2, points, 0, 0);
			}
			if(IsConfidenceOk(details->LeftEyeCenter.Confidence))
			{
				dc.DrawEllipse(details->LeftEyeCenter.X - half, details->LeftEyeCenter.Y - half, m_featureWidth, m_featureWidth);
			}
			if(IsConfidenceOk(details->RightEyeCenter.Confidence))
			{
				dc.DrawEllipse(details->RightEyeCenter.X - half, details->RightEyeCenter.Y - half, m_featureWidth, m_featureWidth);
			}
			if(m_showEyesConfidence)
			{
				if(IsConfidenceOk(details->RightEyeCenter.Confidence))
				{
					dc.DrawText(wxString::Format(wxT("%d"), details->RightEyeCenter.Confidence),
						details->RightEyeCenter.X - m_featureWidth, details->RightEyeCenter.Y + m_featureWidth);
				}
				if(IsConfidenceOk(details->LeftEyeCenter.Confidence))
				{
					dc.DrawText(wxString::Format(wxT("%d"), details->LeftEyeCenter.Confidence),
						details->LeftEyeCenter.X - m_featureWidth, details->LeftEyeCenter.Y + m_featureWidth);
				}
			}
		}

		if(m_showNose && IsConfidenceOk(details->NoseTip.Confidence))
		{
			dc.DrawEllipse(details->NoseTip.X - half, details->NoseTip.Y - half, m_featureWidth, m_featureWidth);

			if(m_showNoseConfidence)
			{
				dc.DrawText(wxString::Format(wxT("%d"), details->NoseTip.Confidence),
						details->NoseTip.X - m_featureWidth, details->NoseTip.Y + m_featureWidth);
			}
		}

		if(m_showMouth && IsConfidenceOk(details->MouthCenter.Confidence))
		{
			dc.DrawEllipse(details->MouthCenter.X - half, details->MouthCenter.Y - half, m_featureWidth, m_featureWidth);
			dc.SetBrush(wxNullBrush);

			if(m_showMouthConfidence)
			{
				dc.DrawText(wxString::Format(wxT("%d"), details->MouthCenter.Confidence),
					details->MouthCenter.X - m_featureWidth, details->MouthCenter.Y + m_featureWidth);
			}
		}


		if (details->FaceAvailable)
		{
			wxPen penGreen(m_faceRectangleColor, m_faceRectangleWidth);
			penGreen.SetCap(wxCAP_PROJECTING);
			penGreen.SetJoin(wxJOIN_MITER);
			dc.SetPen(penGreen);
			double angle = (double)details->Face.Rotation.Roll * M_PI / 180.0;
			double pt1x, pt1y;
			RotatePointAt(details->Face.Rectangle.X, details->Face.Rectangle.Y,
				(details->Face.Rectangle.X * 2 + details->Face.Rectangle.Width) / 2,
				(details->Face.Rectangle.Y * 2 + details->Face.Rectangle.Height) / 2,
				angle, &pt1x, &pt1y);
			double pt2x, pt2y;
			RotatePointAt(details->Face.Rectangle.X + details->Face.Rectangle.Width,
				details->Face.Rectangle.Y,
				(details->Face.Rectangle.X * 2 + details->Face.Rectangle.Width) / 2,
				(details->Face.Rectangle.Y * 2 + details->Face.Rectangle.Height) / 2,
				angle, &pt2x, &pt2y);
			double pt3x, pt3y;
			RotatePointAt(details->Face.Rectangle.X + details->Face.Rectangle.Width,
				details->Face.Rectangle.Y + details->Face.Rectangle.Height,
				(details->Face.Rectangle.X * 2 + details->Face.Rectangle.Width) / 2,
				(details->Face.Rectangle.Y * 2 + details->Face.Rectangle.Height) / 2,
				angle, &pt3x, &pt3y);
			double pt4x, pt4y;
			RotatePointAt(details->Face.Rectangle.X,
				details->Face.Rectangle.Y + details->Face.Rectangle.Height,
				(details->Face.Rectangle.X * 2 + details->Face.Rectangle.Width) / 2,
				(details->Face.Rectangle.Y * 2 + details->Face.Rectangle.Height) / 2,
				angle, &pt4x, &pt4y);
			wxPoint points[] ={ wxPoint((int)pt1x, (int)pt1y),
				wxPoint((int)pt2x, (int)pt2y),
				wxPoint((int)pt3x, (int)pt3y),
				wxPoint((int)pt4x, (int)pt4y),
				wxPoint((int)pt1x, (int)pt1y) };
			dc.DrawLines(5, points, 0, 0);
			dc.SetPen(wxNullPen);

			dc.SetTextForeground(wxColour(0, 255, 0));
			dc.DrawRotatedText(info, (wxCoord)pt4x, (wxCoord)pt4y, (double) -details->Face.Rotation.Roll);

			if (m_showGender || m_showExpression || m_showProperties)
			{
				wxString value = GetDetailsString(details);
				if (value != wxEmptyString)
				{
					wxSize sz = dc.GetTextExtent(value);
					double faceWidth = details->Face.Rectangle.Width;
					int offset = sz.GetWidth() > faceWidth ? (int)((sz.GetWidth() - faceWidth) / 2) : 0;
					dc.SetTextForeground(wxColour(0, 255, 0));
					dc.DrawRotatedText(value, (wxCoord)(pt1x - offset), (wxCoord)pt1y - sz.GetHeight() - 1, (double) -details->Face.Rotation.Roll);
				}
			}
		}
	}
#endif

private:
	wxString GetDetailsString(NleDetectionDetails * details)
	{
		wxString value = wxEmptyString;
		if(m_showGender && IsConfidenceOk(details->GenderConfidence))
		{
			switch(details->Gender)
			{
				case ngUnspecified: value = wxT("Unspecified"); break;
				case ngMale: value = wxT("Male"); break;
				case ngFemale: value = wxT("Female"); break;
				default: value = wxT("Unknown");
			}
			if(m_showGenderConfidence) value.Append(wxString::Format(wxT("(%d)"), details->GenderConfidence));
		}
		if (m_showExpression && IsExpressionOk(details->Expression) && IsConfidenceOk(details->ExpressionConfidence))
		{
			if (value != wxEmptyString) value.Append(wxT(", "));
			value.Append(wxT("Smile"));
			if (m_showExpressionConfidence) value.Append(wxString::Format(wxT("(%d)"), details->ExpressionConfidence));
		}
		if (m_showProperties)
		{
			if (IsConfidenceOk(details->GlassesConfidence) && IsPropertySet(details->Properties, nlpGlasses))
			{
				if (value != wxEmptyString) value.Append(wxT(", "));
				value.append(wxT("Glasses"));
				if (m_showPropertiesConfidence) value.Append(wxString::Format(wxT("(%d)"), details->GlassesConfidence));
			}
			if (IsConfidenceOk(details->MouthOpenConfidence) && IsPropertySet(details->Properties, nlpMouthOpen))
			{
				if (value != wxEmptyString) value.Append(wxT(", "));
				value.append(wxT("Mouth Open"));
				if (m_showPropertiesConfidence) value.Append(wxString::Format(wxT("(%d)"), details->MouthOpenConfidence));
			}
			if (IsConfidenceOk(details->BlinkConfidence) && IsPropertySet(details->Properties, nlpBlink))
			{
				if (value != wxEmptyString) value.Append(wxT(", "));
				value.Append(wxT("Blink"));
				if (m_showPropertiesConfidence) value.Append(wxString::Format(wxT("(%d)"), details->BlinkConfidence));
			}
			if (IsConfidenceOk(details->DarkGlassesConfidence) && IsPropertySet(details->Properties, nlpDarkGlasses))
			{
				if (value != wxEmptyString) value.Append(wxT(", "));
				value.Append(wxT("Dark Glasses"));
				if (m_showPropertiesConfidence) value.Append(wxString::Format(wxT("(%d)"), details->DarkGlassesConfidence));
			}
		}
		return value;
	}

	static bool IsExpressionOk(NLExpression expression) { return expression == nleSmile; }
	static bool IsConfidenceOk(NByte confidence) { return confidence > 0 && confidence <= 100; }
	static bool IsPropertySet(NLProperties value, NLProperties flag) { return (value & flag) == flag; }
private:
	void UpdateFps()
	{
		wxLongLong currentTime = ::wxGetLocalTimeMillis();
		float previousFps = m_currentFps;
		m_currentFps = 0.0f;
		if (currentTime - m_lastTime > 5000)
		{
			m_frameCount = 0;
			m_firstTime = currentTime;
		}
		else
		{
			m_frameCount++;
			if (m_frameCount == MAX_FPS_ENTRIES)
			{
				m_currentFps = (float)((m_frameCount.ToDouble() * 1000.0) / (double)(currentTime - m_firstTime).ToDouble());
			}
			else if (m_frameCount > MAX_FPS_ENTRIES)
			{
				float frameFps = (float)(1000.0 / (currentTime - m_lastTime).ToDouble());
				const float newFpsWeight = (float)1.0f / (float)MAX_FPS_ENTRIES;
				m_currentFps = previousFps * (1.0f - newFpsWeight) + frameFps * newFpsWeight;
			}
		}
		m_lastTime = currentTime;
	}

	wxImage m_image;
	wxBitmap m_bitmap;
	NleDetectionDetails *m_details;
	int m_detailsCount;
	wxColour m_faceRectangleColor;
	int m_faceRectangleWidth;
	wxLongLong m_lastTime;
	wxLongLong m_firstTime;
	wxLongLong m_frameCount;
	float m_currentFps;
	bool m_showFps;
	bool m_showEyes;
	bool m_showNose;
	bool m_showMouth;
	bool m_showNoseConfidence;
	bool m_showEyesConfidence;
	bool m_showMouthConfidence;
	bool m_showGender;
	bool m_showGenderConfidence;
	bool m_showExpression;
	bool m_showExpressionConfidence;
	bool m_showProperties;
	bool m_showPropertiesConfidence;
	bool m_showBaseFeaturePoints;
	int m_featureWidth;
	int m_baseFeatureWidth;
};
#include <Core/NReDeprecate.h>

}}}

#endif // !WX_NLVIEW_HPP_INCLUDED
