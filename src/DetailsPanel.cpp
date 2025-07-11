#include "DetailsPanel.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif // !WX_PRECOMP

DetailsPanel::DetailsPanel(wxWindow* parent, wxWindowID id) : wxPanel(parent, id, wxDefaultPosition, wxDefaultSize)
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    m_propertyGrid = new wxPropertyGrid(this, // parent
        wxID_ANY, // id
        wxDefaultPosition, // position
        wxDefaultSize, // size
        // Here are just some of the supported window styles
        wxPG_AUTO_SORT | // Automatic sorting after items added
        wxPG_SPLITTER_AUTO_CENTER | // Automatically center splitter until user manually adjusts it
        // Default style
        wxPG_DEFAULT_STYLE);


    mainSizer->Add(m_propertyGrid, wxSizerFlags().Expand().Proportion(1).Border());

    SetSizerAndFit(mainSizer);
    Layout();
}
