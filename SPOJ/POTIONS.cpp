#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 
#include <cassert>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
#define gc getchar_unlocked
inline void readNat(unsigned long long *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());//ignore whitespace in front
    //2x + 8x = 10x  optimisation
         for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}

unsigned long long arr,w,x;
unsigned int cumm1[MAX],cumm2[MAX],ans;
int main()
{
    unsigned long long t,n,q,y,z;
    readNat(&t);
    while(t--)
    {
        readNat(&n);readNat(&q);
        cumm1[0] = cumm2[0] = 0;
        for(int i=1;i<=n;i++)
        {
            readNat(&arr);
            cumm1[i] = ((i*arr) + cumm1[i-1])%MOD;
            cumm2[i] = (arr + cumm2[i-1])%MOD;
        }

        for(int i=1;i<=q;i++)            
        {
            readNat(&w);readNat(&x);readNat(&y);readNat(&z);
            ans = ((cumm1[z+x] - cumm1[y+x-1] + MOD)%MOD + ((w-x+MOD)%MOD * (cumm2[z+x]-cumm2[y+x-1]+MOD)%MOD))%MOD;
            printf("%u\n",ans);
        }
    }
    return 0; 
}
