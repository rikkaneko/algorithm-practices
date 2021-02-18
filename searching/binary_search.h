/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#pragma once
#include "common.h"

/* Binary Search
 * Search Worst Complexity: O(lgN)
 * Search Average Complexity: O(lgN) */
class binary_search {
public:
    static constexpr int exact = 0; // search for the exact element, otherwise return -1
    static constexpr int nearest = 1; // search for the closest or equal element
    static constexpr int less_than = 2; // search for the first element less than value
    static int search(const vector<double> &arr, double value, int mode = exact, int st = 0, int ed = -1);
};

