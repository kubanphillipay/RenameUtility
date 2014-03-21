#pragma once

#include <wx/wx.h>
#include <iostream>
#include <vector>
#include "userstring.h"



class ItemPanel : public wxPanel {

public:
	ItemPanel(wxWindow* parent) : wxPanel(parent) {
		using namespace std;
		addInterface();
		addEvents();

	}

	//void onRun(wxEvent& event);
	//void onBrowse(wxEvent& event);
	//void onUnBind(wxEvent& event);
	//void unBind();
	void onSize(wxEvent& event);
	void paintEvent(wxPaintEvent & evt);

	static int GetHeight(){ return ItemPanel::HEIGHT; }
	static int GetWidth(){ return ItemPanel::WIDTH; }


private:
	void addInterface();
	void addEvents();
	void render(wxDC& dc);


	wxStaticText *panelName;
	int width{ ItemPanel::WIDTH };
	int height{ ItemPanel::HEIGHT };
	
	wxTextCtrl* oldNameTextCtrl;
	wxTextCtrl* stepTextCtrl;
	wxTextCtrl* tempTextCtrl;

	//wxButton* Button2;

	
	//wxTextCtrl* outputTextCtrl;

	//wxButton* runButton;
	//wxCheckBox* cppCheckBox;
	//wxCheckBox* hCheckBox;
	//wxTextCtrl* directoryTextCtrl;
	//wxButton* browseButton;

	enum { HEIGHT = 50, WIDTH = 300 , YOFFSET =  10 };


};