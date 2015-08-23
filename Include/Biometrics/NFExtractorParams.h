#ifndef NF_EXTRACTOR_PARAMS_H_INCLUDED
#define NF_EXTRACTOR_PARAMS_H_INCLUDED

#include <Core/NParameters.h>

#ifdef N_CPP
extern "C"
{
#endif


#define NFEP_TEMPLATE_SIZE          100
#define NFEP_EXTRACT_QUALITIES      111
#define NFEP_EXTRACT_CURVATURES     112
#define NFEP_EXTRACT_GS             113
#define NFEP_MIN_MINUTIA_COUNT      119
#define NFEP_EXTRACTED_RIDGE_COUNTS 120
#define NFEP_RETURNED_IMAGE         190

#define NFEP_USE_QUALITY       900
#define NFEP_QUALITY_THRESHOLD 910

#define NFEP_GENERALIZATION_THRESHOLD         300
#define NFEP_GENERALIZATION_MAXIMAL_ROTATION  301
#define NFEP_GENERALIZATION_MIN_MINUTIA_COUNT 319

#define NFEP_MODE 1000
	#define NFE_MODE_GENERAL                           0
	#define NFE_MODE_DIGITALPERSONA_UAREU            100
	#define NFE_MODE_BIOMETRIKA_FX2000               200
	#define NFE_MODE_BIOMETRIKA_FX3000               201
	#define NFE_MODE_KEYTRONIC_SECUREDESKTOP         300
	#define NFE_MODE_IDENTIX_TOUCHVIEW               400
	#define NFE_MODE_IDENTIX_DFR2090                 401
	#define NFE_MODE_PRECISEBIOMETRICS_100CS         500
	#define NFE_MODE_UPEK_TOUCHCHIP                  600
	#define NFE_MODE_IDENTICATORTECHNOLOGY_DF90      700
	#define NFE_MODE_AUTHENTEC_AFS2                  800
	#define NFE_MODE_AUTHENTEC_AES4000               810
	#define NFE_MODE_AUTHENTEC_AES2501B              811
	#define NFE_MODE_ATMEL_FINGERCHIP                900
	#define NFE_MODE_BMF_BLP100                     1000
	#define NFE_MODE_SECUGEN_HAMSTER                1100
	#define NFE_MODE_ETHENTICA                      1200
	#define NFE_MODE_CROSSMATCH_VERIFIER300         1300
	#define NFE_MODE_NITGEN_FINGKEY_HAMSTER         1400
	#define NFE_MODE_TESTECH_BIOI                   1500
	#define NFE_MODE_DIGENT_IZZIX                   1600
	#define NFE_MODE_STARTEK_FM200                  1700
	#define NFE_MODE_FUJITSU_MBF200                 1800
	#define NFE_MODE_FUTRONIC_FS80                  1900
	#define NFE_MODE_LIGHTUNING_LTTC500             2000
	#define NFE_MODE_TACOMA_CMOS                    2100

typedef enum NfeReturnedImage_
{
	nferiNone = 0,
	nferiBinarized = 1,
	nferiSkeletonized = 2
} NfeReturnedImage;

N_DECLARE_TYPE(NfeReturnedImage)

typedef enum NfeTemplateSize_
{
	nfetsSmall = 0,
	nfetsSmallMedium = 64,
	nfetsLargeMedium = 128,
	nfetsLarge = 256
} NfeTemplateSize;

N_DECLARE_TYPE(NfeTemplateSize)

#ifdef N_CPP
}
#endif

#endif // !NF_EXTRACTOR_PARAMS_H_INCLUDED
