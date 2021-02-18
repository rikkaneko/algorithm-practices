/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#include "bst.h"

void print_bst(const bst &bst) {
    auto iter = bst.get_iterator();
    auto ent = iter.get();
    std::cout << "This BST tree has " << bst.get_size() << " elements" << std::endl;
    while ((ent = iter.get())) {
        std::cout << "{\"" << ent->key << "\": \"" << ent->value << "\"}" << std::endl;
        ++iter;
    }
}

void find_bst(const bst &bst, const string &key) {
    auto result = bst.find(key);
    if (!result) {
        std::cout << key << " not found" << std::endl;
        return;
    }
    std::cout << result->key << ": " << result->value << std::endl;
}

int main(int argc, char *argv[]) {
    bst bst;
    bst.insert("name", "Bob");
    bst.insert("food", "tutu");
    bst.insert("age", "10");
    bst.insert("money", "5000");
    bst.insert("name", "Alice");
    bst.insert("food", "double_tutu_soap");
    bst.insert("age", "8");
    bst.insert("money", "10");
    bst.insert("pushable", "true");
    bst.remove("age");
    bst.insert("year", "7");
    print_bst(bst);
    find_bst(bst, "food");
    find_bst(bst, "wrongkey");
    bst.clear();
    find_bst(bst, "food");
    print_bst(bst);
    bst.insert("name", "Potion of Regeneration");
    bst.insert("owner", "Steve");
    bst.insert("level", "5");
    bst.insert("duration", "900");
    bst.insert("script", "tutu_dance.js");
    bst.insert("level", "6");
    print_bst(bst);
    find_bst(bst, "name");
    find_bst(bst, "levels");
    return 0;
}
