//-----------------------------------------------------------------------------
// <auto-generated> 
//   This code was generated by a tool. 
// 
//   Changes to this file may cause incorrect behavior and will be lost if  
//   the code is regenerated.
//
//   Tool: AllJoynCodeGenerator.exe
//
//   This tool is located in the Windows 10 SDK and the Windows 10 AllJoyn 
//   Visual Studio Extension in the Visual Studio Gallery.  
//
//   The generated code should be packaged in a Windows 10 C++/CX Runtime  
//   Component which can be consumed in any UWP-supported language using 
//   APIs that are available in Windows.Devices.AllJoyn.
//
//   Using AllJoynCodeGenerator - Invoke the following command with a valid 
//   Introspection XML file and a writable output directory:
//     AllJoynCodeGenerator -i <INPUT XML FILE> -o <OUTPUT DIRECTORY>
// </auto-generated>
//-----------------------------------------------------------------------------
#pragma once

namespace com { namespace taulty { namespace LightControl {

// This class, and the associated EventArgs classes, exist for the benefit of JavaScript developers who
// do not have the ability to implement ILightControlService. Instead, LightControlServiceEventAdapter
// provides the Interface implementation and exposes a set of compatible events to the developer.
public ref class LightControlServiceEventAdapter sealed : [Windows::Foundation::Metadata::Default] ILightControlService
{
public:
    // Method Invocation Events
    event Windows::Foundation::TypedEventHandler<LightControlServiceEventAdapter^, LightControlGetBuildingDefinitionJsonCalledEventArgs^>^ GetBuildingDefinitionJsonCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LightControlServiceEventAdapter^, LightControlGetBuildingDefinitionJsonCalledEventArgs^>^ handler) 
        { 
            return _GetBuildingDefinitionJsonCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LightControlServiceEventAdapter^>(sender), safe_cast<LightControlGetBuildingDefinitionJsonCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _GetBuildingDefinitionJsonCalled -= token; 
        } 
    internal: 
        void raise(LightControlServiceEventAdapter^ sender, LightControlGetBuildingDefinitionJsonCalledEventArgs^ args) 
        { 
            _GetBuildingDefinitionJsonCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LightControlServiceEventAdapter^, LightControlSwitchBuildingCalledEventArgs^>^ SwitchBuildingCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LightControlServiceEventAdapter^, LightControlSwitchBuildingCalledEventArgs^>^ handler) 
        { 
            return _SwitchBuildingCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LightControlServiceEventAdapter^>(sender), safe_cast<LightControlSwitchBuildingCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _SwitchBuildingCalled -= token; 
        } 
    internal: 
        void raise(LightControlServiceEventAdapter^ sender, LightControlSwitchBuildingCalledEventArgs^ args) 
        { 
            _SwitchBuildingCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LightControlServiceEventAdapter^, LightControlSwitchRoomCalledEventArgs^>^ SwitchRoomCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LightControlServiceEventAdapter^, LightControlSwitchRoomCalledEventArgs^>^ handler) 
        { 
            return _SwitchRoomCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LightControlServiceEventAdapter^>(sender), safe_cast<LightControlSwitchRoomCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _SwitchRoomCalled -= token; 
        } 
    internal: 
        void raise(LightControlServiceEventAdapter^ sender, LightControlSwitchRoomCalledEventArgs^ args) 
        { 
            _SwitchRoomCalled(sender, args);
        } 
    }

    event Windows::Foundation::TypedEventHandler<LightControlServiceEventAdapter^, LightControlToggleRoomLightCalledEventArgs^>^ ToggleRoomLightCalled 
    { 
        Windows::Foundation::EventRegistrationToken add(Windows::Foundation::TypedEventHandler<LightControlServiceEventAdapter^, LightControlToggleRoomLightCalledEventArgs^>^ handler) 
        { 
            return _ToggleRoomLightCalled += ref new Windows::Foundation::EventHandler<Platform::Object^>
            ([handler](Platform::Object^ sender, Platform::Object^ args)
            {
                handler->Invoke(safe_cast<LightControlServiceEventAdapter^>(sender), safe_cast<LightControlToggleRoomLightCalledEventArgs^>(args));
            }, Platform::CallbackContext::Same);
        } 
        void remove(Windows::Foundation::EventRegistrationToken token) 
        { 
            _ToggleRoomLightCalled -= token; 
        } 
    internal: 
        void raise(LightControlServiceEventAdapter^ sender, LightControlToggleRoomLightCalledEventArgs^ args) 
        { 
            _ToggleRoomLightCalled(sender, args);
        } 
    }

    // Property Read Events
    // Property Write Events
    // ILightControlService Implementation
    virtual Windows::Foundation::IAsyncOperation<LightControlGetBuildingDefinitionJsonResult^>^ GetBuildingDefinitionJsonAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info);
    virtual Windows::Foundation::IAsyncOperation<LightControlSwitchBuildingResult^>^ SwitchBuildingAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ bool interfaceMemberOnOff);
    virtual Windows::Foundation::IAsyncOperation<LightControlSwitchRoomResult^>^ SwitchRoomAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberRoomName, _In_ bool interfaceMemberOnOff);
    virtual Windows::Foundation::IAsyncOperation<LightControlToggleRoomLightResult^>^ ToggleRoomLightAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info, _In_ Platform::String^ interfaceMemberRoomName, _In_ int32 interfaceMemberLightIndex);



private:
    event Windows::Foundation::EventHandler<Platform::Object^>^ _GetBuildingDefinitionJsonCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _SwitchBuildingCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _SwitchRoomCalled;
    event Windows::Foundation::EventHandler<Platform::Object^>^ _ToggleRoomLightCalled;
};

} } } 