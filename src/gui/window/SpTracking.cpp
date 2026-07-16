//
//  SpTracking.cpp
//  SpTracking
//
//  Created by DiCode77.
//

#include "SpTracking.hpp"

SpTracking::SpTracking(const wxString title, const wxPoint point, const wxSize size) : wxFrame(nullptr, wxID_ANY, title, point, size){
    fsize size_map = {
        (double)this->GetClientSize().GetX() - 400,
        (double)this->GetClientSize().GetY() - 200
    };
    
    fpoint point_map = {
        ((double)this->GetClientSize().GetX() - size_map.x) /2,
        ((double)this->GetClientSize().GetY() - size_map.y) /2
    };
    
    this->m_panel = new wxPanel(this, wxID_ANY, wxPoint(point_map.x, point_map.y), wxSize(size_map.x, size_map.y));
    this->m_static_box_map = new wxStaticBox(this->m_panel, wxID_ANY, wxT(""), wxPoint(0, 0), wxSize(size_map.x, size_map.y));
    this->m_map = new MapKit(this->m_panel->GetHandle(), fpoint(10, 10), fsize(size_map.x -20, size_map.y +10), fscale::fnone);
    
    this->Bind(wxEVT_SIZE, &SpTracking::OnSizeMainFrame, this);
}

void SpTracking::OnSizeMainFrame(wxSizeEvent &event){
    wxSize size_main_frame_naw = event.GetSize();
    fsize size_map = {
        (double)size_main_frame_naw.GetX() - 400,
        (double)size_main_frame_naw.GetY() - 200
    };
    
    fpoint point_map = {
        ((double)size_main_frame_naw.GetX() - size_map.x) /2,
        ((double)size_main_frame_naw.GetY() - size_map.y) /2
    };
    
    this->m_panel->SetPosition(wxPoint(point_map.x, point_map.y));
    this->m_panel->SetSize(size_map.x, size_map.y);
    
    this->m_static_box_map->SetPosition(wxPoint(0, 0));
    this->m_static_box_map->SetSize(this->m_panel->GetSize());
    
    this->m_map->setPoint(fpoint(10, 10));
    this->m_map->setSize(fsize(size_map.x -20, size_map.y -20));
}
