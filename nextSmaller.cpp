#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void nextSmallerElement(vector<int> arr, vector<int>& ans) {
    stack<int> s;
    s.push(-1);
    for (int i = arr.size() - 1; i >= 0; i--) {
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
    nextSmallerElement(arr, ans);
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }  
    return 0;
}