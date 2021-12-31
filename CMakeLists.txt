cmake_minimum_required(VERSION 3.5)

project(CEF VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        wwlocalregister.cpp
        wwlocalregister.h
        wwlocalregister.ui
        cef_app.cpp
        cef_app.h
        cef_browser_handle.cpp
        cef_browser_handle.h
)

find_library(COCOA_LIBRARY Cocoa)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(CEF
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET CEF APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(CEF SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(CEF
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(CEF PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    ${COCOA_LIBRARY}
    "${PROJECT_SOURCE_DIR}/cef/cef_sandbox.a"
    "${PROJECT_SOURCE_DIR}/cef/libcef_dll_wrapper.a"
    "${PROJECT_SOURCE_DIR}/cef/Chromium\ Embedded\ Framework.framework"
)

set_target_properties(CEF PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CEF)
endif()
