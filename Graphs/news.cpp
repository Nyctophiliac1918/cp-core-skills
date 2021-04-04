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
	list<int> *l;
public:

	Graph(int v)
	{
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int x, int y, bool directed = true)
	{
		l[x].pb(y);

		if (!directed)
			l[y].pb(x);
	}

	bool cycle_helper(int node, bool *visited, int parent)
	{
		visited[node] = true;

		for (auto nbr : l[node])
		{
			if (!visited[nbr])
			{
				bool cycle_mila = cycle_helper(nbr, visited, node);
				if (cycle_mila)
					return true;
			}
			else if (nbr != parent)
				return true;
		}
		return false;
	}

	bool contains_cycle()
	{
		bool *visited = new bool [V];
		for (int i = 0; i < V; i++)
			visited[i] = false;
		return cycle_helper(0, visited, -1);
	}
};

int main()
{
	Graph g(5);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	//g.addEdge(4, 0);

	if (g.contains_cycle())
	{
		cout << "Yes, it is cyclic.";
	}
	else cout << "No, not cyclic.";
}