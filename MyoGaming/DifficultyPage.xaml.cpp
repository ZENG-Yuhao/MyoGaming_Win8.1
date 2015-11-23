//
// DifficultyPage.xaml.cpp
// Implementation of the DifficultyPage class
//

#include "pch.h"
#include "DifficultyPage.xaml.h"
#include "GamePage.xaml.h"
#include "gamepage_var.h"
#include "NewgamePage.xaml.h"

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

DifficultyPage::DifficultyPage()
{
	InitializeComponent();
}

void MyoGaming::DifficultyPage::btn_normal_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GameDifficulty = NORMAL;
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(GamePage::typeid));
}

void MyoGaming::DifficultyPage::btn_nightmare_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GameDifficulty = NIGHTMARE;
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(GamePage::typeid));
}


void MyoGaming::DifficultyPage::btn_hell_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GameDifficulty = HELL;
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(GamePage::typeid));
}


void MyoGaming::DifficultyPage::btn_back_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(NewgamePage::typeid));
}
