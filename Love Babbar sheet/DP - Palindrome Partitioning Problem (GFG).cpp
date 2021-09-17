// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isPalindrome(int i, int j, string& s) {
        while(i<=j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    int solve(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        if(isPalindrome(i,j,s))
            return 0;
            
        int ans = INT_MAX;
        
        for(int k=i;k<j;k++)
        {
            int l = solve(i,k,s,dp);
            int r = solve(k+1,j,s,dp);
            ans = min(ans, 1+l+r);
        }
        
        return dp[i][j] = ans;
        
    }

    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int k = solve(0,n-1,str,dp);
        return k;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
