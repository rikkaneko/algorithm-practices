/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include "common.h"

/* Mergesort
 * Average Complexity: O(NlgN)
 * Best Complexity: O(NlgN)
 * Worse Complexity: O(NlgN)
 * Remark: Stable */
class Mergesort {
public:
    static constexpr int insort_cutoff = 10;
    // Mergesort: Original implementation
    static void sort(vector<double> &arr, int st = 0, int ed = -1);
    // Iterative Mergesort (non-recursive)
    static void sort_v2(vector<double> &arr, int st = 0, int ed = -1);

private:
    static void merge(vector<double> &arr, vector<double> &aux, int lo, int mid, int hi);
    static void sort(vector<double> &arr, vector<double> &aux, int lo, int hi);
    
};
