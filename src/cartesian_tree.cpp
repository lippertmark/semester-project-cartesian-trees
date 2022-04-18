#include <iostream>   // cout
#include <algorithm>  // ???
#include <cmath>      // ???

#include "assignment/cartesian_tree.hpp"

namespace assignment {

  CartesianTree::~CartesianTree() {
    CartesianTree::Clear();
  }

  void CartesianTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  void CartesianTree::clear(Node* node) {
    if (node != nullptr) {
      clear(node->left);
      clear(node->right);
    }

    delete node;
  }

  void CartesianTree::Split(Node* node, int key, Node*& left_tree, Node*& right_tree) {

    if (node == nullptr) {
      left_tree = nullptr;
      right_tree = nullptr;
    }

    else if (node->key <= key) {
      Split(node->right, key, node->right, right_tree);
      left_tree = node;
    } else {
      Split(node->left, key, left_tree, node->left);
      right_tree = node;
    }
  }

  Node* CartesianTree::Merge(Node* left_tree, Node* right_tree) {

    if (left_tree == nullptr || right_tree == nullptr) {
      return left_tree == nullptr ? right_tree : left_tree;
    }

    if (left_tree->priority > right_tree->priority) {
      left_tree->right = Merge(left_tree->right, right_tree);
      return left_tree;
    }

    right_tree->left = Merge(left_tree, right_tree->left);

    return right_tree;
  }

  void CartesianTree::Insert(int key, int priority) {
    if (!root_){
      Node* newNode = new Node(key, priority);
      root_ = newNode;
    }
    else {
      Node* left_tree = nullptr;
      Node* right_tree = nullptr;

      Split(root_, key, left_tree, right_tree);

      left_tree = Merge(left_tree, new Node(key, priority));
      root_ = Merge(left_tree, right_tree);
    }
  }


  bool CartesianTree::Contains(int key) {
    Node* curr = find(key, root_);
    if (curr == nullptr){
      return false;
    }
    return true;
  }

  bool CartesianTree::Remove(int key) {
    root_ = remove(root_, key);
    return root_;
  }

  bool CartesianTree::IsEmpty() const {
    return root_ == nullptr;
  }

  Node* CartesianTree::root() const {
    return root_;
  }

  Node* CartesianTree::find(int key, Node* node){
    if (node==nullptr){
      return nullptr;
    }
    if (node->key == key){
      return node;
    }
    if (node->key > key){
      return find(key, node->left);
    }
    if (node->key < key){
      return find(key, node->right);
    }
  }

  Node* CartesianTree::remove(Node* node, int key){
    if (node == nullptr){
      return nullptr;
    }
    if (node->key == key){
      node = Merge(node->left, node->right);
    }

    else if (key < node->key){
      node->left = remove(node->left, key);
    }
    else {
      node->right = remove(node->right, key);
    }
    return node;
  }

}  // namespace assignment