#pragma once
extern int timerCounter;
extern Windows::Foundation::TimeSpan ts;
extern Windows::UI::Xaml::DispatcherTimer^ timer;
extern Windows::Foundation::EventRegistrationToken registrationtoken;

// these variables above can be used by many pages, this function used to clean/disconnect those variables when a page does not need
// these variables anymore.
extern void timer_var_clear();

