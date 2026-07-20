//
//  SpTracking.cpp
//  SpTracking
//
//  Created by DiCode77.
//

#include "SpTracking.hpp"

SpTracking::SpTracking(const wxString title, const wxPoint point, const wxSize size) : wxFrame(nullptr, wxID_ANY, title, point, size), m_size_main_frame(size){
   
    auto &&prop1 = this->GetNewProperty(this->GetClientSize(), size, wxSize(700, 500), wxPoint(2, 2));
    prop1.first.y -= 20;
    this->m_panel_map = new wxPanel(this, wxID_ANY, prop1.first, prop1.second);
    this->m_panel_map->Bind(wxEVT_SIZE, &SpTracking::OnSizePanelMap, this);
    this->m_static_box_map = new wxStaticBox(this->m_panel_map, wxID_ANY, wxT(""), wxPoint(0, 0), prop1.second);
    this->m_map = new MapKit(this->m_panel_map->GetHandle(), fpoint(10, 10), fsize(prop1.second.x -20, prop1.second.y +10), fscale::fnone);
    
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
    auto &&prop1 = this->GetNewProperty(event.GetSize(), this->m_size_main_frame, wxSize(700, 500), wxPoint(2, 2));
    prop1.first.y -= 20;
    this->m_panel_map->SetPosition(prop1.first);
    this->m_panel_map->SetSize(prop1.second);
    
    std::cout << prop1.second.x << std::endl;
}

void SpTracking::OnSizePanelMap(wxSizeEvent &event){
    this->m_static_box_map->SetPosition(wxPoint(0, 0));
    this->m_static_box_map->SetSize(event.GetSize());
    
    this->m_map->setPoint(fpoint(10, 10));
    this->m_map->setSize(fsize(event.GetSize().x -20, event.GetSize().y -20));
}
