#ifndef REPORT_H
#define REPORT_H

#include <string>

struct Report {
    std::string start;
    std::string end;
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string topic;

    int duration() const;

#endif