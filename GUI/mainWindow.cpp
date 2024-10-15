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
        void ext_menu(wxCommandEvent& event);

};

bool EMU_GUI::OnInit() {
    MainFrame *frame = new MainFrame("EMU 8051");
    frame->Show(true);
    return true;
}

MainFrame :: MainFrame(const wxString& title): wxFrame (nullptr, 1, title, wxDefaultPosition, wxSize(500,500)) {
    
    // creating menu bar.
    wxMenuBar* menubar = new wxMenuBar;
    wxMenu* file_menubar_menu = new wxMenu;
    wxMenu* exit_menubar_menu = new wxMenu;
    
    wxMenuItem* file_menu_selectFile = new wxMenuItem(file_menubar_menu, wxID_ANY, "Select File");

    file_menubar_menu->Append(file_menu_selectFile);
    wxMenuItem* exit_menuOpt = exit_menubar_menu->Append(wxID_ANY, "Exit");
    
    menubar->Append(file_menubar_menu, "File");
    menubar->Append(exit_menubar_menu, "Exit");

    this->SetMenuBar(menubar);
    

    // assigning the function to menu items. 
    file_menubar_menu->Bind(wxEVT_MENU, &MainFrame::open_menu, this);


}

void MainFrame::open_menu(wxCommandEvent& event) {
    printf("HEllo World \n");
}



wxIMPLEMENT_APP(EMU_GUI);



