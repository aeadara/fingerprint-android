#ifndef WX_NAVIEW_HPP_INCLUDED
#define WX_NAVIEW_HPP_INCLUDED

#include <math.h>

#include <Core/NError.hpp>
#include <Biometrics/Standards/ANRecord.hpp>
#include <Biometrics/Standards/ANRecordType.hpp>
#include <Biometrics/Standards/ANType8Record.hpp>
#include <Biometrics/Standards/ANType9Record.hpp>
#include <Biometrics/Standards/ANType14Record.hpp>
#include <Biometrics/Standards/ANImageBinaryRecord.hpp>
#include <Biometrics/Standards/ANFPImageAsciiBinaryRecord.hpp>
#include <Biometrics/Standards/BdifTypes.h>
#include <Biometrics/Standards/BdifTypes.hpp>

#include <Gui/wxNView.hpp>

namespace Neurotec { namespace Biometrics { namespace Standards { namespace Gui
{

const double PI = 3.14;

class wxANView : public Neurotec::Gui::wxNView
{
public:

	wxANView(wxWindow *parent, wxWindowID winid = wxID_ANY)
		: wxNView(parent, winid), _record(NULL), _type8Record(NULL), _type9Record(NULL), _type14Record(NULL), _bitmap(), _imageError((HNError)NULL)
	{
		_sx = 0;
		_sy = 0;
		_w = 0;
		_h = 0;
	}

