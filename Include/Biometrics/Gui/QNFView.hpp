#ifndef QT_NFVIEW_HPP_INCLUDED
#define QT_NFVIEW_HPP_INCLUDED

#include <QToolTip>
#include <Core/NTypes.hpp>
#include <Biometrics/NFRecord.hpp>
#include <Images/NImages.hpp>
#include <Biometrics/NMatchingDetails.hpp>

#include <Gui/QNView.hpp>
#define _USE_MATH_DEFINES
#include <math.h>


namespace Neurotec { namespace Biometrics { namespace Gui
{

typedef QList<Neurotec::NIndexPair> SpanningTree;

class QNFView: public Neurotec::Gui::QNView
{
	Q_OBJECT
private:

public:
	enum ShownImage
	{
		ORIGINAL_IMAGE,
		PROCESSED_IMAGE
	};

	explicit QNFView(QWidget *parent = 0) : Neurotec::Gui::QNView(parent)
	{
		m_originalImage = QImage();
		m_processedImage = QImage();
		m_pRecord = NULL;
		m_drawFeatures = NTrue;
		m_shownImage = ORIGINAL_IMAGE;
		m_selectedMinutia = -1;
		setMouseTracking(true);
	}

	void Clear()
	{
		m_pRecord = NULL;
		m_originalImage = QImage();
		m_processedImage = QImage();

		m_selectedMinutia = -1;
		m_spanningTree.clear();

		SetViewSize(1, 1);
		update();
	}

	void SetOriginalImage(QImage image)
	{
		m_originalImage = image;

		if(!m_originalImage.isNull())
			SetViewSize(m_originalImage.width(), m_originalImage.height());
		else SetViewSize(1, 1);

		update();
	}

	QImage GetOriginalImage()
	{
		return m_originalImage;
	}

	void SetProcessedImage(QImage image)
	{
		m_processedImage = image;
		if(!m_processedImage.isNull())
			SetViewSize(m_processedImage.width(), m_processedImage.height());
		else SetViewSize(1, 1);
		update();
	}

	QImage GetProcessedImage()
	{
		return m_processedImage;
	}

	void SetRecord(Neurotec::Biometrics::QNFRecord * pRecord)
	{
		m_pRecord = pRecord;
		if(pRecord)
			SetViewSize((int)(pRecord->GetWidth() * 500.0 / pRecord->GetHorzResolution()), (int)(pRecord->GetHeight() * 500.0 / pRecord->GetVertResolution()));
		update();
	}

	Neurotec::Biometrics::QNFRecord* GetRecord()
	{
			return m_pRecord;
	}

	void SetSpanningTree(const SpanningTree & spanningTree)
	{
		m_spanningTree = spanningTree;
		QRect imageRect = GetImageRect();
		update(imageRect);
	}

	void SetShownImage(ShownImage shownImage)
	{
		m_shownImage = shownImage;
		update();
	}

	void SetHighlightedMinutia(int minutiaIndex)
	{
		if (minutiaIndex != m_selectedMinutia)
		{
			m_selectedMinutia = minutiaIndex;
			update();
		}
	}

	int GetHighlightedMinutia()
	{
		return m_selectedMinutia;
	}

