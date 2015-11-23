//
// GuidePage.xaml.h
// Declaration of the GuidePage class
//

#pragma once

#include "GuidePage.g.h"

namespace MyoGaming
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class GuidePage sealed
	{
	public:
		GuidePage();
	private:
		void btn_back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
