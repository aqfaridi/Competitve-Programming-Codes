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
    LL t,a,b,x,y,l,pat_height,bb;
    string str;
    //scanf("%d",&t);
    t = 1;
    while(t--)
    {
        cin>>a>>b;
        cin>>str;
        l = str.length();
        x = 0;
        y = 0;
        maxh = INT_MAX;
        
        for(int i=0;i<l;i++)
        {
            if(str[i] == 'L')
                x -= 1;
            else if(str[i] == 'R')
                x += 1;
            else if(str[i] == 'U')
                y += 1;
            else if(str[i] == 'D')
                y -= 1;
        }
        cout<<x<<" "<<y<<endl;
        pat_height = y;
        if(y>=0)
            bb = b - pat_height - 1;
        else
            bb = b + pat_hegith

    }
    return 0;
}

