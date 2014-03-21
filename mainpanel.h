#pragma once

#include <wx/wx.h>
#include <vector>
#include "filedir.h"
#include "userstring.h"
#include "calclines.h"
#include "itemlistpanel.h"

class MainPanel : public wxPanel {

public:
	MainPanel(wxFrame* parent);

	void onRun(wxEvent& event);
	void onBrowse(wxEvent& event);
	void onAdd(wxEvent& event);
	//void onUnBind(wxEvent& event);
	//void unBind();

	~MainPanel();

private:
	void addInterface();
	void addEvents();
	
	//wxButton* Button2;
	
	wxTextCtrl* txt2;
	wxTextCtrl* outputTextCtrl;

	wxButton* runButton;
	wxCheckBox* cppCheckBox;
	wxCheckBox* hCheckBox;
	wxTextCtrl* directoryTextCtrl;
	wxButton* browseButton;
	wxButton* addButton;

	ItemListPanel* itemListPanel;

	enum BUTTONS { BUTTON1, BUTTON2 , ADDBUTTON };

	void captureCout();
	void releaseCout();

	std::streambuf *sbOld { nullptr };


};