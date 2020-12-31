/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "insertion_sort.h"

void Insertionsort::sort(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size() - 1;
    for (int i = st + 1; i <= ed; ++i) {
        for (int j = i; j > st && arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

void Insertionsort::sort_v2(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size();
    for (int i = st + 1; i < ed; ++i) {
        // optimization #1: Half exchanges, shift elements instead of swapping
        double val = arr[i];
        int j = i;
        for (; j > st && arr[j - 1] > val; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = val;
    }
}

int Insertionsort::binary_search_nearest(const vector<double> &arr, double target, int st, int ed) {
    while (st < ed) {
        int mid = st + ((ed - st) / 2);
        if (target > arr[mid]) st = mid + 1;
        else if (target < arr[mid]) ed = mid;
        else if (target == arr[mid]) return mid;
    }
    return st;
}

void Insertionsort::sort_v3(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size();
    for (int i = st + 1; i < ed; ++i) {
        // optimization #2: Use binary search to find the insertion port
        double val = arr[i];
        int pos = binary_search_nearest(arr, val, st, i);
        if (pos < i) {
            for (int j = i; j > pos; --j) arr[j] = arr[j - 1];
            arr[pos] = val;
        }
    }
}
