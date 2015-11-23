//
// NewgamePage.xaml.cpp
// Implementation of the NewgamePage class
//

#include "pch.h"
#include "NewgamePage.xaml.h"
#include "DifficultyPage.xaml.h"
#include "gamepage_var.h"
#include "NavigatorPage.xaml.h"
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

NewgamePage::NewgamePage()
{
	InitializeComponent();
}


void MyoGaming::NewgamePage::btn_classic_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GameMode = CLASSIC;
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(DifficultyPage::typeid));
}


void MyoGaming::NewgamePage::btn_timelimited_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GameMode = TIME_LIMITED;
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(DifficultyPage::typeid));
}


void MyoGaming::NewgamePage::StackPanel_DataContextChanged(Windows::UI::Xaml::FrameworkElement^ sender, Windows::UI::Xaml::DataContextChangedEventArgs^ args)
{
		
}


void MyoGaming::NewgamePage::btn_back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(NavigatorPage::typeid));
}
