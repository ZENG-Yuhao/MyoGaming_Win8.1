//
// GamePage.xaml.cpp
// Implementation of the GamePage class
//

#include "pch.h"
#include "GamePage.xaml.h"
#include "gamepage_var.h"
#include "RecordPage.xaml.h"
#include "timer_var.h"
#include "MainPage.xaml.h"
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

GamePage::GamePage()
{
	InitializeComponent();
	initPaths(GameDifficulty);
	UI_Update();
	fileManager->CreateFile(fileName);
}

//when user has a reation, this method will be called;
void MyoGaming::GamePage::submit(int value)
{
	if (locked || !started) return;

	ExitStoryboard->Begin();
	String^ path;
	if (value == abs(code_direction))
	{	 //verify the answer
		score++;
		nb_right++;
		path = "ms-appx:Assets/right.png";
	}
	else
	{
		nb_wrong++;
		path = "ms-appx:Assets/wrong.png";
		if (GameMode == CLASSIC)
		{
			life--;
			if (life <= 0) GameEnd();
		}
	}

	if (GameMode == CLASSIC)
	{
		timerCounter = 0;
	}


	code_direction = rand() % 4 + 1; //generate next direction  range: 1 to 4
	int sign = rand() % 2; //random sign :  0 - negative , 1 - positive
	if (sign == 0)
	{
		code_direction = -code_direction;
	}

	//replace display image.
	Uri = ref new Windows::Foundation::Uri(path);
	BitmapImage = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(Uri);
	img_display->Source = BitmapImage;
	EnterStoryboard->Begin();
	locked = true;
	UI_Update();
}

void MyoGaming::GamePage::UI_Update()
{
	btn_start->Content = "START";
	txt_score->Text = "Score: " + score;
	txt_rw->Text = "R/W: " + nb_right + "/" + nb_wrong;
	double Ttext;
	if (GameMode == CLASSIC)
	{
		txt_life->Text = "Life : " + life;
		Ttext = (boundsClassic - timerCounter) / 10;
	}else if (GameMode == TIME_LIMITED)
		Ttext = (boundsTimeLimited - timerCounter) / 10;
	//txt_timer->Text = " " + Ttext + "." + (timerCounter % 10);
	txt_timer->Text = "" + Ttext + "s";

}

void MyoGaming::GamePage::PointerIsBack()
{
	if (!started) return;
	Sleep(300);
	//initTimer();
	locked = false;
	//we make the absolute value of those red/blue arrows whose correct geste towards the same direction be the same, but with the oppsite sign.
	String^ path;
	switch (code_direction)
	{
	case 1: 	//up blue
		//path = "ms-appx:Assets/arrow_blue_up.png";
		path = picPaths[0];
		break;
	case 2:	    //down blue
		//path = "ms-appx:Assets/arrow_blue_down.png";
		path = picPaths[1];
		break;
	case 3:	    //left blue
		//path = "ms-appx:Assets/arrow_blue_left.png";
		path = picPaths[2];
		break;
	case 4:	    //right blue
		//path = "ms-appx:Assets/arrow_blue_right.png";
		path = picPaths[3];
		break;
	case -2:	    //up red
		//path = "ms-appx:Assets/arrow_red_up.png";
		path = picPaths[4];
		break;
	case -1:	    //down red
		//path = "ms-appx:Assets/arrow_red_down.png";
		path = picPaths[5];
		break;
	case -4:		//left red
		//path = "ms-appx:Assets/arrow_red_left.png";
		path = picPaths[6];
		break;
	case -3:		//right red
		//path = "ms-appx:Assets/arrow_red_right.png";
		path = picPaths[7];
		break;
	}
	//replace display image.
	Uri = ref new Windows::Foundation::Uri(path);
	BitmapImage = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(uri);
	img_display->Source = BitmapImage;


}

void MyoGaming::GamePage::GameStart()
{
	gamepage_var_clear();
	UI_Update();
	started = true;
}

void MyoGaming::GamePage::initTimer()
{

	timer = ref new Windows::UI::Xaml::DispatcherTimer();
	timerCounter = 0;
	//1 -> 0.0000001s
	ts.Duration = 1000000;	 //0.1 sec
	timer->Interval = ts;
	timer->Start();
	registrationtoken = timer->Tick += ref new EventHandler<Object^>(this, &GamePage::OnTick);
}

void MyoGaming::GamePage::deleteTimer()
{

}

void MyoGaming::GamePage::OnTick(Object^ sender, Object^ e)
{
	timerCounter++;

	switch (GameMode)
	{
	case CLASSIC:
		if (timerCounter >= boundsClassic)
		{
			timerCounter = 0;
			timer->Tick -= registrationtoken;
			timer->Stop();
			delete(timer);
			locked = true;
			life--;
			UI_Update();
			if (life <= 0)
			{
				GameEnd();
			}
			else
				initTimer();
		}
		break;
	case TIME_LIMITED:
		if (timerCounter >= boundsTimeLimited)
		{
			timerCounter = 0;
			timerCounter = 0;
			timer->Tick -= registrationtoken;
			timer->Stop();
			delete(timer);
			GameEnd();
		}
		break;
	default:
		break;
	}
	UI_Update();
}

void MyoGaming::GamePage::GameEnd()
{

	started = false;
	Uri = ref new Windows::Foundation::Uri("ms-appx:Assets/gameover-w.jpg");
	BitmapImage = ref new Windows::UI::Xaml::Media::Imaging::BitmapImage(Uri);
	img_display->Source = BitmapImage;
	fileManager->WriteToFile(txt_score->Text + "      " + txt_rw->Text + ";");
}

void MyoGaming::GamePage::ctr_up_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	submit(1);
}



void MyoGaming::GamePage::ctr_down_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	submit(2);
}


void MyoGaming::GamePage::ctr_left_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	submit(3);
}


void MyoGaming::GamePage::ctr_right_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	submit(4);
}


void MyoGaming::GamePage::pnl_display_PointerEntered(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e)
{
	PointerIsBack();
}


void MyoGaming::GamePage::btn_exit_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	timer_var_clear();
	gamepage_var_clear();
	this->Frame->Navigate(Windows::UI::Xaml::Interop::TypeName(MainPage::typeid));
}



void MyoGaming::GamePage::btn_start_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Sleep(2000);
	GameStart();
	initTimer();
	btn_start->IsEnabled = false;
}
