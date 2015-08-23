#ifndef QT_NEVIEW_HPP_INCLUDED
#define QT_NEVIEW_HPP_INCLUDED

#include <Images/NImages.hpp>
#include <Biometrics/NEExtractor.hpp>
#include <Gui/QNView.hpp>

namespace Neurotec { namespace Biometrics { namespace Gui {


class QNEView : public Neurotec::Gui::QNView
{
public:
	QNEView(QWidget *parent = 0)
		: Neurotec::Gui::QNView(parent)
	{
		m_details.OuterBoundaryAvailable = NFalse;
		m_details.InnerBoundaryAvailable = NFalse;
		m_outerBoundaryColor = QColor::fromRgb(0, 255, 0);
		m_outerBoundaryWidth = 2;
		m_innerBoundaryColor = QColor::fromRgb(255, 0, 0);
		m_innerBoundaryWidth = 2;
		m_image = QImage();
	}

	void Clear()
	{
		m_image = QImage();
		m_details.InnerBoundaryAvailable = NFalse;
		m_details.OuterBoundaryAvailable = NFalse;
		SetViewSize(1, 1);
		update();
	}

	void SetImage(QImage image)
	{
		m_image = image;
		SetViewSize(image.size());
		update();
	}

	QImage GetImage()
	{
		return m_image;
	}

	void SetSegmentationDetails(const NeeSegmentationDetails & details)
	{
		m_details = details;
		update();
	}

	const NeeSegmentationDetails & GetSegmentationDetails()
	{
		return m_details;
	}

	void SetOuterBoundaryColor(const QColor & value)
	{
		m_outerBoundaryColor = value;
	}

	const QColor & GetOuterBoundaryColor()
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

	void SetInnerBoundaryColor(const QColor & value)
	{
		m_innerBoundaryColor = value;
	}

	const QColor & GetInnerBoundaryColor()
	{
		return m_innerBoundaryColor;
	}

	void SetInnerBoundaryWidth(int value)
	{
		m_innerBoundaryWidth = value;
	}

	int GetInnerBoundaryWidth()
	{
		return m_innerBoundaryWidth;
	}

	virtual void OnDraw(QPainter & painter)
	{
		if(!m_image.isNull())
		{
			painter.drawImage(0, 0, m_image);
		}
		if (m_details.OuterBoundaryAvailable)
		{
			QPen outerBoundaryPen(m_outerBoundaryColor);
			outerBoundaryPen.setWidth(m_outerBoundaryWidth);
			painter.setPen(outerBoundaryPen);
			::Neurotec::Geometry::QNPoint *points = static_cast< ::Neurotec::Geometry::QNPoint *>(&m_details.OuterBoundaryPoints[0]);
			for (int i = 1; i < NEE_BOUNDARY_POINT_COUNT; ++i)
			{
				painter.drawLine(points[i - 1].X, points[i - 1].Y, points[i].X, points[i].Y);
			}
			painter.drawLine(points[NEE_BOUNDARY_POINT_COUNT - 1].X, points[NEE_BOUNDARY_POINT_COUNT - 1].Y, points[0].X, points[0].Y);
			painter.setPen(Qt::NoPen);
		}
		if (m_details.InnerBoundaryAvailable)
		{
			QPen innerBoundaryPen(m_innerBoundaryColor);
			innerBoundaryPen.setWidth(m_innerBoundaryWidth);
			painter.setPen(innerBoundaryPen);
			::Neurotec::Geometry::QNPoint *points = static_cast< ::Neurotec::Geometry::QNPoint *>(&m_details.InnerBoundaryPoints[0]);
			for (int i = 1; i < NEE_BOUNDARY_POINT_COUNT; ++i)
			{
				painter.drawLine(points[i - 1].X, points[i - 1].Y, points[i].X, points[i].Y);
			}
			painter.drawLine(points[NEE_BOUNDARY_POINT_COUNT - 1].X, points[NEE_BOUNDARY_POINT_COUNT - 1].Y, points[0].X, points[0].Y);
			painter.setPen(Qt::NoPen);
		}
	}

private:
	QImage m_image;
	NeeSegmentationDetails m_details;
	QColor m_outerBoundaryColor;
	int m_outerBoundaryWidth;
	QColor m_innerBoundaryColor;
	int m_innerBoundaryWidth;
};


}}}

#endif // QT_NEVIEW_HPP_INCLUDED
