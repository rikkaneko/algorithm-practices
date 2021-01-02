/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#pragma once
#include "common.h"
#include <utility>

/* Linked list
 * Search Worst Complexity: O(N)
 * Search Average Complexity: O(N/2)
 * Insert Worst Complexity: O(N)
 * Insert Average Complexity: O(N) */
class LinkedList {
public:
    using node_data_type = std::pair<const string, string>;
    
    class Iterator;
    
    class Node {
        friend class LinkedList;
        
        friend class LinkedList::Iterator;
    
    public:
        const string &get_key() const { return data_.first; }
        
        const string &get_val() const { return data_.second; }
    
    private:
        explicit Node(node_data_type data, Node *prev = nullptr,
                      Node *next = nullptr): data_(std::move(data)), prev_(prev), next_(next) {}
        
        Node *prev_;
        Node *next_;
        node_data_type data_;
    };
    
    class Iterator {
    public:
        explicit Iterator(Node *node): ptr_(node) {}
        
        const Node *get() const {
            if (!ptr_) return nullptr;
            return ptr_;
        }
        
        void operator++() { if (ptr_) ptr_ = ptr_->next_; }
    
    private:
        Node *ptr_ = nullptr;
    };
    
    ~LinkedList() { clear(); }
    
    void insert(const string &key, const string &val);
    bool remove(const string &key);
    const Node *search(const string &key) const;
    void clear();
    
    int get_count() const { return count_; }
    
    Iterator get_iterator() const { return Iterator(head_); }

private:
    Node *__search(const string &key) const;
    Node *head_ = nullptr;
    Node *end_ = nullptr;
    int count_ = 0;
};

