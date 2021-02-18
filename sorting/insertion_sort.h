/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include "common.h"

/* Insertion sort
 * Average Complexity: O(N^2)
 * Best Complexity: O(N)
 * Worse Complexity: O(N^2)
 * Remark: Good for small array or partially ordered array */
class insertionsort {
public:
    // Insertion sort: Original implementation
    static void sort(vector<double> &arr, int st = 0, int ed = -1);
    // Insertion sort: Shift elements instead of swapping
    static void sort_v2(vector<double> &arr, int st = 0, int ed = -1);
    // Insertion sort: Use binary search to find the insertion port
    static void sort_v3(vector<double> &arr, int st = 0, int ed = -1);
};
