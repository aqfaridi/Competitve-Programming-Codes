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
vector<pair<int,int> > v;
int main()
{
    int t,n,cnt,m;
    int x1,y1,x2,y2,x,y;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            v.push_back(make_pair(x,y));
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            cnt = 0;
            for(int j=0;j<v.size();j++)
            {
                if((v[j].second <= max(y1,y2) && v[j].second >= min(y1,y2)) && (v[j].first <= max(x1,x2) && v[j].first >= min(x1,x2)))
                if((v[j].second-y1)*(x2-x1) == (y2-y1)*(v[j].first-x1))
                    cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}

