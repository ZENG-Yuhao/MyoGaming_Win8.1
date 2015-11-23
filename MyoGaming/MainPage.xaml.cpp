//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "timer_var.h"
#include "gamepage_var.h"
#include "NavigatorPage.xaml.h"
#include <iostream>
#include <fstream>
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

MainPage::MainPage()
{
	InitializeComponent();
	fileManager->CreateFile(fileName);
	
}
void MainPage::WelcomeAnimation()
{
	timer = ref new Windows::UI::Xaml::DispatcherTimer();

	ts.Duration = 7000000;	 //0.7 sec

	timer->Interval = ts;
	timer->Start();
	registrationtoken = timer->Tick += ref new EventHandler<Object^>(this, &MainPage::OnTick);
}
void MainPage::OnTick(Object^ sender, Object^ e)
{

	timerCounter++;
	if (timerCounter >= 3) timerCounter = 0;

	switch (timerCounter)
	{
	case 1:
		ExitStoryboard->Begin();
		break;
	case 2:
		EnterStoryboard->Begin();
		break;
	}

}

void MyoGaming::MainPage::lnk_start_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

	timer_var_clear();
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(NavigatorPage::typeid));
}
