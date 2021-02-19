/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "knuth_shuffle.h"
#include "common.h"

namespace nnplib {
    void knuthshuffle::shuffle(std::vector<double> &arr, int st, int ed) {
        if (ed == -1) ed = arr.size();
        for (int i = st + 1; i < ed; ++i) {
            std::swap(arr[i], arr[get_random_integer(st, i)]);
        }
    }
}
