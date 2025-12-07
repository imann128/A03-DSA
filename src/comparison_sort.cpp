#include "comparison_sort.h"
#include <algorithm>
#include <iostream>
#include <chrono>

std::vector<int> ComparisonSort::stdSort(const std::vector<int>& arr) {
    std::vector<int> result = arr;
    std::sort(result.begin(), result.end());
    return result;
}

std::vector<int> ComparisonSort::mergeSort(const std::vector<int>& arr) {
    if (arr.size() <= 1) return arr;
    
    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());
    
    left = mergeSort(left);
    right = mergeSort(right);
    
    // Merge
    std::vector<int> result;
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i++]);
        } else {
            result.push_back(right[j++]);
        }
    }
    
    while (i < left.size()) result.push_back(left[i++]);
    while (j < right.size()) result.push_back(right[j++]);
    
    return result;
}

std::vector<int> ComparisonSort::quickSort(const std::vector<int>& arr) {
    if (arr.size() <= 1) return arr;
    
    int pivot = arr[arr.size() / 2];
    std::vector<int> left, middle, right;
    
    for (int num : arr) {
        if (num < pivot) left.push_back(num);
        else if (num == pivot) middle.push_back(num);
        else right.push_back(num);
    }
    
    left = quickSort(left);
    right = quickSort(right);
    
    left.insert(left.end(), middle.begin(), middle.end());
    left.insert(left.end(), right.begin(), right.end());
    
    return left;
}

void ComparisonSort::comparePerformance() {
    std::cout << "\n=== Comparison Sorts Performance ===" << std::endl;
    std::cout << "std::sort (QuickSort variant): O(n log n) average" << std::endl;
    std::cout << "Merge Sort: O(n log n) guaranteed, stable" << std::endl;
    std::cout << "Quick Sort: O(n log n) average, O(n²) worst-case" << std::endl;
}