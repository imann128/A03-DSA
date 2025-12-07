// src/radix_sort.h

#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include <vector>

class RadixSort {
public:
    // LSD Radix Sort
    static std::vector<int> sort(const std::vector<int>& arr);
    
    // Analyze complexity
    static void analyze(const std::vector<int>& arr);
    
private:
    static int getMax(const std::vector<int>& arr);
    static void countingSortForDigit(std::vector<int>& arr, int exp);
    static int getDigit(int number, int exp);
};

#endif