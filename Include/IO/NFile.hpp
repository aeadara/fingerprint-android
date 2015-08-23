#ifndef N_FILE_HPP_INCLUDED
#define N_FILE_HPP_INCLUDED

#include <IO/NFileStream.hpp>
#include <IO/NStreamReader.hpp>
#include <IO/NStreamWriter.hpp>
namespace Neurotec { namespace IO
{
#include <IO/NFile.h>
}}

N_DEFINE_ENUM_TYPE_TRAITS(Neurotec::IO, NFileAttributes)

namespace Neurotec { namespace IO
{

class NFile
{
	N_DECLARE_STATIC_OBJECT_CLASS(NFile)

public:
	static NFileAttributes GetAttributes(const NStringWrapper & path)
	{
		NFileAttributes value;
		NCheck(NFileGetAttributesN(path.GetHandle(), &value));
		return value;
	}

	static bool Exists(const NStringWrapper & path)
	{
		NBool value;
		NCheck(NFileExistsN(path.GetHandle(), &value));
		return value != 0;
	}

	static void Delete(const NStringWrapper & path)
	{
		NCheck(NFileDeleteN(path.GetHandle()));
	}

	static NFileStream Open(const NStringWrapper & path, NFileMode mode)
	{
		HNFileStream hValue;
		NCheck(NFileOpenN(path.GetHandle(), mode, &hValue));
		return NObject::FromHandle<NFileStream>(hValue);
	}

	static NFileStream Open(const NStringWrapper & path, NFileMode mode, NFileAccess access)
	{
		HNFileStream hValue;
		NCheck(NFileOpenWithAccessN(path.GetHandle(), mode, access, &hValue));
		return NObject::FromHandle<NFileStream>(hValue);
	}

	static NFileStream Open(const NStringWrapper & path, NFileMode mode, NFileAccess access, NFileShare share)
	{
		HNFileStream hValue;
		NCheck(NFileOpenWithAccessAndShareN(path.GetHandle(), mode, access, share, &hValue));
		return NObject::FromHandle<NFileStream>(hValue);
	}

	static NFileStream Create(const NStringWrapper & path)
	{
		HNFileStream hValue;
		NCheck(NFileCreateN(path.GetHandle(), &hValue));
		return NObject::FromHandle<NFileStream>(hValue);
	}

	static NFileStream Create(NSizeType bufferSize, const NStringWrapper & path)
	{
		HNFileStream hValue;
		NCheck(NFileCreateWithBufferSizeN(path.GetHandle(), bufferSize, &hValue));
		return NObject::FromHandle<NFileStream>(hValue);
	}

	static NFileStream OpenRead(const NStringWrapper & path)
	{
		HNFileStream hValue;
		NCheck(NFileOpenReadN(path.GetHandle(), &hValue));
		return NObject::FromHandle<NFileStream>(hValue);
	}

	static NFileStream OpenWrite(const NStringWrapper & path)
	{
		HNFileStream hValue;
		NCheck(NFileOpenWriteN(path.GetHandle(), &hValue));
		return NObject::FromHandle<NFileStream>(hValue);
	}

	static NBuffer ReadAllBytes(const NStringWrapper & path)
	{
		HNBuffer hValue;
		NCheck(NFileReadAllBytesN(path.GetHandle(), &hValue));
		return NObject::FromHandle<NBuffer>(hValue);
	}

	static void WriteAllBytes(const NStringWrapper & path, const NBuffer & content)
	{
		NCheck(NFileWriteAllBytesN(path.GetHandle(), content.GetHandle()));
	}

	static void WriteAllBytes(const NStringWrapper & path, const void * pContent, NSizeType contentLength)
	{
		if (!pContent) NThrowArgumentNullException(N_T("pContent"));
		NCheck(NFileWriteAllBytesPN(path.GetHandle(), pContent, contentLength));
	}

	static NStreamReader OpenText(const NStringWrapper & path)
	{
		HNStreamReader hValue;
		NCheck(NFileOpenTextN(path.GetHandle(), &hValue));
		return NObject::FromHandle<NStreamReader>(hValue);
	}

	static NStreamWriter AppendText(const NStringWrapper & path)
	{
		HNStreamWriter hValue;
		NCheck(NFileAppendTextN(path.GetHandle(), &hValue));
		return NObject::FromHandle<NStreamWriter>(hValue);
	}

