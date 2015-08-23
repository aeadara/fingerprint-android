#ifndef NL_EXTRACTOR_PARAMS_H_INCLUDED
#define NL_EXTRACTOR_PARAMS_H_INCLUDED

#include <Core/NParameters.h>

#ifdef N_CPP
extern "C"
{
#endif

#define NLEP_MIN_IOD                    10101
#define NLEP_MAX_IOD                    10102
#define NLEP_FACE_CONFIDENCE_THRESHOLD  10103
#define NLEP_FAVOR_LARGEST_FACE         10104
#define NLEP_MAX_ROLL_ANGLE_DEVIATION   10105
#define NLEP_MAX_YAW_ANGLE_DEVIATION    10109
#define NLEP_DETECT_MORE_FACES          10110
#define NLEP_FACE_DETECTION_SCALE_COUNT 10111
#define NLEP_FACE_ROLL_ANGLE_BASE       10117

#define NLEP_DETECT_ALL_FEATURE_POINTS  10250
#define NLEP_DETECT_BASE_FEATURE_POINTS 10255

#define NLEP_FACE_QUALITY_THRESHOLD 10350
#define NLEP_TEMPLATE_SIZE          10360

#define NLEP_USE_LIVENESS_CHECK            10402
#define NLEP_LIVENESS_THRESHOLD            10403
#define NLEP_MAX_RECORDS_PER_TEMPLATE      10408
#define NLEP_MAX_STREAM_DURATION_IN_FRAMES 10409

#define NLEP_DETECT_GENDER                     10451
#define NLEP_GENDER_CONFIDENCE_THRESHOLD       10452
#define NLEP_DETECT_GLASSES                    10453
#define NLEP_GLASSES_CONFIDENCE_THRESHOLD      10454
#define NLEP_DETECT_DARK_GLASSES               10455
#define NLEP_DARK_GLASSES_CONFIDENCE_THRESHOLD 10456
#define NLEP_DETECT_EXPRESSION                 10457
#define NLEP_EXPRESSION_CONFIDENCE_THRESHOLD   10458
#define NLEP_DETECT_BLINK                      10459
#define NLEP_BLINK_CONFIDENCE_THRESHOLD        10460
#define NLEP_DETECT_MOUTH_OPEN                 10461
#define NLEP_MOUTH_OPEN_CONFIDENCE_THRESHOLD   10462

#define NLEP_DETECT_EMOTION                    10471

typedef enum NleTemplateSize_
{
	nletsSmall = 0,
	nletsCompact = 1,
	nletsMedium = 64,
	nletsLarge = 128,
} NleTemplateSize;

N_DECLARE_TYPE(NleTemplateSize)

#ifdef N_CPP
}
#endif

#endif // !NL_EXTRACTOR_PARAMS_H_INCLUDED
