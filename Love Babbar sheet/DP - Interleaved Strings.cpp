// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    bool solve(string& a, string& b, string& c, int n, int m, int o, vector<vector<int>>& dp)
    {
        // cout<<n<<" "<<m<<" "<<o<<endl;

        if(o==0)
            return 1;
            
        if(n<0 && m<0)
            return 0;
            
        if(dp[n][m]!=-1) return dp[n][m];
        
        int x = 0, y = 0;
        
        if(o>0 && n>0 && c[o-1]==a[n-1]) x = solve(a,b,c,n-1,m,o-1,dp);
        if(o>0 && m>0 && c[o-1]==b[m-1]) y = solve(a,b,c,n,m-1,o-1,dp);
        
        return dp[n][m] = x || y;
        
    }
    
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int n = A.size(), m = B.size(), o = C.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
        bool k = solve(A,B,C,n,m,o,dp);
        return k;
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends
