/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#pragma once
#include "common.h"

/* Binary Heap (a.k.a Priority Queue)
 * Insert Complexity: lgN
 * Pop Max Complexity: lgN
 * Get Max Complexity: lgN */
class PriorityQueue {
public:
    explicit PriorityQueue(int n = 64): arr_(n) {}
    
    int get_size() const { return count_; }
    
    void insert(double key);
    double pop_max();
    bool pop(double key);

private:
    void swim(int pos);
    void sink(int pos);
    
    vector<double> arr_;
    int count_ = 0;
};
