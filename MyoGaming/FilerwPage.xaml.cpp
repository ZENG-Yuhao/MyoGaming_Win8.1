//
// FilerwPage.xaml.cpp
// Implementation of the FilerwPage class
//

#include "pch.h"
#include "FilerwPage.xaml.h"

using namespace MyoGaming;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace concurrency;
using namespace Windows::Storage;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

FilerwPage::FilerwPage()
{
	InitializeComponent();
}


void MyoGaming::FilerwPage::btnW_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	create_task(KnownFolders::PicturesLibrary->CreateFileAsync("MyoRecord.dat", CreationCollisionOption::ReplaceExisting)).then([this](StorageFile^ file)
	{
		FileRec = file;
	});
	Windows::Storage::StorageFile^ filerec = FileRec;
	if (filerec != nullptr)
	{
		String^ userContent = "asshole";
		txtbox->Text = filerec->DisplayName;
		//if (userContent != nullptr && !userContent->IsEmpty())
		//{
		create_task(FileIO::WriteTextAsync(filerec, "asshole you enzo")).then([this, filerec, userContent](task<void> task)
		{
			try
			{
				task.get();

			}
			catch (COMException^ ex)
			{

			}
		});
		//}
	}
}


void MyoGaming::FilerwPage::btnR_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	StorageFile^ file = FileRec;
	if (file != nullptr)
	{
		create_task(FileIO::ReadTextAsync(file)).then([this, file](task<String^> task)
		{
			try
			{
				FileContent = task.get();

			}
			catch (COMException^ ex)
			{

			}
		});
	}
	else
	{

	}
	txtblock->Text = FileContent;
}
