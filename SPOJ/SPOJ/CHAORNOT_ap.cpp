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
#define MAX 100020
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
long long arr[MAX],sieve[MAX];
vector<long long> q;
deque<long long> dq;
set<long long> diff;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(n==1)
    {
         cout<<arr[0]<<endl;
    }
    else{
    sort(arr,arr+n);
    /******precompute ****/
    q.push_back(arr[0]);
    q.push_back(arr[1]);
    diff.insert(arr[1]-arr[0]);
    set<long long>::iterator it;
    bool flag;
    for(int i=2;i<100 && i<n;i++)
    {
        flag = true;
        for(int j=0;j<i;j++)
        {
            it = diff.find(arr[i] - q[j]);
            if(it == diff.end()) // not present
                dq.push_back(arr[i]-arr[j]);
            else if(it != diff.end())
                flag = false;
        }
        if(flag)
        {
            q.push_back(arr[i]);
            while(!dq.empty())
            {
                diff.insert(dq.front());
                dq.pop_front();
            }
        }
        else
            dq.clear();
        
    }
    cout<<q[0];
    for(int i=1;i<q.size();i++)
        cout<<" "<<q[i];
    cout<<endl;
    }
    return 0;
}

