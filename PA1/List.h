#pragma once

#include "Node.h"

#include <fstream>
#include <iostream>

using std::ifstream;
using std::ofstream;
using std:: endl;
using std::cout;
using std::cin;

template <typename T>
class List
{
    public:
    List();
    List(const List<T>& copyList);

    ~List();

    //getters
    Node<T>* getHeadPtr() const;
    Node<T>* getTailPtr() const;

    //setters
    Node<T>* setHeadPtr(Node<T>* newHead);
    Node<T>* setTailPtr(Node<T>* newTail);
    
    void insertAtFront(T data);
    void printList();
    Node<T>* traverseList(int num);
    void removeNode(T data);


    private:
    Node<T>* tailPtr;
    Node<T>* headPtr;

    Node<T>* makeNode(T data);
    
    void destroyList(Node<T>* const tail);
};

template <typename T> List<T>::List()
{
    headPtr = nullptr;
    tailPtr = nullptr;
}

template <typename T> List<T>::~List()
{
    destroyList(tailPtr);
}

template <typename T> Node<T>* List<T>::getHeadPtr() const
{
    return headPtr;
}

template <typename T> Node<T>* List<T>::getTailPtr() const
{
    return tailPtr;
}

template <typename T> Node<T>* List<T>::setHeadPtr(Node<T>* newHead)
{
    headPtr = newHead;
} 

template <typename T> Node<T>* List<T>::setTailPtr(Node<T>* newTail)
{
    tailPtr = newTail;
} 

template <typename T> void List<T>::insertAtFront(T data)
{
	Node<T>* pMem = makeNode(data);

	if (pMem != nullptr)
	{
		if (headPtr == nullptr)
		{
			headPtr = tailPtr = pMem;
		}
		else
		{
			pMem->setNextPtr(headPtr);
			headPtr->setPrePtr(pMem);
			headPtr = pMem;
		}
	}
}

template <typename T> Node<T>* List<T>::makeNode(T data)
{
    Node<T>* pMem = new Node<T>();
    pMem->setData(data);
    return pMem;
}

template <typename T> void List<T>::removeNode(T data)
{
    Node<T>* pCur = headPtr;

    while(pCur->getData() != data && pCur != nullptr)
    {
        pCur = pCur->getNextPtr();
    }

    if (pCur == nullptr)
    {
        return;
    }


    if(pCur->getPrePtr() != nullptr)
    {
        pCur->getPrePtr()->setNextPtr(pCur->getNextPtr());
    }
    else
    {
        headPtr = pCur->getNextPtr();
    }
    
    if(pCur->getNextPtr() != nullptr)
    {
        pCur->getNextPtr()->setPrePtr(pCur->getPrePtr());
    }

    delete pCur;
}

template <typename T> void List<T>::destroyList(Node<T>* const tail)
{
    Node<T>* pCur = tail;
    Node<T>* pPrev = nullptr;

    while(pCur != nullptr)
    {
        pPrev = pCur->getPrePtr();
        delete pCur;
        pCur = pPrev;
    }
}