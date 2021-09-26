// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    int solve(int n, int x, int y, int z, vector<int>& dp)
    {
        if(n<=0)
            return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int l,m,o;
        l=m=o=INT_MIN;
        
        if(n>=x) l= solve(n-x,x,y,z,dp);
        if(n>=y) m= solve(n-y,x,y,z,dp);
        if(n>=z) o= solve(n-z,x,y,z,dp);
        
        return dp[n] = 1 + max({l,m,o});
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        int k = solve(n,x,y,z,dp);
        // for(int i=0;i<=n;i++)
        //     cout<<dp[i]<<" ";
        if(k<0) return 0;
        return k;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
