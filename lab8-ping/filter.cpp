#include "filter.h"
#include <iostream>

void filterByAuthor(const std::vector<Report>& reports, const std::string& surname,
    const std::string& name, const std::string& patronymic) {
    std::cout << "Доклады автора " << surname << " " << name << " " << patronymic << ":\n";
    for (const auto& report : reports) {
        if (report.surname == surname && report.name == name && report.patronymic == patronymic) {
            std::cout << report.start << " " << report.end << " "
                << report.surname << " " << report.name << " " << report.patronymic
                << " " << report.topic << "\n";
        }
    }
}

void filterByDuration(const std::vector<Report>& reports, int minDuration) {
    std::cout << "Доклады с длительностью больше " << minDuration << " минут:\n";
    for (const auto& report : reports) {
        int duration = report.end - report.start;
        if (duration > minDuration) {
            std::cout << report.start << " " << report.end << " "
                << report.surname << " " << report.name << " " << report.patronymic
                << " " << report.topic << "\n";
        }
    }
}
