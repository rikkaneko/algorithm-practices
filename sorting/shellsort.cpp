/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "shellsort.h"

int Shellsort::get_max_gap(int n) {
    if (n <= 1) return 0;
    int st = 0, ed = sizeof(tokuda_seq) - 1;
    while (st < ed) {
        int mid = st + ((ed - st) / 2);
        if (n > tokuda_seq[mid]) st = mid + 1;
        else if (n < tokuda_seq[mid]) ed = mid;
        else if (n == tokuda_seq[mid]) {
            return mid - 1;
        }
    }
    return (tokuda_seq[st] < n) ? st : st - 1;
}

void Shellsort::sort(vector<double> &arr, int st, int ed) {
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