	static NStreamWriter CreateText(const NStringWrapper & path)
	{
		HNStreamWriter hValue;
		NCheck(NFileCreateTextN(path.GetHandle(), &hValue));
		return NObject::FromHandle<NStreamWriter>(hValue);
	}

	static NArrayWrapper<NString> ReadAllLines(const NStringWrapper & path)
	{
		HNString * arhContent;
		NInt contentLength;
		NCheck(NFileReadAllLinesN(path.GetHandle(), &arhContent, &contentLength));
		return NArrayWrapper<NString>(arhContent, contentLength);
	}

	static NArrayWrapper<NString> ReadAllLines(const NStringWrapper & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks = true)
	{
		HNString * arhContent;
		NInt contentLength;
		NCheck(NFileReadAllLinesWithEncodingN(path.GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, &arhContent, &contentLength));
		return NArrayWrapper<NString>(arhContent, contentLength);
	}

	static NString ReadAllText(const NStringWrapper & path)
	{
		HNString hContent;
		NCheck(NFileReadAllTextN(path.GetHandle(), &hContent));
		return NString(hContent, true);
	}

	static NString ReadAllText(const NStringWrapper & path, NEncoding encoding, bool detectEncodingFromByteOrderMarks = true)
	{
		HNString hContent;
		NCheck(NFileReadAllTextWithEncodingN(path.GetHandle(), encoding, detectEncodingFromByteOrderMarks ? NTrue : NFalse, &hContent));
		return NString(hContent, true);
	}

	static void AppendAllLines(const NStringWrapper & path, const NString * arContent, NInt contentLength)
	{
		NCheck(NFileAppendAllLinesN(path.GetHandle(), reinterpret_cast<const HNString *>(arContent), contentLength));
	}

	static void AppendAllLines(const NStringWrapper & path, const NChar * * arszContent, NInt contentLength)
	{
		NCheck(NFileAppendAllLinesPN(path.GetHandle(), arszContent, contentLength));
	}

	static void AppendAllLines(const NStringWrapper & path, const NString * arContent, NInt contentLength, NEncoding encoding)
	{
		NCheck(NFileAppendAllLinesWithEncodingN(path.GetHandle(), reinterpret_cast<const HNString *>(arContent), contentLength, encoding));
	}

	static void AppendAllLines(const NStringWrapper & path, const NChar * * arszContent, NInt contentLength, NEncoding encoding)
	{
		NCheck(NFileAppendAllLinesWithEncodingPN(path.GetHandle(), arszContent, contentLength, encoding));
	}

	static void AppendAllText(const NStringWrapper & path, const NString & content)
	{
		NCheck(NFileAppendAllTextN(path.GetHandle(), content.GetHandle()));
	}

	static void AppendAllText(const NStringWrapper & path, const NString & content, NEncoding encoding)
	{
		NCheck(NFileAppendAllTextWithEncodingN(path.GetHandle(), content.GetHandle(), encoding));
	}

	static void WriteAllLines(const NStringWrapper & path, const NString * arContent, NInt contentLength)
	{
		NCheck(NFileWriteAllLinesN(path.GetHandle(), reinterpret_cast<const HNString *>(arContent), contentLength));
	}

	static void WriteAllLines(const NStringWrapper & path, const NChar * * arszContent, NInt contentLength)
	{
		NCheck(NFileWriteAllLinesPN(path.GetHandle(), arszContent, contentLength));
	}

	static void WriteAllLines(const NStringWrapper & path, const NString * arContent, NInt contentLength, NEncoding encoding)
	{
		NCheck(NFileWriteAllLinesWithEncodingN(path.GetHandle(), reinterpret_cast<const HNString *>(arContent), contentLength, encoding));
	}

	static void WriteAllLines(const NStringWrapper & path, const NChar * * arszContent, NInt contentLength, NEncoding encoding)
	{
		NCheck(NFileWriteAllLinesWithEncodingPN(path.GetHandle(), arszContent, contentLength, encoding));
	}

	static void WriteAllText(const NStringWrapper & path, const NString & content)
	{
		NCheck(NFileWriteAllTextN(path.GetHandle(), content.GetHandle()));
	}

	static void WriteAllText(const NStringWrapper & path, const NString & content, NEncoding encoding)
	{
		NCheck(NFileWriteAllTextWithEncodingN(path.GetHandle(), content.GetHandle(), encoding));
	}
};

}}

#endif // !N_FILE_HPP_INCLUDED
