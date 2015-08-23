#ifndef WX_NFRICTIONRIDGEVIEW_HPP_INCLUDED
#define WX_NFRICTIONRIDGEVIEW_HPP_INCLUDED

#include <list>
#include <algorithm>

#include <wx/tipwin.h>

#include <Gui/wxNView.hpp>
#include <Images/NImages.hpp>
#include <Biometrics/NFrictionRidge.hpp>

#include <iostream>

namespace Neurotec { namespace Biometrics { namespace Gui
{

typedef std::list<NIndexPair> SpanningTree;

wxDECLARE_EVENT(wxEVT_MINUTIA_SELECTION_CHANGED, wxCommandEvent);
wxDECLARE_EVENT(wxEVT_NFR_PROPERTY_CHANGED, wxCommandEvent);

class wxNFrictionRidgeView: public Neurotec::Gui::wxNView
{
private:
	enum
	{
		ID_DRAW_FEATURES = ID_WX_NVIEW_HIGHEST + 1,
		ID_SHOWN_IMAGE_ORIGINAL,
		ID_SHOWN_IMAGE_PROCESSED,
		ID_SHOWN_IMAGE_SUBMENU,

		ID_CLEAR_VIEW,

		ID_PROPERTY_IMAGE,
		ID_PROPERTY_PROCESSED_IMAGE,
		ID_PROPERTY_TEMPLATE
	};
public:
	enum ShownImage
	{
		ORIGINAL_IMAGE,
		PROCESSED_IMAGE,
	};

	enum QualityVisualStyle
	{
		NONE = 0,
		TEXT = 1,
		STARS = 2,
	};

	wxNFrictionRidgeView(wxWindow *parent, wxWindowID winid = wxID_ANY)
		: wxNView(parent, winid), m_minColor(0, 230, 0), m_maxColor(255, 255, 255), m_record(NULL), m_showPatterClassConfidence(false), m_qualityStyle(STARS), m_boundingRectColor(wxColor(255, 0, 0)), m_frictionRidge(NULL)
	{
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
		contextMenu->AppendSeparator();
		contextMenu->Append(ID_CLEAR_VIEW, wxT("Clear"));

		this->Bind(wxEVT_COMMAND_MENU_SELECTED, &wxNFrictionRidgeView::OnToggleDrawFeatures, this, ID_DRAW_FEATURES);
		this->Bind(wxEVT_COMMAND_MENU_SELECTED, &wxNFrictionRidgeView::OnChooseShownImage, this, ID_SHOWN_IMAGE_ORIGINAL, ID_SHOWN_IMAGE_PROCESSED);
		this->Bind(wxEVT_COMMAND_MENU_SELECTED, &wxNFrictionRidgeView::OnClearView, this, ID_CLEAR_VIEW);
		this->Bind(wxEVT_NFR_PROPERTY_CHANGED, &wxNFrictionRidgeView::OnPropertyChanged, this);
	}

	virtual ~wxNFrictionRidgeView()
	{
		Clear();
	}

