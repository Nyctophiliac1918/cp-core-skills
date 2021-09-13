class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            int ll=0, rl=0, lg=0, rg=0;
            for(int j=i-1;j>=0;j--)
            {
                if(rating[i]>rating[j])
                    ll++;
                else lg++;
            }
            for(int j=i+1;j<n;j++)
            {
                if(rating[i]>rating[j])
                    rl++;
                else rg++;
            }
            ans+=(ll*rg);
            ans+=(lg*rl);
        }
        
        
        return ans;
    }
};
