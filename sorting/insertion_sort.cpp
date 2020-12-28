/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "common.h"

/* Insertion sort
 * Average Complexity: O(N^2)
 * Best Complexity: O(N)
 * Worse Complexity: O(N^2)
 * Remark: Good for small array or partially ordered array
 */
void insertion_sort(vector<double> &arr, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size() - 1;
    for (int i = st + 1; i <= ed; ++i) {
        for (int j = i; j > st && arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
}

void insertion_sort_half(vector<double> &arr, int st = 0, int ed = -1) {
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

int binary_search_nearest(const vector<double> &arr, double target, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size() - 1;
    while (st < ed) {
        int mid = st + ((ed - st) / 2);
        if (target > arr[mid]) st = mid + 1;
        else if (target < arr[mid]) ed = mid;
        else if (target == arr[mid]) return mid;
    }
    return st;
}

void insertion_sort_bsearch(vector<double> &arr, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size();
    for (int i = st + 1; i < ed; ++i) {
        // optimization #2: Use binary search to find the insertion port
        double val = arr[i];
        int pos = binary_search_nearest(arr, val, st, i);
        if (pos < i) {
            // CAUTION: check the condition j >= 0
            for (int j = i; j > pos; --j) arr[j] = arr[j - 1];
            arr[pos] = val;
        }
    }
}

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    print_arr(arr);
    insertion_sort_bsearch(arr);
    print_arr(arr);
    return 0;
}
