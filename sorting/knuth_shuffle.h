/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include <vector>

namespace nnplib {
    class knuthshuffle {
    public:
        // Knuth Shuffle
        static void shuffle(std::vector<double> &arr, int st = 0, int ed = -1);
    };
}
