/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#pragma once
#include "common.h"

/* Double Linked list
 * Search Worst Complexity: O(N)
 * Search Average Complexity: O(N/2)
 * Insert Worst Complexity: O(N)
 * Insert Average Complexity: O(N)
 * Delete Worst Complexity: O(N)
 * Delete Average Complexity: O(N/2) */
class LinkedList {
public:
    class Iterator;
    
    class Node {
        friend class LinkedList;
    
        friend class LinkedList::Iterator;

    public:
        const string &get_key() const { return key_; }
    
        const string &get_val() const { return value_; }

    private:
        explicit Node(const string &key, const string &val, Node *prev = nullptr,
                      Node *next = nullptr): key_(key), value_(val), prev_(prev), next_(next) {}
    
        Node *prev_;
        Node *next_;
        string key_;
        string value_;
    };
    
    class Iterator {
    public:
        explicit Iterator(Node *node): ptr_(node) {}
    
        const Node *get() const { return ptr_; }
    
        void operator++() { if (ptr_) ptr_ = ptr_->next_; }

    private:
        Node *ptr_ = nullptr;
    };
    
    ~LinkedList() {
        clear();
    }
    
    void insert(const string &key, const string &val);
    bool remove(const string &key);
    const Node *find(const string &key) const;
    void clear();
    
    int get_size() const { return count_; }
    
    Iterator get_iterator() const { return Iterator(head_); }

private:
    Node *__search(const string &key) const;
    Node *head_ = nullptr;
    Node *end_ = nullptr;
    int count_ = 0;
};

