#ifndef READ_DATA_H
#define READ_DATA_H

#include <vector>
#include <string>

// Структура Report
struct Report {
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string topic;
    int start_hour;
    int start_minute;
    int end_hour;
    int end_minute;
};

// Функция для чтения данных из файла
bool readData(const std::string& filename, std::vector<Report>& reports);

#endif
