/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include <string>
#include <vector>
#include <iostream>
using std::vector;
using std::swap;

vector<double> parse_arg(int argc, char **argv) {
    vector<double> sequence;
    for (int i = 1; i < argc; ++i) {
        double result;
        try { result = std::stod(argv[i]); }
        catch (...) {}
        sequence.push_back(result);
    }
    return sequence;
}

template<typename T>
void print_arr(const vector<T> &arr) {
    for (auto &val: arr)
        std::cout << val << " ";
    std::endl(std::cout);
}
