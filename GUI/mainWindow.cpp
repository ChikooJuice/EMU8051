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

}

/** 
 * event handler for opening menu and selecting file. 
 */
void MainFrame::open_menu(wxCommandEvent& event) {
    // opening file dialog box 
    printf("HERE for open file\n");
    wxFileDialog openfileDialog(this, _("open File"),"","","HexFile (*.hex)|*.hex", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
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
    // main grid
    wxFlexGridSizer *maingrid = new wxFlexGridSizer(3, 4, 10, 10);

    // Adding the titles. 
    maingrid->Add(new wxStaticText(this, wxID_ANY, "SFR Registers", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER), 5, wxALL | wxEXPAND, 10);
    maingrid->Add(new wxStaticText(this, wxID_ANY, "Program Status Word Register", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER), 5, wxALL | wxEXPAND, 10);
    maingrid->Add(new wxStaticText(this, wxID_ANY, "Timer Control Register", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER), 5, wxALL | wxEXPAND, 10);
    maingrid->Add(new wxStaticText(this, wxID_ANY, "General Purpose Registers", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER), 5, wxALL | wxEXPAND, 10);



    // Add SFR inside main grid. 
    wxFlexGridSizer *SFR_sizer = new wxFlexGridSizer(12, 4, 2, 2);
    maingrid->Add(SFR_sizer, 1, wxEXPAND | wxALL, 5);

    wxString SFR_names[] = {"P0", "SP", "DPL", "DPH", "PCON", "TCON", "TMOD", "TL0", "TL1", "TH0", "TH1", "P1", "SCON", "SBUF", "P2", "IE", "P3", "IP", "PSW", "ACC", "B", "  "};

    for(int i = 0; i < 22; i++) {
        
        SFR_sizer->Add(new wxStaticText(this, wxID_ANY, SFR_names[i], wxDefaultPosition, wxSize(100, 30), wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL), 5,  wxALL | wxEXPAND , 2);
        SFR_sizer->Add(new wxTextCtrl(this, wxID_ANY, wxString(SFR_names[i] + " value"), wxDefaultPosition, wxSize(100,30), wxTE_READONLY | wxALIGN_CENTER_HORIZONTAL), 1, wxEXPAND | wxALL, 2);

    }   

    // Adding program status word info 2
    wxFlexGridSizer *PSW_sizer = new wxFlexGridSizer(8, 2, 2, 2);
    maingrid->Add(PSW_sizer, 1, wxEXPAND | wxALL, 5);

    wxString PSW_names[] = {"P", "XX", "OV", "RS0", "RS1", "F0", "AC", "CY"};
    for(int i = 0; i < 8; i++) {
        
        PSW_sizer->Add(new wxStaticText(this, wxID_ANY, PSW_names[i], wxDefaultPosition, wxSize(100, 10), wxALIGN_CENTER_HORIZONTAL), 1,  wxALL | wxEXPAND , 2);
        PSW_sizer->Add(new wxTextCtrl(this, wxID_ANY, wxString(PSW_names[i] + " value"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY), 1, wxEXPAND | wxALL, 2);

    }

    // TIMER CONTROL REGISTER
    wxFlexGridSizer *TCON_sizer = new wxFlexGridSizer(8, 2, 2, 2);
    maingrid->Add(TCON_sizer, 1, wxEXPAND | wxALL, 5);

    wxString TCON_names[] = {"IT0", "IE0", "IT1", "IE1", "TR0", "TF0", "TR1", "TF1"};
    for(int i = 0; i < 8; i++) {
        
        TCON_sizer->Add(new wxStaticText(this, wxID_ANY, TCON_names[i], wxDefaultPosition, wxSize(100, 10), wxALIGN_CENTER_HORIZONTAL), 1,  wxALL | wxEXPAND , 2);
        TCON_sizer->Add(new wxTextCtrl(this, wxID_ANY, wxString(TCON_names[i] + " value"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY), 1, wxEXPAND | wxALL, 2);

    }    

    // GPR Registers
     // TIMER CONTROL REGISTER
    wxFlexGridSizer *GPR_sizer = new wxFlexGridSizer(8, 2, 2, 2);
    maingrid->Add(GPR_sizer, 1, wxEXPAND | wxALL, 5);

    wxString GPR_names[] = {"R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7"};
    for(int i = 0; i < 8; i++) {
        
        GPR_sizer->Add(new wxStaticText(this, wxID_ANY, GPR_names[i], wxDefaultPosition, wxSize(100, 10), wxALIGN_CENTER_HORIZONTAL), 1,  wxALL | wxEXPAND , 2);
        GPR_sizer->Add(new wxTextCtrl(this, wxID_ANY, wxString(GPR_names[i] + " value"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY), 1, wxEXPAND | wxALL, 2);

    }

    // Buttons grid: 
    // Step | View Memory | 

    wxFlexGridSizer *button_gridSizer = new wxFlexGridSizer(1, 2, 10, 10);
    maingrid->Add(button_gridSizer, 1, wxEXPAND | wxALL, 10);

    wxButton *Step_button = new wxButton(this, wxID_ANY, "STEP", wxDefaultPosition, wxSize(200, 50));
    
    wxButton *view_memory_button = new wxButton(this, wxID_ANY, "Memory", wxDefaultPosition,  wxSize(200, 50));

    button_gridSizer->Add(Step_button, 1, wxALL | wxEXPAND | wxALIGN_CENTER, 2);
    button_gridSizer->Add(view_memory_button, 1, wxALL | wxEXPAND, 2);
    

    
    this->SetSizerAndFit(maingrid);

}

bool EMU_GUI::OnInit() {
    MainFrame *frame = new MainFrame("EMU 8051");
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(EMU_GUI);