	static SpanningTree CalculateSpanningTree(Neurotec::Biometrics::QNFRecord *record, const SpanningTree * matedMinutiae = NULL)
	{
		SpanningTree results;

		// distance matrix
		int minutiaCount = record->GetMinutiae()->GetCount();
		NFMinutia *minutiae = new NFMinutia[minutiaCount];
		int * remap = new int[minutiaCount];
		if (matedMinutiae != NULL)
		{
			int count = 0;
			memset(remap, 0xff, minutiaCount * sizeof(int));
			for (SpanningTree::const_iterator it = matedMinutiae->begin(); it != matedMinutiae->end(); it++)
			{
				if (it->Index1 == -1) continue;
				if (count == minutiaCount) break;
				remap[count] = it->Index1;
				minutiae[count++] = record->GetMinutiae()->Get(it->Index1);
			}
			minutiaCount = count;
		}
		else
		{
			record->GetMinutiae()->GetAll(minutiae, minutiaCount);
			for (int i = 0; i < minutiaCount; i++)
			{
				remap[i] = i;
			}
		}
		int *distanceMatrix = new int[minutiaCount * minutiaCount];
		for (int i = 0; i < minutiaCount; i++)
		{
			for (int j = 0; j < minutiaCount; j++)
			{
				NFMinutia *min1 = &minutiae[i];
				NFMinutia *min2 = &minutiae[j];
				int distance = (int)((double)((min1->X - min2->X) * (min1->X - min2->X)) +
					(double)((min1->Y - min2->Y) * (min1->Y - min2->Y)) + 0.5);
				distanceMatrix[i * minutiaCount + j] = distance;
			}
		}

		std::list<int> inputList;
		std::list<int> outputList;
		for (int i = 0; i < minutiaCount; i++)
		{
			if (i != minutiaCount / 2)
			{
				inputList.push_back(i);
			}
			else
			{
				outputList.push_back(i);
			}
		}

		while (inputList.size() > 0)
		{
			int minDistance = 9999999;
			int bestIndex1 = -1;
			int bestIndex2 = -1;
			for (std::list<int>::iterator i = outputList.begin(); i != outputList.end(); i++)
			{
				for (std::list<int>::iterator j = inputList.begin(); j != inputList.end(); j++)
				{
					if (distanceMatrix[*i * minutiaCount + *j] > 0
						&& distanceMatrix[*i * minutiaCount + *j] < minDistance)
					{
						minDistance = distanceMatrix[*i * minutiaCount + *j];
						bestIndex1 = *i;
						bestIndex2 = *j;
					}
				}
			}
			if (bestIndex1 != -1)
			{
				NIndexPair resultPair;
				resultPair.Index1 = remap[bestIndex1];
				resultPair.Index2 = remap[bestIndex2];
				if (resultPair.Index1 != -1
					&& resultPair.Index2 != -1)
				{
					results.push_back(resultPair);
				}
				outputList.push_back(bestIndex2);
			}
			inputList.remove(bestIndex2);
		}

		delete[] distanceMatrix;
		delete[] remap;
		delete[] minutiae;

		return results;
	}

	static SpanningTree InverseSpanningTree(Neurotec::Biometrics::QNFRecord *record, Neurotec::Biometrics::QNMatchingDetails * pDetails, const SpanningTree & spanningTree)
	{
		SpanningTree results;

		NInt minutiaCount;
		minutiaCount = record->GetMinutiae()->GetCount();
		NInt *indexRemap = new NInt[minutiaCount];

		for (int i = 0; i < minutiaCount; i++)
		{
			indexRemap[i] = -1;
		}
		SpanningTree matedMinutiae = GetMatedMinutiae(pDetails);
		for (SpanningTree::iterator it = matedMinutiae.begin(); it != matedMinutiae.end(); it++)
		{
			indexRemap[it->Index1] = it->Index2;
		}

		for (SpanningTree::const_iterator it = spanningTree.begin(); it != spanningTree.end(); it++)
		{
			NIndexPair remappedPair;
			remappedPair.Index1 = indexRemap[it->Index1];
			remappedPair.Index2 = indexRemap[it->Index2];
			if (remappedPair.Index1 != -1
				&& remappedPair.Index2 != -1)
			{
				results.push_back(remappedPair);
			}
		}

		delete[] indexRemap;

		return results;
	}

	static SpanningTree GetMatedMinutiae(QNMatchingDetails * pDetails)
	{
		SpanningTree results;

		if (!pDetails
			|| !pDetails->GetFingers()
			|| pDetails->GetFingers()->GetCount() != 1) return results;

		QNFMatchingDetails * pFingerDetails = pDetails->GetFingers()->Get(0);
		int pairCount = 0;
		NIndexPair * pPairs = pFingerDetails->GetMatedMinutiae(&pairCount);
		if (pairCount < 1)
		{
			return results;
		}
		for (int i = 0; i < pairCount; i++)
		{
			results.push_back(pPairs[i]);
		}
		delete pPairs;
		return results;
	}

private:

