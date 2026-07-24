#include "LeftPanel.hpp"
#include "gui/window/SpTracking.hpp"

LeftPanel::LeftPanel(SpTracking *parent, const wxWindowID &winid) : LeftPanel::LeftPanel(){
    this->m_sp_tracking = parent;
    this->m_prop = Util::GetNewProperty(parent->get_window_size().client_size, parent->get_window_size().client_size,
                                        wxPoint(parent->get_top_panel()->GetPosition().x, parent->get_map_panel()->GetPosition().y),
                                        wxSize((parent->get_map_panel()->GetPosition().x - parent->get_top_panel()->GetPosition().x) - window::LANDSLIDE_20, parent->get_map_panel()->GetSize().y),
                                        false);
    if (this->init(parent, winid, this->m_prop.first, this->m_prop.second)){
        this->Bind(wxEVT_SIZE, &LeftPanel::OnSizePanelLeftMap, this);
        
        this->m_static_box_panel = new wxStaticBox(this, wxID_ANY, wxEmptyString, wxPoint(0, 0), this->GetSize());
        this->m_static_box_panel->Bind(wxEVT_SIZE, &LeftPanel::OnSizeStaticBoxPanel, this);
        
        const wxSize part = wxSize(this->GetSize().x, (this->GetSize().y -30) / 3);
        
        this->m_static_box_a = new wxStaticBox(this->m_static_box_panel, wxID_ANY, wxEmptyString, wxPoint(0, 0),               wxSize(this->m_static_box_panel->GetSize().x, part.y));
        this->m_static_box_b = new wxStaticBox(this->m_static_box_panel, wxID_ANY, wxEmptyString, wxPoint(0, part.y +10),      wxSize(this->m_static_box_panel->GetSize().x, part.y));
        
        const int size_st_end = (this->m_static_box_panel->GetSize().y - ((this->m_static_box_b->GetPosition().y + part.y)  + window::LANDSLIDE_10));
        this->m_static_box_c = new wxStaticBox(this->m_static_box_panel, wxID_ANY, wxEmptyString, wxPoint(0, (part.y *2) +20), wxSize(this->m_static_box_panel->GetSize().x, size_st_end));
    }
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

SpTracking *LeftPanel::get_sp_tracking(){
    return this->m_sp_tracking;
}

const LeftPanel::Property &LeftPanel::get_property() const{
    return this->m_prop;
}

void LeftPanel::OnEventMainUpdatedResize(wxSizeEvent &event){
    const wxSize &&size = event.GetSize() - this->m_sp_tracking->get_window_size().part;
    Property &&prop = Util::GetNewProperty(wxSize(this->get_sp_tracking()->get_window_size().client_size.x, size.y),
                                           this->get_sp_tracking()->get_window_size().client_size, this->get_property().first, this->get_property().second, false);
    this->SetPosition(prop.first);
    this->SetSize(prop.second);
}

void LeftPanel::OnSizePanelLeftMap(wxSizeEvent &event){
    this->m_static_box_panel->SetSize(event.GetSize());
}

void LeftPanel::OnSizeStaticBoxPanel(wxSizeEvent &event){
    const wxSize part = wxSize(this->m_static_box_panel->GetSize().x, (this->m_static_box_panel->GetSize().y -30) / 3);
    const wxSize reset = event.GetSize() - this->get_property().second;

    this->m_static_box_a->SetPosition(wxPoint(0, (reset.y /5)));
    this->m_static_box_b->SetPosition(wxPoint(0, (part.y +10) + (reset.y /5)));
    this->m_static_box_c->SetPosition(wxPoint(0, ((part.y *2) +20) + (reset.y /5) ));
}
