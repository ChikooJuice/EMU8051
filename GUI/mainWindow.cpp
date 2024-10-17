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
    public:
        MainFrame(const wxString& title);
    private:
        // event handlers. 
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
    wxFileDialog openfileDialog(this, _("open File"),"","","All Files (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openfileDialog.ShowModal() == wxID_CANCEL) {
        printf("PRESSED CANCELED !! \n");
        return;
    }
    else
    {
        wxString chosenFileName, pathname;
        chosenFileName = openfileDialog.GetFilename();
        pathname = openfileDialog.GetPath();

        std::cout << "file name : " << chosenFileName  << " PATH : " << pathname << std::endl;
    }
}

void MainFrame::exit_menu(wxCommandEvent& event) {
    Close(true);
}



bool EMU_GUI::OnInit() {
    MainFrame *frame = new MainFrame("EMU 8051");
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(EMU_GUI);



