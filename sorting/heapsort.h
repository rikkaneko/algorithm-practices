/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include "common.h"

/* Heapsort
 * Average Complexity: O(NlgN)
 * Best Complexity: O(N)
 * Worse Complexity: O(NlgN) */
class Heapsort {
public:
    // Heapsort
    static void sort(vector<double> &arr, int st = 0, int ed = -1);

private:
    static void sink(vector<double> &arr, int pos, int st, int ed);
};
