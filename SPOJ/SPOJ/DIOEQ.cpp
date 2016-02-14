#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int gcd(int a,int b)
{
    int r;
    while(b)
    {
       r = a%b;
       a = b;
       b = r;
    }
    return a;
}
int main()
{
    int a,b,c,g;
    ios::sync_with_stdio(false);
    while(1)
    {
        cin>>a>>b>>c;
        if(a==0 && b==0 && c==0)
            break;
        g = gcd(a,b);
        if(c%g==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }
    return 0;
}

