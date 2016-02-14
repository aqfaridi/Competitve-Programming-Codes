#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long long n,a,b;
    cin>>n;
    if(n>=0)
        cout<<n<<endl;
    else
    {
        a = abs(n%10);
        b = abs((n/10)%10);
        //cout<<a<<" "<<b<<endl;
        if(a>=b)
            cout<<(n/10)<<endl;       
        else
        {
            if(n/100 ==0)
                cout<<0<<endl;
            else
                cout<<n/100<<a<<endl;
        }

    }
    return 0;
}

