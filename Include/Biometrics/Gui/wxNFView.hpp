#ifndef WX_NFVIEW_HPP_INCLUDED
#define WX_NFVIEW_HPP_INCLUDED

#include <Gui/wxNView.hpp>
#include <Biometrics/NFRecord.hpp>
#include <Images/NImages.hpp>
#include <Biometrics/NMatchingDetails.hpp>
#include <wx/tipwin.h>
#include <list>

namespace Neurotec { namespace Biometrics { namespace Gui
{

typedef std::list<NIndexPair> SpanningTree;

wxDECLARE_EVENT(wxEVT_MINUTIA_SELECTION_CHANGED, wxCommandEvent);

#include <Core/NNoDeprecate.h>
class N_DEPRECATED("class is deprecated, use " N_STRINGIZEA(wxNFingerView) " or " N_STRINGIZEA(wxNPalmView) " instead") wxNFView : public Neurotec::Gui::wxNView
{
private:
	enum
	{
		ID_DRAW_FEATURES = ID_WX_NVIEW_HIGHEST + 1,
		ID_SHOWN_IMAGE_ORIGINAL,
		ID_SHOWN_IMAGE_PROCESSED,
		ID_SHOWN_IMAGE_SUBMENU,
	};

public:
	enum ShownImage
	{
		ORIGINAL_IMAGE,
		PROCESSED_IMAGE,
	};

	wxNFView(wxWindow *parent, wxWindowID winid = wxID_ANY)
		: wxNView(parent, winid)
	{
		m_pRecord = NULL;
		m_drawFeatures = NTrue;
		m_shownImage = ORIGINAL_IMAGE;
		m_selectedMinutia = -1;
		SetScrollRate(1, 1);

		wxMenu *contextMenu = GetContextMenu();
		contextMenu->InsertCheckItem(0, ID_DRAW_FEATURES, wxT("Draw features"), wxT("Toggle drawing of minutiae, deltas, cores, and double cores"));
		contextMenu->InsertSeparator(1);
		wxMenu *shownImageSubmenu = new wxMenu();
		shownImageSubmenu->AppendRadioItem(ID_SHOWN_IMAGE_ORIGINAL, wxT("Original image"), wxT("Show original image"));
		shownImageSubmenu->AppendRadioItem(ID_SHOWN_IMAGE_PROCESSED, wxT("Processed image"), wxT("Show processed image"));
		wxMenuItem *shownImageItem = new wxMenuItem(contextMenu, ID_SHOWN_IMAGE_SUBMENU, wxT("Shown image"), wxEmptyString, wxITEM_NORMAL, shownImageSubmenu);
		contextMenu->Insert(2, shownImageItem);
		contextMenu->InsertSeparator(3);
		contextMenu->Check(ID_DRAW_FEATURES, m_drawFeatures);
		contextMenu->Check(ID_SHOWN_IMAGE_ORIGINAL, true);

		this->Bind(wxEVT_COMMAND_MENU_SELECTED, &wxNFView::OnToggleDrawFeatures, this, ID_DRAW_FEATURES);
		this->Bind(wxEVT_COMMAND_MENU_SELECTED, &wxNFView::OnChooseShownImage, this, ID_SHOWN_IMAGE_ORIGINAL, ID_SHOWN_IMAGE_PROCESSED);
	}

	virtual ~wxNFView()
	{
	}

	void Clear()
	{
		m_pRecord = NULL;
		m_originalImage = wxImage();
		m_processedImage = wxImage();
		m_originalBitmap = wxBitmap();
		m_processedBitmap = wxBitmap();

		m_selectedMinutia = -1;
		m_spanningTree.clear();

		GetContextMenu()->Enable(ID_SHOWN_IMAGE_SUBMENU, false);

		SetViewSize(1, 1);
		Refresh(false);
	}

