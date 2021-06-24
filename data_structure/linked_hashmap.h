/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#pragma once
#include "linked_list.h"
#include <vector>

namespace nnplib {
    class linked_hashmap {
    public:
        using node = linked_list::node;
        void insert(const std::string &key, const std::string &value;
        const node *find(const std::string &key) const;
        bool remove(const std::string &key);
        void clear();
        
    private:
        int resize();
        std::vector<linked_list *> arr_;
        int capacity_;
        int count_;
    };
}
