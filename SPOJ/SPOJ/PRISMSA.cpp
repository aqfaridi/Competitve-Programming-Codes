#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    double h,a,S,V;
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)
    {
        cin>>V;
        a = cbrt(4*V);
        h = (4*V) / (a*a*sqrt(3));
        S = a*a*sqrt(3)/2 + 3*a*h;
        printf("%.10f\n",S);
    }
    return 0;
}