	virtual ~wxANView ()
	{
	}

#if wxUSE_GRAPHICS_CONTEXT == 1
virtual void OnDraw(wxGraphicsContext *gc)
{
	if (_bitmap.IsOk())
	{
		gc->DrawBitmap(_bitmap, 0, 0, _bitmap.GetWidth(), _bitmap.GetHeight());
	}
	else if (!_imageError.IsNull() || !_type9Record.IsNull())
	{
		gc->SetBrush(*wxWHITE_BRUSH);
		gc->DrawRectangle(0, 0, _w, _h);

		if (!_imageError.IsNull())
		{
			gc->SetPen(*wxRED_PEN);
			gc->StrokeLine(0, 0, _w - 1, _h - 1);
			gc->StrokeLine(0, _h - 1, _w - 1, _h - 1);

			gc->SetPen(*wxBLACK_PEN);
			gc->DrawText(_imageError.GetMessage(), 0 , 0);
		}
	}

	if (!_type8Record.IsNull())
	{
		if (_type8Record.GetPenVectors().GetCount() > 0)
		{
			ANPenVector vector = _type8Record.GetPenVectors()[0];
			wxColor naviColor(0x00, 0x00, 0x80);
			wxPen pen(naviColor);
			wxGraphicsPath path = gc->CreatePath();

			path.MoveToPoint(vector.X * _sx, (_h / _sy - 1 - vector.Y) * _sy);
			for (int i = 1; i < _type8Record.GetPenVectors().GetCount(); i++)
			{
				vector = _type8Record.GetPenVectors()[i];
				path.AddLineToPoint(vector.X * _sx, (_h / _sy - 1 - vector.Y) * _sy);
			}

			gc->SetPen(pen);
			gc->StrokePath(path);
			gc->SetPen(*wxBLACK_PEN);
		}
	}
	if (!_type9Record.IsNull())
		{
			float minutiaWidth = 50 * _sx, minutiaWidthHalf = minutiaWidth / 2;
			float minutiaHeight = 50 * _sy, minutiaHeightHalf = minutiaHeight / 2;
			float minutiaAngleWidth = 100 * _sx;
			float minutiaAngleHeight = 100 * _sy;

			wxColor red(255, 0, 0);
			wxPen minutiaPen(red);
			gc->SetPen(minutiaPen);
			gc->SetBrush(wxNullBrush);
			ANType9Record::MinutiaCollection minutiae = _type9Record.GetMinutiae();
			for (NInt i = 0; i < minutiae.GetCount(); i++)
			{
				ANFPMinutia minutia = minutiae[i];
				float cx = minutia.X * _sx;
				float cy = (_h / _sy - 1 - minutia.Y) * _sy;
				double th = minutia.Theta + PI;

				gc->DrawEllipse(cx - minutiaWidthHalf, cy - minutiaHeightHalf, minutiaWidth, minutiaHeight);
				gc->StrokeLine(cx, cy, cx + (float)(cos(th) * minutiaAngleWidth), cy + (float)(sin(th) * minutiaAngleHeight));
			}

			float coreWidth = 100 * _sx, coreWidthHalf = coreWidth / 2;
			float coreHeight = 100 * _sy, coreHeightHalf = coreHeight / 2;

			wxColor orangeColor(0xFF, 0xA5, 0x00);
			wxPen corePen(orangeColor);
			gc->SetPen(corePen);
			ANType9Record::CoreCollection cores = _type9Record.GetCores();
			for (NInt i = 0; i < cores.GetCount(); i++)
			{
				ANFCore core = cores[i];
				float cx = core.X * _sx;
				float cy = (_h / _sy - 1 - core.Y) * _sy;
				gc->DrawRectangle(cx - coreWidthHalf, cy - coreHeightHalf, coreWidth, coreHeight);
			}

			float deltaWidth = 75 * _sx;
			float deltaHeight = 75 * _sy;
			float deltaX1 = (float)(cos(-PI / 2) * deltaWidth), deltaY1 = (float)(sin(-PI / 2) * deltaHeight);
			float deltaX2 = (float)(cos(PI / 6) * deltaWidth), deltaY2 = (float)(sin(PI / 6) * deltaHeight);
			float deltaX3 = (float)(cos(5 * PI / 6) * deltaWidth), deltaY3 = (float)(sin(5 * PI / 6) * deltaHeight);

			wxPoint2DDouble deltaPoints[4];
			ANType9Record::DeltaCollection deltas = _type9Record.GetDeltas();
			for (NInt i = 0; i < deltas.GetCount(); i++)
			{
				ANFDelta delta = deltas[i];
				float cx = delta.X * _sx;
				float cy = (_h / _sy - 1 - delta.Y) * _sy;

				deltaPoints[0].m_x = cx + deltaX1;
				deltaPoints[0].m_y = cy + deltaY1;

				deltaPoints[1].m_x = cx + deltaX2;
				deltaPoints[1].m_y = cy + deltaY2;

				deltaPoints[2].m_x = cx + deltaX3;
				deltaPoints[2].m_y = cy + deltaY3;

				deltaPoints[3].m_x = cx + deltaX1;
				deltaPoints[3].m_y = cy + deltaY1;

				gc->StrokeLines(3, deltaPoints, &deltaPoints[1]);
			}
		}
		if (!_type14Record.IsNull())
		{
			gc->SetPen(wxColor(0, 0x64, 0));
			gc->SetBrush(wxNullBrush);

			ANType14Record::SegmentCollection segments = _type14Record.GetSegments();
			for (NInt i = 0; i < segments.GetCount(); i++)
			{
				ANFSegment segment = segments[i];
				gc->DrawRectangle(segment.Left, segment.Top, segment.Right - segment.Left, segment.Bottom - segment.Top);
			}

			wxColor greenYellow(0xAD, 0xFF, 0x2F);
			gc->SetPen(greenYellow);

			ANType14Record::AlternateSegmentVerticesCollection vertices = _type14Record.GetAlternateSegmentsVertices();
			for (NInt i = 0; i < _type14Record.GetAlternateSegments().GetCount(); i++)
			{
				NInt count = vertices.GetCount(i);
				for (NInt j = 0; j < count; j++)
				{
					::Neurotec::Geometry::NPoint first = vertices.Get(i, j);
					::Neurotec::Geometry::NPoint second = vertices.Get(i, (j + 1) % count);
					gc->StrokeLine(first.X, first.Y, second.X, second.Y);
				}
			}
		}
}
#else
virtual void OnDraw(wxDC& dc)
{
	if (_bitmap.IsOk())
	{
		dc.DrawBitmap(_bitmap, 0, 0);
	}
	else if (!_imageError.IsNull() || !_type9Record.IsNull())
	{
		dc.SetPen(wxPen(wxColor(255, 255, 255)));
		dc.SetBrush(*wxWHITE_BRUSH);
		dc.DrawRectangle(0, 0, _w, _h);

		if (!_imageError.IsNull())
		{
			dc.SetPen(*wxRED_PEN);
			dc.DrawLine(0, 0, _w - 1, _h - 1);
			dc.DrawLine(0, _h - 1, _w - 1, _h - 1);
			dc.SetPen(*wxBLACK_PEN);
			dc.DrawText(_imageError.GetMessage(), 0 , 0);
		}

	}
	if (!_type8Record.IsNull())
	{
			if (_type8Record.GetPenVectors().GetCount() > 0)
			{
				ANPenVector prevVector = _type8Record.GetPenVectors()[0];
				wxColor naviColor(0x00, 0x00, 0x80);
				for (int i = 1; i < _type8Record.GetPenVectors().GetCount(); i++)
				{
					ANPenVector currentVector = _type8Record.GetPenVectors()[i];
					dc.SetPen(wxPen(wxColor(0, 0, 0x80, prevVector.Pressure)));
					dc.DrawLine((prevVector.X * _sx), ((_h / _sy - 1 - prevVector.Y) * _sy),
								(currentVector.X * _sx), ((_h / _sy - 1 - currentVector.Y) * _sy));
					prevVector = currentVector;
				}
				dc.SetPen(*wxBLACK_PEN);
			}
	}
	if (!_type9Record.IsNull())
		{
			float minutiaWidth = 50 * _sx, minutiaWidthHalf = minutiaWidth / 2;
			float minutiaHeight = 50 * _sy, minutiaHeightHalf = minutiaHeight / 2;
			float minutiaAngleWidth = 100 * _sx;
			float minutiaAngleHeight = 100 * _sy;
			dc.SetPen(*wxRED_PEN);
			ANType9Record::MinutiaCollection minutiae = _type9Record.GetMinutiae();
			for (NInt i = 0; i < minutiae.GetCount(); i++)
			{
				ANFPMinutia minutia = minutiae[i];
				float cx = minutia.X * _sx;
				float cy = (_h / _sy - 1 - minutia.Y) * _sy;
				double th = minutia.Theta + PI;

				dc.DrawEllipse(cx - minutiaWidthHalf, cy - minutiaHeightHalf, minutiaWidth, minutiaHeight);
				dc.DrawLine(cx, cy, cx + (float)(cos(th) * minutiaAngleWidth), cy + (float)(sin(th) * minutiaAngleHeight));
			}

			float coreWidth = 100 * _sx, coreWidthHalf = coreWidth / 2;
			float coreHeight = 100 * _sy, coreHeightHalf = coreHeight / 2;

			wxColor orangeColor(0xFF, 0xA5, 0x00);
			wxPen corePen(orangeColor);
			dc.SetPen(corePen);

			ANType9Record::CoreCollection cores = _type9Record.GetCores();
			for (NInt i = 0; i < cores.GetCount(); i++)
			{
				ANFCore core = cores[i];
				float cx = core.X * _sx;
				float cy = (_h / _sy - 1 - core.Y) * _sy;
				dc.DrawLine(cx - coreWidthHalf, cy - coreHeightHalf, cx + coreWidthHalf, cy - coreHeightHalf);
				dc.DrawLine(cx + coreWidthHalf, cy - coreHeightHalf, cx + coreWidthHalf, cy + coreHeightHalf);
				dc.DrawLine(cx + coreWidthHalf, cy + coreHeightHalf, cx - coreWidthHalf, cy + coreHeightHalf);
				dc.DrawLine(cx - coreWidthHalf, cy + coreHeightHalf, cx - coreWidthHalf, cy - coreHeightHalf);
			}

			float deltaWidth = 75 * _sx;
			float deltaHeight = 75 * _sy;
			float deltaX1 = (float)(cos(-PI / 2) * deltaWidth), deltaY1 = (float)(sin(-PI / 2) * deltaHeight);
			float deltaX2 = (float)(cos(PI / 6) * deltaWidth), deltaY2 = (float)(sin(PI / 6) * deltaHeight);
			float deltaX3 = (float)(cos(5 * PI / 6) * deltaWidth), deltaY3 = (float)(sin(5 * PI / 6) * deltaHeight);

			wxPen deltaPen(orangeColor);
			wxPoint deltaPoints[4];
			ANType9Record::DeltaCollection deltas =_type9Record.GetDeltas();
			for (NInt i = 0; i < deltas.GetCount(); i++)
			{
				ANFDelta delta = deltas[i];
				float cx = delta.X * _sx;
				float cy = (_h / _sy - 1 - delta.Y) * _sy;

				deltaPoints[0].x = cx + deltaX1;
				deltaPoints[0].y = cy + deltaY1;

				deltaPoints[1].x = cx + deltaX2;
				deltaPoints[1].y = cy + deltaY2;

				deltaPoints[2].x = cx + deltaX3;
				deltaPoints[2].y = cy + deltaY3;

				deltaPoints[3].x = cx + deltaX1;
				deltaPoints[3].y = cy + deltaY1;

				dc.DrawLines(4, deltaPoints);
			}
		}
		if (!_type14Record.IsNull())
		{
			dc.SetPen(wxColor(0, 0x64, 0));
			dc.SetBrush(wxNullBrush);

			ANType14Record::SegmentCollection segments = _type14Record.GetSegments();
			for (NInt i = 0; i < segments.GetCount(); i++)
			{
				ANFSegment segment = segments[i];
				dc.DrawLine(segment.Left, segment.Top, segment.Right, segment.Top);
				dc.DrawLine(segment.Right, segment.Top, segment.Right, segment.Bottom);
				dc.DrawLine(segment.Right, segment.Bottom, segment.Left, segment.Bottom);
				dc.DrawLine(segment.Left, segment.Bottom, segment.Left, segment.Top);
			}

			wxColor greenYellow(0xAD, 0xFF, 0x2F);
			dc.SetPen(greenYellow);

			ANType14Record::AlternateSegmentVerticesCollection vertices = _type14Record.GetAlternateSegmentsVertices();
			for (NInt i = 0; i < _type14Record.GetAlternateSegments().GetCount(); i++)
			{
				NInt count = vertices.GetCount(i);
				for (NInt j = 0; j < count; j++)
				{
					::Neurotec::Geometry::NPoint first = vertices.Get(i, j);
					::Neurotec::Geometry::NPoint second = vertices.Get(i, (j + 1) % count);
					dc.DrawLine(first.X, first.Y, second.X, second.Y);
				}
			}
		}
}
#endif

::Neurotec::Biometrics::Standards::ANRecord & GetANRecord()
{
	return _record;
}

void SetANRecord(const ::Neurotec::Biometrics::Standards::ANRecord & value)
{
	ANRecordType recordType = value.GetRecordType();
	int penVectorCount = 0;

	if (!_bitmap.GetRefData())
	{
		_bitmap = wxImage();
	}

	_imageError = NULL;
	_record = value;
	_type8Record = NULL;
	_type9Record = NULL;
	_type14Record = NULL;
	_sx = 0;
	_sy = 0;

	if (recordType == ANRecordType::GetType8())
	{
		ANType8Record record = ANType8Record(value.GetHandle());
		penVectorCount = record.GetPenVectors().GetCount();
	}

	if (value.IsNull() || !value.GetIsValidated())
	{
		_w = 0;
		_h = 0;
	}
	else if (recordType == ANRecordType::GetType9())
	{
		_type9Record = ANType9Record(value.GetHandle());

		::Neurotec::Biometrics::Standards::BdifFPImpressionType impresionType = _type9Record.GetImpressionType();
		bool isPalmprint = impresionType >= bfpitLiveScanPalm && impresionType  <= bfpitLatentPalmLift;
		ANTemplate owner = _type9Record.GetOwner();
		ANTemplate::RecordCollection records = owner.GetRecords();
		for (int i = 0; i < records.GetCount(); i++)
		{
			ANRecord rec = records[i];
			if (rec.GetIdc() == _type9Record.GetIdc())
			{
				if (!isPalmprint && rec.GetRecordType().GetNumber() >= 3 && rec.GetRecordType().GetNumber() <= 6)
				{
					ANImageBinaryRecord fImageBinaryRecord = NObjectDynamicCast<ANImageBinaryRecord>(rec);
					_sx = _sy = fImageBinaryRecord.GetImageResolution() / 100000.0f;
					_w = fImageBinaryRecord.GetHorzLineLength();
					_h = fImageBinaryRecord.GetVertLineLength();
					try
					{
						::Neurotec::Images::NImage image = fImageBinaryRecord.ToNImage();
						_w = image.GetWidth();
						_h = image.GetHeight();
						_bitmap = image.ToBitmap();
					}
					catch (::Neurotec::NError e)
					{
						_imageError = e;
					}
					break;
				}
				if (rec.GetRecordType().GetNumber() == 13 || (!isPalmprint && rec.GetRecordType().GetNumber() == 14) || (isPalmprint && rec.GetRecordType().GetNumber() == 15))
				{
					ANFPImageAsciiBinaryRecord fpImageAsciiBinaryRecord = NObjectDynamicCast<ANFPImageAsciiBinaryRecord>(rec);
					switch (fpImageAsciiBinaryRecord.GetScaleUnits())
					{
						case bsuPixelsPerInch:
							_sx = fpImageAsciiBinaryRecord.GetHorzPixelScale() / 2540.0f;
							_sy = fpImageAsciiBinaryRecord.GetVertPixelScale() / 2540.0f;
							break;
						case bsuPixelsPerCentimeter:
							_sx = fpImageAsciiBinaryRecord.GetHorzPixelScale() / 1000.0f;
							_sy = fpImageAsciiBinaryRecord.GetVertPixelScale() / 1000.0f;
							break;
						default:
							NThrowNotImplementedException();
					}
					_w = fpImageAsciiBinaryRecord.GetHorzLineLength();
					_h = fpImageAsciiBinaryRecord.GetVertLineLength();
					try
					{
						::Neurotec::Images::NImage image = fpImageAsciiBinaryRecord.ToNImage();
						_w = image.GetWidth();
						_h = image.GetHeight();
						_bitmap = image.ToBitmap();
					}
					catch(::Neurotec::NError e)
					{
						_imageError = e;
					}
					break;
				}
			}
		}
		if (!_bitmap.IsOk())
		{
			NUInt maxX = 0;
			NUInt maxY = 0;
			if (!isPalmprint)
			{
				ANType9Record::CoreCollection cores = _type9Record.GetCores();
				for(NInt i = 0; i < cores.GetCount(); i++)
				{
					ANFCore core = cores[i];
					if (maxX < core.X) maxX = core.X;
					if (maxY < core.Y) maxY = core.Y;
				}

				ANType9Record::DeltaCollection deltas = _type9Record.GetDeltas();
				for (NInt i = 0; i < deltas.GetCount(); i++)
				{
					ANFDelta delta = deltas[i];
					if (maxX < delta.X) maxX = delta.X;
					if (maxY < delta.Y) maxY = delta.Y;
				}
			}

			ANType9Record::MinutiaCollection minutiae = _type9Record.GetMinutiae();
			for (NInt i = 0; i < minutiae.GetCount(); i++)
			{
				ANFPMinutia minutia = minutiae[i];
				if (maxX < minutia.X) maxX = minutia.X;
				if (maxY < minutia.Y) maxY = minutia.Y;
			}
			_sx = _sy = 500.0f / 2540.0f; // Default to 500 dpi display
			_w = NRound((maxX + 1) * _sx);
			_h = NRound((maxY + 1) * _sy);
		}
	}
	else if (recordType == ANRecordType::GetType8() && penVectorCount > 0)
	{
		_type8Record = ANType8Record(_record.GetHandle());

		NUInt maxX = 0;
		NUInt maxY = 0;

		ANType8Record::PenVectorCollection vectors = _type8Record.GetPenVectors();
		for (NInt i = 0; i < vectors.GetCount(); i++)
		{
			ANPenVector v = vectors[i];
			if (maxX < v.X) maxX = v.X;
			if (maxY < v.Y) maxY = v.Y;
		}

		_sx = _sy = 500.0f / 2540.0f;
		_w = NRound((maxX + 1) * _sx);
		_h = NRound((maxY + 1) * _sy);
	}
	else if (recordType == ANImageBinaryRecord::NativeTypeOf())
	{
		ANImageBinaryRecord imageBinaryRecord = NObjectDynamicCast<ANImageBinaryRecord>(_record);
		_w = imageBinaryRecord.GetHorzLineLength();
		_h = imageBinaryRecord.GetVertLineLength();
		try
		{
			::Neurotec::Images::NImage image = imageBinaryRecord.ToNImage();
			_w = image.GetWidth();
			_h = image.GetHeight();
			_bitmap = image.ToBitmap();
		}
		catch (Neurotec::NError e)
		{
			_imageError = e;
		}
	}
	else
	{
		ANImageAsciiBinaryRecord imageAsciiBinaryRecord = NObjectDynamicCast<ANImageAsciiBinaryRecord>(_record);
		if (!imageAsciiBinaryRecord.IsNull())
		{
			_w = imageAsciiBinaryRecord.GetHorzLineLength();
			_h = imageAsciiBinaryRecord.GetVertLineLength();
			try
			{
				::Neurotec::Images::NImage image = imageAsciiBinaryRecord.ToNImage();
				_w = image.GetWidth();
				_h = image.GetHeight();
				_bitmap = image.ToBitmap();
			}
			catch (Neurotec::NError e)
			{
				_imageError = e;
			}
			_type14Record = ANType14Record(imageAsciiBinaryRecord.GetHandle());
		}
	}
	SetViewSize(_w, _h);
}

private:
	ANRecord _record;
	ANType8Record _type8Record;
	ANType9Record _type9Record;
	ANType14Record _type14Record;

	float _sx;
	float _sy;
	int _w;
	int _h;
	wxImage _bitmap;
	::Neurotec::NError _imageError;
};

}}}}

#endif // !WX_NAVIEW_HPP_INCLUDED
