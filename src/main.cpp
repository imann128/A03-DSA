#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include "counting_sort.h"
#include "radix_sort.h"
#include "bucket_sort.h"
#include "pigeonhole_sort.h"
#include "utils.h"
#include "experiment_design.h"
#include "comparison_sort.h"

using namespace std;
using namespace std::chrono;

void showMenu() {
    cout << "\n========================================" << endl;
    cout << "    CS250: NON-COMPARISON SORTING" << endl;
    cout << "========================================" << endl;
    cout << "1. Demo all sorting algorithms" << endl;
    cout << "2. Run Experiment 1: Varying Input Size" << endl;
    cout << "3. Run Experiment 2: Varying Value Range" << endl;
    cout << "4. Run Experiment 3: Different Data Distributions" << endl;
    cout << "5. Run Experiment 4: Stability Test" << endl;
    cout << "6. Run Experiment 5: Compare with std::sort" << endl;
    cout << "7. Run ALL experiments" << endl;
    cout << "8. Test individual algorithm performance" << endl;
    cout << "9. Show algorithm explanations" << endl;
    cout << "0. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Choice: ";
}

void demoAllAlgorithms() {
    cout << "\n=== DEMONSTRATING ALL ALGORITHMS ===" << endl;
    
    vector<int> test = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Test array: ";
    Utils::printArray(test);
    
    cout << fixed << setprecision(3);
    
    // 1. Counting Sort (Stable)
    auto start = high_resolution_clock::now();
    vector<int> cs_stable = CountingSort::stableSort(test);
    auto end = high_resolution_clock::now();
    double time_cs_stable = duration<double, milli>(end - start).count();
    
    cout << "\n1. Counting Sort (Stable):" << endl;
    cout << "   Result: ";
    Utils::printArray(cs_stable);
    cout << "   Time: " << time_cs_stable << " ms" << endl;
    
    // 2. Counting Sort (Non-stable)
    start = high_resolution_clock::now();
    vector<int> cs_nonstable = CountingSort::nonStableSort(test);
    end = high_resolution_clock::now();
    double time_cs_nonstable = duration<double, milli>(end - start).count();
    
    cout << "\n2. Counting Sort (Non-stable):" << endl;
    cout << "   Result: ";
    Utils::printArray(cs_nonstable);
    cout << "   Time: " << time_cs_nonstable << " ms" << endl;
    
    // 3. LSD Radix Sort
    start = high_resolution_clock::now();
    vector<int> radix_result = RadixSort::sort(test);
    end = high_resolution_clock::now();
    double time_radix = duration<double, milli>(end - start).count();
    
    cout << "\n3. LSD Radix Sort:" << endl;
    cout << "   Result: ";
    Utils::printArray(radix_result);
    cout << "   Time: " << time_radix << " ms" << endl;
    
    // 4. Bucket Sort
    start = high_resolution_clock::now();
    vector<int> bucket_result = BucketSort::sort(test);
    end = high_resolution_clock::now();
    double time_bucket = duration<double, milli>(end - start).count();
    
    cout << "\n4. Bucket Sort:" << endl;
    cout << "   Result: ";
    Utils::printArray(bucket_result);
    cout << "   Time: " << time_bucket << " ms" << endl;
    
    // 5. Pigeonhole Sort
    start = high_resolution_clock::now();
    vector<int> pigeonhole_result = PigeonholeSort::sort(test);
    end = high_resolution_clock::now();
    double time_pigeonhole = duration<double, milli>(end - start).count();
    
    cout << "\n5. Pigeonhole Sort:" << endl;
    cout << "   Result: ";
    Utils::printArray(pigeonhole_result);
    cout << "   Time: " << time_pigeonhole << " ms" << endl;
    
    // 6. std::sort (Comparison sort)
    start = high_resolution_clock::now();
    vector<int> std_result = ComparisonSort::stdSort(test);
    end = high_resolution_clock::now();
    double time_std = duration<double, milli>(end - start).count();
    
    cout << "\n6. std::sort (QuickSort variant):" << endl;
    cout << "   Result: ";
    Utils::printArray(std_result);
    cout << "   Time: " << time_std << " ms" << endl;
    
    // Verify all produce same result
    bool all_equal = (cs_stable == cs_nonstable) &&
                    (cs_nonstable == radix_result) &&
                    (radix_result == bucket_result) &&
                    (bucket_result == pigeonhole_result) &&
                    (pigeonhole_result == std_result);
    
    cout << "\n✓ All algorithms produce identical sorted arrays: " 
         << (all_equal ? "YES" : "NO") << endl;
    
    // Show time comparison
    cout << "\n=== TIME COMPARISON (ms) ===" << endl;
    cout << "Counting Sort (Stable): " << time_cs_stable << endl;
    cout << "Counting Sort (Non-stable): " << time_cs_nonstable << endl;
    cout << "Radix Sort: " << time_radix << endl;
    cout << "Bucket Sort: " << time_bucket << endl;
    cout << "Pigeonhole Sort: " << time_pigeonhole << endl;
    cout << "std::sort: " << time_std << endl;
}