	void Clear()
	{
		if (!m_frictionRidge.IsNull())
		{
			m_frictionRidge.RemovePropertyChangedCallback(&wxNFrictionRidgeView::OnPropertyChangedCallback, this);
			m_frictionRidge.GetObjects().RemoveCollectionChangedCallback(&wxNFrictionRidgeView::OnCollectionChanged, this);
		}

		m_frictionRidge = NULL;
		m_record = NULL;
		m_originalBitmap = wxBitmap();
		m_processedBitmap = wxBitmap();
		m_selectedMinutia = -1;
		m_spanningTree.clear();

		GetContextMenu()->Enable(ID_SHOWN_IMAGE_SUBMENU, false);

		SetViewSize(1, 1);
		Refresh(false);
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

	void SetBoundingRectColor(const wxColor & value)
	{
		if (value != m_boundingRectColor)
		{
			m_boundingRectColor = value;
			Refresh();
		}
	}

	wxColor GetBoundingRectColor()
	{
		return m_boundingRectColor;
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

	void SetShowPatternClassConfidence(bool value)
	{
		if (value != m_showPatterClassConfidence)
		{
			m_showPatterClassConfidence = value;
			Refresh();
		}
	}

	bool GetShowPatternClassConfidence()
	{
		return m_showPatterClassConfidence;
	}

	void SetQualityVisualStyle(QualityVisualStyle value)
	{
		if (value != m_qualityStyle)
		{
			m_qualityStyle = value;
			Refresh();
		}
	}

	QualityVisualStyle GetQualityVisualStyle()
	{
		return m_qualityStyle;
	}

	void SetProcessedImageMinColor(::Neurotec::Images::NRgb color)
	{
		m_minColor = color;
	}

	::Neurotec::Images::NRgb GetProcessedImageMinColor()
	{
		return m_minColor;
	}

	void SetProcessedImageMaxColor(::Neurotec::Images::NRgb color)
	{
		m_maxColor = color;
	}

	::Neurotec::Images::NRgb GetProcessedImageMaxColor()
	{
		return m_maxColor;
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

	static SpanningTree CalculateSpanningTree(NFrictionRidge frictionRidge, const std::list<NIndexPair> matedMinutiae)
	{
		std::list<NIndexPair> results;
		NFRecord record = NULL;

		if (!frictionRidge.GetHandle() || frictionRidge.GetObjects().GetCount() <= 0)
			return results;

		record = frictionRidge.GetObjects().Get(0).GetTemplate();

		if (!record.GetHandle())
			return results;

		// distance matrix
		int minutiaCount = record.GetMinutiae().GetCount();
		NFMinutia *minutiae = new NFMinutia[minutiaCount];
		int *remap = new int[minutiaCount];
		if (matedMinutiae.size() == 0)
		{
			int count = 0;
			memset(remap, 0xff, minutiaCount * sizeof(int));
			for (std::list<NIndexPair>::const_iterator it = matedMinutiae.begin(); it != matedMinutiae.end(); it++)
			{
				if (it->Index1 == -1) continue;
				if (count == minutiaCount) break;
				remap[count] = it->Index1;
				minutiae[count++] = record.GetMinutiae().Get(it->Index1);
			}
			minutiaCount = count;
		}
		else
		{
			for (int i = 0; i < minutiaCount; i++)
			{
				minutiae[i] = record.GetMinutiae().Get(i);
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

	static SpanningTree InverseSpanningTree(NFrictionRidge frictionRidge, NMatchingDetails details, const SpanningTree & spanningTree)
	{
		std::list<NIndexPair> results;

		NFRecord record = NULL;

		if (!frictionRidge.GetHandle() || frictionRidge.GetObjects().GetCount() <= 0)
			return results;

		record = frictionRidge.GetObjects().Get(0).GetTemplate();

		if (!record.GetHandle())
			return results;

		NInt minutiaCount;
		minutiaCount = record.GetMinutiae().GetCount();
		NInt *indexRemap = new NInt[minutiaCount];

		for (int i = 0; i < minutiaCount; i++)
		{
			indexRemap[i] = -1;
		}
		std::list<NIndexPair> matedMinutiae = GetMatedMinutiae(details);
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

	static std::list<NIndexPair> GetMatedMinutiae(NMatchingDetails details)
	{
		std::list<NIndexPair> results;

		if (!details.GetHandle()
			|| details.GetFingers().GetCount() != 1) return results;

		NFMatchingDetails fingerDetails = details.GetFingers().Get(0);
		NArrayWrapper<NIndexPair> pairs = fingerDetails.GetMatedMinutiae();
		for (int i = 0; i < pairs.GetCount(); i++)
		{
			results.push_back(pairs[i]);
		}

		return results;
	}

	void SetFrictionRidge(const ::Neurotec::Biometrics::NFrictionRidge & frictionRidge)
	{
		Clear();

		m_frictionRidge = frictionRidge;

		if (m_frictionRidge.GetHandle())
		{
			unsigned int maxWidth = 1, maxHeight = 1;

			::Neurotec::Images::NImage image = m_frictionRidge.GetImage();
			m_originalBitmap = image.GetHandle() ? wxBitmap(image.ToBitmap()) : wxBitmap();
			maxWidth = image.GetHandle() && image.GetWidth() > maxWidth ? image.GetWidth() : maxWidth;
			maxHeight = image.GetHandle() && image.GetHeight() > maxHeight ? image.GetHeight() : maxHeight;

			image = m_frictionRidge.GetProcessedImage();
			if (image.GetHandle())
			{
				::Neurotec::Images::NImage wrappedImage = ::Neurotec::Images::NImages::GetGrayscaleColorWrapper(image, m_minColor, m_maxColor);
				m_processedBitmap = wxBitmap(wrappedImage.ToBitmap());
				SetViewSize(wrappedImage.GetWidth(), wrappedImage.GetHeight());
				maxWidth = wrappedImage.GetWidth() > maxWidth ? wrappedImage.GetWidth() : maxWidth;
				maxHeight = wrappedImage.GetHeight() > maxHeight ? wrappedImage.GetHeight() : maxHeight;
			}
			else
				m_processedBitmap = wxBitmap();

			if (m_frictionRidge.GetObjects().GetCount() > 0)
			{
				m_record = m_frictionRidge.GetObjects().Get(0).GetTemplate();
				if (m_record.GetHandle())
				{
					unsigned int rWidth = (unsigned int)(m_record.GetWidth() * 500.0 / m_record.GetHorzResolution());
					unsigned int rHeight = (unsigned int)(m_record.GetHeight() * 500.0 / m_record.GetVertResolution());

					maxWidth = rWidth > maxWidth ? rWidth : maxWidth;
					maxHeight = rHeight > maxHeight ? rHeight : maxHeight;
				}
			}

			SetViewSize(maxWidth, maxHeight);

			m_frictionRidge.AddPropertyChangedCallback(&wxNFrictionRidgeView::OnPropertyChangedCallback, this);
			m_frictionRidge.GetObjects().AddCollectionChangedCallback(&wxNFrictionRidgeView::OnCollectionChanged, this);

			GetContextMenu()->Enable(ID_SHOWN_IMAGE_SUBMENU, m_originalBitmap.GetRefData() && m_processedBitmap.GetRefData());
		}
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


	wxGraphicsPath CreateStarPath(wxGraphicsContext * gc)
	{
		wxGraphicsPath gp = gc->CreatePath();
		gp.MoveToPoint(150.22026, 16.299561);
		gp.AddCurveToPoint(160.45916, 16.299561, 187.25066, 102.09715, 195.5341, 108.11542);
		gp.AddCurveToPoint(203.81754, 114.13369, 293.69493, 113.10102, 296.85892, 122.83879);
		gp.AddCurveToPoint(300.02292, 132.57656, 226.70359, 184.5697, 223.5396, 194.30747);
		gp.AddCurveToPoint(220.37561, 204.04524, 249.13137, 289.2046, 240.84793, 295.22287);
		gp.AddCurveToPoint(232.56449, 301.24114, 160.45916, 247.57709, 150.22026, 247.57709);
		gp.AddCurveToPoint(139.98137, 247.57709, 67.876021, 301.24114, 59.592581, 295.22287);
		gp.AddCurveToPoint(51.309141, 289.2046, 80.064915, 204.04524, 76.900923, 194.30747);
		gp.AddCurveToPoint(73.736931, 184.5697, 0.41760828, 132.57655, 3.5816007, 122.83878);
		gp.AddCurveToPoint(6.7455931, 113.10101, 96.622978, 114.13369, 104.90642, 108.11542);
		gp.AddCurveToPoint(113.18986, 102.09715, 139.98137, 16.299561, 150.22026, 16.299561);
		gp.CloseSubpath();
		return gp;
	}

	void DrawQualityAndPatternClass(wxGraphicsContext * gc, const ::Neurotec::Biometrics::NFAttributes & attributes, const ::Neurotec::Geometry::NRect & rect)
	{
		wxString text = GetAttributesString(attributes);
		if (text != wxEmptyString)
		{
			gc->DrawText(text, rect.X + 3, rect.Y + rect.Height + 3);
		}

		::Neurotec::Biometrics::NfiqQuality quality = attributes.GetNfiqQuality();
		if (m_qualityStyle == STARS && quality != ::Neurotec::Biometrics::nfqUnknown)
		{
			int starCount = 6 - (int)quality;

			wxGraphicsMatrix m = gc->GetTransform();
			m.Translate(rect.X, rect.Y);

			wxGraphicsPath star = CreateStarPath(gc);
			wxRect2DDouble bounds = star.GetBox();
			double boundsWidth = bounds.GetRight() - bounds.GetLeft();
			double boundsHeight = bounds.GetBottom() - bounds.GetTop();
			double width = rect.Width / 2.0;
			double height = rect.Height;
			double scale = std::min(height / boundsHeight, std::min(width * 0.20, 30.0) / boundsWidth);
			m.Translate(3, height - boundsHeight * scale - 3);
			m.Scale(scale, scale);

			gc->SetTransform(m);
			for (int i = 0; i < 5; i++)
			{
				bool isSilver = i + 1 > starCount;
				if (i > 0)
				{
					wxGraphicsMatrix offset = gc->CreateMatrix();
					offset.Translate(boundsWidth, 0);
					star.Transform(offset);
				}

				wxColor centerColor = isSilver ? wxColor(255, 255, 255) : wxColor(255, 255, 0);
				wxColor edgeColor = isSilver ? wxColor(0xC0, 0xC0, 0xC0) : wxColor(0xDA, 0xA5, 0x20);
				wxGraphicsGradientStops gs(edgeColor, edgeColor);
				gs.Add(centerColor, 0.5f);
				bounds = star.GetBox();
				wxGraphicsBrush gb = gc->CreateLinearGradientBrush(bounds.GetLeft(), bounds.GetTop(), bounds.GetRight(), bounds.GetBottom(), gs);
				gc->SetBrush(gb);
				gc->FillPath(star);
			}
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

		double imageScaleX = m_record.GetHandle() ? 500.0 / m_record.GetHorzResolution() : 1.0;
		double imageScaleY = m_record.GetHandle() ? 500.0 / m_record.GetVertResolution() : 1.0;

		for (int i = 0; i < 2; i++)
		{
			if (bitmapList[i] != NULL && bitmapList[i]->GetRefData())
			{
				gc->DrawBitmap(*bitmapList[i], 0, 0, bitmapList[i]->GetWidth() * imageScaleX, bitmapList[i]->GetHeight() * imageScaleY);
				break;
			}
		}

		if (!m_frictionRidge.IsNull())
		{
			bool infoPainted = false;
			::Neurotec::NArrayWrapper< ::Neurotec::Biometrics::NFAttributes> attributes = m_frictionRidge.GetObjects().GetAll();

			for (::Neurotec::NArrayWrapper< ::Neurotec::Biometrics::NFAttributes>::iterator it = attributes.begin(); it != attributes.end(); it++)
			{
				::Neurotec::Geometry::NRect rect = it->GetBoundingRect();
				NFloat rotation = it->GetRotation();
				if (rect.Width != 0 && rect.Height != 0)
				{
					wxGraphicsMatrix oldTransform = gc->GetTransform();
					double atX = rect.X + rect.Width / 2.0;
					double atY = rect.Y + rect.Height / 2.0;
					double angle = (90 - rotation) * M_PI / 180;
					gc->Translate(atX, atY);
					gc->Rotate(angle);
					gc->Translate(-atX, -atY);

					gc->SetPen(wxPen(m_boundingRectColor));
					gc->SetBrush(wxNullBrush);
					gc->DrawRectangle(rect.X, rect.Y, rect.Width, rect.Height);
					DrawQualityAndPatternClass(gc, *it, rect);
					gc->SetTransform(oldTransform);
					infoPainted = true;
				}
			}

			if (!infoPainted && attributes.GetCount() == 1)
			{
				double w, h;
				wxSize sz = GetImageRect().GetSize();
				::Neurotec::Geometry::NRect rect;
				::Neurotec::Biometrics::NFAttributes first = attributes[0];
				wxString text = GetAttributesString(first);
				gc->GetTextExtent(text, &w, &h);
				rect.X = 0;
				rect.Y = 0;
				rect.Width = sz.GetWidth() / GetZoom();
				rect.Height = sz.GetHeight() / GetZoom() - h - 3;
				wxGraphicsMatrix oldTransform = gc->GetTransform();
				DrawQualityAndPatternClass(gc, first, rect);
				gc->SetTransform(oldTransform);
			}
		}

		if (m_drawFeatures && m_record.GetHandle())
		{
			wxPen singularPointsPen(wxColour(255, 0, 0), 3);
			gc->SetPen(singularPointsPen);

			wxGraphicsPath singularPtPath = gc->CreatePath();
			NInt coreCount = m_record.GetCores().GetCount();
			for (int i = 0; i < coreCount; i++)
			{
				const int coreSize = 20;
				NFCore core = m_record.GetCores().Get(i);
				singularPtPath.AddRectangle(core.X - coreSize / 2, core.Y - coreSize / 2, coreSize, coreSize);
				if (core.Angle != -1)
				{
					DrawDir(&singularPtPath, core.X, core.Y, core.Angle, coreSize);
				}
			}

			NInt doubleCoreCount = m_record.GetDoubleCores().GetCount();
			for (int i = 0; i < doubleCoreCount; i++)
			{
				const int doubleCoreSize = 20;

				NFDoubleCore doubleCore = m_record.GetDoubleCores().Get(i);
				singularPtPath.AddEllipse(doubleCore.X - doubleCoreSize / 2, doubleCore.Y - doubleCoreSize / 2, doubleCoreSize, doubleCoreSize);
			}

			NInt deltaCount = m_record.GetDeltas().GetCount();
			for (int i = 0;i < deltaCount; i++)
			{
				const int deltaSize = 20;

				NFDelta delta = m_record.GetDeltas().Get(i);
				singularPtPath.MoveToPoint(delta.X - deltaSize / 2, delta.Y + deltaSize / 2);
				singularPtPath.AddLineToPoint(delta.X, delta.Y - deltaSize / 2);
				singularPtPath.AddLineToPoint(delta.X + deltaSize / 2, delta.Y + deltaSize / 2);
				singularPtPath.CloseSubpath();
			}

			gc->StrokePath(singularPtPath);

			NInt minutiaCount = m_record.GetMinutiae().GetCount();

			wxPen treePen(wxColour(86, 3, 25), 2);
			gc->SetPen(treePen);

			for (SpanningTree::iterator it = m_spanningTree.begin(); it != m_spanningTree.end(); it++)
			{
				gc->StrokeLine(m_record.GetMinutiae().Get(it->Index1).X,
					m_record.GetMinutiae().Get(it->Index1).Y,
					m_record.GetMinutiae().Get(it->Index2).X,
					m_record.GetMinutiae().Get(it->Index2).Y);
			}

			NArrayWrapper<NFMinutiaNeighbor> minutiaNeighbors = NArrayWrapper<NFMinutiaNeighbor>(0);
			if (m_selectedMinutia >= 0)
			{
				minutiaNeighbors = m_record.GetMinutiaeNeighbors().GetAll(m_selectedMinutia);
			}

			wxGraphicsPath minutiaPath = gc->CreatePath();
			wxGraphicsPath neighborMinutiaPath = gc->CreatePath();
			wxGraphicsPath selectedMinutiaPath = gc->CreatePath();
			for (int i = 0; i < minutiaCount; i++)
			{
				NFMinutia minutia = m_record.GetMinutiae().Get(i);

				wxGraphicsPath *path = &minutiaPath;
				if (i == m_selectedMinutia)
				{
					path = &selectedMinutiaPath;
				}
				else
				{
					for (int j = 0; j < minutiaNeighbors.GetCount(); j++)
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
		double imageScaleX = m_record.GetHandle() ? 500.0 / m_record.GetHorzResolution() : 1.0;
		double imageScaleY = m_record.GetHandle() ? 500.0 / m_record.GetVertResolution() : 1.0;
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

		if (m_drawFeatures && m_record.GetHandle())
		{
			wxPen singularPointsPen(wxColour(255, 0, 0), 3);
			dc.SetPen(singularPointsPen);
			dc.SetBrush(*wxTRANSPARENT_BRUSH);

			NInt coreCount = m_record.GetCores().GetCount();
			for (int i = 0; i < coreCount; i++)
			{
				const int coreSize = 20;
				NFCore core = m_record.GetCores().Get(i);
				dc.DrawRectangle(core.X - coreSize / 2, core.Y - coreSize / 2, coreSize, coreSize);
				if (core.Angle != -1)
				{
					DrawDir(dc, core.X, core.Y, core.Angle, coreSize);
				}
			}

			NInt doubleCoreCount = m_record.GetDoubleCores().GetCount();
			for (int i = 0; i < doubleCoreCount; i++)
			{
				const int doubleCoreSize = 20;

				NFDoubleCore doubleCore = m_record.GetDoubleCores().Get(i);
				dc.DrawEllipse(doubleCore.X - doubleCoreSize / 2, doubleCore.Y - doubleCoreSize / 2, doubleCoreSize, doubleCoreSize);
			}

			NInt deltaCount = m_record.GetDeltas().GetCount();
			for (int i = 0;i < deltaCount; i++)
			{
				const int deltaSize = 20;

				NFDelta delta = m_record.GetDeltas().Get(i);
				wxPoint pt1(delta.X - deltaSize / 2, delta.Y + deltaSize / 2);
				wxPoint pt2(delta.X, delta.Y - deltaSize / 2);
				wxPoint pt3(delta.X + deltaSize / 2, delta.Y + deltaSize / 2);
				wxPoint points[] = { pt1, pt2, pt3, pt1 };
				dc.DrawLines(4, points);
			}

			NInt minutiaCount = m_record.GetMinutiae().GetCount();

			wxPen treePen(wxColour(86, 3, 25), 2);
			dc.SetPen(treePen);

			for (SpanningTree::iterator it = m_spanningTree.begin(); it != m_spanningTree.end(); it++)
			{
				dc.DrawLine(m_record.GetMinutiae().Get(it->Index1).X,
					m_record.GetMinutiae().Get(it->Index1).Y,
					m_record.GetMinutiae().Get(it->Index2).X,
					m_record.GetMinutiae().Get(it->Index2).Y);
			}

			NInt minutiaNeighborCount = 0;
			NFMinutiaNeighbor minutiaNeighbors[8];
			if (m_selectedMinutia >= 0)
			{
				minutiaNeighborCount = m_record.GetMinutiaeNeighbors().GetCount(m_selectedMinutia);
				if (minutiaNeighborCount > 0)
				{
					m_record.GetMinutiaeNeighbors().GetAll(m_selectedMinutia, minutiaNeighbors, 8);
				}
			}

			wxPen minutiaPen(wxColour(255, 0, 0));
			wxPen neighborMinutiaPen(wxColour(255, 128, 0));
			wxPen selectedMinutiaPen(wxColour(255, 255, 0));

			for (int i = 0; i < minutiaCount; i++)
			{
				NFMinutia minutia = m_record.GetMinutiae().Get(i);

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

	wxString GetAttributesQualityString(const ::Neurotec::Biometrics::NFAttributes & attributes)
	{
		::Neurotec::Biometrics::NfiqQuality quality = attributes.GetNfiqQuality();
		if (quality == ::Neurotec::Biometrics::nfqUnknown) return wxEmptyString;
		wxString qualityString = ::Neurotec::NEnum::ToString(::Neurotec::Biometrics::NBiometricTypes::NfiqQualityNativeTypeOf(), quality);
		return wxString::Format(wxT("Nfiq Quality: %s"), qualityString.c_str());
	}

	wxString GetAttributesPatternClassString(const ::Neurotec::Biometrics::NFAttributes & attributes)
	{
		wxString text = wxEmptyString;
		::Neurotec::Biometrics::NFPatternClass pattern = attributes.GetPatternClass();
		::Neurotec::NByte confidence = attributes.GetPatternClassConfidence();
		if (pattern != ::Neurotec::Biometrics::nfpcUnknown && confidence > 0 && confidence <= 100)
		{
			wxString patternString = ::Neurotec::NEnum::ToString(::Neurotec::Biometrics::NBiometricTypes::NFPatternClassNativeTypeOf(), pattern);
			text = wxString::Format(wxT("Pattern class: %s"), patternString.c_str());
			if (m_showPatterClassConfidence) text += wxString::Format(wxT("(%d)"), confidence);
		}
		return text;
	}

	virtual wxString GetAttributesString(const ::Neurotec::Biometrics::NFAttributes & attributes)
	{
		wxString text = wxEmptyString;
		if (m_qualityStyle == TEXT)
		{
			text = GetAttributesQualityString(attributes);
		}
		if (text != wxEmptyString) text += wxT("\n");
		text += GetAttributesPatternClassString(attributes);
		return text;
	}


	virtual void OnMouseMove(wxMouseEvent& event)
	{
		if (event.Dragging())
		{
			wxNView::OnMouseMove(event);
		}
		else if (m_record.GetHandle())
		{
			const int minutiaSize = 8;

			wxRect imageRect = GetImageRect();
			int featureX = event.GetX() - imageRect.x;;
			featureX = (int)((double)featureX / GetZoomFactor());
			int featureY = event.GetY() - imageRect.y;
			featureY = (int)((double)featureY / GetZoomFactor());
			NInt minutiaCount;
			minutiaCount = m_record.GetMinutiae().GetCount();
			int minDistance = minutiaSize;
			int bestMinutia = -1;
			NFMinutia selectedMinutia(0, 0, nfmtUnknown, 0);
			for (int i = 0; i < minutiaCount; i++)
			{
				NFMinutia minutia = m_record.GetMinutiae().Get(i);
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
					NFMinutiaFormat minutiaFormat = m_record.GetMinutiaFormat();
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

	void OnClearView(wxCommandEvent &/*event*/)
	{
		Clear();
	}

	void OnPropertyChanged(wxCommandEvent& event)
	{
		switch (event.GetId())
		{
		case ID_PROPERTY_IMAGE:
			{
				std::auto_ptr<wxImage> image(dynamic_cast<wxImage *>(event.GetEventObject()));
				m_originalBitmap = image.get() ? wxBitmap(*(image.get())) : wxBitmap();
				SetViewSize(image.get() ? image->GetWidth() : 1, image.get() ? image->GetHeight() : 1);
				GetContextMenu()->Enable(ID_SHOWN_IMAGE_SUBMENU, m_originalBitmap.GetRefData() && m_processedBitmap.GetRefData());
			}
			break;
		case ID_PROPERTY_PROCESSED_IMAGE:
			{
				::Neurotec::Images::NImage image = m_frictionRidge.GetProcessedImage();
				if (image.GetHandle())
				{
					::Neurotec::Images::NImage wrappedImage = ::Neurotec::Images::NImages::GetGrayscaleColorWrapper(image, m_minColor, m_maxColor);
					m_processedBitmap = wxBitmap(wrappedImage.ToBitmap());
					SetViewSize(wrappedImage.GetWidth(), wrappedImage.GetHeight());
					GetContextMenu()->Enable(ID_SHOWN_IMAGE_SUBMENU, !m_originalBitmap.IsNull());
				}
				else
				{
					m_processedBitmap = wxBitmap();
					SetViewSize(1, 1);
				}
			}
			break;
		case ID_PROPERTY_TEMPLATE:
			if (m_frictionRidge.GetObjects().GetCount() > 0)
			{
				m_record = m_frictionRidge.GetObjects().Get(0).GetTemplate();
				if (m_record.GetHandle())
					SetViewSize((int)(m_record.GetWidth() * 500.0 / m_record.GetHorzResolution()),
						(int)(m_record.GetHeight() * 500.0 / m_record.GetVertResolution()));
			}
			else
				m_record = NULL;
			break;
		default:
			return;
		}

		Refresh(false);
	}

	static void OnPropertyChangedCallback(::Neurotec::Biometrics::NFrictionRidge::PropertyChangedEventArgs args)
	{
		if (args.GetPropertyName() == N_T("Image"))
		{
			::Neurotec::Biometrics::NFrictionRidge sender = args.GetObject< ::Neurotec::Biometrics::NFrictionRidge>();
			::Neurotec::Images::NImage image = sender.GetImage();
			wxCommandEvent event(wxEVT_NFR_PROPERTY_CHANGED, ID_PROPERTY_IMAGE);
			if (image.GetHandle())
				event.SetEventObject(new wxImage(image.ToBitmap()));
			wxPostEvent(static_cast<wxEvtHandler *>(args.GetParam()), event);
		}
		else if (args.GetPropertyName() == N_T("ProcessedImage"))
		{
			wxCommandEvent event(wxEVT_NFR_PROPERTY_CHANGED, ID_PROPERTY_PROCESSED_IMAGE);
			wxPostEvent(static_cast<wxEvtHandler *>(args.GetParam()), event);
		}
		else if (args.GetPropertyName() == N_T("Template"))
		{
			wxCommandEvent event(wxEVT_NFR_PROPERTY_CHANGED, ID_PROPERTY_TEMPLATE);
			wxPostEvent(static_cast<wxEvtHandler *>(args.GetParam()), event);
		}
	}

	static void OnCollectionChanged(::Neurotec::Collections::CollectionChangedEventArgs< ::Neurotec::Biometrics::NFAttributes> args)
	{
		if (args.GetAction() == ::Neurotec::Collections::nccaAdd && args.GetNewItems().GetCount() > 0)
			args.GetNewItems().Get(0).AddPropertyChangedCallback(&OnPropertyChangedCallback, args.GetParam());
	}

	wxBitmap m_originalBitmap;
	wxBitmap m_processedBitmap;

	::Neurotec::Images::NRgb m_minColor;
	::Neurotec::Images::NRgb m_maxColor;

	::Neurotec::Biometrics::NFRecord m_record;

	int m_selectedMinutia;
	SpanningTree m_spanningTree;
	bool m_drawFeatures;
	ShownImage m_shownImage;
	bool m_showPatterClassConfidence;
	QualityVisualStyle m_qualityStyle;
	wxColor m_boundingRectColor;

protected:

	Neurotec::Biometrics::NFrictionRidge GetFrictionRidge()
	{
		return m_frictionRidge;
	}

	Neurotec::Biometrics::NFrictionRidge m_frictionRidge;
};

}}}

#endif // !WX_NFRICTIONRIDGEVIEW_HPP_INCLUDED
