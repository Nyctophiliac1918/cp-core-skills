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

int fib(int n)  //Space complexity: O(N)
{
	int dp[101] = {};
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	return dp[n];
}

int optimisedSpace_fib(int n)  //Space complexity: O(1)
{
	if(n==0 || n==1)
		return n;
	
	int a=0,b=1,c;
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b,b=c;
	}
	return c;
}
	
int main()
{
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/

	int n = 5;

	cout << fib(n);
	cout << optimisedSpace_fib(n);
}
