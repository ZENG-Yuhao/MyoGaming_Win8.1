//
// DifficultyPage.xaml.h
// Declaration of the DifficultyPage class
//

#pragma once

#include "DifficultyPage.g.h"

namespace MyoGaming
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class DifficultyPage sealed
	{
	public:
		DifficultyPage();
	private:
		void btn_nightmare_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btn_normal_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btn_hell_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void btn_back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
