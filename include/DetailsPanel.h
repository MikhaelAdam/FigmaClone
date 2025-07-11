#pragma once
#include <wx/wx.h>
#include <wx/propgrid/propgrid.h>
class DetailsPanel : public wxPanel
{
	wxPropertyGrid* m_propertyGrid;
public:
	DetailsPanel(wxWindow* parent, wxWindowID id);
	virtual ~DetailsPanel()
	{

	}

};

