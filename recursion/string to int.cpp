#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
#define ll long long
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define w(x) int x; cin>>x; while(x--)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

char nums[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int stint(char *a, int n)
{
	if (n == 0)
		return 0;

	int digit = a[n - 1] - '0';
	int s = stint(a, n - 1);

	return s * 10 + digit;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char a[] = "12345464";
	int n = sizeof(a) / sizeof(a[0]); //int n=strlen(a);
	cout << stint(a, n - 1); //if you use the other method, then send n as an argument.
}
