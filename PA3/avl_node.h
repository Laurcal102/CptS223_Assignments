#pragma once

template <typename F, typename E>
class Node
{
    public:
    
    Node(F newKey, E newVal)
    {
        this->key = newKey;
        this->value = newVal; 
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    };

    Node<F,E>* deepCopy(const Node<F,E>* other)
    {
        if(!other) return nullptr;
        Node<F,E>* newNode = new Node<F,E>(other->key, other->value);
        newNode->left = deepCopy(other->left);
        newNode->right = deepCopy(other->right);
        return newNode;
    }

    Node<F,E>& operator=(const Node<F,E>& other){
        if(this == &other) return *this;

        delete left;
        delete right;

        value = other->value;
        key = other->key;
        this->left = deepCopy(other->left);
        this->right = deepCopy(other->right);

        return *this;
    }

    //Getters
    F getKey() const {return key;}
    const E getValue() const {return value;}
    Node<F,E>* getLeft() const {return left;}
    Node<F,E>* getRight() const {return right;}
    int Height() const {
        if(this) return height;
        else return -1;
    }

    //Setters
    void setKey(F newKey) {key = newKey;}
    void setValue(E newValue) {value = newValue;}
    void setLeft(Node<F,E>* newLeft) {left = newLeft;}
    void setRight(Node<F,E>* newRight) {right = newRight;}
    void setHeight(int newHeight) {height = newHeight;}

    private:
    F key;
    E value;
    Node<F,E>* left;
    Node<F,E>* right;
    int height;
};