#include <iostream>
#include <stdio.h>
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
    void preOrder(Node* node);
    void pre_order();
    void inOrder(Node* node);
    void in_order();
    void postOrder(Node* node);
    void post_order();
    void clear(Node* node);
};

SearchBinaryTree::SearchBinaryTree()
{
  this->Root = NULL;
}

SearchBinaryTree::~SearchBinaryTree()
{
  clear(this->Root);
}

Node* SearchBinaryTree::subtreeSearch(int key, Node* node)
{
  if (key < (node->Data))
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
  cout << k << "\n";
  Node* newNode;
  newNode = new Node(k, NULL, NULL);
  if (this->Root == NULL)
    this->Root = newNode;
  else
    {
      Node* fatherNode;
      fatherNode = subtreeSearch(k, this->Root);
      if (k < (fatherNode->Data))
      {
        fatherNode->Left = newNode;
        cout << fatherNode->Left->Data << " ";
        cout << "to aqui 1\n";
      }
      else
      {
        fatherNode->Right = newNode;
        cout << fatherNode->Right->Data << " ";
        cout << "to aqui 2\n";
      }
    }
}


void SearchBinaryTree::pre_order()
{
  preOrder(this->Root);
}

void SearchBinaryTree::in_order()
{
  inOrder(this->Root);
}

void SearchBinaryTree::post_order()
{
  postOrder(this->Root);
}

void SearchBinaryTree::preOrder(Node* node)
{
  if(node != NULL)
  {
    cout << node->Data << " ";
    preOrder(node->Left);
    preOrder(node->Right);
  }
}

void SearchBinaryTree::inOrder(Node* node)
{
  if(node != NULL)
  {
    preOrder(node->Left);
    cout << node->Data << " ";
    preOrder(node->Right);
  }
}


void SearchBinaryTree::postOrder(Node* node)
{
  if(node != NULL)
  {
    preOrder(node->Left);
    preOrder(node->Right);
    cout << node->Data << " ";
  }
}

void SearchBinaryTree::clear(Node* node)
{
  if(node != NULL)
  {
    clear(node->Left);
    clear(node->Right);
    delete node;
  }
}