	void SetOriginalImage(const wxImage & image)
	{
		m_originalImage = image;
		m_originalBitmap = wxBitmap(image);
		SetViewSize(image.GetWidth(), image.GetHeight());

		GetContextMenu()->Enable(ID_SHOWN_IMAGE_SUBMENU, m_originalImage.GetRefData() && m_processedImage.GetRefData());
	}

	wxImage GetOriginalImage()
	{
		return m_originalImage;
	}

	void SetProcessedImage(const wxImage & image)
	{
		m_processedImage = image;
		m_processedBitmap = wxBitmap(image);
		SetViewSize(image.GetWidth(), image.GetHeight());

		GetContextMenu()->Enable(ID_SHOWN_IMAGE_SUBMENU, m_originalImage.GetRefData() > 0 && m_processedImage.GetRefData() > 0);
	}

	wxImage GetProcessedImage()
	{
		return m_processedImage;
	}

	void SetRecord(Neurotec::Biometrics::NFRecord * pRecord)
	{
		m_pRecord = pRecord;
		if (pRecord)
		{
			SetViewSize((int)(pRecord->GetWidth() * 500.0 / pRecord->GetHorzResolution()),
				(int)(pRecord->GetHeight() * 500.0 / pRecord->GetVertResolution()));
		}
	}

	Neurotec::Biometrics::NFRecord* GetRecord()
	{
		return m_pRecord;
	}

	void SetSpanningTree(const SpanningTree& spanningTree)
	{
		m_spanningTree = spanningTree;
		wxRect imageRect = GetImageRect();
		Refresh(false, &imageRect);
	}

	ShownImage GetShownImage()
	{
		return m_shownImage;
	}

	void SetShownImage(ShownImage shownImage)
	{
		m_shownImage = shownImage;
		switch (m_shownImage)
		{
		case ORIGINAL_IMAGE:
			GetContextMenu()->Check(ID_SHOWN_IMAGE_ORIGINAL, true);
			break;

		case PROCESSED_IMAGE:
			GetContextMenu()->Check(ID_SHOWN_IMAGE_PROCESSED, true);
			break;
		}
		wxRect imageRect = GetImageRect();
		Refresh(false, &imageRect);
	}

	void SetHighlightedMinutia(int minutiaIndex)
	{
		if (minutiaIndex != m_selectedMinutia)
		{
			m_selectedMinutia = minutiaIndex;
			wxRect imageRect = GetImageRect();
			Refresh(false, &imageRect);
		}
	}

	int GetHighlightedMinutia()
	{
		return m_selectedMinutia;
	}

