#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include "cartesian_tree.hpp"

namespace assignment{
    CartesianTree::~CartesianTree(){
        CartesianTree::Clear();
    }

    void CartesianTree::Clear(){
        clear(root_);
        root_ = nullptr;
    }
    void CartesianTree::Split(Node* node, int key, Node*& left_tree, Node*& right_tree){
        if (!node){
            left_tree = nullptr;
            right_tree = nullptr;
            return
        }
        else if (node->key <= key){
            Split(node->right, key, node->right, right_tree);
            left_tree = node;
        }
        else {
            Split(node->left, key, node->left, left_tree);
            right_tree = node;
        }
    }


    Node* Merge(Node* left_tree, Node* right_tree) {
        if (left_tree == nullptr || right_tree == nullptr) {
            return left_tree == 0 ? right_tree : left_tree;
        }
        if (left->priority > right->priority) {
            left_tree->right = Merge(left_tree->right, right_tree);
            return left_tree;
        }
        right_tree->left = Merge(left_tree, right_tree->left);
        return right_tree;
    }

    void CartesianTree:: Insert(int key, int priority){
        Node* left_tree, right_tree;
        Split(root_, key, left_tree, right_tree);
        left_tree = Merge(left_tree, new Node(key, priority));
        root_ = Merge(left_tree, right_tree);
    }

    bool CartesianTree::Contains(int key) const {
        Node* left_tree, equal, right_tree;
        Split(root_, key, left_tree, right_tree);
        Split(right_tree, key+1, equal, right_tree)
        bool result = equel;
        root_ = Merge(Merge(left_tree, equal), right_tree);
        return equel;
    }

    bool Remove(int, key){
        if (!root_){
            return false;
        }
        Node* left_tree, equal, right_tree;
        Split(root_, key, left_tree, right_tree);
        Split(right_tree, key+1, equal, right_tree);
        root_ = Merge(left_tree, right_tree);
        return true;
    }

    bool CartesianTree::IsEmpty() const {
        return root_ == nullptr;
    }

    void CartesianTree::clear(Node* node) {
        if (node!= nullptr) {
            clear(node->left);
            clear(node->right);
        }
        delete node;
    }
}