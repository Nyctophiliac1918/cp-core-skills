class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n, 0);
        int mn = prices[0], mx = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            mx=max(mx,prices[i]);
            dp[i] = max(dp[i+1], mx-prices[i]);
        }
        for(int i=1;i<n;i++)
        {
            mn=min(mn,prices[i]);
            dp[i] = max(dp[i-1], dp[i]+(prices[i]-mn));
        }
        return dp[n-1];
    }
};
