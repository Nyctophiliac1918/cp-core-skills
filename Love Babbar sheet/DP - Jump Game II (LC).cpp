class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]==0) return -1;
        
        int jumps=1, steps=nums[0], mxr = nums[0];
        
        for(int i=1;i<n;i++){
            if(i==n-1) return jumps;
            mxr=max(mxr,i+nums[i]);
            steps--;
            if(steps==0) {
                steps=mxr-i;
                jumps++;
            }
            if(i>=mxr)
                return -1;
        }
        
        return jumps;
    }
};
