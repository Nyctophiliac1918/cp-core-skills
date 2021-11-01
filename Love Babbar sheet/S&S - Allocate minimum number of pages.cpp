#include<bits/stdc++.h>

bool isCorrect(int sum, int b, vector<int>& v) {
    int c = 1, s = 0;
    // cout<<sum<<" ";
    for(int i = 0;i<v.size();i++) {
        if(v[i]>sum) return false;
        if(s+v[i]>sum) {
            c++;
            // cout<<s<<" ";
            s=0;
            s+=v[i];
        }
        else {
            s+=v[i];
        }
    }
    // cout<<endl;
    return c<=b;
}

int Solution::books(vector<int> &A, int B) {
    int mn = *min_element(A.begin(),A.end());
    int l = mn;
    int sum = accumulate(A.begin(), A.end(), 0);
    int r = sum, ans = sum;
    if(A.size()<B) return -1;

    while(l<=r) {
        int md = (l+r) >> 1;
        if(isCorrect(md,B,A))
        {
            ans = md;
            r = md - 1;
        }
        else l = md + 1;
    }

    return ans;
}
