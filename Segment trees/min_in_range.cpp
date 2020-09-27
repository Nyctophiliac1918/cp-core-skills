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

void buildTree(int *a, int s, int e, int *tree, int idx)
{
	if (s == e)
	{
		tree[idx] = a[s];
		return;
	}

	int mid = (s + e) / 2;
	buildTree(a, s, mid, tree, 2 * idx);
	buildTree(a, mid + 1, e, tree, 2 * idx + 1);
	tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
	return;
}

int query(int *tree, int s, int e, int qs, int qe, int idx)
{
	//Complete overlap
	if (s >= qs && e <= qe)
		return tree[idx];

	//No overlap
	if (s > qe || e < qs)
		return INT_MAX;

	//Partial overlap
	int mid = (s + e) / 2;
	int left = query(tree, s, mid, qs, qe, 2 * idx);
	int right = query(tree, mid + 1, e, qs, qe, 2 * idx + 1);
	return min(left, right);

}

void updateNode(int *tree, int s, int e, int i, int inc, int idx)
{
	if (i < s || i > e)
		return;

	if (s == e)
	{
		tree[idx] += inc;
		return;
	}

	int mid = (s + e) / 2;
	updateNode(tree, s, mid, i, inc, 2 * idx);
	updateNode(tree, mid + 1, e, i, inc, 2 * idx + 1);
	tree[idx] = min(tree[2 * idx], tree[2 * idx + 1]);
	return;

}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[] = {1, 3, 2, -5, 6, 4};
	int n = sizeof(a) / sizeof(int);

	int *tree = new int[4 * n + 1];
	buildTree(a, 0, n - 1, tree, 1);

	w(q)
	{
		int l, r;
		cin >> l >> r;
		cout << query(tree, 0, n - 1, l, r, 1) << endl;
	}

	updateNode(tree, 0, n - 1, 3, 10, 1);

	w(p)
	{
		int l, r;
		cin >> l >> r;
		cout << query(tree, 0, n - 1, l, r, 1) << endl;
	}

}
