#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
int main()
{
    ios::sync_with_stdio(false);
    int t,cnt;bool flag; LL n;
    while(scanf("%lld",&n)!=EOF)
    {
        cnt = 0;flag = false;
        LL SQR = sqrt(n);
        for(LL b=SQR;b>=0;b--)
        {
            LL a = sqrt(n - b*b);
            if(a>b)
                break;
            if(a*a + b*b == n)
            {
                flag = true;
                cnt++; 
            }
        }
        if(flag)
            cout<<cnt<<endl;
        else
            cout<<0<<endl;
                
    }
    return  0;
}
