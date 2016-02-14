#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <climits>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007    
set<int> s;
map<int,int> top,bot;
int main()
{
    ios::sync_with_stdio(false);
    int n,ai,flip,bi,half,num,reqd;
    bool flag = false;
    cin>>n;
    for(int i=0;i<n;i++)
    {
       cin>>ai>>bi;
       top[ai]++;
       if(ai != bi)
           bot[bi]++;
       s.insert(ai);s.insert(bi);
    }
    half = (n-1)/2 + 1;
    flip = INT_MAX;
    set<int>::iterator it=s.begin();
    for(;it!=s.end();it++)
    {
        num = (*it);
        reqd = half - top[num];
        if(reqd < 0)
            reqd = 0;
        if(bot[num] >= reqd) //valid num
        {
            flag = true;
            flip = min(flip,reqd);
        }
    }
    
    if(flag)
        cout<<flip<<endl;
    else
        cout<<"Impossible"<<endl;
            
    return 0;
}
