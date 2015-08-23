#ifndef QT_NLVIEW_HPP_INCLUDED
#define QT_NLVIEW_HPP_INCLUDED

#include <Gui/QNView.hpp>
#include <Biometrics/NLTemplate.hpp>
#include <Biometrics/NLExtractor.hpp>
#include <Core/NTimeSpan.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

#define MAX_FPS_ENTRIES 30

namespace Neurotec { namespace Biometrics { namespace Gui
{

class QNLView : public Neurotec::Gui::QNView
{
	Q_OBJECT
public:
	explicit QNLView(QWidget *parent = 0) : Neurotec::Gui::QNView(parent)
	{
		m_image = QImage();
		m_details = NULL;
		m_detailsCount = 0;
		m_frameCount = 0;
		m_currentFps = 0;
		m_showFps = true;
		m_faceRectangleColor = QColor::fromRgb(0, 255, 0);
		m_faceRectangleWidth = 2;
		m_showEyes = true;
		m_showNose = true;
		m_showMouth = true;
		m_showNoseConfidence = false;
		m_showEyesConfidence = false;
		m_showMouthConfidence = false;
		m_showGender = true;
		m_showGenderConfidence = false;
		m_showBaseFeaturePoints = true;
		m_showExpression = true;
		m_showExpressionConfidence = false;
		m_showProperties = true;
		m_showPropertiesConfidence = false;
		m_featureWidth = 4;
		m_baseFeatureWidth = 2;
		m_faceCount = 0;
	}

	void Clear()
	{
		m_image = QImage();
		m_details = NULL;
		m_detailsCount = 0;
		SetViewSize(1, 1);
		update();
	}

	void SetImage(QImage image, NleFace * faces, int faceCount)
	{
		m_faces = faces;
		m_faceCount = faceCount;
		if (m_showFps)
		{
			UpdateFps();
		}

		m_image = image;
		if(!image.isNull())
			SetViewSize(image.size());
		else
			SetViewSize(1, 1);
		update();
	}

	virtual QRect GetImageRect()
	{
		QRect r;
		if (!m_image.isNull())
		{
			r.setWidth(m_image.width()*m_zoomFactor);;
			r.setHeight(m_image.height()*m_zoomFactor);
		}
		return r;
	}

	QImage GetImage()
	{
		return m_image;
	}

	void SetDetectionDetails(NleDetectionDetails *details, int detailsCount)
	{
		m_details = details;
		m_detailsCount = detailsCount;
		update();
	}

	NleDetectionDetails * GetDetectionDetails()
	{
		return m_details;
	}

	int GetDetectionDetailsCount()
	{
		return m_detailsCount;
	}

	void SetFaceRectangleColor(QColor value)
	{
		m_faceRectangleColor = value;
	}

	const QColor GetFaceRectangleColor()
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

	void SetShowFps(bool value)
	{
		m_showFps = value;
	}

	bool GetShowFps()
	{
		return m_showFps;
	}

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
	void SetShowBaseFeaturePoints(bool value){ m_showBaseFeaturePoints = value; }
	bool GetShowBaseFeaturePoints(){ return m_showBaseFeaturePoints; }
	bool GetShowExpression() { return m_showExpression; }
	void SetShowExpression(bool value) { m_showExpression = value; }
	bool GetShowExpressionConfidence() { return m_showExpressionConfidence; }
	void SetShowExpressionConfidence(bool value) { m_showExpressionConfidence = value; }
	bool GetShowProperties() { return m_showProperties; }
	void SetShowProperties(bool value) { m_showProperties = value; }
	bool GetShowPropertiesConfidence() { return m_showPropertiesConfidence; }
	void SetShowPropertiesConfidence(bool value) { m_showPropertiesConfidence = value; }
	int GetFeatureWidth(){ return m_featureWidth; }
	void SetFeatureWidth(int value){ m_featureWidth = value; }
	int GetBaseFeatureWidth(){ return m_baseFeatureWidth; }
	void SetBaseFeatureWidth(int value){ m_baseFeatureWidth = value; }
protected:

