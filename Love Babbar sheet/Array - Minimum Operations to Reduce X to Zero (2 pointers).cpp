class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp, int x, int c) {
        if(x==0) return c;
        if(i>j || x<0) return INT_MAX;
        
        if(dp[i][j]!=-1) return dp[i][j];
        // cout<<i<<" "<<j<<" "<<x<<endl;
        
        int l=solve(i+1,j,nums,dp,x-nums[i],c+1);
        int r=solve(i,j-1,nums,dp,x-nums[j],c+1);
        
        return dp[i][j] = min(l,r);
    }
    
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int l=0, r=0;
        int s=0, mx=-1;
        int m = accumulate(nums.begin(), nums.end(), 0);
        m-=x;
        if(m<0)
            return -1;
        else if(m==0) return n;
        
        while(r<=n) {
            // cout<<s<<" "<<mx<<endl;
            if(s<m)
            {
                if(r==n)
                    break;
                s+=nums[r];
                r++;
            }
            else if(s>m) {
                s-=nums[l];
                l++;
            }
            else {
                mx=max(mx,r-l);
                s+=nums[r];
                r++;
            }
        }
        
        return mx==-1?mx:n-mx;
    }
};
