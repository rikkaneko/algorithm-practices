/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include "common.h"

/* Quicksort
 * Average Complexity: O(NlgN)
 * Best Complexity: O(NlgN)
 * Worse Complexity: O(N^2)
 * Remark: Poor performance in partial sorted array, shuffle before sort is preferred */
class Quicksort {
public:
    static constexpr int insort_cutoff = 10;
    // Quicksort: Original implementation
    static void sort(vector<double> &arr, int st = 0, int ed = -1);
    /* 3-way Quicksort
     * Average Complexity: O(NlgN)
     * Best Complexity: O(N)
     * Worse Complexity: O(N^2) */
    static void sort_v2(vector<double> &arr, int st = 0, int ed = -1);
    /* Dual-pivot Quicksort
     * Average Complexity: O(NlgN)
     * Best Complexity: O(NlgN)
     * Worse Complexity: O(N^2)
     * Remark: Fewer cache miss (?) */
    static void sort_v3(vector<double> &arr, int st = 0, int ed = -1);
    /* Quick select: find the kth smallest item in the array
     * Average Complexity: O(N) # 3.38 n for k = n/2
     * Best Complexity: O(N)
     * Worse Complexity: O(N^2)
     * Remark: Complexity linearly depends on k */
    static double select(const vector<double> &arr, int k, int st = 0, int ed = -1);


private:
    static int partation(vector<double> &arr, int lo, int hi);
    static void __sort(vector<double> &arr, int lo, int hi);
    static void __sort_v2(vector<double> &arr, int lo, int hi);
    static void __sort_v3(vector<double> &arr, int lo, int hi);
};
