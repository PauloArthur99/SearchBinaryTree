#include <iostream>
using namespace std;

class Node{
public:
  int Data;
	Node* Left;
  Node* Right;

	Node(int Data, Node* left, Node* right)
	{
		this->Data = Data;
		this->Left = left;
    this->Right = right;
	}
};

class SearchBinaryTree{
private:
  Node* Root;

public:
    SearchBinaryTree();
    ~SearchBinaryTree();
    void insertNode(int key);
    Node* subtreeSearch(int key, Node* node);
};

SearchBinaryTree::SearchBinaryTree()
{
  Root = NULL;
}

SearchBinaryTree::~SearchBinaryTree()
{
  //DELETE
}

Node* SearchBinaryTree::subtreeSearch(int key, Node* node)
{
  if (key < node->Left)
  {
    if (node->Left != NULL)
      return subtreeSearch(key, node->Left);
  }
  else
  {
    if (node->Right != NULL)
      return subtreeSearch(key, node->Right);
  }
  return node;
}

void SearchBinaryTree::insertNode(int k)
    {
      Node* newNode;
      newNode = new Node(k, NULL, NULL);
      if (!this->Root)
          this->Root = newNode;
      else
      {
        Node* fatherNode;
        fatherNode = subtreeSearch(k, this->Root);
        if (k < fatherNode->Data)
          fatherNode->Left = newNode;
        else
          fatherNode->Right = newNode;
      }
    }
