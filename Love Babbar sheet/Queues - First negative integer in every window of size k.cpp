// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
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
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    int l=0,r=0;
    list<int>q;
    vector<long long>v;
    while(r<N) {
        if(r-l==K) {
            if(q.empty())
                v.push_back(0);
            else v.push_back(q.front());
            if(!q.empty() && q.front()==A[l])
                q.pop_front();
            l++;
            if(A[r]<0)
                q.push_back(A[r]);
            r++;
        }
        else {
            if(A[r]<0)
                q.push_back(A[r]);
            r++;
        }
    }
    if(q.empty())
        v.push_back(0);
    else v.push_back(q.front());
    return v;
 }
