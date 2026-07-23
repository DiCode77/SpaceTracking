//
//  SpTracking.cpp
//  SpTracking
//
//  Created by DiCode77.
//

#include "SpTracking.hpp"

SpTracking::SpTracking(const wxString title, const wxPoint point, const wxSize size) : wxFrame(nullptr, wxID_ANY, title, point, size), m_size_main_frame(this->GetClientSize()){
    this->SetMinSize(size);
    
    this->m_map_panel = new MapPanel(this, wxID_ANY);
    this->m_top_panel = new TopPanel(this, wxID_ANY);
   
    this->Bind(wxEVT_SIZE, &SpTracking::OnSizeMainFrame, this);
}

MapKit *SpTracking::get_map(){
    return this->m_map;
}

MapPanel *SpTracking::get_map_panel(){
    return this->m_map_panel;
}

TopPanel *SpTracking::get_top_panel(){
    return this->m_top_panel;
}

LeftPanel *SpTracking::get_left_panel(){
    return this->m_left_panel;
}

RightPanel *SpTracking::get_right_panel(){
    return this->m_right_panel;
}

ButtomPanel *SpTracking::get_buttom_panel(){
    return this->m_buttom_panel;
}

void SpTracking::OnSizeMainFrame(wxSizeEvent &event){
    this->m_map_panel->OnEventMainUpdatedResize(event);
    this->m_top_panel->OnEventMainUpdatedResize(event);
    this->m_left_panel->OnEventMainUpdatedResize(event);
    this->m_right_panel->OnEventMainUpdatedResize(event);
    this->m_buttom_panel->OnEventMainUpdatedResize(event);
}
