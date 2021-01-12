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
class BST {
public:
    class Iterator;
    
    class Node {
        friend class BST;
        
        friend class Iterator;
    
    public:
        Node(const string &key, const string &val, Node *left = nullptr, Node *right = nullptr)
                : left_(left), right_(right), key_(key), val_(val) {}
        
        Node(Node &node) {
            key_ = node.key_;
            val_ = node.val_;
        }
        
        Node(Node &&node) noexcept {
            key_ = std::move(node.key_);
            val_ = std::move(node.val_);
        }
        
        ~Node() {}
        
        const string &get_key() const { return key_; }
        
        const string &get_val() const { return val_; }
    
    private:
        Node *left_ = nullptr;
        Node *right_ = nullptr;
        string key_;
        string val_;
        int count_ = 1;
    };
    
    class Iterator {
    public:
        explicit Iterator(const BST &bst): bst_(bst), nodes_(bst.inorder()) {}
        
        const Node *get() const {
            if (nodes_.empty()) return nullptr;
            return nodes_.front();
        }
        
        void refresh() { nodes_ = bst_.inorder(); }
        
        void operator++() { nodes_.pop(); }
    
    private:
        queue<const Node *> nodes_;
        const BST &bst_;
    };
    
    void insert(const string &key, const string &val);
    const Node *find(const string &key) const;
    bool remove(const string &key);
    optional<Node> remove_min();
    optional<Node> remove_max();
    queue<const Node *> inorder() const;
    void clear();
    
    Iterator get_iterator() const { return Iterator(*this); }
    
    int get_size() const { return count_; }
    
    ~BST() { clear(); }

private:
    Node *__insert(Node *root, const string &key, const string &val);
    static Node *__find(Node *root, const string &key);
    static Node *__find_min(Node *root);
    static Node *__find_max(Node *root);
    static void __inorder(Node *root, queue<const Node *> &nodes);
    Node *__remove(Node *root, const string &key);
    void __clear(Node *root);
    Node *root_ = nullptr;
    int count_ = 0;
};

