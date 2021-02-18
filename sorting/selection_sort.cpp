/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "selection_sort.h"

void selectionsort::sort(vector<double> &arr, int st, int ed) {
    if (ed == -1) ed = arr.size();
    for (int i = st; i < ed; ++i) {
        int min = i;
        for (int j = i + 1; j < ed; ++j) {
            if (arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }
}
