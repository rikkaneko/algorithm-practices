/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "common.h"

namespace nnplib {
    std::vector<double> parse_arg(int argc, char **argv) {
        std::vector<double> sequence;
        sequence.reserve(argc);
        for (int i = 1; i < argc; ++i) {
            double result;
            try { result = std::stod(argv[i]); }
            catch (...) { continue; }
            sequence.push_back(result);
        }
        return sequence;
    }
    
    int get_random_integer(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        auto dist = std::uniform_int_distribution<int>(min, max);
        return dist(gen);
    }
}
