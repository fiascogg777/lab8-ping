#ifndef SORT_H
#define SORT_H

#include "Report.h"
#include <vector>
#include <algorithm>

class Sort {
public:
    // Пирамидальная сортировка по убыванию длительности доклада
    static void heapSortByDuration(std::vector<Report>& reports) {
        auto compare = [](const Report& a, const Report& b) {
            int durationA = a.end - a.start;
            int durationB = b.end - b.start;
            return durationA < durationB; // Для max-heap
            };

        std::make_heap(reports.begin(), reports.end(), compare);
        std::sort_heap(reports.begin(), reports.end(), compare);
    }

    // Сортировка слиянием по убыванию длительности доклада
    static void mergeSortByDuration(std::vector<Report>& reports) {
        std::stable_sort(reports.begin(), reports.end(), [](const Report& a, const Report& b) {
            int durationA = a.end - a.start;
            int durationB = b.end - b.start;
            return durationA > durationB;
            });
    }

    // Пирамидальная сортировка по фамилии и теме
    static void heapSortBySurnameAndTopic(std::vector<Report>& reports) {
        auto compare = [](const Report& a, const Report& b) {
            if (a.surname == b.surname) {
                return a.topic > b.topic; // Для max-heap
            }
            return a.surname > b.surname;
            };

        std::make_heap(reports.begin(), reports.end(), compare);
        std::sort_heap(reports.begin(), reports.end(), compare);
    }

    // Сортировка слиянием по фамилии и теме
    static void mergeSortBySurnameAndTopic(std::vector<Report>& reports) {
        std::stable_sort(reports.begin(), reports.end(), [](const Report& a, const Report& b) {
            if (a.surname == b.surname) {
                return a.topic < b.topic;
            }
            return a.surname < b.surname;
            });
    }
};

#endif
