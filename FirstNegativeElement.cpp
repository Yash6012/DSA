#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int a[], long long int n, long long int k) {
    // Sliding window
    // 3 Step Solution5
    deque<long long int> q;
    vector<long long> ans;
    // 1. Process first window
    for (int i = 0; i < k; i++)
    {
        if (a[i] < 0) {
            q.push_back(i);
        }
    }
    // store the answer
    if (q.empty()) {
        ans.push_back(0);
    }
    else {
        ans.push_back(a[q.front()]);
    }
    // 2. process the other window
    for (int i = 0; i < n; i++) {
        // A: Removal
        if (!q.empty() && q.front() < i - k + 1) {
            q.pop_front();
        }
        // B: Addition
        if (a[i] < 0) {
            q.push_back(i);
        }
        // C: Store
        if (q.empty()) {
            ans.push_back(0);
        }
        else{
            ans.push_back(a[q.front()]);
        }
    }
    return ans;
    
}
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}