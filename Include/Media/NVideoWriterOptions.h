#ifndef N_VIDEO_WRITER_OPTIONS_H_INCLUDED
#define N_VIDEO_WRITER_OPTIONS_H_INCLUDED

#include <Core/NObject.h>

#ifdef N_CPP
extern "C"
{
#endif

/* \brief A handle of information about video codec.

This handle is allocated by calling #NVideoChooseCompression function with 
appropriate parameters. This handle can be associated with created video file later on by calling
#NVideoSetCompression function. When writing to the file is done this handle can be freed by 
calling #NVideoFreeCompression function. If this function is called between #NVideoSetCompression 
and #NVideoWriterClose functions expect unexpected behaviour.

*/
N_DECLARE_OBJECT_TYPE(NVideoWriterOptions, NObject)

/* \brief Opens a dialog box allowing to choose a compressor for video file.

\param[in] hParentWnd A Windows Window handle. This handle will be used as parent window for a dialog box.
*/
NResult N_API NVideoWriterOptionsCreateWithGui(NHandle hParentWnd, HNVideoWriterOptions * phOptions);


#ifdef N_CPP
}
#endif

#endif // !N_VIDEO_WRITER_OPTIONS_H_INCLUDED
