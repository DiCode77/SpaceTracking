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

class SpTracking;
class ButtomPanel : public wxPanel{
public:
    using Property = window::Property;
private:
    SpTracking      *m_sp_tracking;
    window::Property m_prop;
    bool             m_is_init;
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
