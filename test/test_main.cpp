/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "heapsort.h"

int main(int argc, char *argv[]) {
    auto arr = parse_arg(argc, argv);
    print_arr(arr);
    Heapsort::sort(arr, 10, 35);
    print_arr(arr);
    return is_sorted(arr, true, 10, 35);
}
