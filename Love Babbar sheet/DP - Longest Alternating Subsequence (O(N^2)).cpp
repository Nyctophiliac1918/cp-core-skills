// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		    int n = nums.size();
		    vector<vector<int>>dp(n, vector<int>(2,1));
		    
		    int ma = 1;
		    
		    for(int i=1;i<n;i++) {
		        for(int j=0;j<i;j++) {
		            if(nums[i]>nums[j] && dp[i][0] < 1 + dp[j][1]) dp[i][0] = 1 + dp[j][1];
		            else if(nums[i]<nums[j] && dp[i][1] < 1 + dp[j][0]) dp[i][1] = 1 + dp[j][0];
		        }
		        ma = max({ma,dp[i][0],dp[i][1]});
		    }
		    
		    return ma;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
