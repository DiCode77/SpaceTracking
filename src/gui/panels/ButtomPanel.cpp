#include "ButtomPanel.hpp"
#include "gui/window/SpTracking.hpp"

ButtomPanel::ButtomPanel(SpTracking *parent, const wxWindowID &winid) : ButtomPanel::ButtomPanel(){
    this->m_sp_tracking = parent;
    const int dy_map_panel = parent->get_map_panel()->GetPosition().y + parent->get_map_panel()->GetSize().y;
    const int dy_but_panel = parent->get_window_size().client_size.y  - dy_map_panel - window::LANDSLIDE_20;
    
    this->m_prop = Util::GetNewProperty(parent->get_window_size().client_size,
                                        parent->get_window_size().client_size,
                                        wxPoint(parent->get_top_panel()->GetPosition().x, dy_map_panel + window::LANDSLIDE_10),
                                        wxSize(parent->get_top_panel()->GetSize().x, dy_but_panel),
                                        false);
    
    this->init(parent, winid, this->m_prop.first, this->m_prop.second);
}

bool ButtomPanel::init(SpTracking *parent, const wxWindowID &winid, const wxPoint &point, const wxSize &size){
    if (this->m_is_init == false){
        this->m_is_init = this->Create(parent, winid, point, size);
        return this->m_is_init;
    }
    return false;
}

bool ButtomPanel::is_init(){
    return this->m_is_init;
}

void ButtomPanel::OnEventMainUpdatedResize(wxSizeEvent&){}
void ButtomPanel::OnSizePanelBottomMap(wxSizeEvent&){}
