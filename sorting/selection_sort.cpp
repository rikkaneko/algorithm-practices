/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "common.h"

/* Selection sort
 * Average Complexity: O(N^2)
 * Best Complexity: O(N^2)
 * Worse Complexity: O(N^2) */
void selection_sort(vector<double> &arr, int st = 0, int ed = -1) {
    if (ed == -1) ed = arr.size();
    for (int i = st; i < ed; ++i) {
        int min = i;
        for (int j = i + 1; j < ed; ++j) {
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }
}

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    print_arr(arr);
    selection_sort(arr);
    print_arr(arr);
}
