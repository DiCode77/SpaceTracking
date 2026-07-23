//
//  LeftPanel.hpp
//  LeftPanel
//
//  Created by DiCode77.
//

#ifndef LeftPanel_hpp
#define LeftPanel_hpp

#include <wx/wx.h>
#include <utilites/utilites.hpp>
#include <utilites/constants.hpp>

class SpTracking;
class LeftPanel : public wxPanel{
    SpTracking      *m_sp_tracking;
    window::Property m_prop;
    bool             m_is_init;
private:
    const wxSize m_size_main_window;
public:
    LeftPanel() : m_sp_tracking(nullptr), m_is_init(false){}
    LeftPanel(SpTracking*, const wxWindowID&);
    
    bool init(SpTracking*, const wxWindowID&, const wxPoint&, const wxSize&);
    bool is_init();
public:
    void OnEventMainUpdatedResize(wxSizeEvent&);
private:
    void OnSizePanelLeftMap(wxSizeEvent&);
};

#endif /* LeftPanel_hpp */
