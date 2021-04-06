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

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color)
{
	visited[node] = color;

	for (auto nbr : graph[node])
	{
		if (visited[nbr] == 0)
		{
			int subprob = dfs_helper(graph, nbr, visited, node, 3 - color);

			if (subprob == false)
				return false;
		}
		else if (nbr != parent and color == visited[nbr])
			return false;
	}

	return true;
}

bool dfs(vector<int> graph[], int n)
{
	int visited[n] = {0}; // 0 = not visited, 1 = visited by color 1 and 2 = visited by color 2

	int color = 1;
	int ans = dfs_helper(graph, 0, visited, -1, color);

	for (int i = 0; i < n; i++)
	{
		cout << i << " -> " << visited[i] << endl;
	}

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	vector<int> graph[n];

	while (m--)
	{
		int x, y;
		cin >> x >> y;

		graph[x].pb(y);
		graph[y].pb(x);
	}
	if (dfs(graph, n))
	{
		cout << "Yes, it is bipartite.";
	}
	else cout << "No, not bipartite.";
}
