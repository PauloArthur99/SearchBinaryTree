#include <iostream>
#include "SearchBinaryTree.h"
using namespace std;

int main()
{
  SearchBinaryTree* tree;
  tree = new SearchBinaryTree();
  tree->insertNode(6);
  tree->insertNode(5);
  tree->insertNode(-2);
  tree->insertNode(7);
  tree->insertNode(-1);
  tree->insertNode(0);
  tree->insertNode(6);

  // tree->in_order();

  delete tree;
}