void testIndividualAlgorithm() {
    cout << "\n=== TEST INDIVIDUAL ALGORITHM ===" << endl;
    
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    vector<int> arr = Utils::generateRandomArray(size, 0, 1000);
    
    cout << "\nSelect algorithm:" << endl;
    cout << "1. Counting Sort (Stable)" << endl;
    cout << "2. Counting Sort (Non-stable)" << endl;
    cout << "3. LSD Radix Sort" << endl;
    cout << "4. Bucket Sort" << endl;
    cout << "5. Pigeonhole Sort" << endl;
    cout << "6. std::sort" << endl;
    cout << "Choice: ";
    
    int choice;
    cin >> choice;
    
    auto start = high_resolution_clock::now();
    vector<int> result;
    
    switch(choice) {
        case 1:
            result = CountingSort::stableSort(arr);
            cout << "Running Counting Sort (Stable)..." << endl;
            break;
        case 2:
            result = CountingSort::nonStableSort(arr);
            cout << "Running Counting Sort (Non-stable)..." << endl;
            break;
        case 3:
            result = RadixSort::sort(arr);
            cout << "Running LSD Radix Sort..." << endl;
            break;
        case 4:
            result = BucketSort::sort(arr);
            cout << "Running Bucket Sort..." << endl;
            break;
        case 5:
            result = PigeonholeSort::sort(arr);
            cout << "Running Pigeonhole Sort..." << endl;
            break;
        case 6:
            result = ComparisonSort::stdSort(arr);
            cout << "Running std::sort..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
    }
    
    auto end = high_resolution_clock::now();
    double time = duration<double, milli>(end - start).count();
    
    cout << "Time: " << fixed << setprecision(3) << time << " ms" << endl;
    cout << "Sorted correctly: " << (Utils::isSorted(result) ? "YES" : "NO") << endl;
}

void showAlgorithmExplanations() {
    cout << "\n=== ALGORITHM EXPLANATIONS ===" << endl;
    
    cout << "\n1. COUNTING SORT:" << endl;
    cout << "   - Non-comparison, integer sorting" << endl;
    cout << "   - Time: O(n + k) where k = range" << endl;
    cout << "   - Space: O(n + k)" << endl;
    cout << "   - Stable version preserves order of equal elements" << endl;
    cout << "   - Best when k (range) is small" << endl;
    
    cout << "\n2. LSD RADIX SORT:" << endl;
    cout << "   - Sorts digit by digit from LSD to MSD" << endl;
    cout << "   - Uses Counting Sort as subroutine" << endl;
    cout << "   - Time: O(d * (n + b)) where d = digits, b = base" << endl;
    cout << "   - Good for fixed-length integers" << endl;
    
    cout << "\n3. BUCKET SORT:" << endl;
    cout << "   - Distributes elements into buckets" << endl;
    cout << "   - Sorts each bucket individually" << endl;
    cout << "   - Average: O(n + k), Worst: O(n²)" << endl;
    cout << "   - Assumes uniform distribution" << endl;
    
    cout << "\n4. PIGEONHOLE SORT:" << endl;
    cout << "   - Places each element in its numbered 'hole'" << endl;
    cout << "   - Similar to Counting Sort but with slots" << endl;
    cout << "   - Time: O(n + range)" << endl;
    cout << "   - Simple but needs O(range) space" << endl;
    
    cout << "\n5. COMPARISON SORTS (std::sort):" << endl;
    cout << "   - std::sort uses QuickSort variant" << endl;
    cout << "   - Time: O(n log n) average" << endl;
    cout << "   - General purpose, no assumptions about data" << endl;
    cout << "   - Usually faster for random data with large range" << endl;
}

int main() {
    cout << "========================================" << endl;
    cout << "  CS250 ASSIGNMENT 3: SORTING ALGORITHMS" << endl;
    cout << "========================================" << endl;
    
    int choice;
    do {
        showMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                demoAllAlgorithms();
                break;
            case 2:
                ExperimentDesign::runExperiment1_VaryingSize();
                break;
            case 3:
                ExperimentDesign::runExperiment2_VaryingRange();
                break;
            case 4:
                ExperimentDesign::runExperiment3_DifferentDistributions();
                break;
            case 5:
                ExperimentDesign::runExperiment4_StabilityTest();
                break;
            case 6:
                ExperimentDesign::runExperiment5_ComparisonVsStdSort();
                break;
            case 7:
                ExperimentDesign::runAllExperiments();
                break;
            case 8:
                testIndividualAlgorithm();
                break;
            case 9:
                showAlgorithmExplanations();
                break;
            case 0:
                cout << "\nExiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
        
        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}