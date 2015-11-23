//
// FilerwPage.xaml.h
// Declaration of the FilerwPage class
//

#pragma once

#include "FilerwPage.g.h"

namespace MyoGaming
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class FilerwPage sealed
	{
	public:
		FilerwPage();
		property Windows::Storage::StorageFile^ FileRec
		{
			Windows::Storage::StorageFile^ get()
			{
				return fileRec;
			}
			void set(Windows::Storage::StorageFile^ value)
			{
				fileRec = value;
			}
		}

		property Platform::String^ FileContent
		{
			Platform::String^ get()
			{
				return fileContent;
			}
			void set(Platform::String^ value)
			{
				fileContent = value;
			}
		}
	private:
		void btnW_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		Windows::Storage::StorageFile^ fileRec;
		Platform::String^ fileContent;

		void btnR_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
