/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "insertion_sort.h"
#include "common.h"

int main(int argc, char *argv[]) {
    auto arr = nnplib::parse_arg(argc, argv);
    nnplib::print_arr(arr);
    nnplib::insertionsort::sort_v3(arr);
    nnplib::print_arr(arr);
    return nnplib::is_sorted(arr);
}
