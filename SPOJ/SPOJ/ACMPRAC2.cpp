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
vector<int> v;
int main()
{
    int t,n,l,cnt,size;
    LL sum;
    string str;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d",&n);
        cin>>str;
        l = str.length();
        for(int i=0;i<l;i++)
        {
           cnt = 1;
           while((i+1<l) && str[i] == str[i+1]) 
           {    i++;     cnt++; }
           v.push_back(cnt);            
        }
        sort(v.begin(),v.end(),greater<int>());
        size = v.size();
        sum = 0;
        for(int i=0;i<n;i++)
            sum += v[i];
        cout<<sum<<endl;
    }
    return 0;
}

