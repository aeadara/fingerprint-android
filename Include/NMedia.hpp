#ifndef N_MEDIA_LIBRARY_HPP_INCLUDED
#define N_MEDIA_LIBRARY_HPP_INCLUDED

#include <Geometry/NGeometry.hpp>
#include <Images/NPixelFormat.hpp>
#include <Images/NImage.hpp>
#include <Images/NImageFormat.hpp>
#include <Images/NImageReader.hpp>
#include <Images/NImageWriter.hpp>
#include <Images/NImageInfo.hpp>
#include <Images/NImages.hpp>
#include <Images/NRgb.hpp>
#include <Images/Bmp.hpp>
#include <Images/Tiff.hpp>
#include <Images/Jpeg.hpp>
#include <Images/Png.hpp>
#include <Images/Jpeg2K.hpp>
#include <Images/Wsq.hpp>
#include <Images/NistCom.hpp>
#include <Images/IHead.hpp>
#include <Media/NSampleFormat.hpp>
#include <Media/NMediaTypes.hpp>
#include <Media/NMediaFormat.hpp>
#include <Media/NAudioFormat.hpp>
#include <Media/NVideoFormat.hpp>
#include <Media/NMediaSource.hpp>
#include <Media/NMediaReader.hpp>
#include <Media/NVideoWriter.hpp>
#include <Media/NVideoWriterOptions.hpp>
#include <Media/NMedia.hpp>
#include <SmartCards/SimpleTag.hpp>
#include <SmartCards/SimpleTlv.hpp>
#include <SmartCards/BerTag.hpp>
#include <SmartCards/BerTlv.hpp>
#include <SmartCards/PrimitiveBerTlv.hpp>
#include <SmartCards/ConstructedBerTlv.hpp>
#include <SmartCards/ApduClass.hpp>
#include <SmartCards/ApduInstruction.hpp>
#include <SmartCards/ApduStatus.hpp>
#ifdef N_WINDOWS
#include <SmartCards/NSmartCardsCommands.hpp>
#endif
#include <SmartCards/NSmartCardsDataElements.hpp>
#include <SmartCards/NSmartCardsBiometry.hpp>
#include <Sound/NSoundFormat.hpp>
#include <Sound/NSoundBuffer.hpp>

#endif // !N_MEDIA_LIBRARY_HPP_INCLUDED
