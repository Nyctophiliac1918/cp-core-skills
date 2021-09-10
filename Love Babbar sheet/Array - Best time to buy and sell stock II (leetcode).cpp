//Greedy algo
//Try to take out from every uphill

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int l=0, r=1;
        int s=0;
        while(r<n) {
            if(a[r-1]>a[r])
            {
                s+=a[r-1]-a[l];
                l=r;
            }
            r++;
        }
        s+=a[r-1]-a[l];
        return s;
    }
};
