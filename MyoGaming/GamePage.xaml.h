//
// GamePage.xaml.h
// Declaration of the GamePage class
//

#pragma once

#include "GamePage.g.h"

namespace MyoGaming
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class GamePage sealed
	{
	public:
		GamePage();
	internal:
		property Windows::Foundation::Uri^ Uri {
			Windows::Foundation::Uri^ get()
			{
				return uri;
			}
			void set(Windows::Foundation::Uri^ value)
			{
				uri = value;
			}
		}

		property Windows::UI::Xaml::Media::Imaging::BitmapImage^ BitmapImage {
			Windows::UI::Xaml::Media::Imaging::BitmapImage^ get()
			{
				return bitmapImage;
			}
			void set(Windows::UI::Xaml::Media::Imaging::BitmapImage^ value)
			{
				bitmapImage = value;
			}
		}
	private:
		void submit(int value);
		void UI_Update();
		void PointerIsBack();
		void GameStart();
		void initTimer();
		void deleteTimer();
		void OnTick(Object ^ sender, Object ^ e);
		void GameEnd();
		void ctr_up_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void ctr_down_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void ctr_left_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void ctr_right_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void pnl_display_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void btn_exit_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		Windows::Foundation::Uri^ uri;
		Windows::UI::Xaml::Media::Imaging::BitmapImage^ bitmapImage;
		void btn_start_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
