#include "RightPanel.hpp"
#include "gui/window/SpTracking.hpp"

RightPanel::RightPanel(SpTracking *parent, const wxWindowID &winid) : RightPanel::RightPanel(){
    this->m_sp_tracking = parent;
    const int dx_top_panel = parent->get_top_panel()->GetPosition().x + parent->get_top_panel()->GetSize().x;
    const int dx_map_panel = parent->get_map_panel()->GetPosition().x + parent->get_map_panel()->GetSize().x;
    
    this->m_prop = Util::GetNewProperty(parent->get_window_size().client_size,
                                        parent->get_window_size().client_size,
                                        wxPoint(dx_map_panel + window::LANDSLIDE_20, parent->get_map_panel()->GetPosition().y),
                                        wxSize(dx_top_panel - dx_map_panel - window::LANDSLIDE_20, parent->get_map_panel()->GetSize().y),
                                        false);
    this->init(parent, winid, this->m_prop.first, this->m_prop.second);
}

bool RightPanel::init(SpTracking *parent, const wxWindowID &winid, const wxPoint &point, const wxSize &size){
    if (this->m_is_init == false){
        this->m_is_init = this->Create(parent, winid, point, size);
        return this->m_is_init;
    }
    return false;
}

bool RightPanel::is_init(){
    return this->m_is_init;
}

void RightPanel::OnEventMainUpdatedResize(wxSizeEvent &event){}
void RightPanel::OnSizePanelRightMap(wxSizeEvent &event){}
