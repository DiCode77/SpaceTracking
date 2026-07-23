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
public:
    using Property = window::Property;
private:
    SpTracking      *m_sp_tracking;
    window::Property m_prop;
    bool             m_is_init;
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
};

#endif /* LeftPanel_hpp */
