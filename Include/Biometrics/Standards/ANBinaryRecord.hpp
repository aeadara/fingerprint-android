#ifndef AN_BINARY_RECORD_HPP_INCLUDED
#define AN_BINARY_RECORD_HPP_INCLUDED

#include <Biometrics/Standards/ANRecord.hpp>
namespace Neurotec { namespace Biometrics { namespace Standards
{
#include <Biometrics/Standards/ANBinaryRecord.h>
}}}

namespace Neurotec { namespace Biometrics { namespace Standards
{

class ANBinaryRecord : public ANRecord
{
	N_DECLARE_OBJECT_CLASS(ANBinaryRecord, ANRecord)
};

}}}

#endif // !AN_BINARY_RECORD_HPP_INCLUDED
