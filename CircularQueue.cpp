#include <iostream>
using namespace std;
class CircularQueue
{
private:
    int* arr;
    int n;
    int front;
    int rear;
public:
    CircularQueue(int size) {
        this -> n = size;
        arr = new int[size];
        front = -1;
    }
    void push(int val) {
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
    void pop() {
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
    int getFront() {
        if (front == -1) {
            cout << "Empty Queue" << endl;
        }
        else {
            return arr[front];
        }
    }
    int getSize() {
        if (front == -1 && rear == -1) {
            return 0;
        }
        else if (rear >= front){
            return rear - front + 1;
        }
        else {
            return n - front + rear + 1;
        }
    }
    bool isEmpty() {
        if (front == -1 && rear == -1) {
            return true;
        }
        return false;
    }
};

