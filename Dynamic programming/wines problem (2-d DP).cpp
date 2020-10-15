#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip> //for setprecision()
#include <cstring> //for memset()
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int profit(int wines[], int i, int j, int y, int dp[][100]) // top down
{
	if (i > j)
		return 0;

	if (dp[i][j] != 0)
		return dp[i][j];

	int op1 = wines[i] * y + profit(wines, i + 1, j, y + 1, dp);
	int op2 = wines[j] * y + profit(wines, i, j - 1, y + 1, dp);

	return dp[i][j] = max(op1, op2);
}

int main()
{
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int wines[] = {2, 3, 5, 1 , 4};
	int dp[100][100] = {};

	int n = sizeof(wines) / sizeof(int);
	int y = 1;
	cout << profit(wines, 0, n - 1, y, dp);

	return 0;
}
