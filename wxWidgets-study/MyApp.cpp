// #define WXUSINGDLL
// #define __WXMSW__
// #define _UNICODE

#include <wx/log.h>
#include <wx/frame.h>
#include <wx/textctrl.h>

#include "MyApp.h"
#include "MyLogWindow.h"


bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame();

    MyLogWindow* log_window_m = new MyLogWindow(frame);
    log_window_m->Show(true);

    // MyFrame* frame = new MyFrame();
    frame->SetSize(wxSize(800,600));
    frame->Center();
    frame->Show(true);

    return true;
}

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "��һ������")
{

    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&���...\tCtrl-H",
        "�˲˵�����ʾ�ı���ʾ��״̬��");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "�ļ�(&F)");
    menuBar->Append(menuHelp, "����(&H)");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    LOG_INFO("Hello world from wxWidgets!");
}

wxIMPLEMENT_APP(MyApp);
