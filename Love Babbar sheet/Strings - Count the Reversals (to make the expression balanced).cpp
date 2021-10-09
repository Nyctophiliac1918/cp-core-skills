// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    // your code here
    int n = s.size();
    if(n&1) return -1;
    
    stack<char>st;
    int l=0,r=0;
    for(auto c:s) {
        if(c=='{')
        {
            st.push('{');
            r++;
        }
        else if(c=='}') {
            if(!st.empty() && st.top()=='{')
            {
                st.pop();
                r--;
            }
            else l++;
        }
    }
    if(l&1) l++;
    if(r&1) r++;
    return l/2+r/2;
}
