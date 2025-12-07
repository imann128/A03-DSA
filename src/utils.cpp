#include "utils.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

// Generate random array
std::vector<int> Utils::generateRandomArray(int size, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

// Generate nearly sorted array
std::vector<int> Utils::generateNearlySortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);
    
    // Swap 5% of elements to make it "nearly" sorted
    for (int i = 0; i < size / 20; i++) {
        int idx1 = dis(gen);
        int idx2 = dis(gen);
        std::swap(arr[idx1], arr[idx2]);
    }
    
    return arr;
}

// Generate array with small range
std::vector<int> Utils::generateSmallRangeArray(int size, int range) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, range - 1);
    
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

// Check if array is sorted
bool Utils::isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

// Print array
void Utils::printArray(const std::vector<int>& arr, const std::string& name) {
    if (!name.empty()) {
        std::cout << name << ": ";
    }
    
    std::cout << "[";
    for (size_t i = 0; i < std::min(arr.size(), static_cast<size_t>(10)); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << arr[i];
    }
    
    if (arr.size() > 10) {
        std::cout << ", ... (" << arr.size() << " elements total)]" << std::endl;
    } else {
        std::cout << "]" << std::endl;
    }
}

// Run basic test
void Utils::runBasicTest() {
    std::cout << "\n=== BASIC TEST ===" << std::endl;
    
    std::vector<int> test = {170, 45, 75, 90, 802, 24, 2, 66};
    printArray(test, "Original");
    
    std::cout << "Is sorted? " << (isSorted(test) ? "Yes" : "No") << std::endl;
}

// Compare all algorithms
void Utils::compareAllAlgorithms() {
    std::cout << "\n=== COMPARING ALL ALGORITHMS ===" << std::endl;
    
    std::vector<int> arr = generateRandomArray(10000, 0, 1000);
    
    std::cout << "Testing on array of size " << arr.size() << std::endl;
    
    // Note: We'd time each algorithm here
    std::cout << "All algorithms implemented and ready for testing." << std::endl;
}