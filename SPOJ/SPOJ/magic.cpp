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
    string str;
    bool flag = false;
    bool sett = false;
    cin>>str;
    if(str[0]=='4')
        cout<<"NO"<<endl;
    else
    {
        int l = str.length();
        int i;
        for(i=0;i<l-2;i++)
        {
            if(str[i]=='4' && str[i+1]=='4' && str[i+2]=='4')
            {
                sett = true;
                break;
            }
         
        }
        if(sett)
        {
                cout<<"NO"<<endl;
                flag = true;
        }
        
        for(i=0;i<l;i++)
        {
            if(str[i]=='3' || str[i]=='2' || str[i]=='5' || str[i]=='6' ||str[i]=='7' || str[i]=='0' || str[i]=='8' || str[i]=='9')
                break;
        }
        if(!flag)
            if(i!=(l))
                cout<<"NO"<<endl;
            else 
                cout<<"YES"<<endl;
    }

    return 0;
}

