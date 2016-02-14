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

#define MAX 100010
#define MOD 1000000007    
string sta,stb;
LL nCr[65][65];
void make_nCr()
{
    for(int i=0;i<65;i++)
    {
        nCr[i][0] = 1;
        for(int j=1;j<65;j++)
            nCr[i][j] = (nCr[i][j-1]*(i-j+1))/j;
    }
}
LL compute(LL n)
{
    int already=0;
    LL total = 0;
    for(int i=__lg(n);n>0;i=__lg(n))
    {
        if((4-already >= 0) && (4-already <= i))
            total += nCr[i][4-already];

        if((7-already >= 0) && (7-already <= i))
            total += nCr[i][7-already];
        
        if((44-already >= 0) && (44-already <= i))
            total += nCr[i][44-already];
        
        if((47-already >= 0) && (47-already <= i))
            total += nCr[i][47-already];
        //cout<<total<<endl;
        n ^= (1LL<<i);
        already++;    
    }
    return total;
}
int main()
{
    make_nCr();
    ios::sync_with_stdio(false);
    int t;
    LL a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        b += 1;
        cout<<compute(b)-compute(a)<<endl;
    }
    return 0;
}
