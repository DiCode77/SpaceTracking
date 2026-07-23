//
//  constants.hpp
//  constants
//
//  Created by DiCode77.
//

#ifndef constants_hpp
#define constants_hpp

#include <wx/wx.h>

namespace window{
const wxSize size_wx_main_window     = wxSize(1200, 800);
const wxSize size_wx_panel_map       = wxSize(700, 500);
const wxSize size_wx_zero            = wxSize(0, 0);

const wxPoint point_wx_landlide_2_2 = wxPoint(2, 2);
const wxPoint point_wx_zero         = wxPoint(0, 0);

const int LANDSLIDE_2  = 2;
const int LANDSLIDE_5  = 5;
const int LANDSLIDE_10 = 10;
const int LANDSLIDE_20 = 20;
const int LANDSLIDE_30 = 30;
const int LANDSLIDE_40 = 40;

const int VALUE_X_0 = 0;
const int VALUE_Y_0 = 0;

using Property = std::pair<wxPoint, wxSize>;
};

#endif /* constants_hpp */
