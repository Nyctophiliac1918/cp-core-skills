// do bfs on every node to find the shortest cycle in an undirected graph.

#include <bits/stdc++.h>
#define in(x) int x; cin>>x;
#define w(x) int x; cin>>x; while(x--)
#define ll long long int
#define lin(x) ll x; cin>>x;
#define vi vector<int>
#define si set<int>
#define pb push_back
#define rep(i,n) for(int i=0; i<n; i++)
#define pe(i,a,b) for(int i=a; i<=b; i++)
#define rre(i,n) for(int i=n-1; i>-1; i--)
#define mp make_pair
#define pii pair<ll,ll>
#define endl "\n"
#define pi 3.1415926536
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int1 long long
using namespace std;

const int N = 100005;

vector<int>gr[N];

void bfs(int src, int n, int& ans)
{
	vector<int>dist(n + 1, INT_MAX);
	queue<int> Q;
	Q.push(src);
	dist[src] = 0;

	while (!Q.empty())
	{
		int curr = Q.front();
		Q.pop();

		for (auto nbr : gr[curr]) {
			if (dist[nbr] == INT_MAX)
			{
				//nbr not visited
				dist[nbr] = dist[curr] + 1;
				Q.push(nbr);
			}
			else if (dist[nbr] >= dist[curr])
				ans = min(ans, dist[nbr] + dist[curr] + 1);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		gr[x].pb(y);
		gr[y].pb(x);
	}

	int ans = n + 1;
	for (int i = 1; i <= n; i++)
		bfs(i, n, ans);
	if (ans == n + 1)
		cout << "No cycle";
	else cout << "Shortest cycle is of length " << ans;
}
