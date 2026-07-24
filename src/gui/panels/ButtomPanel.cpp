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
    
    if (this->init(parent, winid, this->m_prop.first, this->m_prop.second)){
        this->Bind(wxEVT_SIZE, &ButtomPanel::OnSizePanelBottomMap, this);
        
        this->m_static_box_panel = new wxStaticBox(this, wxID_ANY, wxEmptyString, wxPoint(0, 0), this->GetSize());
        this->m_static_box_panel->Bind(wxEVT_SIZE, &ButtomPanel::OnSizeStaticBoxPanel, this);
        
        const wxSize part = this->m_static_box_panel->GetSize() / window::LANDSLIDE_5;
        
        this->m_static_box_a = new wxStaticBox(this->m_static_box_panel, wxID_ANY, wxEmptyString, window::point_wx_zero,                          wxSize(part.x, this->GetSize().y));
        this->m_static_box_b = new wxStaticBox(this->m_static_box_panel, wxID_ANY, wxEmptyString, wxPoint((part.x)    + window::LANDSLIDE_10, 0), wxSize(part.x, this->GetSize().y));
        this->m_static_box_c = new wxStaticBox(this->m_static_box_panel, wxID_ANY, wxEmptyString, wxPoint((part.x *2) + window::LANDSLIDE_20, 0), wxSize(part.x, this->GetSize().y));
        
        const int size_st_end = (this->GetSize().x - ((this->m_static_box_c->GetPosition().x + part.x)  + window::LANDSLIDE_10));
        this->m_static_box_d = new wxStaticBox(this->m_static_box_panel, wxID_ANY, wxEmptyString, wxPoint((part.x *3) + window::LANDSLIDE_30, 0), wxSize(size_st_end, this->m_static_box_panel->GetSize().y));
    }
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

SpTracking *ButtomPanel::get_sp_tracking(){
    return this->m_sp_tracking;
}

const ButtomPanel::Property &ButtomPanel::get_property() const{
    return this->m_prop;
}

void ButtomPanel::OnEventMainUpdatedResize(wxSizeEvent &event){
    const wxSize &&size = event.GetSize() - this->m_sp_tracking->get_window_size().part;
    const wxSize &&upd  = size - this->get_sp_tracking()->get_window_size().client_size;
    Property &&prop = Util::GetNewProperty(wxSize(size.x, this->get_sp_tracking()->get_window_size().client_size.y),
                                           this->get_sp_tracking()->get_window_size().client_size,
                                           wxPoint(this->get_property().first.x, this->get_property().first.y + upd.y), this->get_property().second, false);
    this->SetPosition(prop.first);
    this->SetSize(prop.second);
}

void ButtomPanel::OnSizePanelBottomMap(wxSizeEvent &event){
    this->m_static_box_panel->SetSize(event.GetSize());
}

void ButtomPanel::OnSizeStaticBoxPanel(wxSizeEvent &event){
    const wxSize  part = event.GetSize() / window::LANDSLIDE_5;
    const wxSize  reset    = event.GetSize() - this->get_property().second;
    const wxPoint stay     = wxPoint(reset.x, 0);
    
    this->m_static_box_panel->SetSize(event.GetSize());
    
    this->m_static_box_a->SetPosition(wxPoint(stay.x / window::LANDSLIDE_5, stay.y));
    this->m_static_box_b->SetPosition(wxPoint(((part.x)    + window::LANDSLIDE_10) + (stay.x / window::LANDSLIDE_5), stay.y));
    this->m_static_box_c->SetPosition(wxPoint(((part.x *2) + window::LANDSLIDE_20) + (stay.x / window::LANDSLIDE_5), stay.y));
    this->m_static_box_d->SetPosition(wxPoint(((part.x *3) + window::LANDSLIDE_30) + (stay.x / window::LANDSLIDE_5), stay.y));
}
