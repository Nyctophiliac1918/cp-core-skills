class Solution {
public:
    int binarySearch(int l, int r, int target, vector<int>& nums)
    {
        int p = -1;
        
        while(l<=r) {
            int m = (l+r)/2;
            if(nums[m]==target)
                return m;
            else if(nums[m]>=nums[l])
            {
                if(target>=nums[l] && target<=nums[m])
                    r=m-1;
                else l=m+1;
            }
            else {
                if(target>=nums[m] && target<=nums[r])
                    l=m+1;
                else r=m-1;
            }
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1) {
            if(nums[0]==target)
                return 0;
            else return -1;
        }
        
        if(n==2) {
            if(nums[0]==target)
                return 0;
            else if(nums[1]==target)
                return 1;
            else return -1;
        }
        
        return binarySearch(0,n-1,target,nums);
    }
};
