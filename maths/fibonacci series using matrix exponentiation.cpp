#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;

matrix mult(matrix A, matrix B)
{
    matrix C(2, vector<ll> (2));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            for(int k=0;k<2;k++)
                C[i][j]+=A[i][k]*B[k][j];
    return C;
}

matrix pow(matrix T, int p)
{
    if(p==1)
        return T;
    if(p%2)
        return mult(T, pow(T, p-1));
    matrix X=pow(T, p/2);
    return mult(X, X);
}

int main()
{
    int n;
    cin>>n;

    vector<ll> f{0,1};
    matrix T(2, vector<ll>(2));
    T[0][0]=0, T[0][1]=1;
    T[1][0]=1, T[1][1]=1;

    if(n==1)
    {
        cout<<1;
        return 0;
    }

    T = pow(T, n-1);

    ll res=0;
    for(int i=0;i<2;i++)
    {
        res+=T[1][i]*f[i];
    }
    
    cout<<res<<endl;
}
