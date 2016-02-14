#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int main()
{
    long double h,d,x1,y1,x2,y2,R,L;
    int t,n,cases=0;
    cin>>t;
    while(t--)
    {
        cases++;
        cin>>x1>>y1>>x2>>y2>>R>>L;
        d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        if(d - (L/sqrt(2) + R) >= 0.0000005)
        {
            cout<<cases<<". No problem"<<endl;
            continue;
        }
        h = sqrt( R*R - ((R*R/(2.0*d) - L*L/(4*d) + d/2.0)*(R*R/(2.0*d) - L*L/(4*d) + d/2.0)) );
        cout<<cases<<". "<<fixed<<setprecision(3)<<2*h<<endl;
    }
    return 0;
}


