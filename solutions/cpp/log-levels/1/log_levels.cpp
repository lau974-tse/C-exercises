#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    int index = line.find(" ");
    return line.substr(index+1);
}

std::string log_level(std::string line) {
    // return the log level
    int idx1 = line.find("[");
    int idx2 = line.find("]");
    return line.substr(idx1+1,idx2-1);
}

std::string reformat(std::string line) {
    // return the reformatted message
    return message(line)+" ("+log_level(line)+")";
}
}  // namespace log_line
