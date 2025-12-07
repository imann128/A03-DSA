#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <chrono>

class Utils {
public:
    // Array generators
    static std::vector<int> generateRandomArray(int size, int min = 0, int max = 1000);
    static std::vector<int> generateNearlySortedArray(int size);
    static std::vector<int> generateSmallRangeArray(int size, int range = 50);
    
    // Array utilities
    static bool isSorted(const std::vector<int>& arr);
    static void printArray(const std::vector<int>& arr, const std::string& name = "");
    
    // Timing utilities
    template<typename Func>
    static double timeAlgorithm(Func func, const std::vector<int>& arr);
    
    // Experiment utilities
    static void runBasicTest();
    static void compareAllAlgorithms();
};

// Template function implementation
template<typename Func>
double Utils::timeAlgorithm(Func func, const std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> result = func(arr);
    auto end = std::chrono::high_resolution_clock::now();
    
    if (!isSorted(result)) {
        std::cerr << "ERROR: Algorithm failed to sort!" << std::endl;
        return -1.0;
    }
    
    return std::chrono::duration<double, std::milli>(end - start).count();
}

#endif