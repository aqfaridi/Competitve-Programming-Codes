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
    int t,n;
    double u,k1,k2,R,H,theta;
    cin>>t;
    while(t--)
    {
        cin>>u>>k1>>k2;
        if(k2==0)
            theta = M_PI/4.0;
        else
            theta = (M_PI - atan(4.0*k1/k2))/2.0;
        cout<<fixed<<setprecision(3)<<theta<<" ";
        R = u*u * sin(2.0*theta)/10.0;
        H = u*u * sin(theta)*sin(theta) / 20.0 ;
        cout<<fixed<<setprecision(3)<<k1*R + k2*H<<endl;
    }
    return 0;
}


