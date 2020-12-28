/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include <random>
#include "common.h"

void knuth_shuffle(vector<double> &arr, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size();
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = st + 1; i < ed; ++i) {
        auto dist = std::uniform_int_distribution<int>(st, i);
        swap(arr[i], arr[dist(gen)]);
    }
}

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    print_arr(arr);
    knuth_shuffle(arr);
    print_arr(arr);
    return 0;
}
