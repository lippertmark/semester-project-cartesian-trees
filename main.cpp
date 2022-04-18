#include <iostream>  // cout, cin
#include "utils.hpp"
#include <sstream>

#include "include/assignment/cartesian_tree.hpp"

using namespace std;
using namespace assignment;

int main(int args, char** argv) {

  CartesianTree tree;
  CartesianTree tree88;

  tree.Insert(7, 10);
  tree.Insert(4, 6);
  tree.Insert(13, 8);
  tree.Insert(2, 4);
  tree.Insert(6, 2);
  tree.Insert(9, 7);
  tree.Insert(14, 4);
  tree.Insert(0, 3);
  tree.Insert(3, 3);
  tree.Insert(5, 1);
  tree.Insert(11, 3);

  const auto tree_str11 = utils::tree_as_str(tree.root());
  cout << tree_str11<<'\n';

  /*
   *               7
   *       4               13
   *   2      6         9      14
   * 0   3  5   x     x   11  x   x
   *
   * x - это nullptr
   */
  tree.Remove(7);

  const auto tree_str12 = utils::tree_as_str(tree.root());
  cout << tree_str12<<'\n';




  return 0;
}