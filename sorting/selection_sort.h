/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include "common.h"

/* Selection sort
 * Average Complexity: O(N^2)
 * Best Complexity: O(N^2)
 * Worse Complexity: O(N^2) */
class Selectionsort {
public:
    // Selection sort
    static void sort(vector<double> &arr, int st = 0, int ed = -1);
};
