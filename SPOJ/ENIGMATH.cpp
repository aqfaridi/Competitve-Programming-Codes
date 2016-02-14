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
    int A,B,t,n;
    long long  g;
    cin>>t;
    while(t--)
    {
        cin>>A>>B;
        g = __gcd(A,B);                 
        if(g==1)
        {
            cout<<B<<" "<<A<<endl;
        }
        else 
        {
            cout<<B/g<<" "<<A/g<<endl;
        }
    }
    return 0;
}


