// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dist(n,INT_MAX);
	    dist[0] = 0;
	    for(int i=0;i<n-1;i++) {
	        for(auto p:edges) {
	            int x = p[0], y = p[1], z = p[2];
	            if(dist[x]!=INT_MAX && dist[x]+z<dist[y])
	                dist[y] = dist[x]+z;
	        }
	    }
	    
	    bool flag = false;
        for(auto p:edges) {
            int x = p[0], y = p[1], z = p[2];
            if(dist[x]!=INT_MAX && dist[x]+z<dist[y])
                flag = true;
        }
	    
	    return flag;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
