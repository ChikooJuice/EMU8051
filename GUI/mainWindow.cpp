#include <wx-3.0/wx/wx.h>
#include <iostream>

/** 
 * main overridden OnInit function creating
 * the top level window
 */
class EMU_GUI : public wxApp {
    public:
        virtual bool OnInit();
};

/**
 * main frame class. 
 * Entry point into the application
 */
class MainFrame : public wxFrame {
    private:
        wxString FilePath;
    public:
        MainFrame(const wxString& title);
        void draw_GUI();
        void open_menu(wxCommandEvent& event);
        void exit_menu(wxCommandEvent& event);
    

};

MainFrame :: MainFrame(const wxString& title): wxFrame (nullptr, 1, title, wxDefaultPosition, wxSize(500,500)) {
    
    // creating menu bar with 1 menu. 
    wxMenuBar *menubar = new wxMenuBar;
    wxMenu *menubar_menu = new wxMenu;
    
    wxMenuItem *menu_selectFile = new wxMenuItem(menubar_menu, wxID_ANY, "Open File");
    wxMenuItem *menu_exit = new wxMenuItem(menubar_menu, wxID_ANY, "Exit");

    menubar_menu->Append(menu_selectFile);
    menubar_menu->Append(menu_exit);
    
    menubar->Append(menubar_menu, "File");

    this->SetMenuBar(menubar);
    

    // assigning the function to menu items. 
    menubar_menu->Bind(wxEVT_MENU, &MainFrame::open_menu, this, menu_selectFile->GetId());
    menubar_menu->Bind(wxEVT_MENU, &MainFrame::exit_menu, this, menu_exit->GetId());

    this->draw_GUI();

}

/** 
 * event handler for opening menu and selecting file. 
 */
void MainFrame::open_menu(wxCommandEvent& event) {
    // opening file dialog box 
    printf("HERE for open file\n");
    wxFileDialog openfileDialog(this, _("open File"),"","","All Files (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openfileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }
    else
    {
        wxString chosenFileName, pathname;
        FilePath = openfileDialog.GetPath();
        this->draw_GUI();
    }
}

void MainFrame::exit_menu(wxCommandEvent& event) {
    Close(true);
}

void MainFrame::draw_GUI() {
    wxFlexGridSizer maingrid(3, 4, 10, 10);
    this->SetSizer(&maingrid);

}


void MainFrame::draw_GUI() {
    // main grid
    wxFlexGridSizer *maingrid = new wxFlexGridSizer(3, 4, 10, 10);

    // Add SFR inside main grid. 
    wxFlexGridSizer *SFR_sizer = new wxFlexGridSizer(12, 4, 2, 2);
    maingrid->Add(SFR_sizer, 1, wxEXPAND | wxALL, 5);

    wxString SFR_names[] = {"P0", "SP", "DPL", "DPH", "PCON", "TCON", "TMOD", "TL0", "TL1", "TH0", "TH1", "P1", "SCON", "SBUF", "P2", "IE", "P3", "IP", "PSW", "ACC", "B", "  "};

    // heading of registers
    SFR_sizer->Add( new wxStaticText (this, wxID_ANY, "SFR RESGISTERS"), 0,  wxEXPAND | wxALIGN_CENTER_HORIZONTAL | wxALL, 0);
    SFR_sizer->AddSpacer(0); // Empty cell to fill the span`
    SFR_sizer->AddSpacer(0); // Empty cell to fill the span
    SFR_sizer->AddSpacer(0); // Empty cell to fill the span`


    SFR_sizer->AddGrowableCol(0);
    SFR_sizer->AddGrowableCol(1);
    SFR_sizer->AddGrowableCol(2);
    SFR_sizer->AddGrowableCol(3);

    for(int i = 0; i < 22; i++) {
        
        SFR_sizer->Add(new wxTextCtrl(this, wxID_ANY, SFR_names[i], wxDefaultPosition, wxDefaultSize, wxTE_READONLY), 0,  wxALL, 2);
        SFR_sizer->Add(new wxTextCtrl(this, wxID_ANY, wxString(SFR_names[i] + " value"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY), 0, wxEXPAND | wxALL, 2);

    }   

    // Adding program status word info 2
    wxFlexGridSizer *PSW_sizer = new wxFlexGridSizer(8, 2, 2, 2);
    maingrid->Add(PSW_sizer, 1, wxEXPAND | wxALL, 5);

    wxString PSW_names[] = {"P", "XX", "OV", "RS0", "RS1", "F0", "AC", "CY"};
    for(int i = 0; i < 8; i++) {
        
        PSW_sizer->Add(new wxTextCtrl(this, wxID_ANY, PSW_names[i], wxDefaultPosition, wxDefaultSize, wxTE_READONLY), 1,  wxALL, 2);
        PSW_sizer->Add(new wxTextCtrl(this, wxID_ANY, wxString(PSW_names[i] + " value"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY), 1, wxEXPAND | wxALL, 2);

    }

    
    this->SetSizerAndFit(maingrid);

}

bool EMU_GUI::OnInit() {
    MainFrame *frame = new MainFrame("EMU 8051");
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(EMU_GUI);



