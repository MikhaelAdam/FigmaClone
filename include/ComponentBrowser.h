#pragma once
#include <wx/wx.h>
#include <wx/srchctrl.h>
#include <wx/collpane.h>
#include <wx/wrapsizer.h>
class ComponentBrowser : public wxPanel
{
	//wxCollapsiblePane* m_components;
	wxSearchCtrl* m_search;
	wxButton* button[10];
public:
	ComponentBrowser(wxWindow* parent);
	virtual ~ComponentBrowser()
	{

	}
};

