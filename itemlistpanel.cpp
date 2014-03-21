#include "itemlistpanel.h"



void ItemListPanel::addInterface(){
	//wxSizer* tempSizer = new wxBoxSizer(wxHORIZONTAL);
	panelName = new wxStaticText(this, wxID_ANY, "ItemListPanel");
	//tempSizer->Add(panelName);
	SetSize(ItemListPanel::HEIGHT, ItemListPanel::WIDTH);
	Show();
	panelName->Show();


	//SetSizer(tempSizer);
}

void ItemListPanel::addEvents(){
	Bind(wxEVT_SIZE, &ItemListPanel::onSize, this);	
	Bind(wxEVT_PAINT, &ItemListPanel::paintEvent, this);
}

void ItemListPanel::addItem(){
	using namespace std;
	cout << "Adding new item" << endl;
	ItemPanel* temp = new ItemPanel(this);	
	cout << "y offset is " << yOffset << endl;
	temp->Move(5, yOffset );
	yOffset += ItemPanel::GetHeight();
	//temp->SetSize(300, 20);
	itemList.push_back(temp);	

}

void ItemListPanel::onSize(wxEvent& event){
	//std::cout << "Size changed" << std::endl;
	GetClientSize(&width, &height);	
	Refresh();
}

void ItemListPanel::render(wxDC& dc){
	// draw some text

	dc.SetBrush(*wxTRANSPARENT_BRUSH); // transparent filling
	//dc.SetBrush(wxNullBrush); // transparent filling
	dc.SetPen(wxPen(wxColor(255, 175, 175), 10)); // 10-pixels-thick pink outline
	dc.DrawRectangle(0, 0, width, height);

	//dc.DrawText(wxT("ItemPanel"), 5, 5);

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


void ItemListPanel::paintEvent(wxPaintEvent & evt){
	wxPaintDC dc(this);
	render(dc);
}