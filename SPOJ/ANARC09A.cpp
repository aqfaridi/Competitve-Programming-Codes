#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int main()
{
    //ios::sync_with_stdio(false);
    int t,n,cost;
    int open,close,cases=0;
    char str[2010];
    while(scanf("%s",str))
    {
        cost = open = close = 0;
        if(strlen(str) == 0)
            continue;
        if(str[0]=='-')
            break;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='{')
                open++;
            else
            {
                if(open>0)
                    open--;
                else
                    close++;
            }
        }
        cost += (floor(open/2)+floor(close/2));
        open = open - 2*floor(open/2);
        close = close - 2*floor(close/2);
        if(open!=0)
            cost += 2;

        cout<<++cases<<". "<<cost<<endl;
    }
    return 0;
}


