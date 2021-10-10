// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<int>>dp(n, vector<int>(m,0));
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++) {
	        for(int j=0;j<m;j++) {
	            if(grid[i][j]==0)
	                dp[i][j] = INT_MAX;
	            else {
	                dp[i][j] = 0;
	                q.push({i,j});
	            }
	        }
	    }
	    int dx[] = {1,0,-1,0};
	    int dy[] = {0,-1,0,1};
	    while(!q.empty()) {
	        auto curr = q.front();
	        int x = curr.first, y = curr.second;
	        q.pop();
	        for(int i=0;i<4;i++) {
	            if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m && dp[x+dx[i]][y+dy[i]]!=0) {
	                if(1+dp[x][y]<dp[x+dx[i]][y+dy[i]])
	                {
	                    dp[x+dx[i]][y+dy[i]]=1+dp[x][y];
	                    q.push({x+dx[i],y+dy[i]});
	                }
	            }
	        }
	    }
	    return dp;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
