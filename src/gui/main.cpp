//
//  main.cpp
//  SpTracking
//
//  Created by DiCode77.
//

#include "main.hpp"

bool MyApp::OnInit() {
    SpTracking *prog = new SpTracking(wxT("Space Tracking"), wxDefaultPosition, wxSize(400, 500));
    prog->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);
