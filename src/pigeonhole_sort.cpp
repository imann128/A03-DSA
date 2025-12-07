#include "pigeonhole_sort.h"
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> PigeonholeSort::sort(const std::vector<int>& arr) {
    if (arr.empty()) return {};
    
    int min_val = *std::min_element(arr.begin(), arr.end());
    int max_val = *std::max_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;
    
    // Create pigeonholes
    std::vector<std::vector<int>> holes(range);
    
    // Put each element in its pigeonhole
    for (int value : arr) {
        holes[value - min_val].push_back(value);
    }
    
    // Collect sorted elements
    std::vector<int> result;
    for (const auto& hole : holes) {
        for (int value : hole) {
            result.push_back(value);
        }
    }
    
    return result;
}

void PigeonholeSort::analyze(const std::vector<int>& arr) {
    if (arr.empty()) return;
    
    int min_val = *std::min_element(arr.begin(), arr.end());
    int max_val = *std::max_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;
    
    std::cout << "=== Pigeonhole Sort Analysis ===" << std::endl;
    std::cout << "n = " << arr.size() << ", range = " << range << std::endl;
    std::cout << "Complexity: O(n + range)" << std::endl;
    std::cout << "Space: O(n + range)" << std::endl;
}