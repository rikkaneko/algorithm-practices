/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#pragma once
#include "common.h"
#include <optional>
#include <queue>
using std::optional;
using std::queue;

/* Binary Search Tree
 * Search Worst Complexity: O(N)
 * Search Average Complexity: O(lgN)
 * Insert Worst Complexity: O(N)
 * Insert Average Complexity: O(lgN)
 * Delete Worst Complexity: O(N)
 * Delete Average Complexity: O(sqrt(N)) */
class bst {
public:
    class iterator;
    
    struct node {
        string key;
        string value;
        node *left = nullptr;
        node *right = nullptr;
        
    };
    
    class iterator {
    public:
        explicit iterator(const bst &bst): bst_(bst), nodes_(bst.inorder()) {}
        
        const node *get() const {
            if (nodes_.empty()) return nullptr;
            return nodes_.front();
        }
        
        void refresh() { nodes_ = bst_.inorder(); }
        
        void operator++() { nodes_.pop(); }
    
    private:
        queue<const node *> nodes_;
        const bst &bst_;
    };
    
    void insert(const string &key, const string &val);
    const node *find(const string &key) const;
    bool remove(const string &key);
    optional<node> remove_min();
    optional<node> remove_max();
    queue<const node *> inorder() const;
    void clear();
    
    iterator get_iterator() const { return iterator(*this); }
    
    int get_size() const { return count_; }
    
    ~bst() { clear(); }

private:
    node *insert(node *root, const string &key, const string &val);
    static node *find(node *root, const string &key);
    static node *find_min(node *root);
    static node *find_max(node *root);
    static void inorder(node *root, queue<const node *> &nodes);
    node *remove(node *root, const string &key);
    void clear(node *root);
    node *root_ = nullptr;
    int count_ = 0;
};

