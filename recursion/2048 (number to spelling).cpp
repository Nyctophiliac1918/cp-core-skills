#include <bits/stdc++.h>
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

void printSpellings(int n)
{
	if (n == 0)
		return;
	printSpellings(n / 10);
	int d = n % 10;
	cout << nums[d] << " ";
	return;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	printSpellings(n);
}
