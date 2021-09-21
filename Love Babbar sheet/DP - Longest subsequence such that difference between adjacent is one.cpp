// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, int n, int a[], vector<vector<int>>& dp) {
        if(i>=n)
            return 0;
        
        if(j!=-1 && dp[i][j]!=-1)
            return dp[i][j];
        
        int in = 0;
        if(j==-1 || abs(a[i]-a[j])==1) {
            in = 1+ solve(i+1,i,n,a,dp);
        }
        int ex = solve(i+1,j,n,a,dp);
        
        if(j!=-1)
            dp[i][j] = max(in,ex);
        return max(in, ex);
    }
    
    int longestSubsequence(int N, int A[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(N,-1));
        int k = solve(0,-1,N,A,dp);
        // for(int i=0;i<N;i++) {
        //     for(int j=0;j<N;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return k;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends
