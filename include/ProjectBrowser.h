#pragma once

#include <wx/wx.h>
#include <wx/treectrl.h>

class ProjectBrowser : public wxPanel
{
private:
    wxTreeCtrl* m_projectStructure;

public:
    ProjectBrowser(wxWindow* parent);
    virtual ~ProjectBrowser();

    void AddItem(const wxTreeItemId& parent, const wxString& itemName);
    void RemoveItem(const wxTreeItemId& item);
    // Add this method declaration to the ProjectBrowser class
    wxTreeCtrl* GetProjectStructure() { return m_projectStructure; }


protected:
    void OnKeyDown(wxKeyEvent& event); // Event handler for key down events

    wxDECLARE_EVENT_TABLE(); // Declare the event table
};
