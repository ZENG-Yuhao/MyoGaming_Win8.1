//
// NewgamePage.xaml.h
// Declaration of the NewgamePage class
//

#pragma once

#include "NewgamePage.g.h"

namespace MyoGaming
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NewgamePage sealed
	{
	public:
		NewgamePage();
	private:
		void btn_classic_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btn_timelimited_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void StackPanel_DataContextChanged(Windows::UI::Xaml::FrameworkElement^ sender, Windows::UI::Xaml::DataContextChangedEventArgs^ args);
		void btn_back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
