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
    int x,y,a,b,p1=0,p2=0,draw=0;
    cin>>a>>b;
    for(int i=1;i<=6;i++)
    {
        x = abs(a-i);
        y = abs(b-i);
        if(x<y)
            p1++;
        else if(y<x)
            p2++;
        else if(x==y)
            draw++;
    }
    cout<<p1<<" "<<draw<<" "<<p2<<endl;
    return 0;
}
