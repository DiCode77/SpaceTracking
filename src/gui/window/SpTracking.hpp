//
//  SpTracking.hpp
//  SpTracking
//
//  Created by DiCode77.
//

#ifndef SpTracking_hpp
#define SpTracking_hpp

#include <iostream>
#include <wx/wx.h>
#include <MapKit.hpp>

class SpTracking : public wxFrame{
private:
    wxPanel     *m_panel;
    wxStaticBox *m_static_box_map;
    MapKit      *m_map;
public:
    SpTracking(const wxString title, const wxPoint point, const wxSize size);
private:
    void OnSizeMainFrame(wxSizeEvent&);
};

#endif /* SpTracking_hpp */
