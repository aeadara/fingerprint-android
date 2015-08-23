#ifndef N_GUI_LIBRARY_HPP_INCLUDED
#define N_GUI_LIBRARY_HPP_INCLUDED

#include <Core/NTypes.hpp>
#ifdef N_FRAMEWORK_WX
#include <Gui/wxNView.hpp>
#include <Gui/wxAboutBox.hpp>
#include <Gui/wxExceptionDlg.hpp>
#include <Gui/wxPluginManagerDlg.hpp>
#include <Gui/wxNViewZoomSlider.hpp>
#endif
#ifdef N_FRAMEWORK_QT
#include <Gui/QPluginManagerDialog.hpp>
#include <Gui/QAboutBox.hpp>
#include <Gui/QNView.hpp>
#endif

#endif // !N_GUI_LIBRARY_HPP_INCLUDED
