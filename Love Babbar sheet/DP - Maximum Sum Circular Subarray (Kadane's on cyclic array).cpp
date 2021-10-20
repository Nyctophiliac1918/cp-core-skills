class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int sum=0, mn = INT_MAX, m =INT_MIN, mx = INT_MIN, s1 = 0, s2 = 0;
        for(int i=0;i<n;i++) {
            m = max(m, nums[i]);
            s1 += nums[i];
            s2 += nums[i];
            sum += nums[i];
            
            if(s1>=0) s1=0;
            if(s2<=0) s2=0;
            
            mn = min(mn, s1);
            mx = max(mx, s2);
        }
        
        if(m<=0) return m;
        
        return max(sum-mn, mx);
    }
};
