class Solution {
public:    
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        
        string l;
        bool flag = false;
        
        for(int i=0;i<m;i++) {
            if(p[i]!='*' || !flag) l+=p[i];
            if(p[i]=='*') flag = true;
            else flag = false;
        }
        
        vector<vector<bool>>dp(n+1, vector<bool>(l.size()+1,0));
        
        dp[0][0] = true;
        if(p[0]=='*') dp[0][1]=true;
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=l.size();j++) {
                if(l[j-1]=='?' || s[i-1]==l[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else if(l[j-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        
        return dp[n][l.size()];
    }
};
