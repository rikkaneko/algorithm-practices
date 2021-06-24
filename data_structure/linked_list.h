/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#pragma once
#include <string>

namespace nnplib {
    /* Double Linked list
     * Search Worst Complexity: O(N)
     * Search Average Complexity: O(N/2)
     * Insert Worst Complexity: O(N)
     * Insert Average Complexity: O(N)
     * Delete Worst Complexity: O(N)
     * Delete Average Complexity: O(N/2) */
    class linked_list {
    public:
        class iterator;
        
        struct node {
            std::string key;
            std::string value;
            node *prev = nullptr;
            node *next = nullptr;
        };
        
        class iterator {
        public:
            explicit iterator(node *node): ptr_(node) {}
            
            const node *get() const { return ptr_; }
            
            void operator++() { if (ptr_) ptr_ = ptr_->next; }
        
        private:
            node *ptr_ = nullptr;
        };
        
        ~linked_list() {
            clear();
        }
        
        void insert(const std::string &key, const std::string &val);
        bool remove(const std::string &key);
        const node *find(const std::string &key) const;
        void clear();
        
        int get_size() const { return count_; }
        
        iterator get_iterator() const { return iterator(head_); }
    
    private:
        node *__find(const std::string &key) const;
        node *head_ = nullptr;
        node *end_ = nullptr;
        int count_ = 0;
    };
}
