#ifndef EXPERIMENT_DESIGN_H
#define EXPERIMENT_DESIGN_H

#include <vector>
#include <string>
#include <functional>

class ExperimentDesign {
public:
    // Experiment 1: Varying Input Size
    static void runExperiment1_VaryingSize();
    
    // Experiment 2: Varying Value Range
    static void runExperiment2_VaryingRange();
    
    // Experiment 3: Different Data Distributions
    static void runExperiment3_DifferentDistributions();
    
    // Experiment 4: Stability Test
    static void runExperiment4_StabilityTest();
    
    // Experiment 5: Comparison vs std::sort
    static void runExperiment5_ComparisonVsStdSort();
    
    // Run all experiments
    static void runAllExperiments();
    
private:
    static void saveResultsToCSV(const std::string& filename, 
                                 const std::vector<std::vector<double>>& data);
    static void printTable(const std::vector<std::string>& headers,
                          const std::vector<std::vector<std::string>>& rows);
};

#endif