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
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
map<int,int> m;
void primefactorize(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                m[i]++;
                n/=i;
            }
        } 
    }
    if(n>1)
        m[n]++;
}
int main()
{
    int t,n,num;
    scanf("%d",&t);
    while(t--)
    {
        m.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            primefactorize(num);
        }
   
        map<int,int>::iterator it;
        LL ans = 1;
        for(it = m.begin();it!=m.end();it++)
        {
            ans *= ((it->second)+1);
            //cout<<it->first<<" => "<<it->second<<endl;
        }
        printf("%lld\n",ans);
    }
        return 0;
}

