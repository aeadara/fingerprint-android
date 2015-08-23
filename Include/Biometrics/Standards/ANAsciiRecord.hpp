#ifndef AN_ASCII_RECORD_HPP_INCLUDED
#define AN_ASCII_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANAsciiRecord.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

#undef AN_ASCII_RECORD_MAX_FIELD_NUMBER

const NInt AN_ASCII_RECORD_MAX_FIELD_NUMBER = 999999999;

class ANAsciiRecord : public ANRecord
{
	N_DECLARE_OBJECT_CLASS(ANAsciiRecord, ANRecord)
};

}}}

#endif // !AN_ASCII_RECORD_HPP_INCLUDED
