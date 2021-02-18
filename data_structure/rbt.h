/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#pragma once
#include "common.h"

/* Left-leaning Red-Black BSTs */
class rbt {
public:
    struct node {
        enum class color { black = 0, red = 1 };
        string key;
        string value;
        color col = color::red;
        node *left = nullptr;
        node *right = nullptr;
    };
    
    const node *find(const string &key) const;
    void insert(const string &key, const string &val);
    
    int get_size() const { return count_; }

private:
    static node *find(node *root, const string &key);
    node *insert(node *root, const string &key, const string &val);
    static node *rotate_left(node *root);
    static node *rotate_right(node *root);
    static void flip_color(node *root);
    static bool is_red(node *root);
    node *root_ = nullptr;
    int count_ = 0;
};

