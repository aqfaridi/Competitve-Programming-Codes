#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
typedef unsigned long long int LL;
using namespace std;
int main()
{
    int t;
    LL R1,R2,R3;
    double r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu %llu %llu",&R1,&R2,&R3);
        //cout<<R1<<" "<<R2<<" "<<R3<<endl;
        r = (1.0/R1 + 1.0/R2 + 1.0/R3) + 2 * sqrt((1.0/(R1*R2) + 1.0/(R2*R3) + 1.0/(R3*R1))) ;
        printf("%.6lf\n",1.0/r);
    }
    return 0;
}

