// https://www.spoj.com/problems/BUSYMAN/
// We need to see this question with a greedy approach. So, we can sort the vector of pair on the basis of ascending order of activity's end time. This means we can take the first activity for sure. Now, we will check that if the end time of our activity does not interfere with the starting time of our can-be next activity, and we will increase the count on this basis.

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

bool cmp(const pair<int, int>&a, const pair<int, int>&b)
{
	return a.second < b.second;
}

int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/
	w(t)
	{
		int n;
		cin >> n;
		vector<pair<int, int>>v;
		int a, b;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			auto p = make_pair(a, b);
			v.push_back(p);
		}
		sort(v.begin(), v.end(), cmp);
		int k = 1;
		b = v[0].second;
		for (int i = 1; i < n; i++)
		{
			if (v[i].first >= b)
			{
				k++;
				b = v[i].second;
			}
		}
		cout << k << endl;
		cin.get();
	}
}
