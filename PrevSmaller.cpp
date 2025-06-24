#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void prevSmallerElement(vector<int> arr, vector<int>& ans) {
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < arr.size(); i++) {
        int ele = arr[i];
        while (s.top() >= ele) {
            s.pop();
        }
        ans.push_back(s.top());
        s.push(ele);
    }
}
int main() {
    vector<int> arr;
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);
    vector<int> ans;
    prevSmallerElement(arr, ans);
    for (int an : ans) {
        cout << an << endl;
    }  
    return 0;
}