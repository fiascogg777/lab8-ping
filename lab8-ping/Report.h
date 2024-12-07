#ifndef REPORT_H
#define REPORT_H

#include <string>

// ��������� ��� ������������� �������
struct Report {
    int start;        // ����� ������ ������� � ������� ���� (��������, 930 ��� 09:30)
    int end;          // ����� ��������� ������� � ������� ���� (��������, 1045 ��� 10:45)
    std::string surname;   // ������� ������
    std::string name;      // ��� ������
    std::string patronymic; // �������� ������
    std::string topic;     // ���� �������


    // ����������� �� ���������
    Report() : start(0), end(0), surname(""), name(""), patronymic(""), topic("") {}

    // ����������� � �����������
    Report(int start, int end, const std::string& surname,
        const std::string& name, const std::string& patronymic, const std::string& topic)
        : start(start), end(end), surname(surname), name(name), patronymic(patronymic), topic(topic) {
    }
};

#endif
