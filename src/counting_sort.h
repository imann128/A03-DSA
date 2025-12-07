// src/counting_sort.h

#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include <vector>

class CountingSort {
public:
    // Stable Counting Sort (preserves order of equal elements)
    static std::vector<int> stableSort(const std::vector<int>& arr);
    
    // Non-stable Counting Sort (faster but doesn't preserve order)
    static std::vector<int> nonStableSort(const std::vector<int>& arr);
    
    // Analyze complexity for given array
    static void analyze(const std::vector<int>& arr);
    
private:
    static int findRange(const std::vector<int>& arr, int& min_val);
};

#endif