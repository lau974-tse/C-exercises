#include "reverse_string.h"

namespace reverse_string {

    std::string reverse_string(std::string stringToInverse)
    {
        std::string result="";
        if (stringToInverse==" ")
        {
            return " ";
        }
        for (std::size_t i = 0; i< stringToInverse.size(); i++)
        {
            result+=stringToInverse[stringToInverse.size()-1-i];
        }
        return result;
    }
    
}  // namespace reverse_string
