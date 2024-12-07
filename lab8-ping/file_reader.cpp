#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Report> FileReader::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Report> reports;

    if (!file.is_open()) {
        std::cerr << "������: �� ������� ������� ���� " << filename << "\n";
        return reports;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Report report;

        iss >> report.start >> report.end >> report.surname >> report.name >> report.patronymic;
        std::getline(iss, report.topic); // ������ ���������� ����� ������ ��� ����
        report.topic.erase(0, report.topic.find_first_not_of(" ")); // ������� ������� �������

        reports.push_back(report);
    }

    file.close();
    return reports;
}