	virtual void OnDraw(QPainter& painter)
	{
		painter.setRenderHint(QPainter::Antialiasing);
		if (!m_image.isNull())
		{
			painter.drawImage(0, 0, m_image);
		}
		QPen facesRectanglePen(m_faceRectangleColor);
		facesRectanglePen.setWidth(m_faceRectangleWidth);
		painter.setPen(facesRectanglePen);
		if (m_detailsCount)
		{
			for (int i = 0; i < m_detailsCount; i++)
			{
				QString infoString = QString("#%1").arg(i + 1);
				if (m_details[i].FaceAvailable)
				{
					infoString.append(QString("   %1").arg(m_details[i].Face.Confidence));
				}
				DrawDetectionDetails(painter, &m_details[i], infoString);
			}
		}
		else
		{
			for (int i = 0; i < m_faceCount; i++)
			{
				DrawFaceRect(painter, &m_faces[i]);
			}
		}
		if (m_showFps
			&& m_currentFps > 0.5f
			&& m_currentFps < 1000.0f)
		{
			painter.drawText(5, 15, QString::number(m_currentFps));
		}
	}

	static inline void RotatePointAt(double x, double y, double centerX, double centerY, double angle, double *ox, double *oy)
	{
		*ox = centerX + cos(angle) * (x - centerX) - sin(angle) * (y - centerY);
		*oy = centerY + sin(angle) * (x - centerX) + cos(angle) * (y - centerY);
	}

	void DrawFaceRect(QPainter& painter, NleFace * face)
	{
		QPen penGreen(m_faceRectangleColor, m_faceRectangleWidth);
		painter.setPen(penGreen);
		double angle = (double)face->Rotation.Roll * M_PI / 180.0;
		double pt1x, pt1y;
		RotatePointAt(face->Rectangle.X, face->Rectangle.Y,
			(face->Rectangle.X * 2 + face->Rectangle.Width) / 2,
			(face->Rectangle.Y * 2 + face->Rectangle.Height) / 2,
			angle, &pt1x, &pt1y);
		QPoint pt1 = QPoint(pt1x, pt1y);

		double pt2x, pt2y;
		RotatePointAt(face->Rectangle.X + face->Rectangle.Width,
			face->Rectangle.Y,
			(face->Rectangle.X * 2 + face->Rectangle.Width) / 2,
			(face->Rectangle.Y * 2 + face->Rectangle.Height) / 2,
			angle, &pt2x, &pt2y);
		QPoint pt2 = QPoint(pt2x, pt2y);

		double pt3x, pt3y;
		RotatePointAt(face->Rectangle.X + face->Rectangle.Width,
			face->Rectangle.Y + face->Rectangle.Height,
			(face->Rectangle.X * 2 + face->Rectangle.Width) / 2,
			(face->Rectangle.Y * 2 + face->Rectangle.Height) / 2,
			angle, &pt3x, &pt3y);
		QPoint pt3 = QPoint(pt3x, pt3y);

		double pt4x, pt4y;
		RotatePointAt(face->Rectangle.X,
			face->Rectangle.Y + face->Rectangle.Height,
			(face->Rectangle.X * 2 + face->Rectangle.Width) / 2,
			(face->Rectangle.Y * 2 + face->Rectangle.Height) / 2,
			angle, &pt4x, &pt4y);
		QPoint pt4 = QPoint(pt4x, pt4y);

		QPoint points[6];
		points[0] = pt1;
		points[1] = pt2;
		points[5] = pt1;
		double ptYawX, ptYawY;
		if(face->Rotation.Yaw < 0)
		{
			Neurotec::Geometry::NRect rect = face->Rectangle;
			RotatePointAt(rect.X + rect.Width - (rect.Width / 5 * face->Rotation.Yaw / 45),
				rect.Y + rect.Height / 2,
				(face->Rectangle.X * 2 + face->Rectangle.Width) / 2,
				(face->Rectangle.Y * 2 + face->Rectangle.Height) / 2,
				angle, &ptYawX, &ptYawY);
			points[2] = QPoint(ptYawX, ptYawY);
			points[3] = pt3;
			points[4] = pt4;
		}
		else
		{
			Neurotec::Geometry::NRect rect = face->Rectangle;
			RotatePointAt(rect.X - (rect.Width / 5 * face->Rotation.Yaw / 45),
				rect.Y + rect.Height / 2,
				(face->Rectangle.X * 2 + face->Rectangle.Width) / 2,
				(face->Rectangle.Y * 2 + face->Rectangle.Height) / 2,
				angle, &ptYawX, &ptYawY);
			points[2] = pt3;
			points[3] = pt4;
			points[4] = QPoint(ptYawX, ptYawY);
		}

		painter.drawPolyline(points, 6);
	}

