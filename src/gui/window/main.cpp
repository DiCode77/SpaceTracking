//
//  main.cpp
//  SpTracking
//
//  Created by DiCode77.
//

#include "main.hpp"

bool MyApp::OnInit() {
    SpTracking *prog = new SpTracking(wxT("Space Tracking"), wxDefaultPosition, wxSize(1200, 800));
    prog->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);
