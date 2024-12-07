#include "Report.h"
#include <cstdlib>

int Report::duration() const {
    int startHours = std::stoi(start.substr(0, 2));
    int startMinutes = std::stoi(start.substr(3, 2));
    int endHours = std::stoi(end.substr(0, 2));
    int endMinutes = std::stoi(end.substr(3, 2));

    return (endHours * 60 + endMinutes) - (startHours * 60 + startMinutes);
}
