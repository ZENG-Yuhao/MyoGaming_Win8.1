//
// RecordPage.xaml.h
// Declaration of the RecordPage class
//

#pragma once

#include "RecordPage.g.h"
#include "recorder_var.h"
#include "FileManager.h"
namespace MyoGaming
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class RecordPage sealed
	{
	public:
		RecordPage();
		void btn_test_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	internal:	
		property FileManager* Fmngr {
			void set(FileManager* value)
			{
				fmngr = value;
			}

			FileManager* get()
			{
				return fmngr;
			}
		}
	private:
		FileManager* fmngr;
	};
}
