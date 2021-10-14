class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int>l(n),r(n);
        stack<int>s,t;
        for(int i=0;i<n;i++) {
            while(!s.empty() && h[s.top()]>=h[i])
                s.pop();
            if(s.empty())
                l[i]=-1;
            else l[i]=s.top();
            s.push(i);
        }
        for(int i=n-1;i>=0;i--) {
            while(!t.empty() && h[t.top()]>=h[i])
                t.pop();
            if(t.empty())
                r[i]=n;
            else r[i]=t.top();
            t.push(i);
        }
        // for(int i=0;i<n;i++)
        //     cout<<l[i]<<" "<<r[i]<<endl;
        int m=0;
        for(int i=0;i<n;i++) {
            m = max(m, h[i]*(r[i]-l[i]-1));
        }
        return m;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0)
            return 0;
        int m = matrix[0].size();
        vector<int>v(m);
        int mx = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j]=='0')
                    v[j]=0;
                else v[j]++;
            }
            mx = max(mx, largestRectangleArea(v));
        }
        return mx;
    }
};
