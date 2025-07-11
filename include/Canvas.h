#pragma once
#include <wx/wx.h>
#include <wx/glcanvas.h>
class Canvas :public wxPanel
{
	wxGLCanvas* m_canvas;
public:
	Canvas(wxWindow* parent);
	virtual ~Canvas()
	{

	}
};

