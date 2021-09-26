// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int j, int i, int n, int a[], vector<vector<int>>& dp) {
        if(i>=n) return 0;
        
        if(j!=-1 && dp[i][j]!=-1) return dp[i][j];
        
        int in = 0;
        if(j==-1 || a[i]>a[j]) in = 1 + solve(i,i+1,n,a,dp);
        int ex = solve(j,i+1,n,a,dp);
        
        if(j!=-1) dp[i][j] = max(in,ex);
        return max(in,ex);
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
        vector<vector<int>>dp(n, vector<int>(n,-1));
        int k = solve(-1, 0, n, a, dp);
        // cout<<k<<endl;
        // int mx=0;
        // for(int i=0;i<n;i++)
        //     for(int j=0;j<n;j++)
        //     {
        //         mx = max(mx,dp[i][j]);
        //         cout<<dp[i][j]<<" ";
        //     }
        return k;
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
