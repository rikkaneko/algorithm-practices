/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "common.h"
constexpr int insort_cutoff = 10;

void merge(vector<double> &arr, vector<double> &aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; ++k) aux[k] = arr[k];
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
        if (i > mid) arr[k] = aux[j++];
        else if (j > hi) arr[k] = aux[i++];
        else if (aux[i] < aux[j]) arr[k] = aux[i++];
        else arr[k] = arr[j++];
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

void mergesort(vector<double> &arr, vector<double> &aux, int lo, int hi) {
    if (lo >= hi) return;
    // optimization #2: Use insertion sort for small subarray
    if (hi - lo <= insort_cutoff) {
        insertion_sort(arr, lo, hi + 1);
        return;
    }
    int mid = lo + ((hi - lo) / 2);
    mergesort(arr, aux, lo, mid);
    mergesort(arr, aux, mid + 1, hi);
    // optimization #3: skip already sorted subarrays to merge
    if (arr[mid] < arr[mid + 1]) return;
    merge(arr, aux, lo, mid, hi);
}

/* Mergesort
 * Average Complexity: O(NlgN)
 * Best Complexity: O(NlgN)
 * Worse Complexity: O(NlgN)
 * Remark: Stable */
void mergesort(vector<double> &arr, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size();
    // optimization #1: use pre-allocated array for buffer.
    vector<double> aux(arr.size());
    mergesort(arr, aux, st, ed - 1);
}

// Iterative / Non-recursive / Button-up Mergesort
void mergesort_it(vector<double> &arr, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size();
    int n = ed - st;
    vector<double> aux(arr.size());
    for (int sz = 1; sz < n; sz += sz) {
        for (int i = st; i < ed - sz; i += sz + sz) {
            // optimization #3: skip already sorted subarrays to merge
            if (arr[i + sz - 1] < arr[i + sz]) continue;
            merge(arr, aux, i, i + sz - 1, (i + sz + sz - 1 < ed - 1) ? i + sz + sz - 1 : ed - 1);
        }
    }
}

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    print_arr(arr);
    mergesort_it(arr);
    print_arr(arr);
    return 0;
}
