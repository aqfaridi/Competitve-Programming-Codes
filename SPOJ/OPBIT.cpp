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
    int t,A,diff,B,n,a,b,AND,XOR;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a==b)
        {
            cout<<0<<endl;
            continue;
        }
        A = (int)sqrt(a);
        B = (int)sqrt(b);
        AND = (A+1)*(A+1) - A*A;
        XOR = (A+1)*(A+1) - A*A;
        for(int i=A+2;i<=B;i++)
        {
            diff = (i*i) - (i-1)*(i-1);
            AND &= diff;
            XOR ^= diff;
        }
        cout<<(AND & XOR)<<endl;
    }
    return 0;
}
