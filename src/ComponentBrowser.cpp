#include "ComponentBrowser.h"

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif // !WX_PRECOMP

ComponentBrowser::ComponentBrowser(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	//Create controls
	wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);

	m_search = new wxSearchCtrl(this, wxID_ANY);
	
	wxPanel* components_panel = new wxPanel(this);
	wxWrapSizer* wrap_sizer = new wxWrapSizer(wxHORIZONTAL, wxWRAPSIZER_DEFAULT_FLAGS);

	for (int i = 0; i < 10; i++)
	{
		button[i] = new wxButton(components_panel, wxID_ANY);
		wrap_sizer->Add(button[i], wxSizerFlags().Shaped());
	}

	//Add items to the sizers
	main_sizer->Add(m_search, 0, wxALL | wxEXPAND, 0);
	main_sizer->Add(components_panel, 1, wxALL | wxEXPAND, 5);
	//Set layout
	components_panel->SetSizerAndFit(wrap_sizer);
	SetSizerAndFit(main_sizer);
	Layout();
}
