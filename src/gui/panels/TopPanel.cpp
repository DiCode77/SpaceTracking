#include "TopPanel.hpp"
#include "gui/window/SpTracking.hpp"

TopPanel::TopPanel(SpTracking *parent, const wxWindowID &winid) : TopPanel::TopPanel(){
    this->m_sp_tracking = parent;
    this->m_prop = Util::GetNewProperty(parent->get_window_size().client_size,
                                        parent->get_window_size().client_size,
                                        wxPoint(window::LANDSLIDE_20, window::LANDSLIDE_10),
                                        wxSize(parent->get_window_size().client_size.x -window::LANDSLIDE_40, parent->get_map_panel()->GetPosition().y - window::LANDSLIDE_30),
                                        false);
    
    if (this->init(parent, winid, this->m_prop.first, this->m_prop.second)){
        this->Bind(wxEVT_SIZE, &TopPanel::OnSizePanelTopMap, this);
    }
}

bool TopPanel::init(SpTracking *parent, const wxWindowID &winid, const wxPoint &point, const wxSize &size){
    if (this->m_is_init == false){
        this->m_is_init = this->Create(parent, winid, point, size);
        return this->m_is_init;
    }
    return false;
}

bool TopPanel::is_init(){
    return this->m_is_init;
}

SpTracking *TopPanel::get_sp_tracking(){
    return this->m_sp_tracking;
}

const TopPanel::Property &TopPanel::get_property() const{
    return this->m_prop;
}

void TopPanel::OnEventMainUpdatedResize(wxSizeEvent &event){
    const wxSize &&size = event.GetSize() - this->m_sp_tracking->get_window_size().part;
    Property &&prop = Util::GetNewProperty(wxSize(size.x,this->get_sp_tracking()->get_window_size().client_size.y),
                                           this->get_sp_tracking()->get_window_size().client_size, this->get_property().first, this->get_property().second, false);
    this->SetPosition(prop.first);
    this->SetSize(prop.second);
}
void TopPanel::OnSizePanelTopMap(wxSizeEvent &event){}
