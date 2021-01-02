/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "shellsort.h"

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    print_arr(arr);
    Shellsort::sort(arr, 8, 25);
    print_arr(arr);
    return is_sorted(arr, true, 8, 25);
}
