/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "common.h"
#include <random>
constexpr int insort_cutoff = 10;

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

// copy from knuth_shuffle.cpp:6:14
void knuth_shuffle(vector<double> &arr, int st, int ed) {
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = st + 1; i < ed; ++i) {
        auto dist = std::uniform_int_distribution<int>(st, i);
        swap(arr[i], arr[dist(gen)]);
    }
}

// copy from insertion_sort.cpp:20:31
void insertion_sort(vector<double> &arr, int st, int ed) {
    for (int i = st + 1; i < ed; ++i) {
        double val = arr[i];
        int j = i;
        for (; j > st && arr[j - 1] > val; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = val;
    }
}

void __quicksort(vector<double> &arr, int lo, int hi) {
    if (lo >= hi) return;
    // optimization #1: Use insertion sort for small subarray
    if (hi - lo <= insort_cutoff) {
        insertion_sort(arr, lo, hi + 1);
        return;
    }
    // optimization #2: use the median
    int pos = partation(arr, lo, hi);
    __quicksort(arr, lo, pos - 1);
    __quicksort(arr, pos + 1, hi);
}

/* Quicksort
 * Average Complexity: O(NlgN)
 * Best Complexity: O(NlgN)
 * Worse Complexity: O(N^2)
 * Remark: Poor performance in partial sorted array, shuffle before sort is preferred
 */
void quicksort(vector<double> &arr, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size();
    // optimization #1: Shuffle the array
    knuth_shuffle(arr, st, ed);
    __quicksort(arr, st, ed - 1);
}

void __quicksort_threeway(vector<double> &arr, int lo, int hi) {
    if (lo >= hi) return;
    // optimization #2: Use insertion sort for small subarray
    if (hi - lo <= insort_cutoff) {
        insertion_sort(arr, lo, hi + 1);
        return;
    }
    int i = lo, lt = lo, gt = hi;
    double pivot = arr[lo];
    while (i <= gt) {
        if (arr[i] < pivot) swap(arr[lt++], arr[i++]);
        else if (arr[i] > pivot) swap(arr[gt--], arr[i]);
        else if (arr[i] == pivot) ++i;
    }
    __quicksort_threeway(arr, lo, lt - 1);
    __quicksort_threeway(arr, gt + 1, hi);
}

/* 3-way Quicksort
 * Average Complexity: O(NlgN)
 * Best Complexity: O(N)
 * Worse Complexity: O(N^2)
 * Remark: Improve quicksort performance when duplicate keys
 */
void quicksort_threeway(vector<double> &arr, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size();
    knuth_shuffle(arr, st, ed);
    __quicksort_threeway(arr, st, ed - 1);
}

void __quicksort_dualpovit(vector<double> &arr, int lo, int hi) {
    if (lo >= hi) return;
    // optimization #2: Use insertion sort for small subarray
    if (hi - lo <= insort_cutoff) {
        insertion_sort(arr, lo, hi + 1);
        return;
    }
    int i = lo + 1, lt = lo + 1, gt = hi - 1;
    if (arr[lo] > arr[hi]) swap(arr[lo], arr[hi]);
    while (i <= gt) {
        if (arr[i] < arr[lo]) swap(arr[lt++], arr[i++]);
        else if (arr[i] > arr[hi]) swap(arr[gt--], arr[i]);
        else ++i;
    }
    swap(arr[lo], arr[--lt]);
    swap(arr[hi], arr[++gt]);
    __quicksort_dualpovit(arr, lo, lt - 1);
    __quicksort_dualpovit(arr, gt + 1, hi);
    // skip subarray with equal elements
    if (arr[lt] != arr[gt]) __quicksort_dualpovit(arr, lt + 1, gt - 1);
}

/* Dual-pivot Quicksort
 * Average Complexity: O(NlgN)
 * Best Complexity: O(NlgN)
 * Worse Complexity: O(N^2)
 * Remark: Fewer cache miss (?)
 */
void quicksort_dualpovit(vector<double> &arr, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size();
    knuth_shuffle(arr, st, ed);
    __quicksort_dualpovit(arr, st, ed - 1);
}

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    print_arr(arr);
    quicksort_dualpovit(arr);
    print_arr(arr);
    return 0;
}
