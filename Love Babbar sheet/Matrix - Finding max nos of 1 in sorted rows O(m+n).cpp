// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1, p=m;
	    for(int j=0;j<m;j++)
	    {
	        if(arr[n-1][j]==1)
	        {
	            p=j, ans=n-1;
	            break;
	        }
	    }
	   // cout<<p<<endl;
	    for(int i=n-2;i>=0;i--)
	    {
	        if(p==m) {
	            for(int j=0;j<m;j++)
        	    {
        	        if(arr[i][j]==1)
        	        {
        	            p=j, ans=i;
        	            break;
        	        }
        	    }
        	    continue;
	        }
	        if(arr[i][p]==0) continue;
	        else {
	            for(int j=0;j<m;j++) {
	                if(arr[i][j]==1)
	                {
	                    p=j;
	                    ans=i;
	                    break;
	                }
	            }
	            if(arr[i][0] == 1) p=0, ans=i;
	        }
	       // cout<<i<<" "<<p<<endl;
	    }
	    return ans;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
