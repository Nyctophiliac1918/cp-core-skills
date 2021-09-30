#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int timer = 1;

void dfs(int src, vector<int>adj[], vector<int>& ins, vector<int>& out) {

	ins[src] = timer++;

	for(int node: adj[src]) {
		if(ins[node]==0)
			dfs(node, adj, ins, out);
	}

	out[src] = timer++;

}

int main() {
	FAST
	int n,a,b;
	cin>>n;
	vector<int>adj[n+1];
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
	}
	vector<int>ins(n+1),out(n+1);
	dfs(1,adj,ins,out);
	// for(int i=0;i<=n;i++)
	// {
	// 	cout<<i<<" "<<ins[i]<<" "<<out[i]<<endl;
	// }
	int q,d;
	cin>>q;
	while(q--) {
		cin>>d>>a>>b;
		// cout<<ins[a]<<" "<<ins[b]<<" "<<out[a]<<" "<<out[b]<<" ";
		if(d==0 && ins[b]>ins[a] && out[a]>out[b])
			cout<<"YES"<<endl;
		else if(d==1 && ins[b]<ins[a] && out[a]<out[b])
			cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
