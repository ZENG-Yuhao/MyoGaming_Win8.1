﻿

//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#include "pch.h"
#include "DifficultyPage.xaml.h"




void ::MyoGaming::DifficultyPage::InitializeComponent()
{
    if (_contentLoaded)
        return;

    _contentLoaded = true;

    // Call LoadComponent on ms-appx:///DifficultyPage.xaml
    ::Windows::UI::Xaml::Application::LoadComponent(this, ref new ::Windows::Foundation::Uri(L"ms-appx:///DifficultyPage.xaml"), ::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation::Application);

    // Get the TextBlock named 'txt_title'
    txt_title = safe_cast<::Windows::UI::Xaml::Controls::TextBlock^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"txt_title"));
    // Get the HyperlinkButton named 'btn_normal'
    btn_normal = safe_cast<::Windows::UI::Xaml::Controls::HyperlinkButton^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"btn_normal"));
    // Get the HyperlinkButton named 'btn_nightmare'
    btn_nightmare = safe_cast<::Windows::UI::Xaml::Controls::HyperlinkButton^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"btn_nightmare"));
    // Get the HyperlinkButton named 'btn_hell'
    btn_hell = safe_cast<::Windows::UI::Xaml::Controls::HyperlinkButton^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"btn_hell"));
    // Get the HyperlinkButton named 'btn_back'
    btn_back = safe_cast<::Windows::UI::Xaml::Controls::HyperlinkButton^>(static_cast<Windows::UI::Xaml::IFrameworkElement^>(this)->FindName(L"btn_back"));
}

void ::MyoGaming::DifficultyPage::Connect(int connectionId, Platform::Object^ target)
{
    switch (connectionId)
    {
    case 1:
        (safe_cast<::Windows::UI::Xaml::Controls::Primitives::ButtonBase^>(target))->Click +=
            ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::MyoGaming::DifficultyPage::*)(Platform::Object^, Windows::UI::Xaml::RoutedEventArgs^))&DifficultyPage::btn_normal_Click);
        break;
    case 2:
        (safe_cast<::Windows::UI::Xaml::Controls::Primitives::ButtonBase^>(target))->Click +=
            ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::MyoGaming::DifficultyPage::*)(Platform::Object^, Windows::UI::Xaml::RoutedEventArgs^))&DifficultyPage::btn_nightmare_Click);
        break;
    case 3:
        (safe_cast<::Windows::UI::Xaml::Controls::Primitives::ButtonBase^>(target))->Click +=
            ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::MyoGaming::DifficultyPage::*)(Platform::Object^, Windows::UI::Xaml::RoutedEventArgs^))&DifficultyPage::btn_hell_Click);
        break;
    case 4:
        (safe_cast<::Windows::UI::Xaml::Controls::Primitives::ButtonBase^>(target))->Click +=
            ref new ::Windows::UI::Xaml::RoutedEventHandler(this, (void (::MyoGaming::DifficultyPage::*)(Platform::Object^, Windows::UI::Xaml::RoutedEventArgs^))&DifficultyPage::btn_back_Click);
        break;
    }
    (void)connectionId; // Unused parameter
    (void)target; // Unused parameter
    _contentLoaded = true;
}
