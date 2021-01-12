/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#include "linked_list.h"

void LinkedList::insert(const string &key, const string &val) {
    Node *ptr = __search(key);
    if (ptr) {
        ptr->value_ = val;
        return;
    } else {
        ptr = new Node(key, val, end_, nullptr);
        if (end_) end_->next_ = ptr;
        end_ = ptr;
        if (!head_) head_ = ptr;
        ++count_;
    }
}

bool LinkedList::remove(const string &key) {
    Node *ptr = __search(key);
    if (!ptr) return false;
    if (ptr->prev_) ptr->prev_->next_ = ptr->next_;
    if (ptr->next_) ptr->next_->prev_ = ptr->prev_;
    if (head_ == ptr) head_ = ptr->next_;
    if (end_ == ptr) end_ = ptr->prev_;
    delete ptr;
    --count_;
    return true;
}

const LinkedList::Node *LinkedList::find(const string &key) const {
    Node *ptr = __search(key);
    if (!ptr) return nullptr;
    return ptr;
}

void LinkedList::clear() {
    Node *ptr = head_, *next;
    while (ptr) {
        next = ptr->next_;
        delete ptr;
        ptr = next;
    }
    count_ = 0;
    head_ = nullptr;
    end_ = nullptr;
}

LinkedList::Node *LinkedList::__search(const string &key) const {
    Node *ptr = head_;
    while (ptr) {
        if (ptr->key_ == key) return ptr;
        else ptr = ptr->next_;
    }
    return nullptr;
}
