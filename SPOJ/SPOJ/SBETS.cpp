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
    int t;
    string str1,str2,g1,g2;
    scanf("%d",&t);
    while(t--)
    {
        map<string,int> m;
        for(int i=1;i<=16;i++)
        {
            cin>>str1>>str2>>g1>>g2;
            if(g1>g2)
                m[str1]++;
            else if(g2>g1)
                m[str2]++;    
        }        
        map<string,int>::iterator it = m.begin();
        int maxx = 0;
        for(;it!=m.end();it++)
        {
            if((*it).second > maxx)
            {
                maxx = (*it).second;
                str1 = (*it).first;
            }
        }
        cout<<str1<<endl;
    }
    return 0;
}

