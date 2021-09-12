// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    bool check(int i, int j, int n, vector<vector<int>>& vis) {
		if (i > 0 && i <= n && j > 0 && j <= n && !vis[i][j])
			return true;
		return false;
	}

	int solve(int i, int j, int x, int y, int n, vector<int>&k, vector<int>&t, vector<vector<int>>& vis, vector<vector<int>>& dis) {
		queue<pair<int, int>>q;

		int dx[] = {1, 1, 2, 2, -1, -1, -2, -2};
		int dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

		q.push({i, j});
		vis[i][j] = 1;
		dis[i][j] = 0;

		while (!q.empty()) {
			auto curr = q.front();
			i = curr.first, j = curr.second;
			q.pop();

			for (int k = 0; k < 8; k++) {
				if (check(i + dy[k], j + dx[k], n, vis))
				{
					// cout << i + dy[k] << " " << j + dx[k] << endl;
					q.push({i + dy[k], j + dx[k]});
					vis[i + dy[k]][j + dx[k]] = 1;
					dis[i + dy[k]][j + dx[k]] = 1 + dis[i][j];
					if (i + dy[k] == x && j + dx[k] == y)
						return dis[i + dy[k]][j + dx[k]];
				}
			}
		}

		return dis[x][y];
	}

	//Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n)
	{
		// Code here
		vector<vector<int>> vis(n + 1, vector<int>(n + 1, 0));
		vector<vector<int>> dis(n + 1, vector<int>(n + 1, 0));
		int i = KnightPos[0], j = KnightPos[1];
		int x = TargetPos[0], y = TargetPos[1];
		return solve(i, j, x, y, n, KnightPos, TargetPos, vis, dis);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
