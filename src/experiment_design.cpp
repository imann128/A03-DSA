#include <cmath>
#include "experiment_design.h"
#include "counting_sort.h"
#include "radix_sort.h"
#include "bucket_sort.h"
#include "pigeonhole_sort.h"
#include "utils.h"
#include "comparison_sort.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <algorithm>

void ExperimentDesign::runExperiment1_VaryingSize() {
    std::cout << "\n=== EXPERIMENT 1: Varying Input Size ===" << std::endl;
    std::cout << "Testing algorithms with n = 1000, 5000, 10000, 50000" << std::endl;
    
    std::vector<int> sizes = {1000, 5000, 10000, 50000};
    std::vector<std::vector<std::string>> results;
    
    for (int size : sizes) {
        std::vector<int> arr = Utils::generateRandomArray(size, 0, 1000);
        
        double time_cs = Utils::timeAlgorithm(CountingSort::stableSort, arr);
        double time_rs = Utils::timeAlgorithm(RadixSort::sort, arr);
        double time_bs = Utils::timeAlgorithm(BucketSort::sort, arr);
        double time_ps = Utils::timeAlgorithm(PigeonholeSort::sort, arr);
        double time_std = Utils::timeAlgorithm(ComparisonSort::stdSort, arr);
        
        results.push_back({
            std::to_string(size),
            std::to_string(time_cs),
            std::to_string(time_rs),
            std::to_string(time_bs),
            std::to_string(time_ps),
            std::to_string(time_std)
        });
    }
    
    std::vector<std::string> headers = {"Size(n)", "Counting", "Radix", "Bucket", "Pigeonhole", "std::sort"};
    printTable(headers, results);
}

void ExperimentDesign::runExperiment2_VaryingRange() {
    std::cout << "\n=== EXPERIMENT 2: Varying Value Range (k) ===" << std::endl;
    std::cout << "Fixed n = 10000, varying k = 10, 100, 1000, 10000" << std::endl;
    
    int n = 10000;
    std::vector<int> ranges = {10, 100, 1000, 10000};
    std::vector<std::vector<std::string>> results;
    
    for (int range : ranges) {
        std::vector<int> arr = Utils::generateRandomArray(n, 0, range);
        
        std::cout << "\nRange k = " << range << " (n/k = " << n/range << ")" << std::endl;
        
        double time_cs = Utils::timeAlgorithm(CountingSort::stableSort, arr);
        double time_rs = Utils::timeAlgorithm(RadixSort::sort, arr);
        double time_std = Utils::timeAlgorithm(ComparisonSort::stdSort, arr);
        
        results.push_back({
            std::to_string(range),
            std::to_string(time_cs),
            std::to_string(time_rs),
            std::to_string(time_std),
            std::to_string(static_cast<double>(n)/range)
        });
    }
    
    std::vector<std::string> headers = {"Range(k)", "Counting", "Radix", "std::sort", "n/k ratio"};
    printTable(headers, results);
}

void ExperimentDesign::runExperiment3_DifferentDistributions() {
    std::cout << "\n=== EXPERIMENT 3: Different Data Distributions ===" << std::endl;
    
    int n = 10000;
    std::vector<std::vector<std::string>> results;
    
    // Uniform distribution
    std::vector<int> uniform = Utils::generateRandomArray(n, 0, 1000);
    // Nearly sorted
    std::vector<int> nearly_sorted = Utils::generateNearlySortedArray(n);
    // Small range
    std::vector<int> small_range = Utils::generateSmallRangeArray(n, 50);
    
    std::vector<std::pair<std::string, std::vector<int>>> datasets = {
        {"Uniform", uniform},
        {"Nearly Sorted", nearly_sorted},
        {"Small Range", small_range}
    };
    
    for (const auto& [name, arr] : datasets) {
        double time_cs = Utils::timeAlgorithm(CountingSort::stableSort, arr);
        double time_rs = Utils::timeAlgorithm(RadixSort::sort, arr);
        double time_bs = Utils::timeAlgorithm(BucketSort::sort, arr);
        double time_std = Utils::timeAlgorithm(ComparisonSort::stdSort, arr);
        
        results.push_back({
            name,
            std::to_string(time_cs),
            std::to_string(time_rs),
            std::to_string(time_bs),
            std::to_string(time_std)
        });
    }
    
    std::vector<std::string> headers = {"Distribution", "Counting", "Radix", "Bucket", "std::sort"};
    printTable(headers, results);
}

