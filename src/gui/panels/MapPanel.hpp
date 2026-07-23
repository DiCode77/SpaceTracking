//
//  MapPanel.hpp
//  MapPanel
//
//  Created by DiCode77.
//

#ifndef MapPanel_hpp
#define MapPanel_hpp

#include <utilites/constants.hpp>
#include <utilites/utilites.hpp>
#include <wx/wx.h>
#include <wx/statbox.h>

class SpTracking;
class MapPanel : public wxPanel{
public:
    using Property = window::Property;
private:
    SpTracking *m_sp_tracking;
    Property    m_prop;
    bool        m_is_init;
private:
    wxStaticBox *m_static_box;
public:
    MapPanel() : m_sp_tracking(nullptr), m_is_init(false){};
    MapPanel(SpTracking*, const wxWindowID&);
    bool init(SpTracking*, const wxWindowID&, const wxPoint&, const wxSize&);
    bool is_init() const;
    
    SpTracking *get_sp_tracking();
    const Property &get_property() const;
    
    wxStaticBox *get_static_box();
public:
    void OnEventMainUpdatedResize(wxSizeEvent&);
private:
    void OnSizePanelMap(wxSizeEvent&);
};

#endif /* MapPanel_hpp */
