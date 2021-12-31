#include "cef_app.h"
#include "cef_browser_handle.h"
#include "include/wrapper/cef_helpers.h"

CefBrowserApp::CefBrowserApp(){}

void CefBrowserApp::OnContextInitialized()
{
    CEF_REQUIRE_UI_THREAD();
}

CefRefPtr<CefClient> CefBrowserApp::GetDefaultClient() {
  // Called when a new browser window is created via the Chrome runtime UI.
  return CefBrowserHandle::GetInstance();
}
