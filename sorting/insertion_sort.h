/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include <vector>

namespace nnplib {
    /* Insertion sort
         * Average Complexity: O(N^2)
         * Best Complexity: O(N)
         * Worse Complexity: O(N^2)
         * Remark: Good for small array or partially ordered array */
    class insertionsort {
    public:
        // Insertion sort: Original implementation
        static void sort(std::vector<double> &arr, int st = 0, int ed = -1);
        // Insertion sort: Shift elements instead of std::swapping
        static void sort_v2(std::vector<double> &arr, int st = 0, int ed = -1);
        // Insertion sort: Use binary search to find the insertion port
        static void sort_v3(std::vector<double> &arr, int st = 0, int ed = -1);
    };
}
