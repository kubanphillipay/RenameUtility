
#include "itempanel.h"

void ItemPanel::addInterface(){
	//wxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	panelName = new wxStaticText(this, wxID_ANY, "ItemPanel");
	
	oldNameTextCtrl = new wxTextCtrl(this, wxID_ANY, "oldname", wxPoint(5, ItemPanel::YOFFSET), wxSize(80, 30), wxTE_READONLY );
	oldNameTextCtrl->SetLabel("oldlabel");
	stepTextCtrl = new wxTextCtrl(this, wxID_ANY, "step", wxPoint(100, ItemPanel::YOFFSET), wxSize(80, 30));
	stepTextCtrl->SetLabel("steplabel");
	tempTextCtrl = new wxTextCtrl(this, wxID_ANY, "temp", wxPoint(200, ItemPanel::YOFFSET), wxSize(80, 30));
	tempTextCtrl->SetLabel("templabel");

	//tempSizer->Add(panelName);
	SetSize(ItemPanel::WIDTH, ItemPanel::HEIGHT);
	//Show();
	//panelName->Show();


	//SetSizer(tempSizer);
}

void ItemPanel::addEvents(){
	Bind(wxEVT_SIZE, &ItemPanel::onSize, this);
	Bind(wxEVT_PAINT, &ItemPanel::paintEvent, this);
}

void ItemPanel::onSize(wxEvent& event){
	//std::cout << "Size changed" << std::endl;
	GetClientSize(&width, &height);
	Refresh();
}

void ItemPanel::render(wxDC& dc){
	// draw some text

	dc.SetBrush(*wxTRANSPARENT_BRUSH); // transparent filling
	//dc.SetBrush(wxNullBrush); // transparent filling
	dc.SetPen(wxPen(wxColor(75, 167, 255), 10)); // 10-pixels-thick pink outline
	dc.DrawRectangle(0, 0, width, height);



	//dc.DrawText(wxT("Testing"), 40, 60);

	// draw a circle
	//dc.SetBrush(*wxGREEN_BRUSH); // green filling
	//dc.SetPen(wxPen(wxColor(255, 0, 0), 5)); // 5-pixels-thick red outline
	//dc.DrawCircle(wxPoint(200, 100), 25 /* radius */);

	// draw a rectangle
	//dc.SetBrush(*wxBLUE_BRUSH); // blue filling
	//dc.SetPen(wxPen(wxColor(255, 175, 175), 10)); // 10-pixels-thick pink outline
	//dc.DrawRectangle(300, 100, 400, 200);

	// draw a line
	//dc.SetPen(wxPen(wxColor(0, 0, 0), 3)); // black line, 3 pixels thick
	//dc.DrawLine(200, 100, 300, 400); // draw line across the rectangle
}


void ItemPanel::paintEvent(wxPaintEvent & evt){
	wxPaintDC dc(this);
	render(dc);
}