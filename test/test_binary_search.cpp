/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#include "binary_search.h"

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    double val = arr[arr.size() - 1];
    std::cout << BinarySearch::search(arr, val, BinarySearch::less_than, 1, arr.size() - 1) << std::endl;
    return 0;
}