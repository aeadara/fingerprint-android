#ifndef N_VIDEO_WRITER_OPTIONS_HPP_INCLUDED
#define N_VIDEO_WRITER_OPTIONS_HPP_INCLUDED

#include <Core/NObject.hpp>
namespace Neurotec { namespace Video
{
#include <Media/NVideoWriterOptions.h>
}}

#if defined(N_FRAMEWORK_WX)
#include <wx/window.h>
#elif defined(N_FRAMEWORK_MFC)
#include <afxwin.h>
#endif

namespace Neurotec { namespace Video
{

class NVideoWriterOptions : public NObject
{
	N_DECLARE_OBJECT_CLASS(NVideoWriterOptions, NObject)

private:
	static HNVideoWriterOptions Create(NHandle hParent)
	{
		HNVideoWriterOptions handle;
		NCheck(NVideoWriterOptionsCreateWithGui(hParent, &handle));
		return handle;
	}

#if defined(N_FRAMEWORK_WX)
	static HNVideoWriterOptions Create(const wxWindow * pParent)
	{
		if (!pParent) NThrowArgumentNullException(N_T("pParent"));
		return Create((NHandle)pParent->GetHandle());
	}
#elif defined(N_FRAMEWORK_MFC)
	static HNVideoWriterOptions Create(const CWnd * pParent)
	{
		if (!pParent) NThrowArgumentNullException(N_T("pParent"));
		return Create((NHandle)pParent->GetSafeHwnd());
	}
#endif

public:
#ifdef N_WINDOWS
	NVideoWriterOptions(HWND parent)
		: NObject(Create((NHandle)parent), true)
	{
	}
#endif

#if defined(N_FRAMEWORK_WX)
	explicit NVideoWriterOptions(const wxWindow * pParent)
		: NObject(Create(pParent), true)
	{
	}
#elif defined(N_FRAMEWORK_MFC)
	explicit NVideoWriterOptions(const CWnd * pParent)
		: NObject(Create(pParent), true)
	{
	}
#endif
};

}}

#endif // !N_VIDEO_WRITER_OPTIONS_HPP_INCLUDED
