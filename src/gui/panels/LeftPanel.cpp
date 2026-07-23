#include "LeftPanel.hpp"
#include "gui/window/SpTracking.hpp"

LeftPanel::LeftPanel(SpTracking *parent, const wxWindowID &winid) : m_sp_tracking(parent), m_size_main_window(parent->GetClientSize()), m_is_init(false){}

bool LeftPanel::init(SpTracking *parent, const wxWindowID &winid, const wxPoint &point, const wxSize &size){
    if (this->m_is_init == false){
        this->m_is_init = this->Create(parent, winid, point, size);
        return this->m_is_init;
    }
    return false;
}

bool LeftPanel::is_init(){
    return this->m_is_init;
}

void LeftPanel::OnEventMainUpdatedResize(wxSizeEvent&){}
void LeftPanel::OnSizePanelLeftMap(wxSizeEvent&){}
