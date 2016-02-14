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
    int t,n,sum,var;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&var);
            sum += var;
        }
        if(sum%n != 0)
            n = n-1;

        printf("%d\n",n);
    }
    return 0;
}
