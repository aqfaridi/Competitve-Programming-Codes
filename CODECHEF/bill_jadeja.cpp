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

#define MAX 100010
#define MOD 1000000007
int main()
{
    ios::sync_with_stdio(false);
    int i,x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2;
        int minx=min(x1,x2);
        int maxx=min(x1,x2);
        if((y2-y1)==0)
            cout<<abs(x1-x2)<<endl;
        if(x2-x1==0)
            cout<<abs(y1-y2)<<endl;
        double m=(y2-y1)/(x2-x1)*1.00;
        for(int i=minx+1;i<maxx;i++)
        {
            int y=m*i-m*x1+y1;
            if(int(y))
    }
    return 0;
}
