#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 1000010
#define MOD 100000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
pair<int,pair<int,int> > extendedEuclid(LL a,LL b)
{
    LL xLast = 1 , yLast = 0;
    LL x = 0 , y = 1;
    LL m,n,q,r;
    while(b)
    {
        q = a/b;
        r = a%b;
        m = xLast - q*x;
        n = yLast - q*y;

        xLast = x ; yLast = y;
        x = m ; y = n;
        a = b ; b = r; 
    }
    return make_pair(a,make_pair(xLast,yLast));
}
LL modInverse(LL a,LL m)
{
    return ((extendedEuclid(a,m).second.first)+m)%m;
}
LL mulMod(LL a,LL b,LL m= MOD)
{
    LL result = 0 ;
    while(b)
    {
        if((b&1))
            result = (result + a)%m;
        a = (2*a)%m;
        b >>= 1;
    }
    return (result%m);
}
LL expo(LL a,LL n,LL m = MOD)
{
    LL result = 1;
    while(n)
    {
        if((n&1))
            result = mulMod(result,a);
        a = mulMod(a,a);
        n >>= 1;
    }
    return (result % m);
}
LL arr[7];
LL coeff1[]={0,1,1,0,0,0,0};
LL coeff2[]={0,1,3,2,0,0,0};
LL coeff3[]={0,0,1,2,1,0,0};
LL coeff4[]={0,-1,0,10,15,6};
LL coeff5[]={0,0,-1,0,5,6,2};
int main()
{
    LL t,n,k;
    LL modI1 = 50000004;//modInverse(2,MOD);    
    LL modI2 = 16666668;//modInverse(6,MOD);
    LL modI3 = 25000002;//modInverse(4,MOD);
    LL modI4 = 23333335;//modInverse(30,MOD);
    LL modI5 = 8333334;//modInverse(12,MOD);
    /**
    cout<<modI1<<endl;
    cout<<modI2<<endl;
    cout<<modI3<<endl;
    cout<<modI4<<endl;
    cout<<modI5<<endl;
    **/
    scanf("%lld",&t);
    while(t--)
    {
        memset(arr,0,sizeof(arr));
        scanf("%lld %lld",&n,&k);
        switch(k)
        {
            case 0:
                printf("%lld\n",n%MOD);
                break;
            case 1:
                for(int i=1;i<=6;i++)
                    arr[i] = (arr[i-1] + (expo(n,i) * coeff1[i])%MOD)%MOD; 
                printf("%lld\n",(arr[6]*modI1)%MOD);
                break;
            case 2:
                for(int i=1;i<=6;i++)
                    arr[i] = (arr[i-1] + (expo(n,i) * coeff2[i])%MOD)%MOD; 
                printf("%lld\n",(arr[6]*modI2)%MOD);
                break;
            case 3:
                for(int i=1;i<=6;i++)
                    arr[i] = (arr[i-1] + (expo(n,i) * coeff3[i])%MOD)%MOD; 
                printf("%lld\n",(arr[6]*modI3)%MOD);
                break;
            case 4:
                //cout<< (-1 * n )%MOD<<endl;
                for(int i=1;i<=6;i++)
                    arr[i] = (arr[i-1] + ((expo(n,i) * coeff4[i])%MOD + MOD)%MOD)%MOD; 
                printf("%lld\n",(arr[6]*modI4)%MOD);
                break;
            case 5:
                for(int i=1;i<=6;i++)
                    arr[i] = (arr[i-1] + ((expo(n,i) * coeff5[i])%MOD + MOD)%MOD) %MOD; 
                printf("%lld\n",(arr[6]*modI5)%MOD);
                break;
        }
    }
    return 0;
}

