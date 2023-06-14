#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/log.h>
#include <wx/app.h>

#include "MyLogWindow.h"


MyLogWindow::MyLogWindow(wxFrame* parent)
    : wxFrame(parent, wxID_ANY, "My Log Window")
{
    wxPanel* panel = new wxPanel(this);

    // 创建一个垂直盒子Sizer
    wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

    // 添加日志文本控件
    m_textCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
    vbox->Add(m_textCtrl, wxSizerFlags().Proportion(1).Expand().Border(wxALL, 5));

    // 设置Sizer
    panel->SetSizerAndFit(vbox);

    // 设置窗口大小和位置
    SetSize(wxSize(860, 400));
    Centre();

    // 将日志写入文本控件
    wxLog::SetActiveTarget(new wxLogTextCtrl(m_textCtrl));
    // wxLogMessage(wxT("[%s/%s/%u] '%s' is starting"), __TFILE__, wxString::FromAscii(__WXFUNCTION__).c_str(), __LINE__, wxTheApp->GetAppName().c_str());
    LOG_INFO(wxString::Format("'%s' is staring", wxTheApp->GetAppName().c_str()));
    // wxLogVerbose(wxT("[%s/%s/%u] Verbose Logging Enabled"), __TFILE__, wxString::FromAscii(__WXFUNCTION__).c_str(), __LINE__);
}

