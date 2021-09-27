// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
int maxChainLen(struct val p[],int n)
{
    //Your code here
    vector<int>dp(n,1);
    
    vector<pair<int,int>>v(n);
    
    for(int i=0;i<n;i++)
        v[i]={p[i].first, p[i].second};
    
    sort(v.begin(),v.end());
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++) {
            if(v[i].first>v[j].second && dp[i] < 1 + dp[j])
                dp[i] = 1 + dp[j];
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}
