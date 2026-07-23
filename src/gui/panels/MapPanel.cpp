#include "MapPanel.hpp"
#include "gui/window/SpTracking.hpp"

MapPanel::MapPanel(SpTracking *parent, const wxWindowID &winid) : MapPanel::MapPanel(){
    this->m_sp_tracking = parent;
    this->m_prop = Util::GetNewProperty(parent->get_window_size().client_size, parent->get_window_size().client_size, window::point_wx_landlide_2_2, window::size_wx_panel_map);
    
    if (this->init(parent, winid, this->m_prop.first, this->m_prop.second)){
        this->Bind(wxEVT_SIZE, &MapPanel::OnSizePanelMap, this);
        this->m_static_box = new wxStaticBox(this, wxID_ANY, wxEmptyString, window::point_wx_zero, this->get_property().second);
    }
}

bool MapPanel::init(SpTracking *parent, const wxWindowID &winid, const wxPoint &point, const wxSize &size){
    if (this->m_is_init == false){
        this->m_is_init = this->Create(parent, winid, point, size);
        return this->m_is_init;
    }
    return false;
}

bool MapPanel::is_init() const{
    return this->m_is_init;
}

SpTracking *MapPanel::get_sp_tracking(){
    return this->m_sp_tracking;
}

const MapPanel::Property &MapPanel::get_property() const{
    return this->m_prop;
}

wxStaticBox *MapPanel::get_static_box(){
    return this->m_static_box;
}

void MapPanel::OnEventMainUpdatedResize(wxSizeEvent &event){
    const wxSize &&size = event.GetSize() - this->m_sp_tracking->get_window_size().part;
    Property &&prop = Util::GetNewProperty(size, this->m_sp_tracking->get_window_size().client_size, this->get_property().first, this->get_property().second, false);
    this->SetPosition(prop.first);
    this->SetSize(prop.second);
}

void MapPanel::OnSizePanelMap(wxSizeEvent &event){
    this->m_static_box->SetPosition(window::point_wx_zero);
    this->m_static_box->SetSize(event.GetSize());
}
