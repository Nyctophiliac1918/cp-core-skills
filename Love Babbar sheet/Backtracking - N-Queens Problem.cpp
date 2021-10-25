class Solution {
public:
    void solve(int col, int n, vector<string>& p, vector<vector<string>>& ans, vector<int>& r, vector<int>& u, vector<int>& l)
    {
        if(col==n) {
            ans.push_back(p);
            return;
        }
        
        for(int row=0;row<n;row++) {
            if(r[row]==0 && u[n-1+col-row]==0 && l[row+col]==0)
            {
                r[row]=1;
                u[n-1+col-row]=1;
                l[row+col]=1;
                p[row][col] = 'Q';
                solve(col+1,n,p,ans,r,u,l);
                p[row][col] = '.';
                r[row]=0;
                u[n-1+col-row]=0;
                l[row+col]=0;
            }
        }
    }
        
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        string s(n,'.');
        
        vector<string>p(n);
        for(int i=0;i<n;i++) p[i] = s;
        vector<int>r(n), upper(2*n-1), lower(2*n-1);
        
        solve(0,n,p,ans,r,upper,lower);
        
        return ans;
    }
};
