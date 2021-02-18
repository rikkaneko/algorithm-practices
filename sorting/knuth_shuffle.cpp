/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "knuth_shuffle.h"

void knuthshuffle::shuffle(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size();
    for (int i = st + 1; i < ed; ++i) {
        swap(arr[i], arr[get_random_integer(st, i)]);
    }
}
