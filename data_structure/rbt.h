/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#pragma once
#include <string>

namespace nnplib {
    /* Left-leaning Red-Black BSTs */
    class rbt {
    public:
        struct node {
            enum color { black = 0, red = 1 };
            std::string key;
            std::string value;
            color col = red;
            node *left = nullptr;
            node *right = nullptr;
        };
        
        const node *find(const std::string &key) const;
        void insert(const std::string &key, const std::string &val);
        
        int get_size() const { return count_; }
    
    private:
        static node *find(node *root, const std::string &key);
        node *insert(node *root, const std::string &key, const std::string &val);
        static node *rotate_left(node *root);
        static node *rotate_right(node *root);
        static void flip_color(node *root);
        static bool is_red(node *root);
        node *root_ = nullptr;
        int count_ = 0;
    };
}
