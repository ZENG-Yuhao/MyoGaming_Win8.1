//
// RecordPage.xaml.cpp
// Implementation of the RecordPage class
//

#include "pch.h"
#include "RecordPage.xaml.h"
#include "FileManager.h"
#include "recorder_var.h"

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

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

RecordPage::RecordPage()
{

	InitializeComponent(); 
	fileManager->CreateFile(fileName);
	txt_content->Text = fileManager->ReadFromFile();


}

void RecordPage::btn_test_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	//Fmngr = new FileManager();
	//Fmngr->CreateFile("HappyHappy.dat");
	//Fmngr->WriteToFile("HappyNMB");
	//fileManager->CreateFile("HappyHappyHappy.dat");
	//fileManager->WriteToFile("HappyNMMMP");
	txt_content->Text = fileManager->ReadFromFile();
}

