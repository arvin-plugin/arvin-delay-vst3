cmake_minimum_required(VERSION 3.14.0)
set(CMAKE_OSX_DEPLOYMENT_TARGET 10.13 CACHE STRING "")

set(vst3sdk_SOURCE_DIR "C:/VST_SDK/vst3sdk")
if(NOT vst3sdk_SOURCE_DIR)
    message(FATAL_ERROR "Path to VST3 SDK is empty!")
endif()

project(arvin_delay_vst3
    # This is your plug-in version number. Change it here only.
    # Version number symbols usable in C++ can be found in
    # source/version.h and ${PROJECT_BINARY_DIR}/projectversion.h.
    VERSION 1.0.0.0 
    DESCRIPTION "arvin_delay_vst3 VST 3 Plug-in"
)

set(SMTG_VSTGUI_ROOT "${vst3sdk_SOURCE_DIR}")

add_subdirectory(${vst3sdk_SOURCE_DIR} ${PROJECT_BINARY_DIR}/vst3sdk)
smtg_enable_vst3_sdk()

smtg_add_vst3plugin(arvin_delay_vst3
    source/version.h
    source/ARVIN_DELAY_FXcids.h
    source/ARVIN_DELAY_FXprocessor.h
    source/ARVIN_DELAY_FXprocessor.cpp
    source/ARVIN_DELAY_FXcontroller.h
    source/ARVIN_DELAY_FXcontroller.cpp
    source/ARVIN_DELAY_FXentry.cpp
)

#- VSTGUI Wanted ----
if(SMTG_ADD_VSTGUI)
    target_sources(arvin_delay_vst3
        PRIVATE
            resource/ARVIN_DELAY_FXeditor.uidesc
    )
    target_link_libraries(arvin_delay_vst3
        PRIVATE
            vstgui_support
    )
    smtg_target_add_plugin_resources(arvin_delay_vst3
        RESOURCES
            "resource/ARVIN_DELAY_FXeditor.uidesc"
    )
endif(SMTG_ADD_VSTGUI)
# -------------------

smtg_target_add_plugin_snapshots (arvin_delay_vst3
    RESOURCES
        resource/9169991D1CF554B8ADE7BA48AE2D7D4B_snapshot.png
        resource/9169991D1CF554B8ADE7BA48AE2D7D4B_snapshot_2.0x.png
)

target_link_libraries(arvin_delay_vst3
    PRIVATE
        sdk
)

smtg_target_configure_version_file(arvin_delay_vst3)

if(SMTG_MAC)
    smtg_target_set_bundle(arvin_delay_vst3
        BUNDLE_IDENTIFIER com.arvinplugin.arvin-delay
        COMPANY_NAME "Arvin Plugin"
    )
    smtg_target_set_debug_executable(arvin_delay_vst3
        "/Applications/VST3PluginTestHost.app"
        "--pluginfolder;$(BUILT_PRODUCTS_DIR)"
    )
elseif(SMTG_WIN)
    target_sources(arvin_delay_vst3 PRIVATE 
        resource/win32resource.rc
    )
    if(MSVC)
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT arvin_delay_vst3)

        smtg_target_set_debug_executable(arvin_delay_vst3
            "$(ProgramW6432)/Steinberg/VST3PluginTestHost/VST3PluginTestHost.exe"
            "--pluginfolder \"$(OutDir)/\""
        )
    endif()
endif(SMTG_MAC)
