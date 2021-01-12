/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#include "bst.h"

void BST::insert(const string &key, const string &val) {
    root_ = __insert(root_, key, val);
}

const BST::Node *BST::find(const string &key) const {
    return __find(root_, key);
}

bool BST::remove(const string &key) {
    if (!__find(root_, key)) return false;
    __remove(root_, key);
    return true;
}

optional<BST::Node> BST::remove_min() {
    Node *ptr = __find_min(root_);
    if (!ptr) return {};
    Node node(*ptr);
    __remove(root_, ptr->key_);
    return node;
}

optional<BST::Node> BST::remove_max() {
    Node *ptr = __find_max(root_);
    if (!ptr) return {};
    Node node(*ptr);
    __remove(root_, ptr->key_);
    return node;
}

void BST::clear() {
    __clear(root_);
    root_ = nullptr;
    count_ = 0;
}

BST::Node *BST::__insert(Node *root, const string &key, const string &val) {
    if (!root) {
        ++count_;
        return new Node(key, val);
    }
    if (root->key_ > key) root->left_ = __insert(root->left_, key, val);
    else if (root->key_ < key) root->right_ = __insert(root->right_, key, val);
    else root->val_ = val;
    return root;
}

BST::Node *BST::__find(BST::Node *root, const string &key) {
    if (!root) return nullptr;
    if (root->key_ > key) return __find(root->left_, key);
    else if (root->key_ < key) return __find(root->right_, key);
    return root;
}

BST::Node *BST::__find_min(BST::Node *root) {
    if (!root) return nullptr;
    while (root->left_) root = root->left_;
    return root;
}

BST::Node *BST::__find_max(BST::Node *root) {
    if (!root) return nullptr;
    while (root->right_) root = root->right_;
    return root;
}


BST::Node *BST::__remove(Node *root, const string &key) {
    if (!root) return nullptr;
    Node *succ = root;
    if (root->key_ > key) root->left_ = __remove(root->left_, key);
    else if (root->key_ < key) root->right_ = __remove(root->right_, key);
    else {
        if (!root->left_) succ = root->right_;
        else if (!root->right_) succ = root->left_;
        else {
            succ = new Node(*__find_min(root->right_));
            succ->left_ = root->left_;
            succ->right_ = __remove(root->right_, succ->key_);
        }
        delete root;
        --count_;
    }
    return succ;
}

queue<const BST::Node *> BST::inorder() const {
    queue<const Node *> ordered;
    __inorder(root_, ordered);
    return ordered;
}

void BST::__inorder(BST::Node *root, queue<const Node *> &nodes) {
    if (!root) return;
    __inorder(root->left_, nodes);
    nodes.emplace(root);
    __inorder(root->right_, nodes);
}

void BST::__clear(BST::Node *root) {
    if (!root) return;
    __clear(root->left_);
    __clear(root->right_);
    delete root;
}
