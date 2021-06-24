/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include <vector>

namespace nnplib {
    /* Selection sort
     * Average Complexity: O(N^2)
     * Best Complexity: O(N^2)
     * Worse Complexity: O(N^2) */
    class selectionsort {
    public:
        // Selection sort
        static void sort(std::vector<double> &arr, int st = 0, int ed = -1);
    };
}
