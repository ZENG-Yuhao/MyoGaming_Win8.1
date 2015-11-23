
#include "pch.h"
#include "timer_var.h"
int timerCounter = 0;
Windows::Foundation::TimeSpan ts;
Windows::UI::Xaml::DispatcherTimer^ timer;
Windows::Foundation::EventRegistrationToken registrationtoken;

void timer_var_clear()
{
	if (timer != nullptr)
	{
		timerCounter = 0;
		timer->Tick -= registrationtoken;
		timer->Stop();
		delete(timer);
	}
}