#ifndef FILE_READER_H
#define FILE_READER_H

#include "Report.h"
#include <vector>
#include <string>

class FileReader {
public:
    // Метод для чтения данных из файла
    static std::vector<Report> readFromFile(const std::string& filename);
};

#endif