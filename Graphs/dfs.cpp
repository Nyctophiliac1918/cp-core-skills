#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

template<typename T>
class Graph {
	map<T, list<T>>l;

public:
	void addEdge(int x, int y)
	{
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited)
	{
		cout << src << " ";
		visited[src] = true;

		for (T nbr : l[src])
		{
			if (!visited[nbr])
				dfs_helper(nbr, visited);
		}
	}

	void dfs(T src)
	{
		// mark all the visited nodes.
		map<T, bool>visited;

		for (auto p : l)
		{
			T node = p.first;
			visited[node] = false;
		}

		// calling the helper function
		dfs_helper(src, visited);
	}
};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(3, 0);

	g.dfs(4);
}
