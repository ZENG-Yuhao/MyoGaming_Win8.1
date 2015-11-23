//
// NavigatorPage.xaml.cpp
// Implementation of the NavigatorPage class
//

#include "pch.h"
#include "NavigatorPage.xaml.h"
#include "GuidePage.xaml.h"
#include "NewgamePage.xaml.h"
#include "RecordPage.xaml.h"
#include "MainPage.xaml.h"

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

NavigatorPage::NavigatorPage()
{
	InitializeComponent();
}


void MyoGaming::NavigatorPage::btn_newgame_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(NewgamePage::typeid));
}


void MyoGaming::NavigatorPage::btn_record_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(RecordPage::typeid));
}


void MyoGaming::NavigatorPage::btn_guide_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(GuidePage::typeid));
}


void MyoGaming::NavigatorPage::btn_back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(MainPage::typeid));
}
