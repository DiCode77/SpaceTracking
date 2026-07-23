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
class TopPanel : public wxPanel{
    SpTracking      *m_sp_tracking;
    window::Property m_prop;
    bool             m_is_init;
public:
    TopPanel() : m_is_init(false){};
    TopPanel(SpTracking*, const wxWindowID&);
    bool init(SpTracking*, const wxWindowID&, const wxPoint&, const wxSize&);
    bool is_init();
public:
    void OnEventMainUpdatedResize(wxSizeEvent&);
private:
    void OnSizePanelTopMap(wxSizeEvent&);
};

#endif /* TopPanel_hpp */
