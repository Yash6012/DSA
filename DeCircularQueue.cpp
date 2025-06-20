#include <iostream>
using namespace std;
class DeCircularQueue
{
private:
    int* arr;
    int n;
    int front;
    int rear;
public:
    DeCircularQueue(int size) {
        this -> n == size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void pushFront(int val) {
        // 4 cases
        // 1. Overflow
        if ((front == 0 && rear == n-1) || (rear = front - 1)) {
            cout << "Overflow" << endl;
        }
        // 2. First Element
        else if (front == -1 && rear == -1) {
            front++;
            rear++;
            arr[rear] = val;
        }
        // 3. Circular nature
        else if (front == 0 && rear != n - 1) {
            front = n - 1;
            arr[front] = val;
        }
        else {
            front--;
            arr[front] = val;
        }
    }
    void pushBack(int val) {
        // 4 cases
        // 1. Overflow
        if ((front == 0 && rear == n-1) || (rear = front - 1)) {
            cout << "Overflow" << endl;
        }
        // 2. First Element
        else if (front == -1 && rear == -1) {
            front++;
            rear++;
            arr[rear] = val;
        }
        // 3. Circular nature
        else if (rear == n - 1 && front != 0) {
            rear = 0;
            arr[rear] = val;
        }
        // 4. Normal
        else {
            rear++;
            arr[rear] = val;
        }
    }
    void popFront() {
        // 4. Case
        // 1. Underflow
        if (front == -1 && rear == -1) {
            cout << "UnderFlow" << endl;
        }
        // 2. single element
        else if (front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // 3. circular case
        else if (front == n - 1) {
            arr[front] = -1;
            front = 0;
        }
        else {
            arr[front] = -1;
            front++;
        }
    }
    void popBack() {
        // 4. Case
        // 1. Underflow
        if (front == -1 && rear == -1) {
            cout << "UnderFlow" << endl;
        }
        // 2. single element
        else if (front == rear) {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        // 3. circular case
        else if (rear == 0) {
            arr[rear] = - 1;
            rear = n - 1;
        }
        else {
            arr[rear] = -1;
            rear--;
        }
    }
};

DeCircularQueue::DeCircularQueue(/* args */)
{
}

DeCircularQueue::~DeCircularQueue()
{
}
