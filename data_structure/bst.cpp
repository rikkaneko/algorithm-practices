/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#include "bst.h"

void bst::insert(const string &key, const string &val) {
    root_ = insert(root_, key, val);
}

const bst::node *bst::find(const string &key) const {
    return find(root_, key);
}

bool bst::remove(const string &key) {
    if (!find(root_, key)) return false;
    remove(root_, key);
    return true;
}

optional<bst::node> bst::remove_min() {
    node *ptr = find_min(root_);
    if (!ptr) return {};
    node node(*ptr);
    remove(root_, ptr->key);
    return node;
}

optional<bst::node> bst::remove_max() {
    node *ptr = find_max(root_);
    if (!ptr) return {};
    node node(*ptr);
    remove(root_, ptr->key);
    return node;
}

void bst::clear() {
    clear(root_);
    root_ = nullptr;
    count_ = 0;
}

bst::node *bst::insert(node *root, const string &key, const string &val) {
    if (!root) {
        ++count_;
        return new node { .key = key, .value = val };
    }
    if (root->key > key) root->left = insert(root->left, key, val);
    else if (root->key < key) root->right = insert(root->right, key, val);
    else root->value = val;
    return root;
}

bst::node *bst::find(bst::node *root, const string &key) {
    if (!root) return nullptr;
    if (root->key > key) return find(root->left, key);
    else if (root->key < key) return find(root->right, key);
    return root;
}

bst::node *bst::find_min(bst::node *root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

bst::node *bst::find_max(bst::node *root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}


bst::node *bst::remove(node *root, const string &key) {
    if (!root) return nullptr;
    node *succ = root;
    if (root->key > key) root->left = remove(root->left, key);
    else if (root->key < key) root->right = remove(root->right, key);
    else {
        if (!root->left) succ = root->right;
        else if (!root->right) succ = root->left;
        else {
            succ = new node(*find_min(root->right));
            succ->left = root->left;
            succ->right = remove(root->right, succ->key);
        }
        delete root;
        --count_;
    }
    return succ;
}

queue<const bst::node *> bst::inorder() const {
    queue<const node *> ordered;
    inorder(root_, ordered);
    return ordered;
}

void bst::inorder(bst::node *root, queue<const node *> &nodes) {
    if (!root) return;
    inorder(root->left, nodes);
    nodes.emplace(root);
    inorder(root->right, nodes);
}

void bst::clear(bst::node *root) {
    if (!root) return;
    clear(root->left);
    clear(root->right);
    delete root;
}
