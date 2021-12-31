#ifndef CEF_APP_H
#include "include/cef_app.h"
#define CEF_APP_H


class CefBrowserApp : public CefApp, public CefBrowserProcessHandler {
public:
        CefBrowserApp();
        virtual ~CefBrowserApp(){};


        // CefApp methods:
        CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override {
          return this;
        }
        // CefBrowserProcessHandler methods.
        void OnContextInitialized() override;
        CefRefPtr<CefClient> GetDefaultClient() override;


private:

        IMPLEMENT_REFCOUNTING(CefBrowserApp);
        DISALLOW_COPY_AND_ASSIGN(CefBrowserApp);
};

#endif // CEF_APP_H
