// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n = s.size();
	    vector<int>lps(n);
	    int l=0,r=1;
	    while(r<n) {
	        if(s[r]==s[l])
	        {
	            lps[r] = l+1;
	            l++;
	            r++;
	        }
	        else{
	            if(l!=0)
	                l=lps[l-1];
	            else {
	                lps[r]=0;
	                r++;
	            }
	        }
	    }
	    return lps[n-1];
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
