#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 
#include <climits>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int cnt[] = {6,69,405,1725,6027,18312,50016,125445};
int main()
{
    ios::sync_with_stdio(false);
    int t,n,idx;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0){
            cout<<0<<endl;
            continue;
        }
        for(idx = 0;idx<=6;idx++)
        {
            n -= cnt[idx];
            if(n <= 0)
                break;
        }
        cout<<idx+2<<endl;
    }
    return 0; 
}
