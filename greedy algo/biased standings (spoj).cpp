// https://www.spoj.com/problems/BAISED/
// O(logN) solution : We can sort the ranks that people desire and then traverse the array and add the diff of what he desired and what is available.

//O(N) solution
// Here we are the storing the frquency of the ranks teams desire, and find the best that we can provide anyone by seeing which one is available closest to what someone desires.
// Thus we stored the frequency of the ranks that people desire and add the diff of one that is available and he desires to a integer and print it out.
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

int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	int t;
	cin >> t;
	cin.get();
	while (t--)
	{
		int n;
		cin >> n;
		string a;
		int b;
		int c[n + 1] = {};
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			c[b]++;
		}
		ll k = 0;
		int j = 1;
		for (int i = 1; i <= n; i++)
		{
			if (c[i])
			{
				int m = c[i];
				while (m--)
				{
					k += abs(i - j);
					j++;
				}
			}
		}
		cout << k << endl;
		cin.get();
	}
}
