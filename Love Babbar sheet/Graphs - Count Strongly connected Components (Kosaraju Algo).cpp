// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int src, vector<int> adj[], vector<int>& vis, stack<int>& s)
	{
	    vis[src] = 1;
	    
	    for(int node: adj[src])
	    {
	        if(!vis[node])
	        {
	            dfs(node, adj, vis, s);
	        }
	    }
	    
	    s.push(src);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int>adj2[V];
        for(int i=0;i<V;i++) {
            for(int j=0;j<adj[i].size();j++)
                adj2[adj[i][j]].push_back(i);
        }
        
        stack<int>s;
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++)
            if(!vis[i])
                dfs(i,adj,vis,s);
            
        int c = 0;
        vector<int>vis2(V,0);
        stack<int>s2;
        
        while(!s.empty()) {
            // cout<<s.top()<<" ";
            if(!vis2[s.top()])
            {
                dfs(s.top(), adj2, vis2, s2);
                c++;
            }
            // for(int i=0;i<V;i++) cout<<vis[i]<<" ";
            // cout<<endl;
            s.pop();
        }
        
        return c;
        
            
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
