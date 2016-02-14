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
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n==1 or m==1)
            cout<< max(n,m)<<endl;
        else 
            cout<< __gcd(n-1,m-1) + 1<<endl;        
    }
    return 0;
}


