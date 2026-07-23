#include "MapPanel.hpp"
#include "gui/window/SpTracking.hpp"

MapPanel::MapPanel(SpTracking *parent, const wxWindowID &winid) : MapPanel::MapPanel(){
    this->m_sp_tracking = parent;
    this->m_prop = Util::GetNewProperty(parent->get_window_size().client_size, parent->get_window_size().client_size, window::point_wx_landlide_2_2, window::size_wx_panel_map);
    this->init(parent, winid, this->m_prop.first, this->m_prop.second);
}

bool MapPanel::init(SpTracking *parent, const wxWindowID &winid, const wxPoint &point, const wxSize &size){
    if (this->m_is_init == false){
        this->m_is_init = this->Create(parent, winid, point, size);
        return this->m_is_init;
    }
    return false;
}

bool MapPanel::is_init(){
    return this->m_is_init;
}

void MapPanel::OnEventMainUpdatedResize(wxSizeEvent&){}
void MapPanel::OnSizePanelMap(wxSizeEvent&){}
