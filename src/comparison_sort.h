#ifndef COMPARISON_SORT_H
#define COMPARISON_SORT_H

#include <vector>

class ComparisonSort {
public:
    // Wrapper for std::sort (QuickSort variant)
    static std::vector<int> stdSort(const std::vector<int>& arr);
    
    // Merge Sort implementation
    static std::vector<int> mergeSort(const std::vector<int>& arr);
    
    // Quick Sort implementation
    static std::vector<int> quickSort(const std::vector<int>& arr);
    
    // Compare with non-comparison sorts
    static void comparePerformance();
};

#endif