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
    int t,l,prev;
    bool flag;
    string str;
    scanf("%d",&t);
    while(t--)
    {
        cin>>str;
        l = str.length();
        int count = 0,maxx=0;
        for(int i=0;i<l;i++)
        {
            prev = 1;
            flag = false;
            if(str[i]=='.')
            {
                while(i<l && str[i]==str[i+1])
                {
                    prev++;
                    flag  = true;
                    i++;
                }
                if(prev > maxx)
                {
                    maxx = prev;
                    count++;
                }
                if(flag)
                    i--;
            }
        }
        printf("%d\n",count);
                
        
    }
    return 0;
}

