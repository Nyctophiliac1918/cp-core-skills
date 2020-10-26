#include <bits/stdc++.h>
/*#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip> //for setprecision()
#include <cstring> //for memset()*/
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

// recursive solution
int lcs(string s1, string s2, int i, int j)
{
	if (i == s1.size() or j == s2.size())
		return 0;

	if (s1[i] == s2[j])
		return 1 + lcs(s1, s2, i + 1, j + 1);

	int op1 = lcs(s1, s2, i + 1, j);
	int op2 = lcs(s1, s2, i, j + 1);

	return max(op1, op2);

}

// top down dp
int lcs(string s1, string s2, int i, int j, vector< vector<int> > &dp)
{
	if (i == s1.size() or j == s2.size())
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s1[i] == s2[j])
		return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);

	int op1 = lcs(s1, s2, i + 1, j, dp);
	int op2 = lcs(s1, s2, i, j + 1, dp);

	return dp[i][j] = max(op1, op2);

}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;
	cin >> s1 >> s2;

	int n1 = s1.size(), n2 = s2.size();

	vector<vector<int> >dp(n1, vector<int>(n2, -1)); // vector of n1 * n2 size.


	cout << lcs(s1, s2, 0, 0) << endl; // recursive solution
	cout << lcs(s1, s2, 0, 0, dp); // top down dp
}
