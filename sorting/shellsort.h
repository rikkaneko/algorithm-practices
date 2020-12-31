/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include "common.h"

/* Shell sort
 * Average Complexity: -
 * Best Complexity: -
 * Worse Complexity: O(N^2) */
class Shellsort {
public:
    /* A108870 Tokuda's good set of increments for Shell sort.
     * Source: https://oeis.org/A108870 */
    static constexpr int tokuda_seq[] = { 1, 4, 9, 20, 46, 103, 233, 525, 1182, 2660, 5985, 13467, 30301, 68178, 153401,
                                          345152, 776591, 1747331, 3931496, 8845866, 19903198, 44782196, 100759940,
                                          226709866, 510097200, 1147718700 };
    
    // Shell sort
    static void sort(vector<double> &arr, int st = 0, int ed = -1);

private:
    static int get_max_gap(int n);
};
