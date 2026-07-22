//
//  SpTracking.cpp
//  SpTracking
//
//  Created by DiCode77.
//

#include "SpTracking.hpp"

SpTracking::SpTracking(const wxString title, const wxPoint point, const wxSize size) : wxFrame(nullptr, wxID_ANY, title, point, size), m_size_main_frame(this->GetClientSize()){
    this->SetMinSize(size);
   
    // The central panel displaying the map.
    auto &&prop0 = this->GetNewProperty(this->GetClientSize(), this->m_size_main_frame, wxSize(700, 500), wxPoint(2, 2));
    prop0.first.y -= 20; // Let's move the window up a little.
    this->m_panel_map = new wxPanel(this, wxID_ANY, prop0.first, prop0.second);
    this->m_panel_map->Bind(wxEVT_SIZE, &SpTracking::OnSizePanelMap, this);
    this->m_static_box_map = new wxStaticBox(this->m_panel_map, wxID_ANY, wxT(""), wxPoint(0, 0), prop0.second);
    this->m_map = new MapKit(this->m_panel_map->GetHandle(), fpoint(10, 10), fsize(prop0.second.x -20, prop0.second.y -20), fscale::fnone);
    
    // Top panel.
    auto &&prop1 = this->GetNewProperty(this->GetClientSize(), this->m_size_main_frame, wxSize(this->GetClientSize().x -40, this->m_panel_map->GetPosition().y -30), wxPoint(20, 20), false);
    this->m_panel_top_map = new wxPanel(this, wxID_ANY, prop1.first, prop1.second);
    this->m_panel_top_map->Bind(wxEVT_SIZE, &SpTracking::OnSizePanelTopMap, this);
    
    // Left panel.
    auto &&prop2 = this->GetNewProperty(this->GetClientSize(), this->m_size_main_frame, wxSize(this->m_panel_map->GetPosition().x -40, this->m_panel_map->GetSize().y), wxPoint(20, this->m_panel_map->GetPosition().y), false);
    this->m_panel_left_map = new wxPanel(this, wxID_ANY, prop2.first, prop2.second);
    this->m_panel_left_map->Bind(wxEVT_SIZE, &SpTracking::OnSizePanelLeftMap, this);
    
    // Right panel.
    auto &&prop3 = this->GetNewProperty(this->GetClientSize(), this->m_size_main_frame,
                                        wxSize((this->m_size_main_frame.x - this->m_panel_map->GetPosition().x) - this->m_panel_map->GetSize().x -40, this->m_panel_map->GetSize().y),
                                        wxPoint(this->m_panel_map->GetPosition().x + this->m_panel_map->GetSize().x +20, this->m_panel_map->GetPosition().y), false);
    this->m_panel_right_map = new wxPanel(this, wxID_ANY, prop3.first, prop3.second);
    this->m_panel_right_map->Bind(wxEVT_SIZE, &SpTracking::OnSizePanelRightMap, this);
    
    // Bottom panel.
    auto &&prop4 = this->GetNewProperty(this->GetClientSize(), this->m_size_main_frame, wxSize(this->GetClientSize().x - 40, 115), wxPoint(20, this->GetClientSize().y - 130), false);
    this->m_panel_bottom_map = new wxPanel(this, wxID_ANY, prop4.first, prop4.second);
    this->m_panel_bottom_map->Bind(wxEVT_SIZE, &SpTracking::OnSizePanelBottomMap, this);
    
    new wxStaticBox(this->m_panel_bottom_map, wxID_ANY, wxEmptyString, wxPoint(), wxSize());
    this->m_static_box_buttom_map1 = new wxStaticBox(this->m_panel_bottom_map, wxID_ANY, wxEmptyString, wxPoint(0, 0), wxSize(prop4.second.x / 5, prop4.second.y));
    this->m_static_box_buttom_map2 = new wxStaticBox(this->m_panel_bottom_map, wxID_ANY, wxEmptyString,
                                                     wxPoint(this->m_static_box_buttom_map1->GetPosition().x + this->m_static_box_buttom_map1->GetSize().x +10, 0),
                                                     wxSize(prop4.second.x / 5, prop4.second.y));
    this->m_static_box_buttom_map3 = new wxStaticBox(this->m_panel_bottom_map, wxID_ANY, wxEmptyString,
                                                     wxPoint(this->m_static_box_buttom_map2->GetPosition().x + this->m_static_box_buttom_map2->GetSize().x +10, 0),
                                                     wxSize(prop4.second.x / 5, prop4.second.y));
    
    this->m_static_box_buttom_map4 = new wxStaticBox(this->m_panel_bottom_map, wxID_ANY, wxEmptyString,
                                                     wxPoint(this->m_static_box_buttom_map3->GetPosition().x + this->m_static_box_buttom_map3->GetSize().x +10, 0),
                                                     wxSize(prop4.second.x - (this->m_static_box_buttom_map3->GetPosition().x + this->m_static_box_buttom_map3->GetSize().x +10), prop4.second.y));
    
    
    this->Bind(wxEVT_SIZE, &SpTracking::OnSizeMainFrame, this);
}

