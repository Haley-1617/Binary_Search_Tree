//
//  main.cpp
//  Binary_Search_Tree
//
//  Created by Haley Lai on 12/23/19.
//  Copyright © 2019 Haley Lai. All rights reserved.
//

#include <iostream>

using namespace std;

class Tree_Node {
private:
   int height;
public:
   Tree_Node *lftChild, *rtChild, *parent;
   int key;
   Tree_Node() : lftChild(NULL), rtChild(NULL),
   parent(NULL), key(0), height(0) {}
   int getHeight() { return this->height; }
   void setHeight(int h) { this->height = h; }
};

class Binary_Search_Tree {
private:
   Tree_Node *root;
   int mSize;
public:
   Binary_Search_Tree() { root = NULL; mSize = 0; }
   Binary_Search_Tree(const Binary_Search_Tree &rhs);
   ~Binary_Search_Tree() { clear(this->root); }
   bool find(const int &key);
   Tree_Node*& find(Tree_Node *&node, const int &key);  //private
   void insert(const int &key);
   void insert(Tree_Node *node, const int &key);   //private
   void remove(const int &key);
   void clear(Tree_Node *&node);
   bool empty() { return (mSize == 0 ? true : false); }
   void display();
   void display(Tree_Node *node);   //private
   int size() { return this->mSize; }
   Tree_Node* successor(Tree_Node *&node);
   Tree_Node* max(Tree_Node *node);
   Tree_Node* min(Tree_Node *node);
};

bool Binary_Search_Tree::find(const int &key) {
   if (root->key == key) return true;
   if (empty()) return false;
   return (find(root, key) == NULL ? false : true);
}

Tree_Node*& Binary_Search_Tree::find(Tree_Node *&node, const int &key) {
   if (node->key == key) return node;
   if (key < node->key && node->lftChild) return find(node->lftChild, key);
   else if (key > node->key && node->rtChild) return find(node->rtChild, key);
   if (node->key != key) node = NULL;
   return node;
}

void Binary_Search_Tree::insert(const int &key) {
   if (empty()) {
      int firstLv = 1;
      Tree_Node *newNode = new Tree_Node();
      newNode->key = key;
      root = newNode;
      mSize++;
      root->setHeight(firstLv);
   }
//   else if (find(key)) {
//      cout << "node exists already" << endl;
//   }
   else {
      insert(root, key);
   }
}

void Binary_Search_Tree::insert(Tree_Node *node, const int &key) {
   if(node->rtChild == NULL && key > node->key) {
      Tree_Node *newNode = new Tree_Node();
      newNode->key = key;
      newNode->setHeight(node->getHeight() + 1);
      node->rtChild = newNode;
      newNode->parent = node;
      mSize++;
   }
   if(node->lftChild == NULL && key < node->key) {
      Tree_Node *newNode = new Tree_Node();
      newNode->key = key;
      newNode->setHeight(node->getHeight() + 1);
      node->lftChild = newNode;
      newNode->parent = node;
      mSize++;
   }
   if(key > node->key) insert(node->rtChild, key);
   if(key < node->key) insert(node->lftChild, key);
}

void Binary_Search_Tree::remove(const int &key) {
   if (empty()) return;    //empty tree
   if (root->key == key) {
      clear(this->root);
      return;
   }  //only root
   Tree_Node *rmNode = find(this->root, key);
   if (rmNode == NULL) return;   //the node doesn't exist
   Tree_Node *suNode = successor(rmNode);
   Tree_Node *par = find(this->root, suNode->parent->key);
   if (suNode->rtChild == NULL && suNode->lftChild == NULL) {
      if (suNode->key < par->key) par->lftChild = NULL;
      else par->rtChild = NULL;
   }  //no child
   else if (suNode->rtChild == NULL || suNode->lftChild == NULL){
      if (suNode->key < par->key) {
         if (suNode->lftChild) {
            par->lftChild = suNode->lftChild;
         }
         else par->lftChild = suNode->rtChild;
      }
      else {
         if (suNode->lftChild) {
            par->rtChild = suNode->lftChild;
         }
         else par->rtChild = suNode->rtChild;
      }
   }  //one child
   else {
      if (suNode->key < par->key) par->lftChild = suNode->rtChild;
      else par->rtChild = suNode->rtChild;
   }
   rmNode->key = suNode->key;
   mSize--;
}

void Binary_Search_Tree::clear(Tree_Node *&node) {
   if (node == NULL) return;
   if (node->lftChild) clear(node->lftChild);
   if (node->rtChild) clear(node->rtChild);
   delete node;
   node = NULL;
   mSize = 0;
}

void Binary_Search_Tree::display() {
   if (empty()) {
      cout << endl;
      return;
   }
   else cout << root->key << endl;

   if (root->lftChild) display(root->lftChild);
   if (root->rtChild) display(root->rtChild);
}

void Binary_Search_Tree::display(Tree_Node *node) {
   int h = node->getHeight();
   while(--h > 1) {
      cout << "    ";
   }
   node->parent->key > node->key ?
   cout << "├──" : cout << "└──";

   cout << node->key << endl;
   if (node->lftChild) display(node->lftChild);
   if (node->rtChild) display(node->rtChild);
}

Tree_Node* Binary_Search_Tree::successor(Tree_Node *&node) {
   if (node->lftChild) return max(node->lftChild);
   else if (node->rtChild) return min(node->rtChild);
   else return node;
}

Tree_Node* Binary_Search_Tree::max(Tree_Node *node) {
   if (node->rtChild) return max(node->rtChild);
   else return node;
}

Tree_Node* Binary_Search_Tree::min(Tree_Node *node) {
   if (node->lftChild) return min(node->lftChild);
   else return node;
}

int main(int argc, const char * argv[]) {
   Binary_Search_Tree test;
   test.insert(8);
   test.insert(4);
   test.insert(12);
   test.insert(2);
   test.insert(6);
   test.insert(10);
   test.insert(14);
   test.insert(1);
   test.insert(3);
   test.insert(5);
   test.insert(7);
   test.insert(9);
   test.insert(11);
   test.insert(13);
   test.insert(15);
   test.display();
   test.remove(12);
   test.display();
   test.remove(11);
   test.remove(9);
   test.display();
   test.remove(6);
   test.display();
   test.remove(4);
   test.display();
   test.remove(1);
   test.display();
   test.remove(10);
   test.display();
   return 0;
}
