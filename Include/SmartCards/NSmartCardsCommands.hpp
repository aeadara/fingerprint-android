#ifndef N_SMART_CARDS_COMMANDS_HPP_INCLUDED
#define N_SMART_CARDS_COMMANDS_HPP_INCLUDED

#include <SmartCards/ApduClass.hpp>
#include <SmartCards/ApduInstruction.hpp>
#include <SmartCards/ApduStatus.hpp>
#include <IO/NBuffer.hpp>
namespace Neurotec { namespace SmartCards
{
#include <SmartCards/NSmartCardsCommands.h>
}}

namespace Neurotec { namespace SmartCards
{

class NSmartCardsCommands
{
	N_DECLARE_STATIC_OBJECT_CLASS(NSmartCardsCommands)
};

}}

#endif // !N_SMART_CARDS_COMMANDS_HPP_INCLUDED
