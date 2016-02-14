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
    int t,n,cnt,x1,x2,y1,y2,xmin,xmax,ymin,ymax;
    cin>>t;
    while(t--)
    {
        cnt = 0;
        cin>>x1>>y1>>x2>>y2;
        xmin = min(x1,x2);
        xmax = max(x1,x2);
        ymin = min(y1,y2);
        ymax = max(y1,y2);
        for(int i=xmin;i<=xmax;i++)
        {
            for(int j=ymin;j<=ymax;j++)
            {
                if((j-y1)*(x2-x1) == (y2-y1)*(i-x1))
                    cnt++;          
            }
        }
        cout<<cnt-2<<endl;

    }
    return 0;
}
