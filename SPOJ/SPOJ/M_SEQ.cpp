#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    long double n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%Lf",&n);
        n = (8.0*n*n - 4.0*n*(n-1) + 1.0)/(n*n) ; 
        printf("%.8Lf\n",sqrt(n));

    }
    return 0;
}

