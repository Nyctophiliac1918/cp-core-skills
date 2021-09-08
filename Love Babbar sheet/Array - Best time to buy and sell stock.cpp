// sliding window
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int l=0, r=1, n=prices.size(), m=0;
        while(r<n)
        {
            if(prices[l]<prices[r])
            {
                m=max(m,prices[r]-prices[l]);
            }
            else l=r;
            r++;
        }
        return m;
    }
};

//my approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=INT_MAX,p=0;
        for(int i=0;i<prices.size();i++)
        {
            m=min(m,prices[i]);
            p=max(p,prices[i]-m);
        }
        return p;
    }
};
