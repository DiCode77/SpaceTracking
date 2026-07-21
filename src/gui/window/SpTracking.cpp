//
//  SpTracking.cpp
//  SpTracking
//
//  Created by DiCode77.
//

#include "SpTracking.hpp"

SpTracking::SpTracking(const wxString title, const wxPoint point, const wxSize size) : wxFrame(nullptr, wxID_ANY, title, point, size), m_size_main_frame(this->GetClientSize()){
    this->SetMinSize(size);
   
    // Create a panel and attach a map to it.
    auto &&prop1 = this->GetNewProperty(this->GetClientSize(), size, wxSize(700, this->GetClientSize().y -200), wxPoint(2, 2));
    prop1.first.y -= 20; // Let's move the window up a little.
    this->m_panel_map = new wxPanel(this, wxID_ANY, prop1.first, prop1.second);
    this->m_panel_map->Bind(wxEVT_SIZE, &SpTracking::OnSizePanelMap, this);
    this->m_static_box_map = new wxStaticBox(this->m_panel_map, wxID_ANY, wxT(""), wxPoint(0, 0), prop1.second);
    this->m_map = new MapKit(this->m_panel_map->GetHandle(), fpoint(10, 10), fsize(prop1.second.x -20, prop1.second.y +10), fscale::fnone);
    
    //
    auto &&prop2 = this->GetNewProperty(this->GetClientSize(), size, wxSize(this->GetClientSize().x - 40, 115), wxPoint(20, this->GetClientSize().y - 100), false);
    this->m_panel_vision_map = new wxPanel(this, wxID_ANY, prop2.first, prop2.second);
    this->m_panel_vision_map->Bind(wxEVT_SIZE, &SpTracking::OnSizePanelVisionMap, this);
    
    this->m_static_box_vision_map1 = new wxStaticBox(this->m_panel_vision_map, wxID_ANY, wxT(""), wxPoint(0, 0), wxSize(prop2.second.x / 5, prop2.second.y));
    this->m_static_box_vision_map2 = new wxStaticBox(this->m_panel_vision_map, wxID_ANY, wxT(""),
                                                     wxPoint(this->m_static_box_vision_map1->GetPosition().x + this->m_static_box_vision_map1->GetSize().x +10, 0),
                                                     wxSize(prop2.second.x / 5, prop2.second.y));
    this->m_static_box_vision_map3 = new wxStaticBox(this->m_panel_vision_map, wxID_ANY, wxT(""),
                                                     wxPoint(this->m_static_box_vision_map2->GetPosition().x + this->m_static_box_vision_map2->GetSize().x +10, 0),
                                                     wxSize(prop2.second.x / 5, prop2.second.y));
    
    this->m_static_box_vision_map4 = new wxStaticBox(this->m_panel_vision_map, wxID_ANY, wxT(""),
                                                     wxPoint(this->m_static_box_vision_map3->GetPosition().x + this->m_static_box_vision_map3->GetSize().x +10, 0),
                                                     wxSize(prop2.second.x - (this->m_static_box_vision_map3->GetPosition().x + this->m_static_box_vision_map3->GetSize().x +10), prop2.second.y));
    
    
    
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
    const wxSize dete_size = event.GetSize();
    
    auto &&prop1 = this->GetNewProperty(event.GetSize(), this->m_size_main_frame, wxSize(700, 500), wxPoint(2, 2));
    prop1.first.y -= 20; // Let's move the window up a little.
    this->m_panel_map->SetPosition(prop1.first);
    this->m_panel_map->SetSize(prop1.second);
    
    auto &&prop2 = this->GetNewProperty(client_size, this->m_size_main_frame, wxSize(this->m_size_main_frame.x - 40, 115), wxPoint(20, client_size.y - 100), false);
    this->m_panel_vision_map->SetPosition(prop2.first);
    this->m_panel_vision_map->SetSize(prop2.second.x, this->m_panel_vision_map->GetSize().y);
}

void SpTracking::OnSizePanelMap(wxSizeEvent &event){
    this->m_static_box_map->SetPosition(wxPoint(0, 0));
    this->m_static_box_map->SetSize(event.GetSize());
    
    this->m_map->setPoint(fpoint(10, 10));
    this->m_map->setSize(fsize(event.GetSize().x -20, event.GetSize().y -20));
}

void SpTracking::OnSizePanelVisionMap(wxSizeEvent &event){
    const wxSize panel_size = event.GetSize();
    const int size_updf = panel_size.x - this->m_size_main_frame.x + this->m_panel_vision_map->GetPosition().x +20;
    
    this->m_static_box_vision_map1->SetPosition(wxPoint(size_updf /5, 0));
    this->m_static_box_vision_map2->SetPosition(wxPoint((size_updf /5) + (this->m_static_box_vision_map1->GetPosition().x + this->m_static_box_vision_map1->GetSize().x +10), 0));
    this->m_static_box_vision_map3->SetPosition(wxPoint((size_updf /5) + (this->m_static_box_vision_map2->GetPosition().x + this->m_static_box_vision_map2->GetSize().x +10), 0));
    this->m_static_box_vision_map4->SetPosition(wxPoint((size_updf /5) + (this->m_static_box_vision_map3->GetPosition().x + this->m_static_box_vision_map3->GetSize().x +10), 0));
}
