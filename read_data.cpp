#include "read_data.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool readData(const std::string& filename, std::vector<Report>& reports) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        Report report;

        ss >> report.start_hour;
        ss.ignore(); // Пропуск двоеточия
        ss >> report.start_minute;

        ss.ignore(); // Пропуск пробела
        ss >> report.end_hour;
        ss.ignore();
        ss >> report.end_minute;

        ss.ignore();
        ss >> report.surname >> report.name >> report.patronymic;

        std::getline(ss, report.topic);
        if (!report.topic.empty() && report.topic[0] == ' ') {
            report.topic.erase(0, 1); // Удаляем начальный пробел, если он есть
        }

        reports.push_back(report);
    }

    file.close();
    return true;
}
