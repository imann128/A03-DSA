#include "bucket_sort.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Calculate bucket index for a value
int BucketSort::getBucketIndex(int value, int min_val, int max_val, int bucket_count) {
    if (max_val == min_val) return 0;
    
    // Scale value to [0, 1] range
    double scaled = static_cast<double>(value - min_val) / (max_val - min_val);
    // Map to bucket index
    int index = static_cast<int>(scaled * bucket_count);
    
    // Handle edge case
    if (index >= bucket_count) index = bucket_count - 1;
    return index;
}

std::vector<int> BucketSort::sort(const std::vector<int>& arr) {
    if (arr.empty()) return {};
    
    int n = arr.size();
    int min_val = *std::min_element(arr.begin(), arr.end());
    int max_val = *std::max_element(arr.begin(), arr.end());
    
    // Create buckets (using sqrt(n) as bucket count)
    int bucket_count = static_cast<int>(sqrt(n));
    if (bucket_count < 1) bucket_count = 1;
    
    std::vector<std::vector<int>> buckets(bucket_count);
    
    // Put elements in buckets
    for (int value : arr) {
        int index = getBucketIndex(value, min_val, max_val, bucket_count);
        buckets[index].push_back(value);
    }
    
    // Sort individual buckets
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }
    
    // Concatenate buckets
    std::vector<int> result;
    for (const auto& bucket : buckets) {
        result.insert(result.end(), bucket.begin(), bucket.end());
    }
    
    return result;
}

void BucketSort::analyze(const std::vector<int>& arr) {
    int n = arr.size();
    int bucket_count = static_cast<int>(sqrt(n));
    
    std::cout << "=== Bucket Sort Analysis ===" << std::endl;
    std::cout << "n = " << n << ", buckets = " << bucket_count << std::endl;
    std::cout << "Best/Average: O(n + k) where k = buckets" << std::endl;
    std::cout << "Worst: O(n²) if all elements in one bucket" << std::endl;
}