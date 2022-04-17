#include <iostream>  // cout, cin
#include "utils.hpp"
#include <sstream>

#include "include/assignment/cartesian_tree.hpp"

using namespace std;
using namespace assignment;

int main(int args, char** argv) {

  CartesianTree tree;

  tree.Insert(7, 10);
  const auto tree_str1 = utils::tree_as_str(tree.root());
  cout << tree_str1<<'\n';
  tree.Insert(4, 6);
  const auto tree_str2 = utils::tree_as_str(tree.root());
  cout << tree_str2<<'\n';
  tree.Insert(13, 8);
  const auto tree_str3 = utils::tree_as_str(tree.root());
  cout << tree_str3<<'\n';
  tree.Insert(2, 4);
  const auto tree_str4 = utils::tree_as_str(tree.root());
  cout << tree_str4<<'\n';
  tree.Insert(6, 2);
  const auto tree_str5 = utils::tree_as_str(tree.root());
  cout << tree_str5<<'\n';
  tree.Insert(9, 7);
  const auto tree_str6 = utils::tree_as_str(tree.root());
  cout << tree_str6<<'\n';
  tree.Insert(14, 4);
  const auto tree_str7 = utils::tree_as_str(tree.root());
  cout << tree_str7<<'\n';
  tree.Insert(0, 3);
  const auto tree_str8 = utils::tree_as_str(tree.root());
  cout << tree_str8<<'\n';
  tree.Insert(3, 3);
  const auto tree_str9 = utils::tree_as_str(tree.root());
  cout << tree_str9<<'\n';
  tree.Insert(5, 1);
  const auto tree_str10 = utils::tree_as_str(tree.root());
  cout << tree_str10<<'\n';
  tree.Insert(11, 3);

  const auto tree_str11 = utils::tree_as_str(tree.root());
  cout << tree_str11<<'\n';

  return 0;
}