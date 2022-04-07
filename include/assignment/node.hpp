#pragma once
namespace assignment {
    struct Node {
        int key;
        int priority;
        Node *left{nullptr};
        Node *right{nullptr};
        Node(int key, int value) : key{key}, priority{priority} {}
    };
}