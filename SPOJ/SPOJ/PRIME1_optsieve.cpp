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
#define MAX 32000
#define MOD 1000000007
#define DEBUG if(0)
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int prime[MAX];
vector<bool> sseive(MAX);
#define MAX 32000
#define Lim 179
unsigned flag[MAX>>6];
#define ifc(n) (flag[n>>6] & (1<<((n>>1)&31)))
#define isc(n) (flag[n>>6] |= (1<<((n>>1)&31)))
void sieve()
{
    int k;
    for(int i=3;i<Lim;i+=2)
    {
        if(!ifc(i))//testing
        {
            for(int j=i*i,k=i<<1; j<MAX;j+=k)//only odd numbers
            {
                isc(j);//setting
            }
        }        
    }
    k = 0;
    prime[k++] = 2;
    for(int i=3;i<MAX;i+=2)//only odd flagging is done
    {
        if(!ifc(i))
            prime[k++] = i;
    }
}
int main()
{
    int t,n,m;
    scanf("%d",&t);
    sieve();
    DEBUG
    for(int i=0;i<100;i++)
        cout<<prime[i]<<" ";
    //cout<<endl;
    bool flag;
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=n;i<=m;i++)
        {
            flag = true;
            int num = i;
            
            if(num == 1)
                continue;

            int sqr = sqrt(num);
            for(int j=0 ; prime[j] <= sqr ; j++)
            {
                if(num % prime[j] == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                cout<<num<<endl;
        }
    }
    return 0;
}

