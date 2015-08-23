#ifndef N_IMAGE_HPP_INCLUDED
#define N_IMAGE_HPP_INCLUDED

#include <Images/NPixelFormat.hpp>
#include <Core/NObject.hpp>
#include <Core/NArray.hpp>
#include <Media/NVideoFormat.hpp>
#include <Images/NRgb.hpp>
namespace Neurotec { namespace Images
{
using ::Neurotec::IO::NFileAccess;
using ::Neurotec::Media::HNVideoFormat;
#include <Images/NImage.h>
#include <Images/NMonochromeImage.h>
#include <Images/NGrayscaleImage.h>
#include <Images/NRgbImage.h>
}}
#if defined(N_FRAMEWORK_MFC)
	#include <afxstr.h>
	#include <atlimage.h>
#elif defined(N_FRAMEWORK_WX)
	#include <wx/image.h>
#elif defined(N_FRAMEWORK_QT)
	#include <QImage>
#endif

#include <Images/Interop/NImageDefWinTypes.h>

namespace Neurotec { namespace Images
{

#undef NI_READ_UNKNOWN_IMAGE
#undef NI_WRITE_UNKNOWN_IMAGE
#undef NI_DST_SWAP_CHANNELS
#undef NI_DST_ALPHA_CHANNEL_FIRST
#undef NI_DST_BOTTOM_TO_TOP
#undef NI_SRC_SWAP_CHANNELS
#undef NI_SRC_ALPHA_CHANNEL_FIRST
#undef NI_SRC_BOTTOM_TO_TOP

#undef NI_ALL_DST
#undef NI_ALL_SRC
#undef NI_ALL_DST_AND_SRC

const NUInt NI_READ_UNKNOWN_IMAGE      = 0x00000001;
const NUInt NI_WRITE_UNKNOWN_IMAGE     = 0x00000001;
const NUInt NI_DST_SWAP_CHANNELS       = 0x00000100;
const NUInt NI_DST_ALPHA_CHANNEL_FIRST = 0x00000200;
const NUInt NI_DST_BOTTOM_TO_TOP       = 0x00000400;
const NUInt NI_SRC_SWAP_CHANNELS       = 0x00001000;
const NUInt NI_SRC_ALPHA_CHANNEL_FIRST = 0x00002000;
const NUInt NI_SRC_BOTTOM_TO_TOP       = 0x00004000;

const NUInt NI_ALL_DST = 0x00000F00;
const NUInt NI_ALL_SRC = 0x0000F000;
const NUInt NI_ALL_DST_AND_SRC = (NI_ALL_DST | NI_ALL_SRC);

class NImageFormat;
class NImageInfo;

#include <Core/NNoDeprecate.h>
class NImage : public NObject
{
	N_DECLARE_OBJECT_CLASS(NImage, NObject)

public:
	class PlaneCollection : public ::Neurotec::Collections::NCollectionWithAllOutBase< ::Neurotec::IO::NBuffer, NImage,
		NImageGetPlaneCount, NImageGetPlane, NImageGetPlanesEx>
	{
		PlaneCollection(const NImage & owner)
		{
			SetOwner(owner);
		}

		friend class NImage;
	};

