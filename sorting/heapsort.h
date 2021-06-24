/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include <vector>

namespace nnplib {
    /* Heapsort
     * Average Complexity: O(NlgN)
     * Best Complexity: O(N)
     * Worse Complexity: O(NlgN) */
    class heapsort {
    public:
        static void sort(std::vector<double> &arr, int st = 0, int ed = -1);
    
    private:
        static void sink(std::vector<double> &arr, int pos, int st, int ed);
    };
}
