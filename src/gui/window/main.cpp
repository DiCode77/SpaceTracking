//
//  main.cpp
//  SpTracking
//
//  Created by DiCode77.
//

#include "main.hpp"

bool MyApp::OnInit() {
    SpTracking *prog = new SpTracking(wxT("Space Tracking"), wxDefaultPosition, window::size_wx_main_window);
    prog->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);
