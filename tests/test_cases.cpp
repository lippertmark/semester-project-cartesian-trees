#include "assignment/cartesian_tree.hpp"  // CartesianTree

#include <catch2/catch.hpp>

using assignment::CartesianTree;
using assignment::Node;

TEST_CASE("CartesianTree constructor") {

  CartesianTree tree;  // default constructor

  CHECK(tree.IsEmpty());  // tree.IsEmpty() == true?
  CHECK(tree.root() == nullptr);
}