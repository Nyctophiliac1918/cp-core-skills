// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int s, int d){
        // code here
        if(9*d<s) return "-1";
        s-=1;
        vector<int>v(d);
        for(int i=d-1;i>0;i--) {
            if(s>=9) {
                s-=9;
                v[i]=9;
            }
            else {
                v[i]=s;
                s=0;
            }
        }
        v[0] = s+1;
        string p;
        for(int i=0;i<d;i++)
            p+=to_string(v[i]);
        return p;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends
