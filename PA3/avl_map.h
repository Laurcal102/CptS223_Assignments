#pragma once 
#include "avl_node.h"

template <typename t>
class AVL_Map
{
    public:
    AVL_Map();

    //getters
    Node<T>* getRoot() const {
        return root;
    };

    void insert(const T& key, const T& value)
    {
        if(this->root)
        {
            this->insertHelper(this->root);
        }        
        else
        {
            this->root = new Node<T>(value, key);
        }
    }


    private:

    Node<T>* root;

    void insertHelper(Node<T>* branchNode, T val, T key){
        if (branchNode->key > key){
            if(!branchNode->left)
            {
                branchNode->left = new Node<T>(val, key);
            }
            else
            {
                insertHelper(branchNode->left, val, key);
            }
        }
        else{
            if(!branchNode->right)
            {
                branchNode->right = new Node<T>(val, key);
            }
            else
            {
                insertHelper(branchNode->right, val, key);
            }
        }

        branchNode->height = 1 + max(branchNode->left->Height(), 
                               branchNode->right->Height());
                    
        int balance = balance(branchNode);

        if (balance > 1 && key < branchNode->left->key){
            return rightRotate(branchNode);
        }

        if(balance < -1 && key > branchNode->right->key){
            return leftRotate(branchNode); 
        }

        if(balance > 1 && key > branchNode->left->key){
            branchNode->left = leftRotate(branchNode->left);
            return rightRotate(branchNode);
        }

        if(balance < -1 && key < branchNode->right->key ){
            branchNode->right = rightRotate(branchNode->right);
            return leftRotate(branchNode);
        }

        return branchNode;
        
    }

    void deleteHelper(T key)
    {
        if (branchNode->key > key){
            if(!branchNode->left)
            {
                branchNode->left = new Node<T>(val, key);
            }
            else
            {
                insertHelper(branchNode->left, val, key);
            }
        }
        else{
            if(!branchNode->right)
            {
                branchNode->right = new Node<T>(val, key);
            }
            else
            {
                insertHelper(branchNode->right, val, key);
            }
        }
    }

    //Rotate Functions
    void rightRotate(Node<T>* pivot)
    {
        Node<T>* newSubRoot = pivot->left;
        Node<T>* tempSubTree = newSubRoot->right;

        newSubRoot->right = pivot;
        pivot->left = tempSubTree;

        pivot->height = max(pivot->left->getHeight(), pivot->right->getHeight()) + 1;
        newSubRoot->height = max(newSubRoot->left->getHeight(), newSubRoot->right->getHeight()) + 1;

        return newSubRoot;
    }

    void leftRotate(Node<T>* pivot)
    {
        Node<T>* newSubRoot = pivot->right;
        Node<T>* tempSubTree = newSubRoot->left;

        newSubRoot->left = pivot;
        pivot->right = tempSubTree;

        pivot->height = max(pivot->left->getHeight(), pivot->right->getHeight()) + 1;
        newSubRoot->height = max(newSubRoot->left->getHeight(), newSubRoot->right->getHeight()) + 1;

        return newSubRoot;
    }
    
    int balance(Node<T>* currNode)
    {
        if(currNode == nullptr)
        {
            return 0;
        }
        return currNode->left->height() - currNode->right->height();
    }



};