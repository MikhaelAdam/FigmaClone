#pragma once
#include "wx/wx.h"
class PreferenceDialog : public wxDialog
{
public:
	PreferenceDialog(wxWindow* parent, wxWindowID id, const wxString& title);
	virtual ~PreferenceDialog()
	{

	}
};

