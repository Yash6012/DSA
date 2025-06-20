#include <iostream>
#include <stack>
#include <queue>
using namespace std;
void reverseKGroup(queue<int>& q, int count, int k) {
    if (count >= k) {
        stack<int> s;
        for (int i = 0; i < k; i++) {
            int ele = q.front();
            q.pop();
            s.push(ele);
        } 
        for (int i = 0; i < k; i++) {
            int ele = s.top();
            s.pop();
            q.push(ele);
        }
        reverseKGroup(q, count - k, k);
    }
    else {
        // element ko starting se utha ke end mei laga degi
        for (int i = 0; i < count; i++) {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
    }
}
int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);
    int count = q.size();
    int k = 3;
    reverseKGroup(q, count, k);
    while (!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    return 0;
}