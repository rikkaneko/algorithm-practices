/* This file is part of algorithm_practices.
 * Copyright (c) 2021 rikkaneko. */
#include "common.h"
#include "linked_list.h"

void print_list(const nnplib::linked_list &list) {
    auto iter = list.get_iterator();
    auto ent = iter.get();
    while ((ent = iter.get()) != nullptr) {
        std::cout << "{\"" << ent->key << "\": \"" << ent->value << "\"}" << std::endl;
        ++iter;
    }
}

int main(int argc, char *argv[]) {
    nnplib::linked_list list;
    list.insert("color", "red");
    list.insert("quality", "95%");
    list.insert("!wrongdata!", "xxx");
    list.insert("gender", "female");
    list.insert("name", "Alice");
    list.insert("color", "green");
    list.insert("quality", "0%");
    list.insert("name", "Bob");
    std::cout << list.remove("!wrongdata!") << std::endl;
    std::cout << list.get_size() << std::endl;
    auto result = list.find("name");
    if (result) std::cout << result->value << std::endl;
    print_list(list);
    list.clear();
    std::cout << list.get_size() << std::endl;
    list.insert("name", "Alice");
    list.insert("color", "green");
    list.insert("color", "red");
    list.insert("quality", "95%");
    list.insert("gender", "male");
    list.insert("name", "Sandy");
    list.insert("color", "black");
    list.insert("quality", "0%");
    list.insert("name", "Tinder");
    std::cout << list.remove("quality") << std::endl;
    std::cout << list.remove("nonexist") << std::endl;
    std::cout << list.get_size() << std::endl;
    print_list(list);
    return 0;
}
