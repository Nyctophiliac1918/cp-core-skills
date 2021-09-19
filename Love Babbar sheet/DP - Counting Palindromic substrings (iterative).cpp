class Solution {
public:  
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                if(g==0) dp[i][j]=1;
                else if(g==1) {
                    if(s[i]==s[j])
                        dp[i][j]=1;
                }
                else {
                    if(s[i]==s[j] && dp[i+1][j-1])
                        dp[i][j]=true;
                }
                if(dp[i][j])
                    ans++;
            }
        }
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//                 cout<<dp[i][j]<<" ";
//             cout<<endl;
//         }
        
        return ans;

    }
};
