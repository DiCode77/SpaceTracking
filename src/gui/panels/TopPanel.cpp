#include "TopPanel.hpp"
#include "gui/window/SpTracking.hpp"

TopPanel::TopPanel(SpTracking *parent, const wxWindowID &winid) : m_sp_tracking(parent), m_size_main_window(parent->GetClientSize()), m_is_init(false){
    this->m_prop = Util::GetNewProperty(parent->GetClientSize(), this->m_size_main_window,
                                        wxPoint(window::LANDSLIDE_20, window::LANDSLIDE_20),
                                        wxSize(parent->GetClientSize().x -window::LANDSLIDE_40, parent->get_map_panel()->GetPosition().y - window::LANDSLIDE_30), false);
    this->init(parent, winid, this->m_prop.first, this->m_prop.second);
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

void TopPanel::OnEventMainUpdatedResize(wxSizeEvent&){}
void TopPanel::OnSizePanelTopMap(wxSizeEvent &event){}
