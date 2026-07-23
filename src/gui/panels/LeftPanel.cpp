#include "LeftPanel.hpp"
#include "gui/window/SpTracking.hpp"

LeftPanel::LeftPanel(SpTracking *parent, const wxWindowID &winid) : LeftPanel::LeftPanel(){
    this->m_sp_tracking = parent;
    this->m_prop = Util::GetNewProperty(parent->get_window_size().client_size, parent->get_window_size().client_size,
                                        wxPoint(parent->get_top_panel()->GetPosition().x, parent->get_map_panel()->GetPosition().y),
                                        wxSize((parent->get_map_panel()->GetPosition().x - parent->get_top_panel()->GetPosition().x) - window::LANDSLIDE_20, parent->get_map_panel()->GetSize().y),
                                        false);
    this->init(parent, winid, this->m_prop.first, this->m_prop.second);
}

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
