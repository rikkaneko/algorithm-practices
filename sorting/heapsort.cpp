/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "heapsort.h"

void heapsort::sink(vector<double> &arr, int pos, int st, int ed) {
    int child = st + (pos - st) * 2 + 1;
    while (child <= ed) {
        if (child < ed && arr[child] < arr[child + 1]) ++child;
        if (arr[pos] >= arr[child]) break;
        swap(arr[pos], arr[child]);
        pos = child;
        child = st + (child - st) * 2 + 1;
    }
}

void heapsort::sort(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size();
    int n = ed - st;
    for (int k = st + n / 2 - 1; k >= st; --k) {
        sink(arr, k, st, ed - 1);
    }
    while (st < ed) {
        swap(arr[st], arr[ed-- - 1]);
        sink(arr, st, st, ed - 1);
    }
}
