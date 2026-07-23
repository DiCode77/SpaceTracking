//
//  utilites.hpp
//  utilites
//
//  Created by DiCode77.
//

#ifndef utilites_hpp
#define utilites_hpp

#include "constants.hpp"
#include <wx/wx.h>

class Util{
public:
    // 1 - updates size, 2 - oem size, 3 - user size, 4 - point size, set user point
    static window::Property GetNewProperty(const wxSize&, const wxSize&, const wxPoint&, const wxSize&, bool = true);
};

#endif /* utilites_hpp */
