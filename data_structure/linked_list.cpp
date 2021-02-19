/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#include "linked_list.h"

namespace nnplib {
    void linked_list::insert(const std::string &key, const std::string &val) {
        node *ptr = __find(key);
        if (ptr) {
            ptr->value = val;
            return;
        } else {
            ptr = new node { .key = key, .value = val, .prev = end_ };
            if (end_) end_->next = ptr;
            end_ = ptr;
            if (!head_) head_ = ptr;
            ++count_;
        }
    }
    
    bool linked_list::remove(const std::string &key) {
        node *ptr = __find(key);
        if (!ptr) return false;
        if (ptr->prev) ptr->prev->next = ptr->next;
        if (ptr->next) ptr->next->prev = ptr->prev;
        if (head_ == ptr) head_ = ptr->next;
        if (end_ == ptr) end_ = ptr->prev;
        delete ptr;
        --count_;
        return true;
    }
    
    const linked_list::node *linked_list::find(const std::string &key) const {
        node *ptr = __find(key);
        if (!ptr) return nullptr;
        return ptr;
    }
    
    void linked_list::clear() {
        node *ptr = head_, *next;
        while (ptr) {
            next = ptr->next;
            delete ptr;
            ptr = next;
        }
        count_ = 0;
        head_ = nullptr;
        end_ = nullptr;
    }
    
    linked_list::node *linked_list::__find(const std::string &key) const {
        node *ptr = head_;
        while (ptr) {
            if (ptr->key == key) return ptr;
            else ptr = ptr->next;
        }
        return nullptr;
    }
}
