#include <Biometrics/Gui/wxNFrictionRidgeView.hpp>

#ifndef WX_NFINGERVIEW_HPP_INCLUDED
#define WX_NFINGERVIEW_HPP_INCLUDED

#include <Biometrics/NFinger.hpp>

namespace Neurotec { namespace Biometrics { namespace Gui
{

class wxNFingerView : public wxNFrictionRidgeView
{
public:
	wxNFingerView(wxWindow *parent, wxWindowID winid = wxID_ANY)
		: wxNFrictionRidgeView(parent, winid)
	{
	}

	void SetFinger(const ::Neurotec::Biometrics::NFinger & finger)
	{
		if (finger.IsNull())
		{
			Clear();
		}
		else
		{
			SetFrictionRidge(NObjectDynamicCast<NFrictionRidge>(finger));
		}
	}

	::Neurotec::Biometrics::NFinger GetFinger()
	{
		return GetFrictionRidge().GetHandle();
	}
};

}}}

#endif // !WX_NFINGERVIEW_HPP_INCLUDED
