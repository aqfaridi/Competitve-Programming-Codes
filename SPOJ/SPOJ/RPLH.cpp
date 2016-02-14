#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t,cases=0,d,u;
    double theta,g=9.806;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d %d",&d,&u);
        theta = asin((d*1.0*g)/(u*u)) / 2.0;
        //converting to degrees
        theta = theta * 180.0 / (2.0*acos(0.0));
        if(theta <= 45 && theta >= 0 )
            printf("Scenario #%d: %.2lf\n",cases,theta);
        else
            printf("Scenario #%d: -1\n",cases);
    }
    return 0;
}

