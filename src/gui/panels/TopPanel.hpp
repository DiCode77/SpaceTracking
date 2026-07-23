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

class SpTracking;
class TopPanel : wxPanel{
    SpTracking      *m_sp_tracking;
    window::Property m_prop;
    bool             m_is_init;
private:
    const wxSize m_size_main_window;
public:
    TopPanel() : m_is_init(false){};
    TopPanel(SpTracking*, const wxWindowID&);
    bool init(SpTracking*, const wxWindowID&, const wxPoint&, const wxSize&);
    bool is_init();
    
    void set_property(const window::Property &prop){
        this->m_prop = prop;
    }
    
    window::Property get_property() const{
        return this->m_prop;
    }
public:
    void OnEventMainUpdatedResize(wxSizeEvent&);
private:
    void OnSizePanelTopMap(wxSizeEvent&);
};

#endif /* TopPanel_hpp */
