// src/counting_sort.cpp

#include "counting_sort.h"
#include <iostream>
#include <vector>
#include <algorithm>

// Find range and minimum value
int CountingSort::findRange(const std::vector<int>& arr, int& min_val) {
    if (arr.empty()) {
        min_val = 0;
        return 0;
    }
    
    min_val = *std::min_element(arr.begin(), arr.end());
    int max_val = *std::max_element(arr.begin(), arr.end());
    
    return max_val - min_val + 1;
}

// Stable Counting Sort
std::vector<int> CountingSort::stableSort(const std::vector<int>& arr) {
    if (arr.empty()) return {};
    
    int min_val;
    int range = findRange(arr, min_val);
    
    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());
    
    // Count frequencies
    for (int num : arr) {
        count[num - min_val]++;
    }
    
    // Cumulative counts
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output from RIGHT to LEFT (STABLE)
    for (int i = arr.size() - 1; i >= 0; i--) {
        int index = arr[i] - min_val;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }
    
    return output;
}

// Non-stable Counting Sort
std::vector<int> CountingSort::nonStableSort(const std::vector<int>& arr) {
    if (arr.empty()) return {};
    
    int min_val;
    int range = findRange(arr, min_val);
    
    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());
    
    // Count frequencies
    for (int num : arr) {
        count[num - min_val]++;
    }
    
    // Fill output directly (NON-STABLE)
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            output[index++] = i + min_val;
            count[i]--;
        }
    }
    
    return output;
}

void CountingSort::analyze(const std::vector<int>& arr) {
    int min_val;
    int range = findRange(arr, min_val);
    
    std::cout << "=== Counting Sort Analysis ===" << std::endl;
    std::cout << "n = " << arr.size() << ", k = " << range << std::endl;
    std::cout << "Complexity: O(n + k) = O(" << arr.size() + range << ")" << std::endl;
}