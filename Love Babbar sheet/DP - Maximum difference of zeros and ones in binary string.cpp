// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int n = S.size();
	    
	    vector<int>v(n);
	    for(int i=0;i<n;i++) {
	        if(S[i]=='0') v[i]=1;
	        else v[i]=-1;
	       // cout<<v[i]<<" ";
	    }
	    
	    int mx=0, m=0, e=INT_MIN;
	    
	    for(int i=0;i<n;i++) {
	        m+=v[i];
	        if(m<0){
	            m=0;
	        }
	        mx=max(mx,m);
	        e=max(e,v[i]);
	    }
	    
	    if(mx==0 && e<0)
	        return -1;
	    return mx;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
