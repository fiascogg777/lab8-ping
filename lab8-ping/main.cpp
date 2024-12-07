#include <iostream>
#include <vector>
#include "file_reader.h"
#include "sort.h"

// Функция для фильтрации докладов по автору
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

// Функция для фильтрации докладов по длительности
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

void printReports(const std::vector<Report>& reports) {
    for (const auto& report : reports) {
        std::cout << report.start << " " << report.end << " "
            << report.surname << " " << report.name << " " << report.patronymic
            << " " << report.topic << "\n";
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    std::vector<Report> reports;

    // Чтение данных из файла
    reports = FileReader::readFromFile("data.txt");

    int choice;

    std::cout << "Выберите действие:\n";
    std::cout << "1. Фильтрация по автору (Иванов Иван Иванович)\n";
    std::cout << "2. Фильтрация по длительности доклада (>15 минут)\n";
    std::cout << "3. Сортировка\n";
    std::cin >> choice;

    if (choice == 1) {
        filterByAuthor(reports, "Ivanov", "Ivan", "Ivanovich");
    }
    else if (choice == 2) {
        filterByDuration(reports, 15);
    }
    else if (choice == 3) {
        int sortMethod, sortCriterion;

        std::cout << "Выберите метод сортировки:\n";
        std::cout << "1. Пирамидальная сортировка (Heap sort)\n";
        std::cout << "2. Сортировка слиянием (Merge sort)\n";
        std::cin >> sortMethod;

        std::cout << "Выберите критерий сортировки:\n";
        std::cout << "1. По убыванию длительности доклада\n";
        std::cout << "2. По возрастанию фамилии автора доклада (и темы)\n";
        std::cin >> sortCriterion;

        if (sortMethod == 1) {
            if (sortCriterion == 1) {
                Sort::heapSortByDuration(reports);
            }
            else if (sortCriterion == 2) {
                Sort::heapSortBySurnameAndTopic(reports);
            }
        }
        else if (sortMethod == 2) {
            if (sortCriterion == 1) {
                Sort::mergeSortByDuration(reports);
            }
            else if (sortCriterion == 2) {
                Sort::mergeSortBySurnameAndTopic(reports);
            }
        }

        // Вывод отсортированных данных
        std::cout << "Отсортированные доклады:\n";
        printReports(reports);
    }

    return 0;
}
