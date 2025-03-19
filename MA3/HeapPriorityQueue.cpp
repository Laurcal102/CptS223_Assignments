#include "HeapPriorityQueue.h"
#include "PrinterJob.h"
//#include <ios>
#include <iostream>

// TODO: Implement the constructor
HeapPriorityQueue::HeapPriorityQueue() {
    size = 0;
}

// TODO: Implement the destructor
HeapPriorityQueue::~HeapPriorityQueue() {
}

// TODO: Implement the copy constructor
HeapPriorityQueue::HeapPriorityQueue(const HeapPriorityQueue& other) {
    size = other.size;

    for(int i = 0; i < size; i++)
    {
        heap[i] = other.heap[i];
    }
    
}

// TODO: Implement the copy assignment operator
HeapPriorityQueue &HeapPriorityQueue::operator=(const HeapPriorityQueue &other) {
  size = other.size;

  for (int i = 0; i < size; i++) {
    heap[i] = other.heap[i];
  }
  return *this;
}

// TODO: Implement enqueue function
void HeapPriorityQueue::enqueue(const string& str, int priority) {
    PrinterJob newJob(str, priority);
    heap[size] = newJob;
    percolateUp(size);
    size ++;
}

// TODO: Implement printJobs function
void HeapPriorityQueue::printJobs() {
    while(size != 0)
    {
      cout << heap[0].printString << " <Priority: " << heap[0].priority << ">"
           << endl;
      heap[0] = heap[size - 1];
      size--;
      percolateDown(0);
    }
}

// TODO: Implement percolateUp function
void HeapPriorityQueue::percolateUp(int index) {
    if (index == 0) return;

    int parentIndex = (index - 1) / 2;
    if (heap[index] < heap[parentIndex])
    {
        PrinterJob temp;
        temp = heap[parentIndex];
        heap[parentIndex] = heap[index];
        heap[index] = temp;
        percolateUp(parentIndex);
    }
}

// TODO: Implement percolateDown function
void HeapPriorityQueue::percolateDown(int index) {
    int leftChild = (2*index) + 1;
    int rightChild = (2*index) + 2;

    if(leftChild >= size) return;

    
    int lesserChild;
    if(rightChild < size)
    {
       lesserChild = (heap[leftChild] < heap[rightChild]) ? leftChild : rightChild; 
    }
    else {
        lesserChild = leftChild;
    }
    
    if(heap[index].priority > heap[lesserChild].priority)
    {
        PrinterJob temp = heap[index];
        heap[index] = heap[lesserChild];
        heap[lesserChild] = temp;

        percolateDown(lesserChild);
    }
}
