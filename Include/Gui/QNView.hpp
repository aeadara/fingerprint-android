#ifndef QT_NVIEW_HPP_INCLUDED
#define QT_NVIEW_HPP_INCLUDED

#include <QWidget>
#include <QSize>
#include <QRect>
#include <QScrollBar>
#include <QMouseEvent>
#include <QPainter>

#include <stdlib.h>
#include <QScrollArea>

#include <Core/NObject.hpp>

namespace Neurotec { namespace Gui {

class QNView : public QWidget
{
	Q_OBJECT
public:
	QNView(QWidget *parent = 0) : QWidget(parent)
	{
		m_zoomFactor = 1;
		SetViewSize(1, 1);
	}

	virtual ~QNView()
	{
	}

	double GetZoomFactor()
	{
		return m_zoomFactor;
	}

private:
	static inline double Min(double x, double y)
	{
		if (x < y) return x; else return y;
	}

	void wheelEvent(QWheelEvent * event)
	{
		if ((event->modifiers() & Qt::ControlModifier) == Qt::ControlModifier)
		{
			int wheelDelta = event->delta();
			if (wheelDelta < 0)
			{
				Zoom(m_zoomFactor * (1 - 0.1));
			}
			else if (wheelDelta > 0)
			{
				Zoom(m_zoomFactor * (1 + 0.1));
			}
			emit WheelZoom(m_zoomFactor);
			event->accept();
		}
		else
		{
			event->ignore();
		}
	}

protected:
	void paintEvent ( QPaintEvent * )
	{
		int translateX = 0;
		int translateY = 0;
		QSize imageSize = GetImageSize();
		QSize parentSize = GetParentSize();
		resize(parentSize);
		if(parentSize.width() > imageSize.width())
		{
			translateX = (parentSize.width() - imageSize.width()) / 2 + 1;
		}
		if(parentSize.height() > imageSize.height())
		{
			translateY = (parentSize.height() - imageSize.height()) / 2 + 1;
		}

		QPainter painter(this);
		painter.save();
		painter.setClipRect(translateX, translateY, imageSize.width(), imageSize.height());
		painter.translate(translateX, translateY);
		painter.scale(m_zoomFactor, m_zoomFactor);
		OnDraw(painter);
		painter.restore();
	}

	virtual void OnDraw(QPainter &)
	{
		int translateX = 0;
		int translateY = 0;
		QSize imageSize = GetImageSize();
		QSize parentSize = GetParentSize();
		resize(parentSize);
		if(parentSize.width() > imageSize.width())
			translateX = (parentSize.width() - imageSize.width()) / 2 + 1;
		if(parentSize.height() > imageSize.height())
			translateY = (parentSize.height() - imageSize.height()) / 2 + 1;

		QPainter painter(this);
		painter.save();
		painter.setClipRect(translateX, translateY, imageSize.width(), imageSize.height());
		painter.translate(translateX, translateY);
		painter.scale(m_zoomFactor, m_zoomFactor);
		OnDraw(painter);
		painter.restore();
	}

	QSize GetParentSize()
	{
		QWidget * parent = parentWidget();
		if(parent)
			return parent->size();
		else
			return QSize();
	}

	QSize GetImageSize()
	{
		return QSize((int)((double)m_viewSize.width() * m_zoomFactor), (int)((double)m_viewSize.height() * m_zoomFactor));
	}

	virtual QRect GetImageRect()
	{
		return QRect(QPoint(0, 0), GetImageSize());
	}

	void SetViewSize(QSize size)
	{
		SetViewSize(size.width(), size.height());
	}

	void SetViewSize(int viewWidth, int viewHeight)
	{
		m_viewSize = QSize(viewWidth, viewHeight);
		QSize imageSz = GetImageSize();
		QSize parentSz = GetParentSize();
		setMinimumSize(qMax(imageSz.width(), parentSz.width()), qMax(imageSz.height(), parentSz.height()));
	}

	double m_zoomFactor;
	QSize m_viewSize;

public slots:
	void ZoomToFit()
	{
		QWidget * viewport = parentWidget();
		if(viewport)
		{
			double zoomFactor = Min((double)viewport->width() / m_viewSize.width(), (double)viewport->height() / m_viewSize.height());
			if(zoomFactor != m_zoomFactor)
				Zoom(zoomFactor);
		}
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
		if(m_zoomFactor == zoomFactor)
			return;
		m_zoomFactor = zoomFactor;
		setMinimumSize(GetImageSize());
		update();
	}

signals:
	void WheelZoom(double newZoomFactor);

};

}}

#endif // !QT_NVIEW_HPP_INCLUDED
