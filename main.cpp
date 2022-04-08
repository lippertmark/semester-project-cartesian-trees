//#include <iostream>
#include "include/assignment/cartesian_tree.hpp"
using namespace std;
using namespace assignment;

int main(int args, char** argv){
    CartesianTree tree;

    tree.Insert(8, 1);
    tree.Insert(3, 2);
    tree.Insert(10, 3);
    tree.Insert(1, 4);
    tree.Insert(6, 5);
    tree.Insert(4, 6);
    tree.Insert(7, 7);
    tree.Insert(14, 8);
    tree.Insert(13, 9);
    //cout << tree;
    return 0;
}