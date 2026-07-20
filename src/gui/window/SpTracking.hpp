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
    const wxSize m_size_main_frame;
private:
    wxPanel     *m_panel_map;
    wxStaticBox *m_static_box_map;
    MapKit      *m_map;
public:
    SpTracking(const wxString title, const wxPoint point, const wxSize size);
private:
    // 1 - updates size, 2 - oem size, 3 - user size, 4 - point size, set user point
    std::pair<wxPoint, wxSize> GetNewProperty(const wxSize&, const wxSize&, const wxSize&, const wxPoint&, bool = true);
    void OnSizeMainFrame(wxSizeEvent&);
    void OnSizePanelMap(wxSizeEvent&);
};

#endif /* SpTracking_hpp */
