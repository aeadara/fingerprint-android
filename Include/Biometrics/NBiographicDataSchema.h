#ifndef N_BIOGRAPHIC_DATA_SCHEMA_H_INCLUDED
#define N_BIOGRAPHIC_DATA_SCHEMA_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

typedef enum NDBType_
{
	ndbtNone = 0,
	ndbtString = 1,
	ndbtInteger = 2,
	ndbtBlob = 4,
} NDBType;

N_DECLARE_TYPE(NDBType)

struct NBiographicDataElement_
{
	HNString hName;
	HNString hDbColumn;
	NDBType dbType;
};
#ifndef N_BIOGRAPHIC_DATA_SCHEMA_HPP_INCLUDED
typedef struct NBiographicDataElement_ NBiographicDataElement;
#endif
N_DECLARE_TYPE(NBiographicDataElement)

NResult N_API NBiographicDataElementCreateN(HNString hName, HNString hDbColumn, NDBType type, struct NBiographicDataElement_ * pValue);
#ifndef N_NO_ANSI_FUNC
NResult N_API NBiographicDataElementCreateA(const NAChar * szName, const NAChar * szDbColumn, NDBType type, struct NBiographicDataElement_ * pValue);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBiographicDataElementCreateW(const NWChar * szName, const NWChar * szDbColumn, NDBType type, struct NBiographicDataElement_ * pValue);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBiographicDataElementCreate(const NChar * szName, const NChar * szDbColumn, NDBType type, NBiographicDataElement_ * pValue);
#endif
#define NBiographicDataElementCreate N_FUNC_AW(NBiographicDataElementCreate)

NResult N_API NBiographicDataElementDispose(struct NBiographicDataElement_ * pValue);
NResult N_API NBiographicDataElementCopy(const struct NBiographicDataElement_ * pSrcValue, struct NBiographicDataElement_ * pDstValue);
NResult N_API NBiographicDataElementSet(const struct NBiographicDataElement_ * pSrcValue, struct NBiographicDataElement_ * pDstValue);

N_DECLARE_OBJECT_TYPE(NBiographicDataSchema, NObject)

NResult N_API NBiographicDataSchemaCreate(HNBiographicDataSchema * phBiographicSchema);

NResult N_API NBiographicDataSchemaTryParseN(HNString hValue, HNString hFormat, HNBiographicDataSchema * phSchema, NBool * pResult);
#ifndef N_NO_ANSI_FUNC
NResult N_API NBiographicDataSchemaTryParseA(const NAChar * szValue, const NAChar * szFormat, HNBiographicDataSchema * phSchema, NBool * pResult);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBiographicDataSchemaTryParseW(const NWChar * szValue, const NWChar * szFormat, HNBiographicDataSchema * phSchema, NBool * pResult);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBiographicDataSchemaTryParse(const NChar * szValue, const NChar * szFormat, HNBiographicDataSchema * phSchema, NBool * pResult);
#endif
#define NBiographicDataSchemaTryParse N_FUNC_AW(NBiographicDataSchemaTryParse)

NResult N_API NBiographicDataSchemaParseN(HNString hValue, HNString hFormat, HNBiographicDataSchema * phSchema);
#ifndef N_NO_ANSI_FUNC
NResult N_API NBiographicDataSchemaParseA(const NAChar * szValue, const NAChar * szFormat, HNBiographicDataSchema * phSchema);
#endif
#ifndef N_NO_UNICODE
NResult N_API NBiographicDataSchemaParseW(const NWChar * szValue, const NWChar * szFormat, HNBiographicDataSchema * phSchema);
#endif
#ifdef N_DOCUMENTATION
NResult N_API NBiographicDataSchemaParse(const NChar * szValue, const NChar * szFormat, HNBiographicDataSchema * phSchema);
#endif
#define NBiographicDataSchemaParse N_FUNC_AW(NBiographicDataSchemaParse)

NResult N_API NBiographicDataSchemaGetElementCount(HNBiographicDataSchema hSchema, NInt * pValue);
NResult N_API NBiographicDataSchemaGetElement(HNBiographicDataSchema hSchema, NInt index, struct NBiographicDataElement_ * pValue);
NResult N_API NBiographicDataSchemaGetElements(HNBiographicDataSchema hSchema, struct NBiographicDataElement_ * * parValues, NInt * pValueCount);
NResult N_API NBiographicDataSchemaGetElementCapacity(HNBiographicDataSchema hSchema, NInt * pValue);
NResult N_API NBiographicDataSchemaSetElementCapacity(HNBiographicDataSchema hSchema, NInt value);
NResult N_API NBiographicDataSchemaSetElement(HNBiographicDataSchema hSchema, NInt index, const struct NBiographicDataElement_ * pValue);
NResult N_API NBiographicDataSchemaAddElement(HNBiographicDataSchema hSchema, const struct NBiographicDataElement_ * pValue, NInt * pIndex);
NResult N_API NBiographicDataSchemaInsertElement(HNBiographicDataSchema hSchema, NInt index, const struct NBiographicDataElement_ * pValue);
NResult N_API NBiographicDataSchemaRemoveElementAt(HNBiographicDataSchema hSchema, NInt index);
NResult N_API NBiographicDataSchemaClearElements(HNBiographicDataSchema hSchema);

#ifdef N_CPP
}
#endif

#endif // !N_BIOGRAPHIC_DATA_SCHEMA_H_INCLUDED
