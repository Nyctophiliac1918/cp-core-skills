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

int dp[3005][3005] = {};  // defined globally as there was a runtime error when called by function.

int lcs(string& s1, string& s2, int i, int j)   // If we don't take string as reference, then the solution would become O(N^3) instead of O(N^2) because of some transitions as the string will be called as whole again.
{
	if (i == (int)s1.size() or j == (int)s2.size())
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	if (s1[i] == s2[j])
		return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1);

	int op1 = lcs(s1, s2, i + 1, j);
	int op2 = lcs(s1, s2, i, j + 1);

	return dp[i][j] = max(op1, op2);
}

string LCS(string& s, string& t, int len)   // If we don't take string as reference, then the solution would become O(N^3) instead of O(N^2) because of some transitions as the string will be called as whole again.
{
	string LCS;
	int i = 0, j = 0;
	while (len > 0)
	{
		if (s[i] == t[j])
		{
			LCS += s[i];
			i++;
			j++;
			len--;
		}
		else
		{
			if (dp[i + 1][j] > dp[i][j + 1])
				i++;
			else j++;
		}
	}
	return LCS;
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

	memset(dp, -1, sizeof(dp));

	int len = lcs(s1, s2, 0, 0);

	cout << LCS(s1, s2, len);

}
