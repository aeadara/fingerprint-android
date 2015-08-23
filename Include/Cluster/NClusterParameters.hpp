#ifndef N_CLUSTER_PARAMETERS_HPP_INCLUDED
#define N_CLUSTER_PARAMETERS_HPP_INCLUDED

#include <Core/NTypes.hpp>
#include <vector>

namespace Neurotec { namespace Cluster
{
#include <NCluster.h>
}}

#define SwapNUInt32(x) \
	(NUInt32) \
	(((x & 0xFF000000) >> 24) | \
	  ((x & 0x00FF0000) >> 8) | \
	  ((x & 0x0000FF00) << 8)  | \
	  ((x & 0x000000FF) << 24))

#define SwapNUInt64(x) ((NUInt64)(((NUInt64)SwapNUInt32(x) << 32) | SwapNUInt32((x) >> 32)))

namespace Neurotec { namespace Cluster
{
	class MParameter
	{
	public:
		NUInt32 part;
		NUInt32 id;
		NUInt64 value;
		MParameter(NUInt32 part, NUInt32 id, NUInt64 value)
		{
			const int num = 1;
			bool isBigEndian = (*(char*)&num == 1);

			this->part = isBigEndian? SwapNUInt32(part) : part;
			this->id = isBigEndian? SwapNUInt32(id) : id;
			this->value = isBigEndian? SwapNUInt64(value) : value;
		}
	} ;
	class MatchingParameters
	{
	private:
		std::vector<MParameter*> parameters;

	public:
		MatchingParameters()
		{
		}

		void AddParameter(NUInt32 part, NUInt32 id, NByte value)
		{
			NUInt64 fixed_value = ((NUInt64)value);
			parameters.push_back(new MParameter(part, id, fixed_value));
		}

		void AddParameter(NUInt32 part, NUInt32 id, NShort value)
		{
			NUInt64 fixed_value = ((NUInt64)value);
			parameters.push_back(new MParameter(part, id, fixed_value));
		}

		void AddParameter(NUInt32 part, NUInt32 id, NUInt16 value)
		{
			NUInt64 fixed_value = ((NUInt64)value);
			parameters.push_back(new MParameter(part, id, fixed_value));
		}

		void AddParameter(NUInt32 part, NUInt32 id, NInt32 value)
		{
			NUInt64 fixed_value = ((NUInt64)value);
			parameters.push_back(new MParameter(part, id, fixed_value));
		}

		void AddParameter(NUInt32 part, NUInt32 id, NUInt32 value)
		{
			NUInt64 fixed_value = ((NUInt64)value);
			parameters.push_back(new MParameter(part, id, fixed_value));
		}

		void AddParameter(NUInt32 part, NUInt32 id, NUInt64 value)
		{
			parameters.push_back(new MParameter(part, id, value));
		}

		void AddParameter(NUInt32 part, NUInt32 id, bool value)
		{
			parameters.push_back(new MParameter(part, id, value ? 1 : 0));
		}

		void AddParameter(NUInt32 part, NUInt32 id, NDouble value)
		{
			NUInt64 * fixed_value = (NUInt64 *)&value;
			AddParameter(part, id, *fixed_value);
		}

		void AddParameter(NUInt32 id, NByte value)
		{
			AddParameter(0, id, value);
		}

		void AddParameter(NUInt32 id, NShort value)
		{
			AddParameter(0, id, value);
		}

		void AddParameter(NUInt32 id, NUShort value)
		{
			AddParameter(0, id, value);
		}

		void AddParameter(NUInt32 id, NInt32 value)
		{
			AddParameter(0, id, value);
		}

		void AddParameter(NUInt32 id, NUInt32 value)
		{
			AddParameter(0, id, value);
		}

		void AddParameter(NUInt32 id, NUInt64 value)
		{
			AddParameter(0, id, value);
		}

		void AddParameter(NUInt32 id, NDouble value)
		{
			AddParameter(0, id, value);
		}

		void AddParameter(NUInt32 id, bool value)
		{
			AddParameter(0, id, value);
		}

		void GetBuffer(void ** buffer, NSizeType * bufferSize)
		{
			size_t size = parameters.size() * 16;
			*buffer = NAlloc(size);
			char * pos = (char *)*buffer;
			for (std::vector<MParameter *>::const_iterator param = parameters.begin(); param != parameters.end(); param ++)
			{
				NUInt32 * val = (NUInt32 *)pos;
				*val = (*param)->part;
				pos += 4;
				val = (NUInt32 *)pos;
				*val = (*param)->id;
				pos += 4;
				NUInt64 * val64 = (NUInt64 *)pos;
				*val64 = (*param)->value;
				pos += 8;
			}
			*bufferSize = size;
		}

	};

}}

#undef SwapNUInt64
#undef SwapNUInt32

#endif // !N_CLUSTER_PARAMETERS_HPP_INCLUDED
