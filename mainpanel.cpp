

#include "mainpanel.h"
#include "userstring.h"

using namespace std;

MainPanel::MainPanel(wxFrame* parent) : wxPanel(parent){
	addInterface();
	addEvents();
	captureCout();
}
//very few comments

void MainPanel::addInterface(){

	wxSizer* vertSizer = new wxBoxSizer(wxVERTICAL);

		wxSizer* dirHSizer = new wxBoxSizer(wxHORIZONTAL);
		String currentDir = wxGetCwd();
		directoryTextCtrl = new wxTextCtrl(this, wxID_ANY, currentDir);
		dirHSizer->Add(directoryTextCtrl, 3);
		browseButton = new wxButton(this, wxID_ANY, "Browse");
		dirHSizer->Add(browseButton, 2);
	
	vertSizer->Add(dirHSizer); 
	vertSizer->AddSpacer(5);

		wxSizer* gridSizer = new wxGridSizer(2, 0, 0);
		cppCheckBox = new wxCheckBox(this, wxID_ANY, ".cpp");
		cppCheckBox->SetValue(true);
		gridSizer->Add(cppCheckBox);
		hCheckBox = new wxCheckBox(this, wxID_ANY, ".h");
		gridSizer->Add(hCheckBox);
		hCheckBox->SetValue(true);

	vertSizer->Add(gridSizer);
	vertSizer->AddSpacer(5);

	runButton = new wxButton(this, BUTTON1, "Run");
	vertSizer->Add(runButton);
	vertSizer->AddSpacer(5);

	addButton = new wxButton(this, ADDBUTTON, "Add");
	vertSizer->Add(addButton);
	vertSizer->AddSpacer(5);

	itemListPanel = new ItemListPanel(this);
	vertSizer->Add(itemListPanel, 2, wxEXPAND);

	outputTextCtrl = new wxTextCtrl(this, wxID_ANY, "TEST", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);	
	outputTextCtrl->SetSize(200, 400);
	vertSizer->Add(outputTextCtrl, 1 , wxEXPAND);

	SetSizer(vertSizer);


	


}

void MainPanel::addEvents(){
	runButton->Bind(wxEVT_BUTTON, &MainPanel::onRun, this);
	browseButton->Bind(wxEVT_BUTTON, &MainPanel::onBrowse, this);
	addButton->Bind(wxEVT_BUTTON, &MainPanel::onAdd, this);
}

MainPanel::~MainPanel(){
	releaseCout();
	//wxPanel::~wxPanel();
}

void MainPanel::captureCout(){
	sbOld = std::cout.rdbuf();
	std::cout.rdbuf(outputTextCtrl);
}
void MainPanel::releaseCout(){
	if(sbOld != nullptr )
		std::cout.rdbuf(sbOld);
	sbOld = nullptr;
}

void MainPanel::onRun(wxEvent& event){
	using namespace std;
	

	cout << "Run Clicked";
	//captureCout();

	/*outputTextCtrl->AppendText("Running...\n");
	String dir = directoryTextCtrl->GetValue();
	if (!wxIsAbsolutePath(dir)){
		std::cout << "Warning " << dir << " is not a directory" << std::endl
			<< "Aborting..." << std::endl;
	}
	else {
		std::vector<String> cppFiles, hFiles, allFiles;
		dir.append("\\");
		if (cppCheckBox->IsChecked())
			cppFiles = listFiles(dir, "*.cpp");
		if (hCheckBox->IsChecked())
			hFiles = listFiles(dir, "*.h");
		allFiles.insert(allFiles.end(), cppFiles.begin(), cppFiles.end());
		allFiles.insert(allFiles.end(), hFiles.begin(), hFiles.end());
		
		auto totalData = calculateLineCount(allFiles);
		LineCountData total("Total");
		for (LineCountData data : totalData){
			total.code += data.code;
			total.comment += data.comment;
			total.lineCount += data.lineCount;
			total.empty += data.empty;
		}
		total.print();
		
	}*/
	//calculate_output(std::string(txt2->GetValue().mb_str()));

	//releaseCout();

}

void MainPanel::onAdd(wxEvent& event){
	
	cout << "Add Clicked" << endl;
	itemListPanel->addItem();
}


void MainPanel::onBrowse(wxEvent& event){
	//std::streambuf *sbOld = std::cout.rdbuf();
	//std::cout.rdbuf(outputTextCtrl);
	String currentDir = wxGetCwd();

	wxDirDialog dirDialog(this, "Choose a file" , currentDir );
	dirDialog.ShowModal();
	
	directoryTextCtrl->SetValue(dirDialog.GetPath());
	//calculate_output(std::string(txt2->GetValue().mb_str()));

	//std::cout.rdbuf(sbOld);

}

/*
void MainPanel::onUnBind(wxEvent& event){
	outputTextCtrl->AppendText("UnBind\n");
	unBind();
	//Button1->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &MainPanel::onClick, this);
}

void MainPanel::unBind(){

	//Button1->Unbind(wxEVT_COMMAND_BUTTON_CLICKED, &MainPanel::onClick, this);
}*/
