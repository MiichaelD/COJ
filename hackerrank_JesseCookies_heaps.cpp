// https://www.hackerrank.com/challenges/jesse-and-cookies
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <unordered_map>

using namespace std;

template<class T>
class Heap{
protected:
    vector<T> items;
    int size = 0;
    
    virtual bool heapDownComp(T itemA, T itemB) = 0;
    virtual bool heapUpComp(T itemA, T itemB) = 0;
    virtual ~Heap(){};
    
    int getLeftChildIndex(int parentIndex) {
        return 2 * parentIndex + 1;
    }
    
    int getRightChildIndex(int parentIndex) {
        return 2 * parentIndex + 2;
    }
    
    int getParentIndex(int childIndex) {
        return (childIndex - 1) / 2;
    }
    
    bool hasLeftChild(int index) {
        return getLeftChildIndex(index) < size;
    }
    
    bool hasRightChild(int index) {
        return getRightChildIndex(index) < size;
    }
    
    bool hasParent(int index) {
        return getParentIndex(index) >= 0;
    }
    
    T leftChild(int index) {
        return items[getLeftChildIndex(index)];
    }
    
    T rightChild(int index) {
        return items[getRightChildIndex(index)];
    }
    
    T parent(int index) {
        return items[getParentIndex(index)];
    }
    
    void swap(T indexOne, T indexTwo) {
        T temp = items[indexOne];
        items[indexOne] = items[indexTwo];
        items[indexTwo] = temp;
    }    
    
    void heapifyDown() {
        int index = 0;
        while(hasLeftChild(index)) {
            int smallerChildIndex = (hasRightChild(index) 
                && heapDownComp(rightChild(index), leftChild(index)) )
                ? getRightChildIndex(index)
                : getLeftChildIndex(index);
            
            
            if(heapDownComp(items[index], items[smallerChildIndex])) {
                break;
            } else{
                swap(index, smallerChildIndex);
            }
            index = smallerChildIndex;
        }
    }
    
    void heapifyUp() {
        int index = size - 1;
        while(hasParent(index) &&  heapUpComp(parent(index),items[index]) ) {
            swap(getParentIndex(index), index);
            index = getParentIndex(index);
        }
    }    
    
    void forceNotEmpty(const string &methodName) const {
        if(isEmpty()) {
            throw std::underflow_error (
                "You cannot perform '" + methodName + "' on an empty Heap."
            );
        }
    }

public:
    Heap(int elements) {
        items.reserve(elements);
    }
    
    int getSize() const { return size; }

    bool isEmpty() const { return size == 0; }
    
    T peek() {
        forceNotEmpty("peek");
        return items[0];
    }
    
    T poll() {
        // Throws an exception if empty.
        forceNotEmpty("poll");
        // Else, not empty
        int item = items[0];
        items[0] = items[--size];

        heapifyDown();
        return item;
    }
    
    void add(T item) {        
        // Insert value at the next open location in heap
        if (size < items.size()){
            items[size] = item;
        } else{
            items.push_back(item);
        }
        ++size;
        // Correct order property
        heapifyUp();
    }
    
};

template<class T = int>
class MinHeap : public Heap<T>{
    using Heap<T>::Heap;
    virtual bool heapDownComp(T itemA, T itemB) override{
        return itemA < itemB; //minHeap
    }
    
    virtual bool heapUpComp(T itemA, T itemB) override{
        return itemA > itemB;// minHeap
    }
};

int countOperations(MinHeap<int> &cookiesHeap, int k) {
    int steps = 0;
    while(cookiesHeap.getSize() > 0) {
        int last = cookiesHeap.poll();
        if (last >= k)
          return steps;

        if (cookiesHeap.getSize() < 1)
          return -1; // no way to get 1 cookie
        
        int secondLast = cookiesHeap.poll();
        int newCookie = last + 2 * secondLast;
        ++steps;
        cookiesHeap.add(newCookie);
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    MinHeap<int> cookiesHeap(n);
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        cookiesHeap.add(val);
    }
    int requiredSteps = countOperations(cookiesHeap, k);
    cout << requiredSteps << endl;
    return 0;
}
