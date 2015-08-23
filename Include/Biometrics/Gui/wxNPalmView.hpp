#include <Biometrics/Gui/wxNFrictionRidgeView.hpp>

#ifndef WX_NPALMVIEW_HPP_INCLUDED
#define WX_NPALMVIEW_HPP_INCLUDED

#include <Biometrics/NPalm.hpp>

namespace Neurotec { namespace Biometrics { namespace Gui
{

class wxNPalmView : public wxNFrictionRidgeView
{
public:
	wxNPalmView(wxWindow *parent, wxWindowID winid = wxID_ANY)
		: wxNFrictionRidgeView(parent, winid)
	{
	}

	void SetPalm(const ::Neurotec::Biometrics::NPalm & palm)
	{
		if (palm.IsNull())
		{
			Clear();
		}
		else
		{
			SetFrictionRidge(NObjectDynamicCast<NFrictionRidge>(palm));
		}
	}

	::Neurotec::Biometrics::NPalm GetPalm()
	{
		return GetFrictionRidge().GetHandle();
	}
};

}}}

#endif // !WX_NPALMVIEW_HPP_INCLUDED
