/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#include "binary_search.h"

int binary_search::search(const vector<double> &arr, double value, int mode, int st, int ed) {
    if (ed == -1) ed = arr.size() - 1;
    else --ed;
    if (mode == nearest) {
        if (arr[st] > value) return st;
        if (arr[ed] < value) return ed;
    } else if (mode == less_than) {
        if (arr[st] > value) return st - 1;
        if (arr[ed] < value) return ed;
    }
    
    int mid;
    while (st <= ed) {
        mid = st + (ed - st) / 2;
        if (arr[mid] < value) st = mid + 1;
        else if (arr[mid] > value) ed = mid - 1;
        else return mid;
    }
    if (mode == less_than) return (arr[mid] < value) ? mid : mid - 1;
    if (mode == nearest) return (value - arr[st] > arr[ed] - value) ? st : ed;
    return -1;
}
