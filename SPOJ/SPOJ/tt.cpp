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
int track[26],freq[26];
int main()
{
    int t;
    long long ans = 1;
    string str ;
    //scanf("%d",&t);
    t = 1;
    while(t--)
    {
        cin>>str;
        int l = str.length();
        int cntr = 10;
        if(str[0] >= 'A' && str[0] <='J')
        {
            ans *= 9;
            cntr = 9;
            track[str[0]-'A'] = 1;
        
        }
        else if(str[0] == '?')
        {
            ans *= 9;
            cntr = 10;
        }
        for(int i=1;i<l;i++)
        {
            if((str[i] >='A' && str[i] <='J') && (track[str[i]-'A']==0))
            {
                ans *= cntr;
                cntr--;
                track[str[i]-'A'] = 1;
            }
            else if (str[i] == '?')
                ans *= 10;
        }
        printf("%lld\n",ans);

    }
    return 0;
}

