/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "quicksort.h"
#include "knuth_shuffle.h"

namespace nnplib {
    double quicksort::select(const std::vector<double> &arr, int k, int st, int ed) {
        if (ed == -1) ed = arr.size();
        if (st == ed - 1) return arr[st];
        --k;
        std::vector<double> temp(arr.begin() + st, arr.begin() + ed);
        knuthshuffle::shuffle(temp);
        int lo = 0, hi = temp.size() - 1;
        while (hi > lo) {
            int pos = partation(temp, lo, hi);
            if (pos > k) hi = pos - 1;
            else if (pos < k) lo = pos + 1;
            else return temp[k];
        }
        return temp[k];
    }
}
