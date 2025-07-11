#pragma once
#include "DetailsPanel.h"
#include "ProjectBrowser.h"
#include "Canvas.h"
#include "ComponentBrowser.h"
#include "Dialog/PreferenceDialog.h"

#include <wx/wx.h>
#include <wx/display.h>
#include <wx/aui/aui.h>

class Frame : public wxFrame
{
    DetailsPanel* m_detailsPanel;
    PreferenceDialog* m_preferenceDialog;
    ProjectBrowser* m_projectBrowser;
    Canvas* m_canvas;
    ComponentBrowser* m_componentBrowser;
    wxAuiManager m_mgr;

public:
    Frame(const wxString& title);
    virtual ~Frame()
    {
        m_mgr.UnInit();
    }

protected:
    void OnAddItem(wxCommandEvent& event); // Event handler for adding an item

    wxDECLARE_EVENT_TABLE(); // Declare the event table
};
