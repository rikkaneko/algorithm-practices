/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "mergesort.h"
#include "insertion_sort.h"

void Mergesort::merge(vector<double> &arr, vector<double> &aux, int lo, int mid, int hi) {
    for (int k = lo; k <= hi; ++k) aux[k] = arr[k];
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
        if (i > mid) arr[k] = aux[j++];
        else if (j > hi) arr[k] = aux[i++];
        else if (aux[i] < aux[j]) arr[k] = aux[i++];
        else arr[k] = arr[j++];
    }
}

void Mergesort::sort(vector<double> &arr, vector<double> &aux, int lo, int hi) {
    if (lo >= hi) return;
    // optimization #2: Use insertion sort for small subarray
    if (hi - lo <= insort_cutoff) {
        Insertionsort::sort_v2(arr, lo, hi + 1);
        return;
    }
    int mid = lo + ((hi - lo) / 2);
    sort(arr, aux, lo, mid);
    sort(arr, aux, mid + 1, hi);
    // optimization #3: skip already sorted subarrays to merge
    if (arr[mid] < arr[mid + 1]) return;
    merge(arr, aux, lo, mid, hi);
}

void Mergesort::sort(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size();
    // optimization #1: use pre-allocated array for buffer.
    vector<double> aux(arr.size());
    sort(arr, aux, st, ed - 1);
}

void Mergesort::sort_v2(vector<double> &arr, int st, int ed) {
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
