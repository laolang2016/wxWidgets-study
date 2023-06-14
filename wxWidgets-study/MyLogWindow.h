#ifndef _MY_LOG_WINDOW_H_
#define _MY_LOG_WINDOW_H_

#include <wx/textctrl.h>
#include <wx/frame.h>
#include <wx/filename.h>

#define LOG_INFO(msg) wxLogMessage(wxT("[%s][%s:%u] - %s"), wxFileName::FileName(__TFILE__).GetFullName(), wxString::FromAscii(__WXFUNCTION__).c_str(), __LINE__, msg);
#define LOG_WARN(msg) wxLogWarning(wxT("[%s][%s:%u] - %s"), wxFileName::FileName(__TFILE__).GetFullName(), wxString::FromAscii(__WXFUNCTION__).c_str(), __LINE__, msg);
#define LOG_ERROR(msg) wxLogError(wxT("[%s][%s:%u] - %s"), wxFileName::FileName(__TFILE__).GetFullName(), wxString::FromAscii(__WXFUNCTION__).c_str(), __LINE__, msg);

class MyLogWindow : public wxFrame
{
public:
    MyLogWindow(wxFrame* parent);

private:
    wxTextCtrl* m_textCtrl;
};

#endif // !_MY_LOG_WINDOW_H_
