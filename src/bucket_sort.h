#ifndef BUCKET_SORT_H
#define BUCKET_SORT_H

#include <vector>

class BucketSort {
public:
    // Bucket sort for integers (scaled to 0-1 range)
    static std::vector<int> sort(const std::vector<int>& arr);
    
    // Analyze complexity
    static void analyze(const std::vector<int>& arr);
    
private:
    static int getBucketIndex(int value, int min_val, int max_val, int bucket_count);
};

#endif