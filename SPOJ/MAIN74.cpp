#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define forr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) forr(i,0,n)
void multiply(LL a[][2],LL b[][2])
{
    LL c[2][2];
    rep(i,2) rep(j,2)
            {
                c[i][j] = 0;
                rep(k,2)
                    c[i][j] = (c[i][j] + a[i][k]*b[k][j])%MOD;        
            }
    
    rep(i,2) rep(j,2)
            a[i][j] = c[i][j];
}
void expo(LL a[][2],LL n)
{
    LL result[2][2] = {{1,0},{0,1}};
    while(n>0)
    {
        if((n&1))
            multiply(result,a);
        multiply(a,a);
        n>>=1;
    }

    rep(i,2) rep(j,2)
            a[i][j] = result[i][j];
}
LL fibo(LL n)
{
    LL obj_mat[2][2] = {{0,1},{1,1,}};
    expo(obj_mat,n-1);
    return (5*obj_mat[0][0] + 8*obj_mat[0][1])%MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    long long t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        
        if(n==0)
        {
            cout<<0<<endl;
            continue;
        }
        else if(n==1)
        {
            cout<<2<<endl;
            continue;
        }
        n = n-1;        
        cout<<fibo(n)<<endl;
    }
    return 0;
}