void ExperimentDesign::runExperiment4_StabilityTest() {
    std::cout << "\n=== EXPERIMENT 4: Stability Test ===" << std::endl;
    
    // Create array with pairs (value, original_index)
    std::vector<std::pair<int, int>> arr_with_indices = {
        {5, 0}, {2, 1}, {5, 2}, {3, 3}, {2, 4}, {5, 5}
    };
    
    // Extract just values
    std::vector<int> arr;
    for (const auto& p : arr_with_indices) {
        arr.push_back(p.first);
    }
    
    std::cout << "Original: ";
    for (const auto& p : arr_with_indices) {
        std::cout << "(" << p.first << "," << p.second << ") ";
    }
    std::cout << std::endl;
    
    // Test stable counting sort
    std::vector<int> stable_result = CountingSort::stableSort(arr);
    std::cout << "Stable Counting Sort result: ";
    for (int val : stable_result) std::cout << val << " ";
    std::cout << std::endl;
    
    // Test non-stable counting sort  
    std::vector<int> nonstable_result = CountingSort::nonStableSort(arr);
    std::cout << "Non-stable Counting Sort result: ";
    for (int val : nonstable_result) std::cout << val << " ";
    std::cout << std::endl;
    
    std::cout << "\nNote: Stable sort preserves original order of equal elements." << std::endl;
    std::cout << "For the three 5's: stable keeps order (5@0, 5@2, 5@5)" << std::endl;
    std::cout << "Non-stable may change their order." << std::endl;
}

void ExperimentDesign::runExperiment5_ComparisonVsStdSort() {
    std::cout << "\n=== EXPERIMENT 5: Non-Comparison vs Comparison Sorts ===" << std::endl;
    
    std::vector<int> sizes = {1000, 5000, 10000};
    std::vector<std::vector<std::string>> results;
    
    for (int size : sizes) {
        std::vector<int> arr = Utils::generateRandomArray(size, 0, 1000);
        
        double time_cs = Utils::timeAlgorithm(CountingSort::stableSort, arr);
        double time_rs = Utils::timeAlgorithm(RadixSort::sort, arr);
        double time_std = Utils::timeAlgorithm(ComparisonSort::stdSort, arr);
        
        double speedup_cs = time_std / time_cs;
        double speedup_rs = time_std / time_rs;
        
        results.push_back({
            std::to_string(size),
            std::to_string(time_cs),
            std::to_string(time_rs),
            std::to_string(time_std),
            std::to_string(speedup_cs),
            std::to_string(speedup_rs)
        });
    }
    
    std::vector<std::string> headers = {"Size", "Counting", "Radix", "std::sort", "Speedup(CS)", "Speedup(RS)"};
    printTable(headers, results);
    
    std::cout << "\n=== THEORETICAL ANALYSIS ===" << std::endl;
    std::cout << "Counting Sort: O(n + k)" << std::endl;
    std::cout << "Radix Sort: O(d * (n + b)) where d = digits, b = base" << std::endl;
    std::cout << "std::sort (QuickSort): O(n log n) average" << std::endl;
    std::cout << "\nWhen n=10000, k=1000:" << std::endl;
    std::cout << "Counting: ~" << 10000 + 1000 << " operations" << std::endl;
    std::cout << "QuickSort: ~" << 10000 * log2(10000) << " operations" << std::endl;
    std::cout << "Counting Sort is faster when k < n log n" << std::endl;
}

void ExperimentDesign::runAllExperiments() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "   RUNNING ALL EXPERIMENTS" << std::endl;
    std::cout << "========================================" << std::endl;
    
    runExperiment1_VaryingSize();
    runExperiment2_VaryingRange();
    runExperiment3_DifferentDistributions();
    runExperiment4_StabilityTest();
    runExperiment5_ComparisonVsStdSort();
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "   EXPERIMENTS COMPLETED" << std::endl;
    std::cout << "========================================" << std::endl;
}

void ExperimentDesign::saveResultsToCSV(const std::string& filename, 
                                       const std::vector<std::vector<double>>& data) {
    std::ofstream file(filename);
    if (file.is_open()) {
        // Write header
        file << "Experiment,Counting,Radix,Bucket,Pigeonhole,std::sort\n";
        
        // Write data
        for (const auto& row : data) {
            for (size_t i = 0; i < row.size(); i++) {
                if (i > 0) file << ",";
                file << row[i];
            }
            file << "\n";
        }
        file.close();
        std::cout << "Results saved to " << filename << std::endl;
    }
}

void ExperimentDesign::printTable(const std::vector<std::string>& headers,
                                 const std::vector<std::vector<std::string>>& rows) {
    // Calculate column widths
    std::vector<int> col_widths(headers.size());
    for (size_t i = 0; i < headers.size(); i++) {
        col_widths[i] = headers[i].length();
    }
    
    for (const auto& row : rows) {
        for (size_t i = 0; i < row.size(); i++) {
            if (row[i].length() > static_cast<size_t>(col_widths[i])) {
                col_widths[i] = row[i].length();
            }
        }
    }
    
    // Print header
    std::cout << "\n" << std::string(80, '-') << std::endl;
    for (size_t i = 0; i < headers.size(); i++) {
        std::cout << std::setw(col_widths[i] + 2) << std::left << headers[i];
    }
    std::cout << std::endl << std::string(80, '-') << std::endl;
    
    // Print rows
    for (const auto& row : rows) {
        for (size_t i = 0; i < row.size(); i++) {
            std::cout << std::setw(col_widths[i] + 2) << std::left << row[i];
        }
        std::cout << std::endl;
    }
    std::cout << std::string(80, '-') << std::endl;
}