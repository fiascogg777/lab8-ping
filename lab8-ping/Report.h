#ifndef REPORT_H
#define REPORT_H

#include <string>

// Структура для представления доклада
struct Report {
    int start;        // Время начала доклада в формате ЧЧММ (например, 930 для 09:30)
    int end;          // Время окончания доклада в формате ЧЧММ (например, 1045 для 10:45)
    std::string surname;   // Фамилия автора
    std::string name;      // Имя автора
    std::string patronymic; // Отчество автора
    std::string topic;     // Тема доклада

    // Конструктор по умолчанию
    Report() : start(0), end(0), surname(""), name(""), patronymic(""), topic("") {}

    // Конструктор с параметрами
    Report(int start, int end, const std::string& surname,
        const std::string& name, const std::string& patronymic, const std::string& topic)
        : start(start), end(end), surname(surname), name(name), patronymic(patronymic), topic(topic) {
    }
};

#endif
