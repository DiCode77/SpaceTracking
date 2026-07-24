//
//  TopPanel.hpp
//  TopPanel
//
//  Created by DiCode77.
//

#ifndef TopPanel_hpp
#define TopPanel_hpp

#include "utilites/constants.hpp"
#include <wx/wx.h>
#include <wx/statbox.h>

class SpTracking;
class TopPanel : public wxPanel{
public:
    using Property = window::Property;
private:
    SpTracking      *m_sp_tracking;
    window::Property m_prop;
    bool             m_is_init;
private:
    wxStaticBox *m_static_box_panel;
public:
    TopPanel() : m_is_init(false){};
    TopPanel(SpTracking*, const wxWindowID&);
    bool init(SpTracking*, const wxWindowID&, const wxPoint&, const wxSize&);
    bool is_init();
    
    SpTracking *get_sp_tracking();
    const Property &get_property() const;
public:
    void OnEventMainUpdatedResize(wxSizeEvent&);
private:
    void OnSizePanelTopMap(wxSizeEvent&);
    void OnSizeStaticBoxPanel(wxSizeEvent&);
};

#endif /* TopPanel_hpp */
