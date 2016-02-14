#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define forr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n)    forr(i,0,n)
#define MOD 1000000007

void multiply(LL a[][4],LL b[][4])
{
    LL c[4][4];
    rep(i,4)
        rep(j,4)
        {
            c[i][j] = 0;
            rep(k,4)
                c[i][j] = (c[i][j]%MOD + (a[i][k]*b[k][j])%MOD)%MOD;
        }

    rep(i,4) rep(j,4)
        a[i][j] = c[i][j];
}
void expo(LL a[][4],LL n)
{
    LL result[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    while(n)
    {
        if((n&1))
            multiply(result,a);
        multiply(a,a);
        n>>=1;
    }

    rep(i,4) rep(j,4)
        a[i][j] = result[i][j];
}
LL F(LL n)
{
    LL obj_mat[4][4]={{2,1,0,0},{1,0,1,1},{0,0,1,1},{0,0,1,0}};
    expo(obj_mat,n-1);
    /*
    rep(i,4)
    {
        rep(j,4)
            cout<<obj_mat[i][j]<<" ";
        cout<<endl;
    }
    */
    return ((obj_mat[0][0]%MOD + obj_mat[0][1]%MOD)%MOD + obj_mat[0][3]%MOD)%MOD; 
}
int main()
{
    ios::sync_with_stdio(false);
    LL t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        n-=1;
        cout<<F(n)<<endl;
    }
    return 0;
}


