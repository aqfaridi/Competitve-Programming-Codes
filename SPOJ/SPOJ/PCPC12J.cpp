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
int main()
{
    int t,n,max_freq,min_div,diV,freq,num;
    bool flag;
    scanf("%d",&t);
    while(t--)
    {
        max_freq = 0;
        flag = false;
        min_div = INT_MAX;
        map<int,int> m;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            m[num]++;
        }
        map<int,int>::iterator it;
        //map is sorted according to key
        for(it=m.begin();it!=m.end();it++)
        {
            freq = (it->second);
            diV = (it->first);
            if(freq % diV == 0)
            {
                //lucky div
                if(freq > max_freq)
                {
                    max_freq = freq;
                    min_div = diV;
                }
                else if (freq == max_freq)
                {
                    //do nothing
                    //if(diV < min_div)
                     //   min_div = diV;
                }
                flag = true;
            }
                
        }
        if(flag)
            printf("%d\n",min_div);
        else 
            printf("-1\n");
    }
    return 0;
}