	static void DrawDir(QPainter& dc, int x, int y, int angle, int length)
	{
		double radians = angle * M_PI / 128;
		int dx = (int)(cos(radians) * length);
		int dy = (int)(sin(radians) * length);
		dc.drawLine(x, y, x + dx, y + dy);
	}

	static void DrawMinutia(QPainter& dc, const NFMinutia& minutia)
	{
		const int minutiaSize = 8;
		const int minutiaAngleSize = 16;

		dc.drawEllipse(minutia.X - minutiaSize / 2, minutia.Y - minutiaSize / 2, minutiaSize, minutiaSize);

		switch (minutia.Type)
		{
		case nfmtBifurcation:
			{
				int angle1 = minutia.Angle - 10;
				if (angle1 < 0) angle1 += 255;
				int angle2 = minutia.Angle + 10;
				if (angle2 > 255) angle2 -= 255;
				DrawDir(dc, minutia.X, minutia.Y, angle1, minutiaAngleSize);
				DrawDir(dc, minutia.X, minutia.Y, angle2, minutiaAngleSize);
			}
			break;

		default:
			DrawDir(dc, minutia.X, minutia.Y, minutia.Angle, minutiaAngleSize);
			break;
		}
	}

	virtual void OnDraw(QPainter& painter)
	{
		if(m_shownImage == ORIGINAL_IMAGE && !m_originalImage.isNull())
		{
			painter.drawImage(0, 0, m_originalImage);
		}
		if(m_shownImage == PROCESSED_IMAGE && !m_processedImage.isNull())
		{
			painter.drawImage(0, 0, m_processedImage);
		}
		if (m_drawFeatures && m_pRecord)
		{
			QPen singularPointsPen(QColor::fromRgb(255, 0, 0), 3);
			painter.setPen(singularPointsPen);

			NInt coreCount = m_pRecord->GetCores()->GetCount();
			for (int i = 0; i < coreCount; i++)
			{
				const int coreSize = 20;
				NFCore core = m_pRecord->GetCores()->Get(i);
				painter.drawRect(core.X - coreSize / 2, core.Y - coreSize / 2, coreSize, coreSize);
				if (core.Angle != -1)
				{
					DrawDir(painter, core.X, core.Y, core.Angle, coreSize);
				}
			}
			NInt doubleCoreCount = m_pRecord->GetDoubleCores()->GetCount();
			for (int i = 0; i < doubleCoreCount; i++)
			{
				const int doubleCoreSize = 20;

				NFDoubleCore doubleCore = m_pRecord->GetDoubleCores()->Get(i);
				painter.drawEllipse(doubleCore.X - doubleCoreSize / 2, doubleCore.Y - doubleCoreSize / 2, doubleCoreSize, doubleCoreSize);
			}
			NInt deltaCount = m_pRecord->GetDeltas()->GetCount();
			for (int i = 0;i < deltaCount; i++)
			{
				const int deltaSize = 20;
				NFDelta delta = m_pRecord->GetDeltas()->Get(i);
				QPoint pt1(delta.X - deltaSize / 2, delta.Y + deltaSize / 2);
				QPoint pt2(delta.X, delta.Y - deltaSize / 2);
				QPoint pt3(delta.X + deltaSize / 2, delta.Y + deltaSize / 2);
				QPoint points[] = { pt1, pt2, pt3, pt1 };
				painter.drawPolyline(points, 4);
			}

			NInt minutiaCount = m_pRecord->GetMinutiae()->GetCount();

			QPen treePen(QColor::fromRgb(86, 3, 25), 2);
			painter.setPen(treePen);

			for (NInt i = 0; i < m_spanningTree.count(); i++)
			{
				QNFMinutia minutia1 = m_pRecord->GetMinutiae()->Get(m_spanningTree.at(i).Index1);
				QNFMinutia minutia2 = m_pRecord->GetMinutiae()->Get(m_spanningTree.at(i).Index2);
				painter.drawLine(minutia1.X, minutia1.Y, minutia2.X, minutia2.Y);
			}

			NInt minutiaNeighborCount = 0;
			NFMinutiaNeighbor minutiaNeighbors[8];
			if (m_selectedMinutia >= 0)
			{
				minutiaNeighborCount = m_pRecord->GetMinutiaeNeighbors()->GetCount(m_selectedMinutia);
				if (minutiaNeighborCount > 0)
				{
					m_pRecord->GetMinutiaeNeighbors()->GetAll(m_selectedMinutia, minutiaNeighbors, 8);
				}
			}

			QPen minutiaPen(QColor::fromRgb(255, 0, 0));
			QPen neighborMinutiaPen(QColor::fromRgb(255, 128, 0));
			QPen selectedMinutiaPen(QColor::fromRgb(255, 255, 0));

			for (int i = 0; i < minutiaCount; i++)
			{
				NFMinutia minutia = m_pRecord->GetMinutiae()->Get(i);

				painter.setPen(minutiaPen);
				if (i == m_selectedMinutia)
				{
					painter.setPen(selectedMinutiaPen);
				}
				else
				{
					for (int j = 0; j < minutiaNeighborCount; j++)
					{
						if (i == minutiaNeighbors[j].Index)
						{
							painter.setPen(neighborMinutiaPen);
							break;
						}
					}
				}
				DrawMinutia(painter, minutia);
			}

		}
	}


