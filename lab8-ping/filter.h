#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <string>
#include "Report.h"

// ���������� �� ������
void filterByAuthor(const std::vector<Report>& reports, const std::string& surname,
    const std::string& name, const std::string& patronymic);

// ���������� �� ������������
void filterByDuration(const std::vector<Report>& reports, int minDuration);

#endif
