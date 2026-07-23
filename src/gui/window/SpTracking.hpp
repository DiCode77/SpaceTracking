//
//  SpTracking.hpp
//  SpTracking
//
//  Created by DiCode77.
//

#ifndef SpTracking_hpp
#define SpTracking_hpp

#include <gui/window/Includes.hpp>

class SpTracking : public wxFrame{
    struct window_size{
        const wxSize  size;
        const wxSize  client_size;
        const wxPoint position;
    } mw_size;;
private:
    MapKit      *m_map;
    MapPanel    *m_map_panel;
    TopPanel    *m_top_panel;
    LeftPanel   *m_left_panel;
    RightPanel  *m_right_panel;
    ButtomPanel *m_buttom_panel;
public:
    SpTracking(const wxString &title, const wxPoint &point, const wxSize &size);
public:
    window_size &get_window_size();
public:
    MapKit      *get_map();
    MapPanel    *get_map_panel();
    TopPanel    *get_top_panel();
    LeftPanel   *get_left_panel();
    RightPanel  *get_right_panel();
    ButtomPanel *get_buttom_panel();
private:
    void OnSizeMainFrame(wxSizeEvent&);
};

#endif /* SpTracking_hpp */
