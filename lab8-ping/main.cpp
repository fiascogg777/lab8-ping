#include <iostream>
#include <vector>
#include "file_reader.h"
#include "sort.h"

// ������� ��� ���������� �������� �� ������
void filterByAuthor(const std::vector<Report>& reports, const std::string& surname,
    const std::string& name, const std::string& patronymic) {
    std::cout << "������� ������ " << surname << " " << name << " " << patronymic << ":\n";
    for (const auto& report : reports) {
        if (report.surname == surname && report.name == name && report.patronymic == patronymic) {
            std::cout << report.start << " " << report.end << " "
                << report.surname << " " << report.name << " " << report.patronymic
                << " " << report.topic << "\n";
        }
    }
}

// ������� ��� ���������� �������� �� ������������
void filterByDuration(const std::vector<Report>& reports, int minDuration) {
    std::cout << "������� � ������������� ������ " << minDuration << " �����:\n";
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

    // ������ ������ �� �����
    reports = FileReader::readFromFile("data.txt");

    int choice;

    std::cout << "�������� ��������:\n";
    std::cout << "1. ���������� �� ������ (������ ���� ��������)\n";
    std::cout << "2. ���������� �� ������������ ������� (>15 �����)\n";
    std::cout << "3. ����������\n";
    std::cin >> choice;

    if (choice == 1) {
        filterByAuthor(reports, "Ivanov", "Ivan", "Ivanovich");
    }
    else if (choice == 2) {
        filterByDuration(reports, 15);
    }
    else if (choice == 3) {
        int sortMethod, sortCriterion;

        std::cout << "�������� ����� ����������:\n";
        std::cout << "1. ������������� ���������� (Heap sort)\n";
        std::cout << "2. ���������� �������� (Merge sort)\n";
        std::cin >> sortMethod;

        std::cout << "�������� �������� ����������:\n";
        std::cout << "1. �� �������� ������������ �������\n";
        std::cout << "2. �� ����������� ������� ������ ������� (� ����)\n";
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

        // ����� ��������������� ������
        std::cout << "��������������� �������:\n";
        printReports(reports);
    }

    return 0;
}
