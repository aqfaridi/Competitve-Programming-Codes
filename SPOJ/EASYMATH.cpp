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
LL lcm(LL a,LL b)
{
    return (a*b)/__gcd(a,b);
}
int main()
{
    int t,n,m,a,d;
    LL ans,A,B,C,D,E,term1,term2,term3,term4,term5;
    cin>>t;
    while(t--)
    {
        cin>>m>>n>>a>>d;
        A = a; B = a+d; C = a+2*d; D = a+3*d; E = a+4*d;
        term1 = (n/A + n/B + n/C + n/D + n/E); //- (m/A + m/B + m/C + m/D + m/E);
        
        LL a1 = lcm(A,B) , a2 = lcm(A,C) , a3 = lcm(A,D) ,a4 = lcm(A,E) ,a5 = lcm(B,C), a6 = lcm(B,D), a7 = lcm(B,E) , a8 = lcm(C,D) , a9 = lcm(C,E) , a10 = lcm(D,E) ;//- (m/(A*B) + m/(A*C) + m/(A*D) + m/(A*E) + m/(B*C) + m/(B*D) + m/(B*E) + m/(C*D) + m/(C*E) + m/(D*E));
        
        term2 = (n/a1 + n/a2 + n/a3 + n/a4 + n/a5 + n/a6 + n/a7 + n/a8 + n/a9 + n/a10);// -  (m/a1 + m/a2 + m/a3 + m/a4 + m/a5 + m/a6 + m/a7 + m/a8 + m/a9 + m/a10) ;
        LL a11 = lcm(a1,C) , a12 = lcm(a1,D) , a13 = lcm(a1,E),a14=lcm(a2,D),a15=(a2,E),a16=lcm(a3,E),a17=lcm(a5,D),a18=lcm(a5,E),a19=lcm(a6,E),a20=lcm(a8,E);
        term3 = (n/a16 + n/a11 + n/a12 + n/a13 + n/a14 + n/a15 + n/a17 + n/a18 + n/a19 + n/a20);// - (m/a16 + m/a11 + m/a12 + m/a13 + m/a14 + m/a15 + m/a17 + m/a18 + m/a19 + m/a20);

        term4 =  (n/(lcm(a11,D)) + n/(lcm(a11,E)) + n/(lcm(a12,E)) + n/(lcm(a14,E)) + n/(lcm(a17,E)));// - (m/(lcm(a11,D)) + m/(lcm(a11,E)) + m/(lcm(a12,E)) + m/(lcm(a14,E)) + m/(lcm(a17,E)));

        term5 = n/lcm(lcm(a11,D),E);// - m/lcm(lcm(a11,D),E); 
        
        ans = term1 -term2 + term3 - term4 + term5;
        cout<<ans<<endl;
        cout<<(n-m+1) - ans<<endl;
    }
    return 0;
}
