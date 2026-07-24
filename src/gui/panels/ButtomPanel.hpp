//
//  ButtomPanel.hpp
//  ButtomPanel
//
//  Created by DiCode77.
//

#ifndef ButtomPanel_hpp
#define ButtomPanel_hpp

#include <wx/wx.h>
#include <utilites/utilites.hpp>
#include <utilites/constants.hpp>
#include <wx/statbox.h>

class SpTracking;
class ButtomPanel : public wxPanel{
public:
    using Property = window::Property;
private:
    SpTracking      *m_sp_tracking;
    window::Property m_prop;
    bool             m_is_init;
private:
    wxStaticBox *m_static_box_a;
    wxStaticBox *m_static_box_b;
    wxStaticBox *m_static_box_c;
    wxStaticBox *m_static_box_d;
public:
    ButtomPanel() : m_sp_tracking(nullptr), m_is_init(false){}
    ButtomPanel(SpTracking*, const wxWindowID&);
    
    bool init(SpTracking*, const wxWindowID&, const wxPoint&, const wxSize&);
    bool is_init();
    
    SpTracking *get_sp_tracking();
    const Property &get_property() const;
public:
    void OnEventMainUpdatedResize(wxSizeEvent&);
private:
    void OnSizePanelBottomMap(wxSizeEvent&);
};

#endif /* ButtomPanel_hpp */
