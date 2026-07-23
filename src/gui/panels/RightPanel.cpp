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
    if (this->init(parent, winid, this->m_prop.first, this->m_prop.second)){
        this->Bind(wxEVT_SIZE, &RightPanel::OnSizePanelRightMap, this);
    }
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

SpTracking *RightPanel::get_sp_tracking(){
    return this->m_sp_tracking;
}

const RightPanel::Property &RightPanel::get_property() const{
    return this->m_prop;
}

void RightPanel::OnEventMainUpdatedResize(wxSizeEvent &event){
    const wxSize &&size = event.GetSize() - this->m_sp_tracking->get_window_size().part;
    const wxSize &&upd  = size - this->get_sp_tracking()->get_window_size().client_size;
    
    Property &&prop = Util::GetNewProperty(wxSize(this->get_sp_tracking()->get_window_size().client_size.x, size.y),
                                           this->get_sp_tracking()->get_window_size().client_size, wxPoint(this->get_property().first.x + upd.x, this->get_property().first.y), this->get_property().second, false);
    this->SetPosition(prop.first);
    this->SetSize(prop.second);
}
void RightPanel::OnSizePanelRightMap(wxSizeEvent &event){}
