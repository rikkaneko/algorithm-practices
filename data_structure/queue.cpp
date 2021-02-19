/* This file is part of algorithm_practices.
 * Copyright (c) 2020 rikkaneko. */
#include "queue.h"

namespace nnplib {
    void queue::insert(double key) {
        if (count_ >= arr_.max_size())
            arr_.resize((count_ > 0) ? count_ * 2 : 2);
        arr_[++count_] = key;
        swim(count_);
    }
    
    double queue::pop_max() {
        double max = arr_[1];
        std::swap(arr_[1], arr_[count_--]);
        sink(1);
        return max;
    }
    
    bool queue::pop(double key) {
        int pos = 0;
        for (int i = 1; i <= count_; ++i) {
            if (arr_[i] == key) pos = i;
        }
        if (!pos) return false;
        std::swap(arr_[pos], arr_[count_--]);
        if (arr_[pos] > key) swim(pos);
        else if (arr_[pos] < key) sink(pos);
        return true;
    }
    
    void queue::swim(int pos) {
        int parent = pos / 2;
        while (pos > 1 && arr_[parent] < arr_[pos]) {
            std::swap(arr_[parent], arr_[pos]);
            pos = parent;
            parent /= 2;
        }
    }
    
    void queue::sink(int pos) {
        int child = pos * 2;
        while (child <= count_) {
            if (child < count_ && arr_[child] < arr_[child + 1]) ++child;
            if (arr_[pos] >= arr_[child]) break;
            std::swap(arr_[pos], arr_[child]);
            pos = child;
            child *= 2;
        }
    }
}
