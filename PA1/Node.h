#pragma once

#include <iostream>
#include <string>

using std::string;

template <typename T>
class Node 
{
    public:
    Node();

    //getters
    T& getData();
    Node<T>* getNextPtr() const;
    Node<T>* getPrePtr() const;

    //setters
    void setData(T newData);
    void setNextPtr(Node<T>* newNextPtr);
    void setPrePtr(Node<T>* newPrePtr);

    private:
    T data;
    Node<T>* prePtr;
    Node<T>* nextPtr;
};

template <typename T> Node<T>::Node()
{
    nextPtr = nullptr;
    prePtr = nullptr;
}

template <typename T> Node<T>* Node<T>::getNextPtr() const
{
    return nextPtr;
}

template <typename T> Node<T>* Node<T>::getPrePtr() const
{
    return prePtr;
}

template<typename T> T& Node<T>::getData()
{
    return data;
}

template<typename T> void Node<T>::setData(T newData)
{
    data = newData;
}

template <typename T> void Node<T>::setNextPtr(Node<T>* newNextPtr)
{
    nextPtr = newNextPtr;
}

template <typename T> void Node<T>::setPrePtr(Node<T>* newPrePtr)
{
    prePtr = newPrePtr;
}

