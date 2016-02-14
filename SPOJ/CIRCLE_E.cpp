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
    LL R1,R2,R3,A,B,C;
    double r1,r2,D;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&R1,&R2,&R3);
        A = R1*R2 + R2*R3 + R3*R1 ;
        B = R1*R2*(R1+R2) + R2*R3*(R2+R3) + R3*R1*(R3+R1);
        C = R1*R2*R3*(R1+R2+R3) * (-1) ;
        D = sqrt(B*B - 4*A*C) ;
        cout<<D<<endl;
        //two roots r1 and r2
        r1 = (D-B)/(2.0*A);
        r2 = (-1.0*B-D)/(2.0*A);
        cout<<r1<<" "<<r2<<endl; 
    }

    return 0;
}

