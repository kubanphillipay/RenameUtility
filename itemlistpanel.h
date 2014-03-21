#pragma once

#include <wx/wx.h>
#include <iostream>
#include <vector>
#include "userstring.h"
#include "itempanel.h"



class ItemListPanel : public wxPanel {
	

public:

	ItemListPanel(wxWindow* parent) : wxPanel(parent) {
		addInterface();	
		addEvents();	
	}

	//void onRun(wxEvent& event);
	//void onBrowse(wxEvent& event);
	//void onUnBind(wxEvent& event);
	//void unBind();
	void onSize(wxEvent& event);
	void paintEvent(wxPaintEvent & evt);
	void addItem();
	

private:
	void addInterface();
	void addEvents();
	void render(wxDC& dc);

	
	wxStaticText *panelName;
	int width{ ItemListPanel::WIDTH };
	int height{ ItemListPanel::HEIGHT };
	int yOffset{ ItemListPanel::STARTOFFSET };

	//wxButton* Button2;

	//wxTextCtrl* txt2;
	//wxTextCtrl* outputTextCtrl;

	//wxButton* runButton;
	//wxCheckBox* cppCheckBox;
	//wxCheckBox* hCheckBox;
	//wxTextCtrl* directoryTextCtrl;
	//wxButton* browseButton;

	enum { HEIGHT = 100, WIDTH = 300 , STARTOFFSET = 10 };
	std::vector<ItemPanel*> itemList;

};