#include "utilites.hpp"

window::Property Util::GetNewProperty(const wxSize &p_updated, const wxSize &p_oem, const wxPoint &p_point, const wxSize &p_user_size, bool s_point){
    wxSize new_updated_size = (p_updated - p_oem) + p_user_size;
    wxSize new_point        =  p_updated - new_updated_size;
    
    if (s_point){
        new_point.x /= p_point.x;
        new_point.y /= p_point.y;
    }else{
        new_point.x = p_point.x;
        new_point.y = p_point.y;
    }
    
    return std::make_pair(wxPoint(new_point.x, new_point.y), new_updated_size);
}
