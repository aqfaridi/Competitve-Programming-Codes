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
LL a[MAX],b[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL n,total,u,v;
    t = 1;
    while(t--)
    {
        total = 0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        
        for(int i=0;i<n;i++)
        { 
            u = b[i]/2; 
            v = b[i]/2;
            if(u==0 || v==0)
            {
                total -= 1;
                continue;
            }
            if(b[i]&1)
                v += 1;
            if(u <= a[i] && v <= a[i])
                total += u*v;
            else
                total -= 1;
        }
        cout<<total<<endl;
    }
    return 0;
}
