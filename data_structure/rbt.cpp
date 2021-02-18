/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#include "rbt.h"

const rbt::node *rbt::find(const string &key) const {
    return find(root_, key);
}

rbt::node *rbt::find(rbt::node *root, const string &key) {
    if (!root) return nullptr;
    if (root->key > key) return find(root->left, key);
    else if (root->key < key) return find(root->right, key);
    return root;
}

void rbt::insert(const string &key, const string &val) {
    root_ = insert(root_, key, val);
}

rbt::node *rbt::insert(rbt::node *root, const string &key, const string &val) {
    if (!root) {
        ++count_;
        return new node { .key = key, .value = val };
    }
    if (root->key > key) root->left = insert(root->left, key, val);
    else if (root->key < key) root->right = insert(root->right, key, val);
    else root->value = val;
    if (is_red(root->right) && !is_red(root->left)) root = rotate_left(root);
    if (is_red(root->left) && is_red(root->left->left)) root = rotate_right(root);
    if (is_red(root->left) && is_red(root->right)) flip_color(root);
    return root;
}

rbt::node *rbt::rotate_left(rbt::node *root) {
    if (!is_red(root->right)) return root;
    node *ptr = root->right;
    root->right = ptr->right;
    ptr->left = root;
    ptr->col = root->col;
    root->col = node::color::red;
    return ptr;
}

rbt::node *rbt::rotate_right(rbt::node *root) {
    if (!is_red(root->left)) return root;
    node *ptr = root->left;
    root->left = ptr->right;
    ptr->right = root;
    ptr->col = root->col;
    root->col = node::color::red;
    return ptr;
}

void rbt::flip_color(rbt::node *root) {
    if (!is_red(root) && is_red(root->left) && is_red(root->right)) return;
    root->col = node::color::red;
    root->left->col = node::color::black;
    root->right->col = node::color::black;
}

bool rbt::is_red(rbt::node *root) {
    if (!root) return false;
    return root->col == node::color::red;
}


