#pragma once 
#include "avl_node.h"
#include <iostream>

using std::cout;
using std::endl;
using std::max;
using std::string;


template <typename F, typename E>
class AVL_Map
{
    public:
    AVL_Map(){
        root = nullptr;
    };

    //getters
    Node<F,E>* getRoot() const {return root;}

    //setters
    void setRoot(Node<F,E>* newRoot) {root = newRoot;}

    void printNode(Node<F,E>* node) const {
        if (node) {
            cout << node->getKey() << ": " << node->getValue() << endl;
        }
    }

    void insert(F key, E value)
    {
        if(root)
        {
            root = insertHelper(root, value, key);
        }        
        else
        {
            root = new Node<F,E> (key, value);
        }
    }

    void erase(const F&key)
    {
        eraseHelper(root, key);
    }

    class Iterator {
        private:
        Node<F,E> &nodeRef;
        public:

        Iterator(Node<F,E> &node) : nodeRef(node) {}
    };

    Iterator find (const F& key)
    {
        Node<F,E>* findNode = findHelper(root, key);

        return Iterator(*findNode);
    }

    void printTree(Node<F,E>* root, int depth = 0) {
        if (!root) return;
        printTree(root->getRight(), depth + 1);
        cout << string(depth * 4, ' ') << root->getKey() << endl;
        printTree(root->getLeft(), depth + 1);
    }

  private:

    Node<F,E>* root;

    Node<F,E>* findHelper(Node<F,E>* root, F key)
    {
        if(!root) return nullptr;

        if(key == root->getKey()){
            return findHelper(root->getLeft(), key);
        }
        else{
            return findHelper(root->getRight(), key);
        }
    }

    Node<F,E>* insertHelper(Node<F,E>* root, E val, F key)
    {
       if(root == nullptr)
       {
           return new Node<F,E>(key, val);
       }

       if (key < root->getKey()) {
         root->setLeft(insertHelper(root->getLeft(), val, key));
       } else if (key > root->getKey()) {
         root->setRight(insertHelper(root->getRight(), val, key));
       } else {
         return root;
       }

       root->setHeight(1 + max(root->getLeft()->Height(), root->getRight()->Height()));
                   
       int balance = balanceCalc(root);

       if (balance > 1 && key < root->getLeft()->getKey()){
           return rightRotate(root);
       }

       if(balance < -1 && key > root->getRight()->getKey()){
           return leftRotate(root); 
       }

       if(balance > 1 && key > root->getLeft()->getKey()){
           root->setLeft(leftRotate(root->getLeft()));
           return rightRotate(root);
       }

       if(balance < -1 && key < root->getRight()->getKey() ){
           root->setRight(rightRotate(root->getRight()));
           return leftRotate(root);
       }
       
       return root;
       
   }

   Node<F,E>* eraseHelper(Node<F,E>* root, F key)
   {
       if(root == nullptr)
       {
           return root;
       }

       if (key < root->getKey())
       {
          root->setLeft(eraseHelper(root->getLeft(), key));
       }
       else if (key > root->getKey())
       {
           root->getRight(eraseHelper(root->getRight(), key));
       }
       else
       {
           Node<F,E>* temp = nullptr;
           //one child/no child
           if(root->setLeft(nullptr) || root->setRight(nullptr)){
               if(root->getLeft()) root->setLeft(temp);
               else root->setRight(temp);
               *root = *temp;
               delete temp;
           }
           else{//two children
               Node<F,E>* temp = root->getRight();//find minimum of right subtree of root
               while(temp->getLeft())
               {
                    temp->setLeft(temp);
               }
               *root = *temp;
               delete temp;
           }
       }

       if(root == nullptr)
       {
           return root;
       }

       if(!root->getLeft())
       {
        root->getLeft()->setHeight(-1);
       }
       if(!root->getRight())
       {
        root->getRight()->setHeight(-1);
       }
       root->setHeight(1 + max(root->getLeft()->Height(), root->getRight()->Height()));
                   
       int balance = balance(root);

       if (balance > 1 && balance(root->getLeft()) >= 0){
           return rightRotate(root);
       }

       if(balance < -1 && balance(root->getRight()) <= 0){
           return leftRotate(root); 
       }

       if(balance > 1 && balance(root->getLeft()) < 0){
           root->setLeft(leftRotate(root->getLeft()));
           return rightRotate(root);
       }

       if(balance < -1 && balance(root->getRight()) > 0){
           root->setRight(rightRotate(root->getRight()));
           return leftRotate(root);
       }

       return root;
   }

   
    //Rotate Functions
    Node<F,E>* rightRotate(Node<F,E>* pivot)
    {
        Node<F,E>* newSubRoot = pivot->getLeft();
        Node<F,E>* tempSubTree = newSubRoot->getRight();

        newSubRoot->setRight(pivot);
        pivot->setLeft(tempSubTree);

        pivot->setHeight(max(pivot->getLeft()->Height(), pivot->getRight()->Height()) + 1);
        newSubRoot->setHeight(max(newSubRoot->getLeft()->Height(), newSubRoot->getRight()->Height()) + 1);

        return newSubRoot;
    }

    Node<F,E>* leftRotate(Node<F,E>* pivot)
    {
        Node<F,E>* newSubRoot = pivot->getRight();
        Node<F,E>* tempSubTree = newSubRoot->getLeft();

        newSubRoot->setLeft(pivot);
        pivot->setRight(tempSubTree);

        pivot->setHeight(max(pivot->getLeft()->Height(), pivot->getRight()->Height()) + 1);
        newSubRoot->setHeight(max(newSubRoot->getLeft()->Height(), newSubRoot->getRight()->Height()) + 1);

        return newSubRoot;
    }
    
    //Get balance
    int balanceCalc(Node<F,E>* currNode)
    {
        if(currNode == nullptr)
        {
            return 0;
        }
        return (currNode->getLeft()->Height() - currNode->getRight()->Height());
    }

};