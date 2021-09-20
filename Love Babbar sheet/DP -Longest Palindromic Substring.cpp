class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        int dp[n][n];
        string p;
        p+=s[0];
        memset(dp,0,sizeof(dp));
        int mx=1;
        for(int g=0;g<n;g++) {
            bool flag = false;
            for(int i=0,j=g;j<n;i++,j++) {
                if(g==0) dp[i][j]=1;
                else if(g==1) {
                    if(s[i]==s[j]) dp[i][j]=1;
                }
                else {
                    if(s[i]==s[j] && dp[i+1][j-1])
                        dp[i][j]=1;
                }
                if(dp[i][j] and !flag)
                {
                    if(mx<g+1)
                    {
                        flag=true;
                        mx=g+1;
                        p=s.substr(i,j-i+1);
                    }
                } 
            }
        }
        return p;
    }
};
