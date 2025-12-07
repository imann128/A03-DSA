#ifndef PIGEONHOLE_SORT_H
#define PIGEONHOLE_SORT_H

#include <vector>

class PigeonholeSort {
public:
    static std::vector<int> sort(const std::vector<int>& arr);
    static void analyze(const std::vector<int>& arr);
};

#endif