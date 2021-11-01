class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) {
            // swap(n1,n2);
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int l = 0, r=n1;
        while(l<=r) {
            // cout<<l<<" "<<r<<endl;
            
            int cnt1 = (l+r) >> 1;
            int cnt2 = (n1+n2+1)/2 - cnt1;
            
            // cout<<cnt1<<" "<<cnt2<<endl;
            
            int l1 = cnt1==0 ? INT_MIN : nums1[cnt1-1];
            int l2 = cnt2==0 ? INT_MIN : nums2[cnt2-1];
            int r1 = cnt1==n1 ? INT_MAX : nums1[cnt1];
            int r2 = cnt2==n2 ? INT_MAX : nums2[cnt2];
            
            if(l1<=r2 && l2<=r1) {
                // cout<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
                if((n1+n2) % 2 == 0)
                {
                    return (max(l1,l2)+min(r1,r2)) / 2.0;
                }
                return max(l1,l2);
            }
            else if(l1>r2) {
                r = cnt1-1;
            }
            else l = cnt1+1;
        }
        return 0;
    }
};
