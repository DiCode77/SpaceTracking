//
//  RightPanel.hpp
//  RightPanel
//
//  Created by DiCode77.
//

#ifndef RightPanel_hpp
#define RightPanel_hpp

#include <wx/wx.h>
#include <utilites/utilites.hpp>
#include <utilites/constants.hpp>

class SpTracking;
class RightPanel : public wxPanel{
    SpTracking      *m_sp_tracking;
    window::Property m_prop;
    bool             m_is_init;
private:
    const wxSize m_size_main_window;
public:
    RightPanel() : m_sp_tracking(nullptr), m_is_init(false){}
    RightPanel(SpTracking*, const wxWindowID&);
    
    bool init(SpTracking*, const wxWindowID&, const wxPoint&, const wxSize&);
    bool is_init();
public:
    void OnEventMainUpdatedResize(wxSizeEvent&);
private:
    void OnSizePanelRightMap(wxSizeEvent&);
};

#endif /* RightPanel_hpp */
