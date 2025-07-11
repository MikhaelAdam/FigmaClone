#include "ProjectBrowser.h"
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/treectrl.h>
#endif // !WX_PRECOMP

wxBEGIN_EVENT_TABLE(ProjectBrowser, wxPanel)
EVT_KEY_DOWN(ProjectBrowser::OnKeyDown) // Bind the key down event
wxEND_EVENT_TABLE()

ProjectBrowser::ProjectBrowser(wxWindow* parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
    m_projectStructure = new wxTreeCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT);

    main_sizer->Add(m_projectStructure, wxSizerFlags().Expand().Proportion(1).Border());
    SetSizerAndFit(main_sizer);
    Layout();

    // Add a root item for demonstration
    wxTreeItemId rootItem = m_projectStructure->AddRoot("My Project");
    m_projectStructure->Expand(rootItem);
}

ProjectBrowser::~ProjectBrowser()
{
    // Destructor can be used for cleanup if needed
}

void ProjectBrowser::AddItem(const wxTreeItemId& parent, const wxString& itemName)
{
    // Add a new item under the specified parent
    m_projectStructure->AppendItem(parent, itemName);
}

void ProjectBrowser::RemoveItem(const wxTreeItemId& item)
{
    // Remove the specified item from the tree
    m_projectStructure->Delete(item);
}

void ProjectBrowser::OnKeyDown(wxKeyEvent& event)
{
    // Check if Shift key is pressed and 'A' key is pressed
    if (event.ControlDown() && event.GetKeyCode() == 'A')
    {
        wxMessageBox("ADD ITEM");
    }
    // Call the base class event handler
    event.Skip();
}
