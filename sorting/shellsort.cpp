/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "shellsort.h"
#include "binary_search.h"

int shellsort::get_max_gap(int n) {
    int st = 0, ed = sizeof(tokuda_seq) / sizeof(tokuda_seq[0]) - 1;
    if (n <= 1) return 0;
    if (n > tokuda_seq[ed]) return ed;
    int mid;
    while (st <= ed) {
        mid = st + ((ed - st) / 2);
        if (n > tokuda_seq[mid]) st = mid + 1;
        else if (n < tokuda_seq[mid]) ed = mid - 1;
        else return mid - 1;
    }
    return (tokuda_seq[mid] < n) ? mid : mid - 1;
}

void shellsort::sort(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size();
    for (int index = get_max_gap(ed - st); index >= 0; --index) {
        int gap = tokuda_seq[index];
        for (int i = gap; i < ed; ++i) {
            double val = arr[st + i];
            int j = i;
            for (; j >= gap && arr[st + j - gap] > val; j -= gap) {
                arr[st + j] = arr[st + j - gap];
            }
            arr[st + j] = val;
        }
    }
}
