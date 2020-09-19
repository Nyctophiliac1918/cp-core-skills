/* To reach nth step if you can only take 1, 2 or 3 steps*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;
int k=3;

matrix mult(matrix A, matrix B)
{
    matrix C(k, vector<ll> (k));
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            for(int l=0;l<k;l++)
                C[i][j]+=A[i][l]*B[l][j];
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

    vector<ll> f{0,1,2};
    matrix T(k, vector<ll>(k));
    T[0][0]=0, T[0][1]=1, T[0][2]=0;
    T[1][0]=0, T[1][1]=0, T[1][2]=1;
    T[2][0]=1, T[2][1]=1, T[2][2]=1;

    if(n==1)
    {
        cout<<1;
        return 0;
    }
    if(n==2)
    {
        cout<<2;
        return 0;
    }

    T = pow(T, n-k+1);

    ll res=0;
    for(int i=0;i<k;i++)
    {
        res+=T[k-1][i]*f[i];
    }

    cout<<res<<endl;
}
