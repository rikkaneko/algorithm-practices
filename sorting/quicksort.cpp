/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "quicksort.h"
#include "insertion_sort.h"
#include "knuth_shuffle.h"

int quicksort::partation(vector<double> &arr, int lo, int hi) {
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

void quicksort::__sort(vector<double> &arr, int lo, int hi) {
    if (lo >= hi) return;
    // optimization #1: Use insertion sort for small subarray
    if (hi - lo <= insort_cutoff) {
        insertionsort::sort_v2(arr, lo, hi + 1);
        return;
    }
    // optimization #2: use the median
    int pos = partation(arr, lo, hi);
    __sort(arr, lo, pos - 1);
    __sort(arr, pos + 1, hi);
}


void quicksort::sort(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size();
    // optimization #1: Shuffle the array
    knuthshuffle::shuffle(arr, st, ed);
    __sort(arr, st, ed - 1);
}

void quicksort::__sort_v2(vector<double> &arr, int lo, int hi) {
    if (lo >= hi) return;
    // optimization #2: Use insertion sort for small subarray
    if (hi - lo <= insort_cutoff) {
        insertionsort::sort_v2(arr, lo, hi + 1);
        return;
    }
    int i = lo, lt = lo, gt = hi;
    double pivot = arr[lo];
    while (i <= gt) {
        if (arr[i] < pivot) swap(arr[lt++], arr[i++]);
        else if (arr[i] > pivot) swap(arr[gt--], arr[i]);
        else if (arr[i] == pivot) ++i;
    }
    __sort_v2(arr, lo, lt - 1);
    __sort_v2(arr, gt + 1, hi);
}

void quicksort::sort_v2(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size();
    knuthshuffle::shuffle(arr, st, ed);
    __sort_v2(arr, st, ed - 1);
}

void quicksort::__sort_v3(vector<double> &arr, int lo, int hi) {
    if (lo >= hi) return;
    // optimization #2: Use insertion sort for small subarray
    if (hi - lo <= insort_cutoff) {
        insertionsort::sort_v2(arr, lo, hi + 1);
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
    __sort_v3(arr, lo, lt - 1);
    __sort_v3(arr, gt + 1, hi);
    // skip subarray with equal elements
    if (arr[lt] != arr[gt]) __sort_v3(arr, lt + 1, gt - 1);
}

void quicksort::sort_v3(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size();
    knuthshuffle::shuffle(arr, st, ed);
    __sort_v3(arr, st, ed - 1);
}