	static SpanningTree CalculateSpanningTree(NFRecord *record, const std::list<NIndexPair> * matedMinutiae = NULL)
	{
		std::list<NIndexPair> results;

		// distance matrix
		int minutiaCount = record->GetMinutiae()->GetCount();
		NFMinutia *minutiae = new NFMinutia[minutiaCount];
		int * remap = new int[minutiaCount];
		if (matedMinutiae != NULL)
		{
			int count = 0;
			memset(remap, 0xff, minutiaCount * sizeof(int));
			for (std::list<NIndexPair>::const_iterator it = matedMinutiae->begin(); it != matedMinutiae->end(); it++)
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

	static SpanningTree InverseSpanningTree(NFRecord *record, NMatchingDetails * pDetails, const SpanningTree & spanningTree)
	{
		std::list<NIndexPair> results;

		NInt minutiaCount;
		minutiaCount = record->GetMinutiae()->GetCount();
		NInt *indexRemap = new NInt[minutiaCount];

		for (int i = 0; i < minutiaCount; i++)
		{
			indexRemap[i] = -1;
		}
		std::list<NIndexPair> matedMinutiae = GetMatedMinutiae(pDetails);
		for (std::list<NIndexPair>::iterator it = matedMinutiae.begin(); it != matedMinutiae.end(); it++)
		{
			indexRemap[it->Index1] = it->Index2;
		}

		for (std::list<NIndexPair>::const_iterator it = spanningTree.begin(); it != spanningTree.end(); it++)
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

	static std::list<NIndexPair> GetMatedMinutiae(NMatchingDetails * pDetails)
	{
		std::list<NIndexPair> results;

		if (!pDetails
			|| !pDetails->GetFingers()
			|| pDetails->GetFingers()->GetCount() != 1) return results;

		NFMatchingDetails * pFingerDetails = pDetails->GetFingers()->Get(0);
		int pairCount = 0;
		::std::auto_ptr<NIndexPair> pairs(pFingerDetails->GetMatedMinutiae(&pairCount));
		for (int i = 0; i < pairCount; i++)
		{
			results.push_back(pairs.get()[i]);
		}

		return results;
	}

private:
#if wxUSE_GRAPHICS_CONTEXT == 1
	static void DrawDir(wxGraphicsPath *path, int x, int y, int angle, int length)
	{
		double radians = angle * M_PI / 128;
		int dx = (int)(cos(radians) * length);
		int dy = (int)(sin(radians) * length);
		path->MoveToPoint(x, y);
		path->AddLineToPoint(x + dx, y + dy);
	}

	static void DrawMinutia(wxGraphicsPath *path, const NFMinutia& minutia)
	{
		const int minutiaSize = 8;
		const int minutiaAngleSize = 16;

		path->AddEllipse(minutia.X - minutiaSize / 2, minutia.Y - minutiaSize / 2, minutiaSize, minutiaSize);

		switch (minutia.Type)
		{
		case nfmtBifurcation:
			{
				int angle1 = minutia.Angle - 10;
				if (angle1 < 0) angle1 += 255;
				int angle2 = minutia.Angle + 10;
				if (angle2 > 255) angle2 -= 255;
				DrawDir(path, minutia.X, minutia.Y, angle1, minutiaAngleSize);
				DrawDir(path, minutia.X, minutia.Y, angle2, minutiaAngleSize);
			}
			break;

		default:
			DrawDir(path, minutia.X, minutia.Y, minutia.Angle, minutiaAngleSize);
			break;
		}
	}

	virtual void OnDraw(wxGraphicsContext *gc)
	{
		wxBitmap *bitmapList[2] = { NULL, NULL };
		if (m_shownImage == ORIGINAL_IMAGE)
		{
			bitmapList[0] = &m_originalBitmap;
			bitmapList[1] = &m_processedBitmap;
		}
		else
		{
			bitmapList[0] = &m_processedBitmap;
			bitmapList[1] = &m_originalBitmap;
		}

		double imageScaleX = m_pRecord ? 500.0 / m_pRecord->GetHorzResolution() : 1.0;
		double imageScaleY = m_pRecord ? 500.0 / m_pRecord->GetVertResolution() : 1.0;

		for (int i = 0; i < 2; i++)
		{
			if (bitmapList[i] != NULL && bitmapList[i]->GetRefData())
			{
				gc->DrawBitmap(*bitmapList[i], 0, 0, bitmapList[i]->GetWidth() * imageScaleX, bitmapList[i]->GetHeight() * imageScaleY);
				break;
			}
		}

		if (m_drawFeatures && m_pRecord)
		{
			wxPen singularPointsPen(wxColour(255, 0, 0), 3);
			gc->SetPen(singularPointsPen);

			wxGraphicsPath singularPtPath = gc->CreatePath();
			NInt coreCount = m_pRecord->GetCores()->GetCount();
			for (int i = 0; i < coreCount; i++)
			{
				const int coreSize = 20;
				NFCore core = m_pRecord->GetCores()->Get(i);
				singularPtPath.AddRectangle(core.X - coreSize / 2, core.Y - coreSize / 2, coreSize, coreSize);
				if (core.Angle != -1)
				{
					DrawDir(&singularPtPath, core.X, core.Y, core.Angle, coreSize);
				}
			}

			NInt doubleCoreCount = m_pRecord->GetDoubleCores()->GetCount();
			for (int i = 0; i < doubleCoreCount; i++)
			{
				const int doubleCoreSize = 20;

				NFDoubleCore doubleCore = m_pRecord->GetDoubleCores()->Get(i);
				singularPtPath.AddEllipse(doubleCore.X - doubleCoreSize / 2, doubleCore.Y - doubleCoreSize / 2, doubleCoreSize, doubleCoreSize);
			}

			NInt deltaCount = m_pRecord->GetDeltas()->GetCount();
			for (int i = 0;i < deltaCount; i++)
			{
				const int deltaSize = 20;

				NFDelta delta = m_pRecord->GetDeltas()->Get(i);
				singularPtPath.MoveToPoint(delta.X - deltaSize / 2, delta.Y + deltaSize / 2);
				singularPtPath.AddLineToPoint(delta.X, delta.Y - deltaSize / 2);
				singularPtPath.AddLineToPoint(delta.X + deltaSize / 2, delta.Y + deltaSize / 2);
				singularPtPath.CloseSubpath();
			}

			gc->StrokePath(singularPtPath);

			NInt minutiaCount = m_pRecord->GetMinutiae()->GetCount();

			wxPen treePen(wxColour(86, 3, 25), 2);
			gc->SetPen(treePen);

			for (SpanningTree::iterator it = m_spanningTree.begin(); it != m_spanningTree.end(); it++)
			{
				gc->StrokeLine(m_pRecord->GetMinutiae()->Get(it->Index1).X,
					m_pRecord->GetMinutiae()->Get(it->Index1).Y,
					m_pRecord->GetMinutiae()->Get(it->Index2).X,
					m_pRecord->GetMinutiae()->Get(it->Index2).Y);
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

			wxGraphicsPath minutiaPath = gc->CreatePath();
			wxGraphicsPath neighborMinutiaPath = gc->CreatePath();
			wxGraphicsPath selectedMinutiaPath = gc->CreatePath();
			for (int i = 0; i < minutiaCount; i++)
			{
				NFMinutia minutia = m_pRecord->GetMinutiae()->Get(i);

				wxGraphicsPath *path = &minutiaPath;
				if (i == m_selectedMinutia)
				{
					path = &selectedMinutiaPath;
				}
				else
				{
					for (int j = 0; j < minutiaNeighborCount; j++)
					{
						if (i == minutiaNeighbors[j].Index)
						{
							path = &neighborMinutiaPath;
							break;
						}
					}
				}

				DrawMinutia(path, minutia);
			}

			wxPen minutiaPen(wxColour(255, 0, 0));
			wxPen neighborMinutiaPen(wxColour(255, 128, 0));
			wxPen selectedMinutiaPen(wxColour(255, 255, 0));

			gc->SetPen(minutiaPen);
			gc->StrokePath(minutiaPath);
			gc->SetPen(neighborMinutiaPen);
			gc->StrokePath(neighborMinutiaPath);
			gc->SetPen(selectedMinutiaPen);
			gc->StrokePath(selectedMinutiaPath);

			gc->SetPen(wxNullPen);
		}
	}
#else
	static void DrawDir(wxDC& dc, int x, int y, int angle, int length)
	{
		double radians = angle * M_PI / 128;
		int dx = (int)(cos(radians) * length);
		int dy = (int)(sin(radians) * length);
		dc.DrawLine(x, y, x + dx, y + dy);
	}

	static void DrawMinutia(wxDC& dc, const NFMinutia& minutia)
	{
		const int minutiaSize = 8;
		const int minutiaAngleSize = 16;

		dc.DrawEllipse(minutia.X - minutiaSize / 2, minutia.Y - minutiaSize / 2, minutiaSize, minutiaSize);

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

	virtual void OnDraw(wxDC& dc)
	{
		wxBitmap *bitmapList[2] = { NULL, NULL };
		if (m_shownImage == ORIGINAL_IMAGE)
		{
			bitmapList[0] = &m_originalBitmap;
			bitmapList[1] = &m_processedBitmap;
		}
		else
		{
			bitmapList[0] = &m_processedBitmap;
			bitmapList[1] = &m_originalBitmap;
		}

		double oldScaleX, oldScaleY;
		dc.GetUserScale(&oldScaleX, &oldScaleY);
		double imageScaleX = m_pRecord ? 500.0 / m_pRecord->GetHorzResolution() : 1.0;
		double imageScaleY = m_pRecord ? 500.0 / m_pRecord->GetVertResolution() : 1.0;
		dc.SetUserScale(oldScaleX * imageScaleX, oldScaleY * imageScaleY);
		for (int i = 0; i < 2; i++)
		{
			if (bitmapList[i] != NULL && bitmapList[i]->GetRefData())
			{
				dc.DrawBitmap(*bitmapList[i], 0, 0, false);
				break;
			}
		}
		dc.SetUserScale(oldScaleX, oldScaleY);

		if (m_drawFeatures && m_pRecord)
		{
			wxPen singularPointsPen(wxColour(255, 0, 0), 3);
			dc.SetPen(singularPointsPen);
			dc.SetBrush(*wxTRANSPARENT_BRUSH);

			NInt coreCount = m_pRecord->GetCores()->GetCount();
			for (int i = 0; i < coreCount; i++)
			{
				const int coreSize = 20;
				NFCore core = m_pRecord->GetCores()->Get(i);
				dc.DrawRectangle(core.X - coreSize / 2, core.Y - coreSize / 2, coreSize, coreSize);
				if (core.Angle != -1)
				{
					DrawDir(dc, core.X, core.Y, core.Angle, coreSize);
				}
			}

			NInt doubleCoreCount = m_pRecord->GetDoubleCores()->GetCount();
			for (int i = 0; i < doubleCoreCount; i++)
			{
				const int doubleCoreSize = 20;

				NFDoubleCore doubleCore = m_pRecord->GetDoubleCores()->Get(i);
				dc.DrawEllipse(doubleCore.X - doubleCoreSize / 2, doubleCore.Y - doubleCoreSize / 2, doubleCoreSize, doubleCoreSize);
			}

			NInt deltaCount = m_pRecord->GetDeltas()->GetCount();
			for (int i = 0;i < deltaCount; i++)
			{
				const int deltaSize = 20;

				NFDelta delta = m_pRecord->GetDeltas()->Get(i);
				wxPoint pt1(delta.X - deltaSize / 2, delta.Y + deltaSize / 2);
				wxPoint pt2(delta.X, delta.Y - deltaSize / 2);
				wxPoint pt3(delta.X + deltaSize / 2, delta.Y + deltaSize / 2);
				wxPoint points[] = { pt1, pt2, pt3, pt1 };
				dc.DrawLines(4, points);
			}

			NInt minutiaCount = m_pRecord->GetMinutiae()->GetCount();

			wxPen treePen(wxColour(86, 3, 25), 2);
			dc.SetPen(treePen);

			for (SpanningTree::iterator it = m_spanningTree.begin(); it != m_spanningTree.end(); it++)
			{
				dc.DrawLine(m_pRecord->GetMinutiae()->Get(it->Index1).X,
					m_pRecord->GetMinutiae()->Get(it->Index1).Y,
					m_pRecord->GetMinutiae()->Get(it->Index2).X,
					m_pRecord->GetMinutiae()->Get(it->Index2).Y);
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

			wxPen minutiaPen(wxColour(255, 0, 0));
			wxPen neighborMinutiaPen(wxColour(255, 128, 0));
			wxPen selectedMinutiaPen(wxColour(255, 255, 0));

			for (int i = 0; i < minutiaCount; i++)
			{
				NFMinutia minutia = m_pRecord->GetMinutiae()->Get(i);

				dc.SetPen(minutiaPen);
				if (i == m_selectedMinutia)
				{
					dc.SetPen(selectedMinutiaPen);
				}
				else
				{
					for (int j = 0; j < minutiaNeighborCount; j++)
					{
						if (i == minutiaNeighbors[j].Index)
						{
							dc.SetPen(neighborMinutiaPen);
							break;
						}
					}
				}
				DrawMinutia(dc, minutia);
			}

			dc.SetPen(wxNullPen);
			dc.SetBrush(wxNullBrush);
		}
	}
#endif

	virtual void OnMouseMove(wxMouseEvent& event)
	{
		if (event.Dragging())
		{
			wxNView::OnMouseMove(event);
		}
		else if (m_pRecord)
		{
			const int minutiaSize = 8;

			wxRect imageRect = GetImageRect();
			int featureX = event.GetX() - imageRect.x;;
			featureX = (int)((double)featureX / GetZoomFactor());
			int featureY = event.GetY() - imageRect.y;
			featureY = (int)((double)featureY / GetZoomFactor());
			NInt minutiaCount;
			minutiaCount = m_pRecord->GetMinutiae()->GetCount();
			int minDistance = minutiaSize;
			int bestMinutia = -1;
			NFMinutia selectedMinutia(0, 0, nfmtUnknown, 0);
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
					wxString tipText;
					NFMinutiaFormat minutiaFormat = m_pRecord->GetMinutiaFormat();
					if (minutiaFormat & nfmfHasG)
					{
						if (tipText.Length() > 0) tipText.Append(wxT("\n"));
						tipText.Append(wxString::Format(wxT("G: %d"), selectedMinutia.G));
					}
					if (minutiaFormat & nfmfHasQuality)
					{
						if (tipText.Length() > 0) tipText.Append(wxT("\n"));
						tipText.Append(wxString::Format(wxT("Quality: %d"), selectedMinutia.Quality));
					}
					if (minutiaFormat & nfmfHasCurvature)
					{
						if (tipText.Length() > 0) tipText.Append(wxT("\n"));
						tipText.Append(wxString::Format(wxT("Curvature: %d"), selectedMinutia.Curvature));
					}

					static wxTipWindow* s_tipWindow = NULL;

					if (s_tipWindow)
					{
						s_tipWindow->SetTipWindowPtr(NULL);
						s_tipWindow->Close();
					}

					if (!tipText.IsEmpty())
					{
						int ptX = event.GetX();
						int ptY = event.GetY();
						ClientToScreen(&ptX, &ptY);
						wxRect minutiaBounds((int)(ptX - minutiaSize * GetZoomFactor()),
							(int)(ptY - minutiaSize * GetZoomFactor()),
							(int)(minutiaSize * 2 * GetZoomFactor()),
							(int)(minutiaSize * 2 * GetZoomFactor()));

						s_tipWindow = new wxTipWindow(this, tipText, 100, &s_tipWindow, &minutiaBounds);
					}
				}

				wxCommandEvent event(wxEVT_MINUTIA_SELECTION_CHANGED, GetId());
				event.SetInt(m_selectedMinutia);
				GetEventHandler()->ProcessEvent( event );

				Refresh(false);
			}
		}
	}

	void OnToggleDrawFeatures(wxCommandEvent& event)
	{
		m_drawFeatures = event.IsChecked();
		wxRect imageRect = GetImageRect();
		Refresh(false, &imageRect);
	}

	void OnChooseShownImage(wxCommandEvent& event)
	{
		switch (event.GetId())
		{
		case ID_SHOWN_IMAGE_ORIGINAL:
			m_shownImage = ORIGINAL_IMAGE;
			break;

		case ID_SHOWN_IMAGE_PROCESSED:
			m_shownImage = PROCESSED_IMAGE;
			break;
		}
		wxRect imageRect = GetImageRect();
		Refresh(false, &imageRect);
	}


	wxImage m_originalImage;
	wxImage m_processedImage;
	Neurotec::Biometrics::NFRecord *m_pRecord;
	wxBitmap m_originalBitmap;
	wxBitmap m_processedBitmap;
	int m_selectedMinutia;
	SpanningTree m_spanningTree;
	bool m_drawFeatures;
	ShownImage m_shownImage;
};
#include <Core/NReDeprecate.h>

}}}

#endif // !WX_NFVIEW_HPP_INCLUDED
