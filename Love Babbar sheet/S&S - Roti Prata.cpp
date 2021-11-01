#include <bits/stdc++.h>
using namespace std;
// template<typename... T>
// void see(T&... args) { ((cin >> args), ...);}
// template<typename... T>
// void put(T&&... args) { ((cout << args << " "), ...);}
// template<typename... T>
// void putl(T&&... args) { ((cout << args << " "), ...); cout << '\n';}
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
#define pii pair<int,int>
#define pll pair<long long,long long>
#define endl "\n"
#define pi 3.1415926536
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 1e9 + 7;

// int path(int n)
// {
// 	for (int i = 1; i < n; i++)
// 	{
// 		if (a[i][0] != '*')
// 			dp[i][0] = dp[i - 1][0];

// 		if (a[0][i] != '*')
// 			dp[0][i] = dp[0][i - 1];
// 	}

// 	for (int i = 1 ; i < n; i++)
// 	{
// 		for (int j = 1; j < n; j++)
// 		{
// 			if (a[i][j] != '*')
// 				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
// 		}
// 	}

// 	return dp[n - 1][n - 1] % 1000000007;

// }

int dp[1010][1010];

int solve(int h, int a, int i) {
	// cout << h << " " << a << endl;

	if (h <= 0 || a <= 0) return 0;

	if (dp[h][a] != -1) return dp[h][a];

	int m = INT_MIN;

	if (i != 1) m = max(m, 1 + solve(h + 3, a + 2, 1));
	if (i != 2) m = max(m, 1 + solve(h - 5, a - 10, 2));
	if (i != 3) m = max(m, 1 + solve(h - 20, a + 5, 3));

	return dp[h][a] = m;
}

void dijkstra(int src, int dest, vector<pll> adj[], vector<ll>& dist) {
	dist[src] = 0;

	priority_queue<pll, vector<pll>, greater<pll>>pq;

	pq.push({0, src});

	while (!pq.empty()) {
		ll d = pq.top().first, curr = pq.top().second;
		pq.pop();

		for (auto node : adj[curr]) {
			if (d > dist[curr]) break;
			// cout << node.first << " " << node.second << endl;
			if (d + node.second < dist[node.first])
			{
				dist[node.first] = d + node.second;
				pq.push({dist[node.first], node.first});
			}
		}
	}
}

class Node {
public:
	int data;
	Node* next;

	Node() {
		next = NULL;
	}

	Node(int x) {
		data = x;
		next = NULL;
	}
};

bool canMake(int t, vector<int>& v, int p) {
	int pr = 0;

	for (int i = 0; i < v.size(); i++) {
		int time = v[i], j = 1;
		while (time <= t) {
			pr++;
			j++;
			time += (j * v[i]);
		}
		if (pr >= p)
			return true;
	}

	return false;
}

int main()
{
	FAST
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// Node* n = new Node(1);
	// Node* s = new Node(2);
	// Node* t = new Node();
	// t->data = 3;
	// n->next = s;
	// s->next = t;

	// while (n != NULL)
	// {
	// 	cout << n->data << endl;
	// 	n = n->next;
	// }

	w(t) {
		int m;
		cin >> m;

		int n;
		cin >> n;
		vector<int>v(n);
		rep(i, n) cin >> v[i];

		int l = 0, r = 1e7;
		int ans = r;

		while (l <= r) {
			int mid = (l + r) >> 1;

			if (canMake(mid, v, m))
			{
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		cout << ans << endl;
	}

	return 0;

}
