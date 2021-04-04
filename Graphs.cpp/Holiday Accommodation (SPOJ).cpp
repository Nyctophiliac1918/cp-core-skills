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

class Graph {
	int V;
	list<pair<int, int> > *l;
public:

	Graph(int v)
	{
		V = v;
		l = new list<pair<int, int> >[V];
	}

	void addEdge(int x, int y, int p)
	{
		l[x].pb(mp(y, p));
		l[y].pb(mp(x, p));
	}

	int dfs_helper(int node, bool *visited, int *count, long long &ans)
	{
		visited[node] = true;
		count[node] = 1;

		for (auto nbr_pair : l[node])
		{
			int nbr = nbr_pair.first;
			int wt = nbr_pair.second;
			if (!visited[nbr])
			{
				count[node] += dfs_helper(nbr, visited, count, ans);
				int nx = count[nbr];
				int ny = V - nx;
				ans += 2 * min(nx, ny) * wt;
			}

		}
		return count[node];
	}

	long long dfs()
	{
		bool *visited = new bool[V];
		int *count = new int[V];

		for (int i = 0; i < V; i++)
		{
			visited[i] = false;
			count[i] = 0;
		}
		long long ans = 0;
		long long k = dfs_helper(0, visited, count, ans);
		//cout << k << endl;
		return ans;
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	FAST
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		int n, a, b, p;
		cin >> n;

		Graph g(n);
		for (int j = 1; j < n; j++)
		{
			cin >> a >> b >> p;
			g.addEdge(a - 1, b - 1, p);
		}

		cout << "Case #" << i << ": " << g.dfs() << endl;
	}
}
