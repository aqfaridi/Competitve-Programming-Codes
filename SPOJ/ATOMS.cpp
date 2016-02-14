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
#define gc getchar_unlocked
inline void readNat(LL *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}
typedef unsigned long long i64;
LL n;
i64 expo(i64 a,i64 nn)
{
    i64 result = 1;
    while(nn)
    {
        if(nn&1)
        {
            if(((int)(log10(a)+1) + (int)(log10(result)+1))<=20) 
                result *= a;
            else
                return -1;
        }

        if(((int)(log10(a)+1) + (int)(log10(a)+1))<=20) 
            a *= a;
        else
            return -1;
        nn >>= 1;
    }
    cout<<"res"<<result<<endl;
    if(((int)(log10(n)+1) + (int)(log10(result)+1))<=20) 
        return result*n;
    else
        return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    LL t;
    double kt;
    LL k,m;
    i64 pwr; 
    //readNat(&t);
    cin>>t;
    while(t--)
    {
        //readNat(&n);
        //readNat(&k);
        //readNat(&m);
        cin>>n>>k>>m;

        if(((int)(log10(n)+1) + (int)(log10(k)+1))>=19) 
        {
            cout<<0<<endl;
            continue;
        }
/*
        kt = (m*1.0)/n;
        int i = (int)(log2(kt)/log2(k));
        i+=10;
*/
        
        for(int i=1;;i++)
        {
            pwr = expo(k,i);
            cout<<"i"<<i<<endl;
            cout<<pwr;
            if(pwr==-1 || pwr > m)
            {
                cout<<i-1<<endl;
                break;
            }
        }
    }
    return 0;
}
