#pragma once

template <typename T>
class Node
{
    public:
    Node(T val, T key)
    {
        this->key = key;
        this->value = val; 
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0;
    };

    //getters
    T& getKey() const {
        return key;
    };

    T& getValue() const {
        return value;
    };

    Node<T>*getRight() const {
        return right;
    };

    Node<T>*getLeft() const {
        return left;
    };

    int& getHeight() const {
        return height;
    };

    //setters
    void setKey(T newKey){
        key = newKey;
    };

    void setValue(T newValue){
        value = newValue;
    };

    void setRight(Node* newRight){
        right = newRight;
    };

    void setLeft(Node* newLeft){
        left = newLeft;
    };

    void setHeight(int newHeight){
        height = newHeight;
    };

    //Rotation functions
    void rotateLeft(Node* N)
    {
        
    }

    private:
    T key;
    T value;
    Node<T>* left;
    Node<T>* right;
    int height;
};