	virtual void mousePressEvent ( QMouseEvent *)
	{
	}

	virtual void mouseReleaseEvent ( QMouseEvent *)
	{

	}

	virtual void mouseMoveEvent ( QMouseEvent * e )
	{
		if (m_pRecord)
		{
			const int minutiaSize = 8;

			QRect imageRect = GetImageRect();
			int featureX = e->x() - imageRect.x();
			featureX = (int)((double)featureX / GetZoomFactor());
			int featureY = e->y() - imageRect.y();
			featureY = (int)((double)featureY / GetZoomFactor());
			NInt minutiaCount;
			minutiaCount = m_pRecord->GetMinutiae()->GetCount();
			int minDistance = minutiaSize;
			int bestMinutia = -1;

			NFMinutia selectedMinutia = NFMinutia();
			for (int i = 0; i < minutiaCount; i++)
			{
				NFMinutia minutia = m_pRecord->GetMinutiae()->Get(i);
				int distance = abs(minutia.X - featureX) + abs(minutia.Y - featureY);
				if (distance < minutiaSize
					&& distance < minDistance)
				{
					minDistance = distance;
					bestMinutia = i;
					selectedMinutia = minutia;
				}
			}
			if (m_selectedMinutia != bestMinutia)
			{
				m_selectedMinutia = bestMinutia;

				if (m_selectedMinutia != -1)
				{
					QString tipText;
					NFMinutiaFormat minutiaFormat = m_pRecord->GetMinutiaFormat();
					if (minutiaFormat & nfmfHasG)
					{
						if (tipText.length() > 0) tipText.append("\n");
						tipText.append(QString("G: %1").arg(selectedMinutia.G));
					}
					if (minutiaFormat & nfmfHasQuality)
					{
						if (tipText.length() > 0) tipText.append("\n");
						tipText.append(QString("Quality: %1").arg(selectedMinutia.Quality));
					}
					if (minutiaFormat & nfmfHasCurvature)
					{
						if (tipText.length() > 0) tipText.append("\n");
						tipText.append(QString("Curvature: %1").arg(selectedMinutia.Curvature));
					}
					QToolTip::hideText();
					if (!tipText.isEmpty())
					{
						QPoint localPoint = mapToGlobal(e->pos());
						int ptX = localPoint.x();
						int ptY = localPoint.y();
						QPoint minutiaPosition((int)(ptX - minutiaSize * GetZoomFactor()),
							(int)(ptY - minutiaSize * GetZoomFactor()));
						QToolTip::showText(minutiaPosition, tipText, this);
					}
				}
				else
				{
					QToolTip::hideText();
				}

				update();
			}
		}
	}

	QImage m_originalImage;
	QImage m_processedImage;
	Neurotec::Biometrics::QNFRecord *m_pRecord;
	int m_selectedMinutia;
	SpanningTree m_spanningTree;
	bool m_drawFeatures;
	ShownImage m_shownImage;
};

}}}




#endif // QT_NFVIEW_HPP_INCLUDED