	class ImagePalette : public ::Neurotec::Collections::NCollectionBase<NArray, NImage,
		NImageGetPaletteLength, NImageGetPaletteEntry>
	{
		ImagePalette(const NImage & owner)
		{
			SetOwner(owner);
		}

	public:
		void Set(NInt index, const NArray & value)
		{
			NCheck(NImageSetPaletteEntry(this->GetOwnerHandle(), index, value.GetHandle()));
		}

		NSizeType GetEntriesSize()
		{
			NSizeType value;
			NCheck(NImageGetPaletteSize(this->GetOwnerHandle(), &value));
			return value;
		}

		::Neurotec::IO::NBuffer GetEntries()
		{
			HNBuffer hValue;
			NCheck(NImageGetPalette(this->GetOwnerHandle(), &hValue));
			return FromHandle< ::Neurotec::IO::NBuffer>(hValue, true);
		}

		const void * GetEntriesPtr() const
		{
			void * pValue;
			NCheck(NImageGetPalettePtr(this->GetOwnerHandle(), &pValue));
			return pValue;
		}

		void * GetEntriesPtr()
		{
			void * pValue;
			NCheck(NImageGetPalettePtr(this->GetOwnerHandle(), &pValue));
			return pValue;
		}

		void SetEntries(const ::Neurotec::IO::NBuffer & palette, NInt paletteLength)
		{
			NCheck(NImageSetPaletteN(this->GetOwnerHandle(), palette.GetHandle(), paletteLength));
		}

		void SetEntries(const void * pPalette, NSizeType paletteSize, NInt paletteLength)
		{
			NCheck(NImageSetPalette(this->GetOwnerHandle(), pPalette, paletteSize, paletteLength));
		}

		friend class NImage;
	};

public:
	static NImage GetWrapper(const NPixelFormat & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		const ::Neurotec::IO::NBuffer & pixels, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperExN(pixelFormat.GetValue(), width, height, stride, pixels.GetHandle(), flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage GetWrapper(const NPixelFormat & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		void * pPixels, NSizeType pixelsSize, bool ownsPixels, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperEx(pixelFormat.GetValue(), width, height, stride, pPixels, pixelsSize, ownsPixels ? NTrue : NFalse, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage GetWrapper(const NPixelFormat & pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
		const ::Neurotec::IO::NBuffer & pixels, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperForPartExN(pixelFormat.GetValue(), srcWidth, srcHeight, stride, pixels.GetHandle(), left, top, width, height, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage GetWrapper(const NPixelFormat & pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
		void * pPixels, NSizeType pixelsSize, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperForPartEx(pixelFormat.GetValue(), srcWidth, srcHeight, stride, pPixels, pixelsSize, left, top, width, height, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage GetWrapper(const NPixelFormat & pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
		const NArrayWrapper< ::Neurotec::IO::NBuffer>& planes, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperForPlanesPartN(pixelFormat.GetValue(), srcWidth, srcHeight, stride, const_cast<HNBuffer *>(planes.GetPtr()), planes.GetCount(), left, top, width, height, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage GetWrapper(const NPixelFormat & pixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType stride,
		void * const * arpPlanes, const NSizeType * arPlaneSizes, NInt planeCount, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperForPlanesPart(pixelFormat.GetValue(), srcWidth, srcHeight, stride, arpPlanes, arPlaneSizes, planeCount, left, top, width, height, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage GetWrapper(const NImage & srcImage, NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateWrapperForImagePartEx2(srcImage.GetHandle(), left, top, width, height, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage Create(const NPixelFormat & pixelFormat, NUInt width, NUInt height, NSizeType stride, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateEx(pixelFormat.GetValue(), width, height, stride, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage FromData(const NPixelFormat & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NSizeType srcStride, const ::Neurotec::IO::NBuffer & srcPixels, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromDataExN(pixelFormat.GetValue(), width, height, stride, srcStride, srcPixels.GetHandle(), flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage FromData(const NPixelFormat & pixelFormat, NUInt width, NUInt height, NSizeType stride,
		NSizeType srcStride, const void * pSrcPixels, NSizeType srcPixelsSize, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromDataEx(pixelFormat.GetValue(), width, height, stride, srcStride, pSrcPixels, srcPixelsSize, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage FromData(const NPixelFormat & pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const ::Neurotec::IO::NBuffer & srcPixels, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromDataPartExN(pixelFormat.GetValue(), stride, srcWidth, srcHeight,
			srcStride, srcPixels.GetHandle(), srcLeft, srcTop, width, height, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage FromData(const NPixelFormat & pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const void * pSrcPixels, NSizeType srcPixelsSize, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromDataPartEx(pixelFormat.GetValue(), stride, srcWidth, srcHeight,
			srcStride, pSrcPixels, srcPixelsSize, srcLeft, srcTop, width, height, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage FromData(const NPixelFormat & pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const NArrayWrapper< ::Neurotec::IO::NBuffer>& srcPlanes, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromDataPlanesPartN(pixelFormat.GetValue(), stride, srcWidth, srcHeight,
			srcStride, const_cast<HNBuffer *>(srcPlanes.GetPtr()), srcPlanes.GetCount(), srcLeft, srcTop, width, height, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage FromData(const NPixelFormat & pixelFormat, NSizeType stride, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromDataPlanesPart(pixelFormat.GetValue(), stride, srcWidth, srcHeight,
			srcStride, arpSrcPlanes, arSrcPlaneSizes, srcPlaneCount, srcLeft, srcTop, width, height, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage FromImage(const NPixelFormat & pixelFormat, NSizeType stride, const NImage & srcImage, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromImageEx2(pixelFormat.GetValue(), stride, srcImage.GetHandle(), flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage FromImage(const NPixelFormat & pixelFormat, NSizeType stride, const NImage & srcImage,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		HNImage handle;
		NCheck(NImageCreateFromImagePartEx2(pixelFormat.GetValue(), stride, srcImage.GetHandle(),
			left, top, width, height, flags, &handle));
		return FromHandle<NImage>(handle);
	}

	static NImage FromFile(const NStringWrapper & fileName, const NImageFormat & imageFormat, NUInt flags, NImageInfo * pInfo );
	static NImage FromMemory(const ::Neurotec::IO::NBuffer & buffer, const NImageFormat & imageFormat, NUInt flags, NSizeType * pSize, NImageInfo * pInfo);
	static NImage FromMemory(const void * pBuffer, NSizeType bufferSize, const NImageFormat & imageFormat, NUInt flags, NSizeType * pSize, NImageInfo * pInfo);
	static NImage FromStream(const ::Neurotec::IO::NStream & stream, const NImageFormat & imageFormat, NUInt flags, NImageInfo * pInfo);

#if defined(N_WINDOWS) || defined(N_DOCUMENTATION)
	static NImage FromHBitmap(HBITMAP hBitmap, NUInt flags = 0)
	{
		HNImage hImage;
		NCheck(NImageCreateFromHBitmap(hBitmap, flags, &hImage));
		return FromHandle<NImage>(hImage);
	}

	static NImage FromBitmapInfoAndBits(BITMAPINFO * pBitmapInfo, NSizeType bitmapInfoSize, const void * pBits, NSizeType bitsSize, NUInt flags = 0)
	{
		HNImage hImage;
		NCheck(NImageCreateFromBitmapInfoAndBits(pBitmapInfo, bitmapInfoSize, pBits, bitsSize, flags, &hImage));
		return FromHandle<NImage>(hImage);
	}
#endif

#if defined(N_FRAMEWORK_MFC)
	static NImage FromBitmap(CImage * pImage)
	{
		if (!pImage) NThrowArgumentNullException(N_T("pImage"));
		return FromHBitmap((HBITMAP)*pImage);
	}
#elif defined(N_FRAMEWORK_WX)
	static NImage FromBitmap(const wxImage & image)
	{
		return FromData(NPF_RGB_8U, image.GetWidth(), image.GetHeight(), 0,
			image.GetWidth() * 3, image.GetData(), image.GetHeight() * image.GetWidth() * 3);
	}
#elif defined(N_FRAMEWORK_QT)
	static NImage FromBitmap(const QImage & image)
	{
		QImage rgbImage = image;
		if (image.format() != QImage::Format_RGB32)
		{
			rgbImage = image.convertToFormat(QImage::Format_RGB32);
		}
		NUInt width = rgbImage.width();
		NUInt height = rgbImage.height();
		
		const uchar * srcBits = rgbImage.bits();
		uchar * dstBits = NULL;
		dstBits = (uchar*) NAlloc(width*height*3);
		for (uint y=0; y<height; y++)
		{
			int dstOffset_y = y*width*3;
			int srcOffset_y = y*4*width;
			for (uint x=0; x<width; x++)
			{
				int dstOffset = dstOffset_y + x*3;
				int srcOffset = srcOffset_y + x*4;
				
				dstBits[dstOffset] = srcBits[srcOffset+2];
				dstBits[dstOffset+1] = srcBits[srcOffset+1];
				dstBits[dstOffset+2] = srcBits[srcOffset];
			}
		}
		NImage nimage = FromData(NPF_RGB_8U, width, height, 0,
			width * 3, dstBits, height * width * 3);
		NFree(dstBits);
		return nimage;
	}
#endif

	static NArrayWrapper<NUInt> GetSupportedVideoSubtypes()
	{
		NUInt * arValues;
		NInt valueCount;
		NCheck(NImageGetSupportedVideoSubtypes(&arValues, &valueCount));
		return NArrayWrapper<NUInt>(arValues, valueCount);
	}

	static bool IsVideoSubtypeSupported(NUInt value)
	{
		NBool result;
		NCheck(NImageIsVideoSubtypeSupported(value, &result));
		return result != 0;
	}

	static bool IsVideoFormatSupported(const ::Neurotec::Media::NVideoFormat & format)
	{
		NBool result;
		NCheck(NImageIsVideoFormatSupported(format.GetHandle(), &result));
		return result != 0;
	}

	static NImage FromVideoSample(::Neurotec::Media::NVideoFormat & format, ::Neurotec::IO::NBuffer & sample)
	{
		HNImage hImage;
		NCheck(NImageCreateFromVideoSampleN(format.GetHandle(), sample.GetHandle(), &hImage));
		return FromHandle<NImage>(hImage);
	}

	static NImage FromVideoSample(const ::Neurotec::Media::NVideoFormat & format, const void * pSample, NSizeType sampleSize)
	{
		HNImage hImage;
		NCheck(NImageCreateFromVideoSample(format.GetHandle(), pSample, sampleSize, &hImage));
		return FromHandle<NImage>(hImage);
	}

	static void Copy(const NPixelFormat & srcPixelFormat, const NArray & srcMinValue, const NArray & srcMaxValue, const ::Neurotec::IO::NBuffer & srcPalette, NInt srcPaletteLength,
		NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const NArrayWrapper< ::Neurotec::IO::NBuffer>& srcPlanes, NUInt srcLeft, NUInt srcTop,
		const NPixelFormat & dstPixelFormat, const NArray & dstMinValue, const NArray & dstMaxValue, const ::Neurotec::IO::NBuffer & dstPalette, NInt dstPaletteLength,
		NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, const NArrayWrapper< ::Neurotec::IO::NBuffer>& dstPlanes, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyDataPlanesExN(srcPixelFormat.GetValue(), srcMinValue.GetHandle(), srcMaxValue.GetHandle(), srcPalette.GetHandle(), srcPaletteLength, srcWidth, srcHeight, srcStride, srcPlanes.GetPtr(), srcPlanes.GetCount(), srcLeft, srcTop,
			dstPixelFormat.GetValue(), dstMinValue.GetHandle(), dstMaxValue.GetHandle(), dstPalette.GetHandle(), dstPaletteLength, dstWidth, dstHeight, dstStride, dstPlanes.GetPtr(), dstPlanes.GetCount(), dstLeft, dstTop, width, height, flags));
	}

	static void Copy(const NPixelFormat & srcPixelFormat, const NArray & srcMinValue, const NArray & srcMaxValue, const void * pSrcPalette, NSizeType srcPaletteSize, NInt srcPaletteLength,
		NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		const NPixelFormat & dstPixelFormat, const NArray & dstMinValue, const NArray & dstMaxValue, const void * pDstPalette, NSizeType dstPaletteSize, NInt dstPaletteLength,
		NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyDataPlanesEx(srcPixelFormat.GetValue(), srcMinValue.GetHandle(), srcMaxValue.GetHandle(), pSrcPalette, srcPaletteSize, srcPaletteLength, srcWidth, srcHeight, srcStride, arpSrcPlanes, arSrcPlaneSizes, srcPlaneCount, srcLeft, srcTop,
			dstPixelFormat.GetValue(), dstMinValue.GetHandle(), dstMaxValue.GetHandle(), pDstPalette, dstPaletteSize, dstPaletteLength, dstWidth, dstHeight, dstStride, arpDstPlanes, arDstPlaneSizes, dstPlaneCount, dstLeft, dstTop, width, height, flags));
	}

	static void Copy(const NPixelFormat & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const NArrayWrapper< ::Neurotec::IO::NBuffer>& srcPlanes, NUInt srcLeft, NUInt srcTop,
		const NPixelFormat & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, const NArrayWrapper< ::Neurotec::IO::NBuffer>& dstPlanes, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyDataPlanesN(srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, srcPlanes.GetPtr(), srcPlanes.GetCount(), srcLeft, srcTop,
			dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride, dstPlanes.GetPtr(), dstPlanes.GetCount(), dstLeft, dstTop, width, height, flags));
	}

	static void Copy(const NPixelFormat & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		const NPixelFormat & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyDataPlanes(srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, arpSrcPlanes, arSrcPlaneSizes, srcPlaneCount, srcLeft, srcTop,
			dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride, arpDstPlanes, arDstPlaneSizes, dstPlaneCount, dstLeft, dstTop, width, height, flags));
	}

	static void Copy(const NPixelFormat & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const ::Neurotec::IO::NBuffer & srcPixels, NUInt srcLeft, NUInt srcTop,
		const NPixelFormat & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, const ::Neurotec::IO::NBuffer & dstPixels, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyDataN(srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, srcPixels.GetHandle(), srcLeft, srcTop,
			dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride, dstPixels.GetHandle(), dstLeft, dstTop,
			width, height, flags));
	}

	static void Copy(const NPixelFormat & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * pSrcPixels, NSizeType srcPixelsSize, NUInt srcLeft, NUInt srcTop,
		const NPixelFormat & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * pDstPixels, NSizeType dstPixelsSizes, NUInt dstLeft, NUInt dstTop,
		NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyData(srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, pSrcPixels, srcPixelsSize, srcLeft, srcTop,
			dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride, pDstPixels, dstPixelsSizes, dstLeft, dstTop,
			width, height, flags));
	}

	static void Copy(const NImage & srcImage, NUInt left, NUInt top, NUInt width, NUInt height, const NImage & dstImage, NUInt dstLeft, NUInt dstTop)
	{
		NCheck(NImageCopy(srcImage.GetHandle(), left, top, width, height, dstImage.GetHandle(), dstLeft, dstTop));
	}

	void CopyFrom(const NPixelFormat & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const ::Neurotec::IO::NBuffer & srcPixels, NUInt left, NUInt top, NUInt flags = 0)
	{
		NCheck(NImageCopyFromDataN(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, srcPixels.GetHandle(), left, top, flags));
	}

	void CopyFrom(const NPixelFormat & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const void * pSrcPixels, NSizeType srcPixelsSizes, NUInt left, NUInt top, NUInt flags = 0)
	{
		NCheck(NImageCopyFromData(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride, pSrcPixels, srcPixelsSizes, left, top, flags));
	}

	void CopyFrom(const NPixelFormat & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const ::Neurotec::IO::NBuffer & srcPixels, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyFromDataPartN(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride,
			srcPixels.GetHandle(), srcLeft, srcTop, left, top, width, height, flags));
	}

	void CopyFrom(const NPixelFormat & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const void * pSrcPixels, NSizeType srcPixelsSizes, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyFromDataPart(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride,
			pSrcPixels, srcPixelsSizes, srcLeft, srcTop, left, top, width, height, flags));
	}

	void CopyFrom(const NPixelFormat & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const NArrayWrapper< ::Neurotec::IO::NBuffer>& srcPlanes, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyFromDataPlanesPartN(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride,
			srcPlanes.GetPtr(), srcPlanes.GetCount(), srcLeft, srcTop,
			left, top, width, height, flags));
	}

	void CopyFrom(const NPixelFormat & srcPixelFormat, NUInt srcWidth, NUInt srcHeight, NSizeType srcStride,
		const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyFromDataPlanesPart(GetHandle(), srcPixelFormat.GetValue(), srcWidth, srcHeight, srcStride,
			arpSrcPlanes, arSrcPlaneSizes, srcPlaneCount, srcLeft, srcTop,
			left, top, width, height, flags));
	}

	void CopyFrom(const NPixelFormat & srcPixelFormat, const NArray & srcMinValue, const NArray & srcMaxValue, const ::Neurotec::IO::NBuffer & srcPalette, NInt srcPaletteLength,
		NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const NArrayWrapper< ::Neurotec::IO::NBuffer>& srcPlanes, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyFromDataPlanesPartExN(GetHandle(), srcPixelFormat.GetValue(), srcMinValue.GetHandle(), srcMaxValue.GetHandle(), srcPalette.GetHandle(), srcPaletteLength, srcWidth, srcHeight, srcStride,
			srcPlanes.GetPtr(), srcPlanes.GetCount(), srcLeft, srcTop,
			left, top, width, height, flags));
	}

	void CopyFrom(const NPixelFormat & srcPixelFormat, const NArray & srcMinValue, const NArray & srcMaxValue, const void * pSrcPalette, NSizeType srcPaletteSize, NInt srcPaletteLength,
		NUInt srcWidth, NUInt srcHeight, NSizeType srcStride, const void * const * arpSrcPlanes, const NSizeType * arSrcPlaneSizes, NInt srcPlaneCount, NUInt srcLeft, NUInt srcTop,
		NUInt left, NUInt top, NUInt width, NUInt height, NUInt flags = 0)
	{
		NCheck(NImageCopyFromDataPlanesPartEx(GetHandle(), srcPixelFormat.GetValue(), srcMinValue.GetHandle(), srcMaxValue.GetHandle(), pSrcPalette, srcPaletteSize, srcPaletteLength, srcWidth, srcHeight, srcStride,
			arpSrcPlanes, arSrcPlaneSizes, srcPlaneCount, srcLeft, srcTop,
			left, top, width, height, flags));
	}

	void CopyTo(const NPixelFormat & dstPixelFormat, NUInt dstWidth, NUInt dstHeight,
		NSizeType dstStride, const ::Neurotec::IO::NBuffer & dstPixels, NUInt dstLeft, NUInt dstTop, NUInt flags = 0) const
	{
		NCheck(NImageCopyToDataN((HNImage)GetHandle(), dstPixelFormat.GetValue(), dstWidth, dstHeight,
			dstStride, dstPixels.GetHandle(), dstLeft, dstTop, flags));
	}

	void CopyTo(const NPixelFormat & dstPixelFormat, NUInt dstWidth, NUInt dstHeight,
		NSizeType dstStride, void * pDstPixels, NSizeType dstPixelsSize, NUInt dstLeft, NUInt dstTop, NUInt flags = 0) const
	{
		NCheck(NImageCopyToData((HNImage)GetHandle(), dstPixelFormat.GetValue(), dstWidth, dstHeight,
			dstStride, pDstPixels, dstPixelsSize, dstLeft, dstTop, flags));
	}

	void CopyTo(NUInt left, NUInt top, const NPixelFormat & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
		const ::Neurotec::IO::NBuffer & dstPixels, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		NCheck(NImageCopyToDataPartN(GetHandle(), left, top, dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride,
			dstPixels.GetHandle(), dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(NUInt left, NUInt top, const NPixelFormat & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
		void * pDstPixels, NSizeType dstPixelsSize, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		NCheck(NImageCopyToDataPart(GetHandle(), left, top, dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride,
			pDstPixels, dstPixelsSize, dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(NUInt left, NUInt top, const NPixelFormat & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
		const NArrayWrapper< ::Neurotec::IO::NBuffer>& dstPlanes, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		NCheck(NImageCopyToDataPlanesPartN(GetHandle(), left, top, dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride,
			dstPlanes.GetPtr(), dstPlanes.GetCount(), dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(NUInt left, NUInt top, const NPixelFormat & dstPixelFormat, NUInt dstWidth, NUInt dstHeight, NSizeType dstStride,
		void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		NCheck(NImageCopyToDataPlanesPart(GetHandle(), left, top, dstPixelFormat.GetValue(), dstWidth, dstHeight, dstStride,
			arpDstPlanes, arDstPlaneSizes, dstPlaneCount, dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(NUInt left, NUInt top, const NPixelFormat & dstPixelFormat, const NArray & dstMinValue, const NArray & dstMaxValue, const ::Neurotec::IO::NBuffer & dstPalette, NInt dstPaletteLength,
		NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, const NArrayWrapper< ::Neurotec::IO::NBuffer>& dstPlanes, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		NCheck(NImageCopyToDataPlanesPartExN(GetHandle(), left, top, dstPixelFormat.GetValue(), dstMinValue.GetHandle(), dstMaxValue.GetHandle(), dstPalette.GetHandle(), dstPaletteLength,
			dstWidth, dstHeight, dstStride, dstPlanes.GetPtr(), dstPlanes.GetCount(), dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(NUInt left, NUInt top, const NPixelFormat & dstPixelFormat, const NArray & dstMinValue, const NArray & dstMaxValue, const void * pDstPalette, NSizeType dstPaletteSize, NInt dstPaletteLength,
		NUInt dstWidth, NUInt dstHeight, NSizeType dstStride, void * const * arpDstPlanes, const NSizeType * arDstPlaneSizes, NInt dstPlaneCount, NUInt dstLeft, NUInt dstTop, NUInt width, NUInt height, NUInt flags = 0) const
	{
		NCheck(NImageCopyToDataPlanesPartEx(GetHandle(), left, top, dstPixelFormat.GetValue(), dstMinValue.GetHandle(), dstMaxValue.GetHandle(), pDstPalette, dstPaletteSize, dstPaletteLength,
			dstWidth, dstHeight, dstStride, arpDstPlanes, arDstPlaneSizes, dstPlaneCount, dstLeft, dstTop, width, height, flags));
	}

	void CopyTo(const NImage & dstImage, NUInt dstLeft, NUInt dstTop) const
	{
		NCheck(NImageCopyTo(GetHandle(), dstImage.GetHandle(), dstLeft, dstTop));
	}

	::Neurotec::IO::NBuffer ExportPalette(const NPixelFormat & dstPixelFormat, const NArray & dstMinValue, const NArray & dstMaxValue, NInt * pPaletteLength, NUInt flags = 0) const
	{
		HNBuffer hPalette;
		NCheck(NImageExportPalette(GetHandle(), dstPixelFormat.GetValue(), dstMinValue.GetHandle(), dstMaxValue.GetHandle(), flags, pPaletteLength, &hPalette));
		return FromHandle< ::Neurotec::IO::NBuffer>(hPalette);
	}

	void Save(const NStringWrapper & fileName, const NImageFormat & imageFormat, const NImageInfo & info, NUInt flags) const;
	::Neurotec::IO::NBuffer Save(const NImageFormat & imageFormat, const NImageInfo & info, NUInt flags) const;
	void Save(const ::Neurotec::IO::NStream & stream, const NImageFormat & imageFormat, const NImageInfo & info, NUInt flags) const;

	void FlipHorizontally()
	{
		NCheck(NImageFlipHorizontally((HNImage)GetHandle()));
	}

	void FlipVertically()
	{
		NCheck(NImageFlipVertically((HNImage)GetHandle()));
	}

	void FlipDiagonally()
	{
		NCheck(NImageFlipDiagonally((HNImage)GetHandle()));
	}

	NImage RotateFlip(NImageRotateFlipType rotateFlipType) const
	{
		HNImage handle;
		NCheck(NImageRotateFlip(GetHandle(), rotateFlipType, &handle));
		return FromHandle<NImage>(handle);
	}

	NImage Crop(NUInt left, NUInt top, NUInt width, NUInt height) const
	{
		HNImage handle;
		NCheck(NImageCrop(GetHandle(), left, top, width, height, &handle));
		return FromHandle<NImage>(handle);
	}

#if defined(N_WINDOWS) || defined(N_DOCUMENTATION)
	HBITMAP ToHBitmap() const
	{
		HBITMAP hBitmap;
		NCheck(NImageToHBitmap(GetHandle(), &hBitmap));
		return hBitmap;
	}
#endif
#if defined(N_FRAMEWORK_MFC)
	CImage * ToBitmap() const
	{
		::std::auto_ptr<CImage> image(new CImage());
		image->Attach(ToHBitmap());
		return image.release();
	}
#elif defined(N_FRAMEWORK_WX)
	wxImage ToBitmap() const
	{
		NUInt width = GetWidth();
		NUInt height = GetHeight();
		wxImage image(width, height, false);
		CopyTo(NPF_RGB_8U, width, height, width * 3, image.GetData(), height * width * 3, 0, 0);
		return image;
	}
#elif defined(N_FRAMEWORK_QT)
	QImage ToBitmap() const;
#endif

	NPixelFormat GetPixelFormat() const
	{
		NPixelFormat_ value;
		NCheck(NImageGetPixelFormat(GetHandle(), &value));
		return NPixelFormat(value);
	}

	NArray GetMinValue() const
	{
		HNArray hValue;
		NCheck(NImageGetMinValue(GetHandle(), &hValue));
		return FromHandle<NArray>(hValue, true);
	}

	void SetMinValue(const NArray & value)
	{
		NCheck(NImageSetMinValue(GetHandle(), value.GetHandle()));
	}

	NArray GetMaxValue() const
	{
		HNArray hValue;
		NCheck(NImageGetMaxValue(GetHandle(), &hValue));
		return FromHandle<NArray>(hValue, true);
	}

	void SetMaxValue(const NArray & value)
	{
		NCheck(NImageSetMaxValue(GetHandle(), value.GetHandle()));
	}

	NUInt GetWidth() const
	{
		NUInt value;
		NCheck(NImageGetWidth(GetHandle(), &value));
		return value;
	}

	NUInt GetHeight() const
	{
		NUInt value;
		NCheck(NImageGetHeight(GetHandle(), &value));
		return value;
	}

	NSizeType GetStride() const
	{
		NSizeType value;
		NCheck(NImageGetStride(GetHandle(), &value));
		return value;
	}

	NSizeType GetPlaneSize() const
	{
		NSizeType value;
		NCheck(NImageGetPlaneSize(GetHandle(), &value));
		return value;
	}

	NSizeType GetImageSize() const
	{
		NSizeType value;
		NCheck(NImageGetImageSize(GetHandle(), &value));
		return value;
	}

	NFloat GetHorzResolution() const
	{
		NFloat value;
		NCheck(NImageGetHorzResolution(GetHandle(), &value));
		return value;
	}

	void SetHorzResolution(NFloat value)
	{
		NCheck(NImageSetHorzResolution(GetHandle(), value));
	}

	NFloat GetVertResolution() const
	{
		NFloat value;
		NCheck(NImageGetVertResolution(GetHandle(), &value));
		return value;
	}

	void SetVertResolution(NFloat value)
	{
		NCheck(NImageSetVertResolution(GetHandle(), value));
	}

	bool GetResolutionIsAspectRatio() const
	{
		NBool value;
		NCheck(NImageGetResolutionIsAspectRatio(GetHandle(), &value));
		return value != 0;
	}

	void SetResolutionIsAspectRatio(bool value)
	{
		NCheck(NImageSetResolutionIsAspectRatio(GetHandle(), value ? NTrue : NFalse));
	}

	NArray GetPixel(NUInt x, NUInt y) const
	{
		HNArray hValue;
		NCheck(NImageGetPixel(GetHandle(), x, y, &hValue));
		return FromHandle<NArray>(hValue, true);
	}

	void SetPixel(NUInt x, NUInt y, const NArray & value)
	{
		NCheck(NImageSetPixel(GetHandle(), x, y, value.GetHandle()));
	}

	NInt GetIndex(NUInt x, NUInt y) const
	{
		NInt value;
		NCheck(NImageGetIndex(GetHandle(), x, y, &value));
		return value != 0;
	}

	void SetIndex(NUInt x, NUInt y, NInt value)
	{
		NCheck(NImageSetIndex(GetHandle(), x, y, value ? NTrue : NFalse));
	}

	::Neurotec::IO::NBuffer GetPixels()
	{
		HNBuffer hValue;
		NCheck(NImageGetPixelsN(GetHandle(), &hValue));
		return FromHandle< ::Neurotec::IO::NBuffer>(hValue, true);
	}

	const void * GetPixelsPtr() const
	{
		void * pValue;
		NCheck(NImageGetPixelsPtr(GetHandle(), &pValue));
		return pValue;
	}

	void * GetPixelsPtr()
	{
		void * pValue;
		NCheck(NImageGetPixelsPtr(GetHandle(), &pValue));
		return pValue;
	}

	PlaneCollection GetPlanes()
	{
		return PlaneCollection(*this);
	}

	const ImagePalette GetPalette()
	{
		return ImagePalette(*this);
	}

	NImageInfo GetInfo();
};
#include <Core/NReDeprecate.h>

}}

#include <Images/Interop/NImageUndefWinTypes.h>

#include <Images/NImageFormat.hpp>
#include <Images/NImageInfo.hpp>

namespace Neurotec { namespace Images
{

inline NImage NImage::FromFile(const NStringWrapper & fileName, const NImageFormat & imageFormat = NULL, NUInt flags = 0, NImageInfo * pInfo = NULL)
{
	HNImage hImage;
	HNImageInfo hInfo = NULL;
	NCheck(NImageCreateFromFileExN(fileName.GetHandle(), imageFormat.GetHandle(), flags, pInfo ? &hInfo : NULL, &hImage));
	if (pInfo) *pInfo = FromHandle<NImageInfo>(hInfo);
	return FromHandle<NImage>(hImage);
}

inline NImage NImage::FromMemory(const ::Neurotec::IO::NBuffer & buffer, const NImageFormat & imageFormat = NULL, NUInt flags = 0, NSizeType * pSize = NULL, NImageInfo * pInfo = NULL)
{
	HNImage hImage;
	HNImageInfo hInfo = NULL;
	NCheck(NImageCreateFromMemoryN(buffer.GetHandle(), imageFormat.GetHandle(), flags, pSize, pInfo ? &hInfo : NULL, &hImage));
	if (pInfo) *pInfo = FromHandle<NImageInfo>(hInfo);
	return FromHandle<NImage>(hImage);
}

inline NImage NImage::FromMemory(const void * pBuffer, NSizeType bufferSize, const NImageFormat & imageFormat = NULL, NUInt flags = 0, NSizeType * pSize = NULL, NImageInfo * pInfo = NULL)
{
	HNImage hImage;
	HNImageInfo hInfo = NULL;
	NCheck(NImageCreateFromMemory(pBuffer, bufferSize, imageFormat.GetHandle(), flags, pSize, pInfo ? &hInfo : NULL, &hImage));
	if (pInfo) *pInfo = FromHandle<NImageInfo>(hInfo);
	return FromHandle<NImage>(hImage);
}

inline NImage NImage::FromStream(const ::Neurotec::IO::NStream & stream, const NImageFormat & imageFormat = NULL, NUInt flags = 0, NImageInfo * pInfo = NULL)
{
	HNImage hImage;
	HNImageInfo hInfo = NULL;
	NCheck(NImageCreateFromStream(stream.GetHandle(), imageFormat.GetHandle(), flags, pInfo ? &hInfo : NULL, &hImage));
	if (pInfo) *pInfo = FromHandle<NImageInfo>(hInfo);
	return FromHandle<NImage>(hImage);
}

#if defined(N_FRAMEWORK_QT)
inline QImage NImage::ToBitmap() const
{
	NUInt width = GetWidth();
	NUInt height = GetHeight();
	QImage image(width, height, QImage::Format_RGB32);
	CopyTo(NPF_RGB_A_8U, width, height, width * 4, image.bits(), width * height * 4, 0, 0, 0);
	image.setDotsPerMeterX(GetHorzResolution() * 100 / 2.54);
	image.setDotsPerMeterY(GetVertResolution() * 100 / 2.54);
	return image;
}
#endif

inline void NImage::Save(const NStringWrapper & fileName, const NImageFormat & imageFormat = NULL, const NImageInfo & info = NULL, NUInt flags = 0) const
{
	NCheck(NImageSaveToFileExN(GetHandle(), fileName.GetHandle(), imageFormat.GetHandle(), info.GetHandle(), flags));
}

inline ::Neurotec::IO::NBuffer NImage::Save(const NImageFormat & imageFormat, const NImageInfo & info = NULL, NUInt flags = 0) const
{
	HNBuffer hBuffer;
	NCheck(NImageSaveToMemoryN(GetHandle(), imageFormat.GetHandle(), info.GetHandle(), flags, &hBuffer));
	return FromHandle< ::Neurotec::IO::NBuffer>(hBuffer);
}

inline void NImage::Save(const ::Neurotec::IO::NStream & stream, const NImageFormat & imageFormat, const NImageInfo & info = NULL, NUInt flags = 0) const
{
	NCheck(NImageSaveToStream(GetHandle(), stream.GetHandle(), imageFormat.GetHandle(), info.GetHandle(), flags));
}

inline NImageInfo NImage::GetInfo()
{
	HNImageInfo hValue;
	NCheck(NImageGetInfo(GetHandle(), &hValue));
	return FromHandle<NImageInfo>(hValue, true);
}

}}

#endif // !N_IMAGE_HPP_INCLUDED
