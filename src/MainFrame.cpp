#include "MainFrame.h"

enum { ID_Hello = 1 };

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame) EVT_MENU(wxID_EXIT, MainFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MainFrame::OnAbout) wxEND_EVENT_TABLE()

        MainFrame::MainFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title) {
  wxMenu* menuFile = new wxMenu;
  menuFile->Append(wxID_EXIT, "E&xit\tCtrl-Q", "Quit the application");

  wxMenu* menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT, "&About", "Show info about this application");

  wxMenuBar* menuBar = new wxMenuBar;
  menuBar->Append(menuFile, "&File");
  menuBar->Append(menuHelp, "&Help");

  SetMenuBar(menuBar);

  CreateStatusBar();
  SetStatusText("Welcome to Basic GUI App!");
}

void MainFrame::OnExit(wxCommandEvent& event) { Close(true); }

void MainFrame::OnAbout(wxCommandEvent& event) {
  wxMessageBox("This is a basic portable GUI application using wxWidgets.", "About Basic GUI App",
               wxOK | wxICON_INFORMATION);
}
