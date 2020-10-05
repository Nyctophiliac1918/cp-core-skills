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

int fib(int n, int dp[])
{
	//Base case
	if (n == 0 or n == 1)
		return n;

	//Recursive case
	if (dp[n] != 0)
		return dp[n];

	int ans;
	ans = fib(n - 1, dp) + fib(n - 2, dp);
	return dp[n] = ans;
}

int main()
{
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int n = 15;
	int dp[101] = {};
	
	cout << fib(n, dp);
}
