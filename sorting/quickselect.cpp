/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "common.h"
#include <random>

// copy from knuth_shuffle.cpp:6:14
void knuth_shuffle(vector<double> &arr, int st, int ed) {
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = st + 1; i < ed; ++i) {
        auto dist = std::uniform_int_distribution<int>(st, i);
        swap(arr[i], arr[dist(gen)]);
    }
}

// copy from quicksort.cpp:7:18
int partation(vector<double> &arr, int lo, int hi) {
    double pivot = arr[hi];
    int i = lo, j = hi - 1;
    while (true) {
        while (i < hi && arr[i] < pivot) ++i;
        while (j > lo && arr[j] >= pivot) --j;
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[hi]);
    return i;
}

/* Quick select: find the kth smallest item in the array
 * Average Complexity: O(nN) # 3.38 n for k = n/2
 * Best Complexity: O(N)
 * Worse Complexity: O(N^2)
 * Remark: Complexity linearly depends on k
 */
double quickselect(const vector<double> &arr, int k, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size();
    if (k <= 0) return NAN;
    vector<double> seq(arr);
    knuth_shuffle(seq, st, ed);
    while (ed > st) {
        int pos = partation(seq, st, ed);
        if (pos > k) ed = pos - 1;
        else if (pos < k) st = pos + 1;
        else return seq[k];
    }
    return seq[k];
}

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    print_arr(arr);
    std::cout << 5 << "th minimum element: " << quickselect(arr, 5) << std::endl;
}