std::pair<wxPoint, wxSize> SpTracking::GetNewProperty(const wxSize &p_updated, const wxSize &p_oem, const wxSize &p_user_size, const wxPoint &p_point, bool s_point){
    wxSize new_updated_size = (p_updated - p_oem) + p_user_size;
    wxSize new_point        =  p_updated - new_updated_size;
    
    if (s_point){
        new_point.x /= p_point.x;
        new_point.y /= p_point.y;
    }else{
        new_point.x = p_point.x;
        new_point.y = p_point.y;
    }
    
    return std::make_pair(wxPoint(new_point.x, new_point.y), new_updated_size);
}

void SpTracking::OnSizeMainFrame(wxSizeEvent &event){
    const wxSize client_size = dynamic_cast<wxWindow*>(event.GetEventObject())->GetClientSize();
    
    // The central panel displaying the map.
    auto &&prop0 = this->GetNewProperty(client_size, this->m_size_main_frame, wxSize(700, 500), wxPoint(2, 2));
    prop0.first.y -= 20; // Let's move the window up a little.
    this->m_panel_map->SetPosition(prop0.first);
    this->m_panel_map->SetSize(prop0.second);
    
    // Top panel.
    auto &&prop1 = this->GetNewProperty(client_size, this->m_size_main_frame, wxSize(this->m_size_main_frame.x -40, this->m_panel_map->GetPosition().y -30), wxPoint(20, 20), false);
    this->m_panel_top_map->SetPosition(prop1.first);
    this->m_panel_top_map->SetSize(prop1.second.x, this->m_panel_top_map->GetSize().y);
    
    // Left panel.
    static wxSize static_size_left_panel = this->m_panel_left_map->GetSize();
    auto &&prop2 = this->GetNewProperty(wxSize(this->m_size_main_frame.x, client_size.y), this->m_size_main_frame, static_size_left_panel, this->m_panel_left_map->GetPosition(), false);
    this->m_panel_left_map->SetPosition(prop2.first);
    this->m_panel_left_map->SetSize(prop2.second);
    
    // Right panel.
    static wxSize static_size_right_panel = this->m_panel_right_map->GetSize();
    auto &&prop3 = this->GetNewProperty(client_size, this->m_size_main_frame,
                                        wxSize((this->m_size_main_frame.x - this->m_panel_map->GetPosition().x) - this->m_panel_map->GetSize().x -40, static_size_right_panel.y),
                                        wxPoint((this->m_panel_map->GetPosition().x + this->m_panel_map->GetSize().x +20), this->m_panel_map->GetPosition().y), false);
    
    this->m_panel_right_map->SetPosition(prop3.first);
    this->m_panel_right_map->SetSize(prop3.second);
    
    
    // Bottom panel.
    auto &&prop4 = this->GetNewProperty(client_size, this->m_size_main_frame, wxSize(this->m_size_main_frame.x - 40, 115), wxPoint(20, client_size.y - 130), false);
    this->m_panel_bottom_map->SetPosition(prop4.first);
    this->m_panel_bottom_map->SetSize(prop4.second.x, this->m_panel_bottom_map->GetSize().y);
}

void SpTracking::OnSizePanelMap(wxSizeEvent &event){
    this->m_static_box_map->SetPosition(wxPoint(0, 0));
    this->m_static_box_map->SetSize(event.GetSize());
    
    this->m_map->setPoint(fpoint(10, 10));
    this->m_map->setSize(fsize(event.GetSize().x -20, event.GetSize().y -20));
}

void SpTracking::OnSizePanelTopMap(wxSizeEvent &event){}

void SpTracking::OnSizePanelLeftMap(wxSizeEvent &event){}

void SpTracking::OnSizePanelRightMap(wxSizeEvent &event){}

void SpTracking::OnSizePanelBottomMap(wxSizeEvent &event){
    const wxSize panel_size = event.GetSize();
    const int size_updf = panel_size.x - this->m_size_main_frame.x + this->m_panel_bottom_map->GetPosition().x +20;
    
    this->m_static_box_buttom_map1->SetPosition(wxPoint(size_updf /5, 0));
    this->m_static_box_buttom_map2->SetPosition(wxPoint((size_updf /5) + (this->m_static_box_buttom_map1->GetPosition().x + this->m_static_box_buttom_map1->GetSize().x +10), 0));
    this->m_static_box_buttom_map3->SetPosition(wxPoint((size_updf /5) + (this->m_static_box_buttom_map2->GetPosition().x + this->m_static_box_buttom_map2->GetSize().x +10), 0));
    this->m_static_box_buttom_map4->SetPosition(wxPoint((size_updf /5) + (this->m_static_box_buttom_map3->GetPosition().x + this->m_static_box_buttom_map3->GetSize().x +10), 0));
}
