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

    void insert(T key, T value)
    {
        new newNode = Node(value, key);
        
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
        else
        {
            if(!branchNode->right)
            {
                branchNode->right = new Node<T>(val, key);
            }
            else
            {
                insertHelper(branchNode->right, val, key);
            }
        }

        branchNode->height = 1 + max(branchNode->left->getHeight(), 
                               branchNode->right->getHeight());
                    
        int balance = balance(branchNode);

        if (balance > 1 && key < branchNode->left->key){
            //Left 
        }

        if(balance < -1 && key > root->right->key){
            //Right 
        }

        if(balance > 1 && key > root->left->key){
            //Right Left
        }

        if(balance < -1 && key < ){
            //Left Right
        }
        
    }
    
    int balance(Node<T>* currNode)
    {
        return height(currNode->left) - height(currNode->right);
    }



};