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
#include <wx/statbox.h>

class SpTracking;
class LeftPanel : public wxPanel{
public:
    using Property = window::Property;
private:
    SpTracking      *m_sp_tracking;
    window::Property m_prop;
    bool             m_is_init;
private:
    wxStaticBox *m_static_box_panel;
    wxStaticBox *m_static_box_a;
    wxStaticBox *m_static_box_b;
    wxStaticBox *m_static_box_c;
public:
    LeftPanel() : m_sp_tracking(nullptr), m_is_init(false){}
    LeftPanel(SpTracking*, const wxWindowID&);
    
    bool init(SpTracking*, const wxWindowID&, const wxPoint&, const wxSize&);
    bool is_init();
    
    SpTracking *get_sp_tracking();
    const Property &get_property() const;
public:
    void OnEventMainUpdatedResize(wxSizeEvent&);
private:
    void OnSizePanelLeftMap(wxSizeEvent&);
    void OnSizeStaticBoxPanel(wxSizeEvent&);
};

#endif /* LeftPanel_hpp */
