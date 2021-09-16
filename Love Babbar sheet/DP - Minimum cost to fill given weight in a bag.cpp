// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		
	public:
	
	int solve(int cost[], int n, int w, vector<vector<int>>& dp) {
		if (n < 0 and w <= 0)
			return 0;
		if (n < 0) return 1e9;
		if (w == 0)
			return 0;

		if (dp[n][w] != -1)
			return dp[n][w];

		if (n + 1 > w or cost[n] == -1) return dp[n][w] = solve(cost, n - 1, w, dp);
		int x = solve(cost, n - 1, w, dp);
		int y = cost[n] + solve(cost, n, w - n - 1, dp);

		return dp[n][w] = min(x, y);
	}
	
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
		int k = solve(cost, N - 1, W, dp);
		for (int i = 0; i < N; i++)
// 		{
// 			for (int j = 0; j <= W; j++)
// 				cout << dp[i][j] << " ";
// 			cout << endl;
// 		}
		return k;
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
