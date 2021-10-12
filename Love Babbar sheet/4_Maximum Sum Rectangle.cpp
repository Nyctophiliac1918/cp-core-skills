// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int m = INT_MIN;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++)
                m=max(m,M[i][j]);
        }
        if(m<0) return m;
        
        int mx = 0;
        int i=0;
        while(i<C) {
            int j=i;
            vector<int>v(R,0);
            while(j<C) {
                for(int k=0;k<R;k++) {
                    v[k] += M[k][j];
                }
                int curr=0, s=0;
                for(int k=0;k<R;k++) {
                    s+=v[k];
                    if(s<0)
                        s=0;
                    if(curr<s) {
                        curr = s;
                    }
                }
                if(curr>mx) {
                    mx=curr;
                }
                // cout<<curr<<endl;
                j++;
            }
            i++;
        }
        return mx;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends
