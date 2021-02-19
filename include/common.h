/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <random>

namespace nnplib {
    std::vector<double> parse_arg(int argc, char **argv);
    int get_random_integer(int min, int max);
    
    template<typename T>
    void print_arr(const std::vector<T> &arr, int st = 0, int ed = -1) {
        if (ed == -1) ed = arr.size();
        for (int i = st; i < ed; ++i)
            std::cout << arr[i] << " ";
        std::endl(std::cout);
    }
    
    template<typename T>
    int is_sorted(const std::vector<T> &arr, bool ascending = true, int st = 0, int ed = -1) {
        if (ed == -1) ed = arr.size();
        for (int i = st; i < ed - 1; ++i) {
            if ((ascending && arr[i] > arr[i + 1]) || (!ascending && arr[i] < arr[i + 1]))
                return -1;
        }
        return 0;
    }
}
