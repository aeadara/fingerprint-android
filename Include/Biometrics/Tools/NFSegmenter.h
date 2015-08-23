#ifndef NF_SEGMENTER_H_INCLUDED
#define NF_SEGMENTER_H_INCLUDED

#include <Biometrics/NBiometricTypes.h>
#include <Images/NGrayscaleImage.h>
#include <Geometry/NGeometry.h>
#include <Biometrics/Tools/NFSegmenterParams.h>

#ifdef N_CPP
extern "C"
{
#endif

N_DECLARE_OBJECT_TYPE(NFSegment, NObject)

NResult N_API NFSegmentGetTopLeft(HNFSegment hSegment, struct NPoint_ * pValue);
NResult N_API NFSegmentGetTopRight(HNFSegment hSegment, struct NPoint_ * pValue);
NResult N_API NFSegmentGetBottomRight(HNFSegment hSegment, struct NPoint_ * pValue);
NResult N_API NFSegmentGetBottomLeft(HNFSegment hSegment, struct NPoint_ * pValue);
NResult N_API NFSegmentGetPosition(HNFSegment hSegment, NFPosition * pValue);
NResult N_API NFSegmentGetPossiblePositionCount(HNFSegment hSegment, NInt * pValue);
NResult N_API NFSegmentGetPossiblePosition(HNFSegment hSegment, NInt index, NFPosition * pValue);
NResult N_API NFSegmentGetPossiblePositions(HNFSegment hSegment, NFPosition * arValues, NInt valueLength);
NResult N_API NFSegmentGetStatus(HNFSegment hSegment, NBiometricStatus * pValue);

N_DECLARE_STATIC_OBJECT_TYPE(NFSegmenter)

NResult N_API NFSegmenterLocate(HNGrayscaleImage hImage, NFPosition position, HNFSegment * * parhSegments, NInt * pSegmentCount);
NResult N_API NFSegmenterLocateEx(HNGrayscaleImage hImage, NFPosition position, NFPosition * arMissingFingers, NInt missingFingerCount, HNFSegment * * parhSegments, NInt * pSegmentCount);
NResult N_API NFSegmenterCutSingle(HNGrayscaleImage hImage, HNFSegment hSegment, HNGrayscaleImage * phImage);
NResult N_API NFSegmenterCutMultiple(HNGrayscaleImage hImage, HNFSegment * arhSegments, NInt segmentCount, HNGrayscaleImage * * parhImages);

#ifdef N_CPP
}
#endif

#endif // !NF_SEGMENTER_H_INCLUDED
