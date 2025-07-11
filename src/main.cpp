#include "Frame.h"
#include <wx/artprov.h>

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/artprov.h>
#endif // !WX_PRECOMP

class App : public wxApp {
public:
    bool OnInit() override {
        SetAppearance(Appearance::System);
        Frame* f = new Frame("Figma Clone");

        wxDisplay display;
        wxSize screenSize = display.GetGeometry().GetSize();
        int halfWidth = 2 * screenSize.GetWidth() / 3;
        int halfHeight = 2 * screenSize.GetHeight() / 3;
        f->SetSize(halfWidth, halfHeight);
        f->Centre();

        f->SetIcon(wxArtProvider::GetIcon(wxART_WX_LOGO));
        f->Show();
        f->Maximize();

        return true;
    }
};
wxIMPLEMENT_APP(App);