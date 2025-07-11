#include "Frame.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif 

wxBEGIN_EVENT_TABLE(Frame, wxFrame)
EVT_MENU(wxID_ANY, Frame::OnAddItem) // Bind the menu event to the handler
wxEND_EVENT_TABLE()

Frame::Frame(const wxString& title)
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE)
{
    SetDoubleBuffered(true);
    m_mgr.SetManagedWindow(this);
    m_mgr.SetFlags(wxAUI_MGR_ALLOW_FLOATING | wxAUI_MGR_TRANSPARENT_HINT | wxAUI_MGR_HINT_FADE | wxAUI_MGR_NO_VENETIAN_BLINDS_FADE | wxAUI_MGR_ALLOW_ACTIVE_PANE);

    m_detailsPanel = new DetailsPanel(this, wxID_ANY);
    m_projectBrowser = new ProjectBrowser(this);
    m_componentBrowser = new ComponentBrowser(this);
    m_canvas = new Canvas(this);
    m_preferenceDialog = new PreferenceDialog(this, wxID_PREFERENCES, "Preferences");

    m_mgr.AddPane(m_detailsPanel, wxAuiPaneInfo()
        .Name("details_panel").Right().Caption("Details").CloseButton(true)
        .BestSize(wxSize(600, 350)));

    m_mgr.AddPane(m_projectBrowser, wxAuiPaneInfo()
        .Name("project_browser").Top().Left()
        .Caption("Project Browser").CloseButton(true)
        .BestSize(wxSize(600, 350)));

    m_mgr.AddPane(m_componentBrowser, wxAuiPaneInfo()
        .Name("component_browser").Left().Caption("Component Browser").CloseButton(true)
        .BestSize(wxSize(600, 350)));

    m_mgr.AddPane(m_canvas, wxAuiPaneInfo()
        .Name("canvas").Center().CloseButton(false)
        .BestSize(wxSize(600, 350)));

    m_mgr.Update();

    // Create a menu bar
    wxMenuBar* menuBar = new wxMenuBar();

    // Create a menu
    wxMenu* fileMenu = new wxMenu();
    fileMenu->Append(wxID_ANY, "Add Item\tShift+A", "Add a new item to the project");

    // Bind the menu item to the event
    Bind(wxEVT_MENU, &Frame::OnAddItem, this, wxID_ANY);

    // Add the menu to the menu bar
    menuBar->Append(fileMenu, "File");
    SetMenuBar(menuBar);
}

void Frame::OnAddItem(wxCommandEvent& event)
{
    // Get the currently selected item from the ProjectBrowser
    wxTreeItemId selectedItem = m_projectBrowser->GetProjectStructure()->GetSelection();
    if (selectedItem.IsOk())
    {
        // Add a new item under the selected item
        m_projectBrowser->AddItem(selectedItem, "New Item");
    }
    else
    {
        // If no item is selected, add to the root
        wxTreeItemId rootItem = m_projectBrowser->GetProjectStructure()->GetRootItem();
        m_projectBrowser->AddItem(rootItem, "New Item");
    }
}
