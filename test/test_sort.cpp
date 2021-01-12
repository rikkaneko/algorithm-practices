/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "insertion_sort.h"

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    print_arr(arr);
    Insertionsort::sort_v3(arr);
    print_arr(arr);
    return is_sorted(arr);
}
