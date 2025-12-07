// src/radix_sort.cpp

#include "radix_sort.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Get maximum value
int RadixSort::getMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

// Get digit at position exp (1=ones, 10=tens, 100=hundreds)
int RadixSort::getDigit(int number, int exp) {
    return (number / exp) % 10;
}

// Counting sort for a specific digit
void RadixSort::countingSortForDigit(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);  // Digits 0-9
    
    // Count occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = getDigit(arr[i], exp);
        count[digit]++;
    }
    
    // Cumulative counts
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Build output array (stable - from right to left)
    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(arr[i], exp);
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    
    // Copy back
    arr = output;
}

// LSD Radix Sort
std::vector<int> RadixSort::sort(const std::vector<int>& arr) {
    if (arr.empty()) return arr;
    
    std::vector<int> result = arr;
    int max_val = getMax(result);
    
    // Do counting sort for each digit
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countingSortForDigit(result, exp);
    }
    
    return result;
}

void RadixSort::analyze(const std::vector<int>& arr) {
    if (arr.empty()) return;
    
    int max_val = getMax(arr);
    int digits = (max_val == 0) ? 1 : static_cast<int>(log10(max_val)) + 1;
    
    std::cout << "=== Radix Sort Analysis ===" << std::endl;
    std::cout << "n = " << arr.size() << ", d = " << digits << std::endl;
    std::cout << "Complexity: O(d * (n + b)) = O(" 
              << digits << " * (" << arr.size() << " + 10))" << std::endl;
}