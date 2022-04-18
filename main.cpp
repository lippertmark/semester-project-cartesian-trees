#include <iostream>  // cout, cin
#include "utils.hpp"
#include <sstream>

#include "include/assignment/cartesian_tree.hpp"

using namespace std;
using namespace assignment;

int main(int args, char** argv) {

  CartesianTree left_tree;
  CartesianTree right_tree;
  const auto keys_l = std::vector<int>{4, 1, 6, 3};
  const auto values_l = std::vector<int>{9, 3, 4, 1};
  for (int index = 0; index < keys_l.size(); ++index) {
    left_tree.Insert(keys_l[index], values_l[index]);
  }
  const auto keys_r = std::vector<int>{13, 7, 14, 10, 8};
  const auto values_r = std::vector<int>{13, 10, 6, 2, 0};
  for (int index = 0; index < keys_r.size(); ++index) {
    right_tree.Insert(keys_r[index], values_r[index]);
  }
  right_tree.Merge(left_tree.root(), right_tree.root());
  const auto right_tree1 = utils::tree_as_str(right_tree.root());
  cout << right_tree1<<'\n';
  return 0;
  }


  /*
   *               7
   *       4               13
   *   2      6         9      14
   * 0   3  5   x     x   11  x   x
   *
   * x - это nullptr
   */
