/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#include "binary_search.h"
#include "common.h"

int main(int argc, char *argv[]) {
    auto arr = nnplib::parse_arg(argc, argv);
    if (arr.empty()) return 0;
    double val = arr[arr.size() - 1];
    std::cout << nnplib::binary_search::search(arr, val, nnplib::binary_search::less_than, 0, arr.size() - 1)
              << std::endl;
    return 0;
}