	void DrawDetectionDetails(QPainter& dc, NleDetectionDetails *details, const QString info)
	{
		QPen penGreen(m_faceRectangleColor, m_faceRectangleWidth);
		QBrush brush(m_faceRectangleColor);
		dc.setPen(penGreen);
		dc.setBrush(brush);
		QFont font(dc.font());
		font.setPixelSize(16);
		dc.setFont(font);
		dc.setRenderHint(QPainter::TextAntialiasing);
		if(details->FaceAvailable)
		{
			DrawFaceRect(dc, &details->Face);

			double angle = details->Face.Rotation.Roll;
			QTransform oldTransform = dc.transform();
			QTransform transform = QTransform(oldTransform.toAffine());
			transform.translate(details->Face.Rectangle.X + details->Face.Rectangle.Width / 2, details->Face.Rectangle.Y + details->Face.Rectangle.Height / 2);
			transform.rotate(angle);
			transform.translate(-(details->Face.Rectangle.X + details->Face.Rectangle.Width / 2), -(details->Face.Rectangle.Y + details->Face.Rectangle.Height / 2));
			dc.setTransform(transform);

			dc.drawText(details->Face.Rectangle.X, details->Face.Rectangle.Y - 1, info);

			if (m_showGender || m_showProperties || m_showExpression)
			{
				QString value = QString();
				if(m_showGender && IsConfidenceOk(details->GenderConfidence))
				{
					switch(details->Gender)
					{
					case ngUnspecified: value = QString("Unspecified"); break;
					case ngMale: value = QString("Male"); break;
					case ngFemale: value = QString("Female"); break;
					default: value = QString("Unknown"); 
					}
					if(m_showGenderConfidence) value += QString("(%1%)").arg(QString::number(details->GenderConfidence));
				}
				if (m_showExpression && IsExpressionOk(details->Expression) && IsConfidenceOk(details->ExpressionConfidence))
				{
					if (!value.isEmpty()) value += ", ";
					value += "Smile";
					if (m_showExpressionConfidence) value += QString("(%1%)").arg(QString::number(details->ExpressionConfidence));
				}
				if (m_showProperties)
				{
					if (IsConfidenceOk(details->GlassesConfidence) && IsPropertySet(details->Properties, nlpGlasses))
					{
						if (!value.isEmpty()) value += ", ";
						value += "Glasses";
						if (m_showPropertiesConfidence) value += QString("(%1%)").arg(QString::number(details->GlassesConfidence));
					}
					if (IsConfidenceOk(details->MouthOpenConfidence) && IsPropertySet(details->Properties, nlpMouthOpen))
					{
						if (!value.isEmpty()) value += ", ";
						value += "MouthOpen";
						if (m_showPropertiesConfidence) value += QString("(%1%)").arg(QString::number(details->MouthOpenConfidence));
					}
					if (IsConfidenceOk(details->BlinkConfidence) && IsPropertySet(details->Properties, nlpBlink))
					{
						if (!value.isEmpty()) value += ", ";
						value += "Blink";
						if (m_showPropertiesConfidence) value += QString("(%1%)").arg(QString::number(details->BlinkConfidence));
					}
					if (IsConfidenceOk(details->DarkGlassesConfidence) && IsPropertySet(details->Properties, nlpDarkGlasses))
					{
						if (!value.isEmpty()) value += ", ";
						value += "Dark Glasses";
						if (m_showPropertiesConfidence) value += QString("(%1%)").arg(QString::number(details->DarkGlassesConfidence));
					}
				}

				if (!value.isEmpty())
				{
					QFontMetrics metrics(dc.font());
					QRect rect = metrics.boundingRect(value);
					rect = metrics.boundingRect(details->Face.Rectangle.X, details->Face.Rectangle.Y + details->Face.Rectangle.Height, details->Face.Rectangle.Width, 1024, Qt::TextWordWrap, value);
					dc.drawText(rect, Qt::TextWordWrap, value);
				}
			}
			dc.setTransform(oldTransform);
		}

		int half = m_baseFeatureWidth / 2;
		if(m_showBaseFeaturePoints)
		{
			for(int i = 0; i < NLE_FEATURE_POINT_COUNT; i++)
			{
				if(details->Points[i].Confidence > 0)
				{
					QRect rect(details->Points[i].X - half, details->Points[i].Y - half, m_baseFeatureWidth, m_baseFeatureWidth);
					dc.drawEllipse(rect);
				}
			}
		}

		half = m_featureWidth / 2;
		if (m_showEyes && (IsConfidenceOk(details->LeftEyeCenter.Confidence) || IsConfidenceOk(details->RightEyeCenter.Confidence)))
		{
			if(IsConfidenceOk(details->LeftEyeCenter.Confidence) && IsConfidenceOk(details->RightEyeCenter.Confidence))
			{
				QPoint points[] =
				{
					QPoint(details->LeftEyeCenter.X, details->LeftEyeCenter.Y),
					QPoint(details->RightEyeCenter.X, details->RightEyeCenter.Y)
				};
				dc.drawPolyline(points, 2);
			}
			if(IsConfidenceOk(details->LeftEyeCenter.Confidence))
			{
				QRect rect(details->LeftEyeCenter.X - half, details->LeftEyeCenter.Y - half, m_featureWidth, m_featureWidth);
				dc.drawEllipse(rect);
			}
			if(IsConfidenceOk(details->RightEyeCenter.Confidence))
			{
				QRect rect(details->RightEyeCenter.X - half, details->RightEyeCenter.Y - half, m_featureWidth, m_featureWidth);
				dc.drawEllipse(rect);
			}

			if(m_showEyesConfidence)
			{
				if(IsConfidenceOk(details->LeftEyeCenter.Confidence))
				{
					dc.drawText(details->LeftEyeCenter.X - m_featureWidth, details->LeftEyeCenter.Y - m_featureWidth, QString::number(details->LeftEyeCenter.Confidence));
				}
				if(IsConfidenceOk(details->RightEyeCenter.Confidence))
				{
					dc.drawText(details->RightEyeCenter.X - m_featureWidth, details->RightEyeCenter.Y - m_featureWidth, QString::number(details->RightEyeCenter.Confidence));
				}
			}
		}
		if(m_showNose && IsConfidenceOk(details->NoseTip.Confidence))
		{
			QRect rect(details->NoseTip.X - half, details->NoseTip.Y - half, m_featureWidth, m_featureWidth);
			dc.drawEllipse(rect);

			if(m_showNoseConfidence)
			{
				dc.drawText(details->NoseTip.X - m_featureWidth, details->NoseTip.Y - m_featureWidth, QString::number(details->NoseTip.Confidence));
			}
		}
		if(m_showMouth && IsConfidenceOk(details->MouthCenter.Confidence))
		{
			QRect rect(details->MouthCenter.X - half, details->MouthCenter.Y - half, m_featureWidth, m_featureWidth);
			dc.drawEllipse(rect);

			if(m_showMouthConfidence)
			{
				dc.drawText(details->MouthCenter.X - m_featureWidth, details->MouthCenter.Y - m_featureWidth, QString::number(details->MouthCenter.Confidence));
			}
		}
	}

private:
	static bool IsExpressionOk(NLExpression expression) { return expression == nleSmile; }
	static bool IsPropertySet(NLProperties value, NLProperties flag) { return (value & flag) == flag; }
	static bool IsConfidenceOk(NByte confidence) { return confidence > 0 && confidence <= 100; }
private:
	void UpdateFps()
	{
		int elapsed_ms = m_fpsCounter.elapsed();
		m_currentFps = 0.0f;
		if (elapsed_ms > 5000)
		{
			m_frameCount = 0;
			m_fpsCounter.restart();
		}
		else
		{
			m_frameCount++;
			m_currentFps = (float)((m_frameCount * 1000.0) / (double)(elapsed_ms));
		}
	}

	QImage m_image;
	NleDetectionDetails *m_details;
	NleFace * m_faces;
	int m_faceCount;

	int m_detailsCount;
	QColor m_faceRectangleColor;
	int m_faceRectangleWidth;
	QTime m_fpsCounter;
	long m_frameCount;
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
	bool m_showBaseFeaturePoints;
	bool m_showExpression;
	bool m_showExpressionConfidence;
	bool m_showProperties;
	bool m_showPropertiesConfidence;
	int m_featureWidth;
	int m_baseFeatureWidth;
};

}}}


#endif // QT_NLVIEW_HPP_INCLUDED
