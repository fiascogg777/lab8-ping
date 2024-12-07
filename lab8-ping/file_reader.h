#ifndef FILE_READER_H
#define FILE_READER_H

#include "Report.h"
#include <vector>
#include <string>

class FileReader {
public:
    // ����� ��� ������ ������ �� �����
    static std::vector<Report> readFromFile(const std::string& filename);
};

#endif