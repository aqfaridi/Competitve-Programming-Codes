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

#define MAX 1000010
#define MOD 1000000007   
#define maxx (1LL<<40)
int pre[MAX];
vector<LL> v;
void precompute()
{
    LL S2,SQR,size,cnt=0;
    for(LL i=1;i<=1010;i++)
    {
        for(LL j=i+1;j<=1010;j++)
        {
            S2 = (i*i + j*j);
            if(S2<MAX)
            {
                v.push_back(S2);
                pre[S2] = 1;
            }
        }
    }
    
    size = v.size();
    for(LL i=0;i<size;i++)
        for(LL j=1;j<MAX;j++)       
        {
            if(j*v[i] < MAX)
                pre[j*v[i]] = 1;
            else
                break;
        }
        
}
int main()
{
    precompute();
    ios::sync_with_stdio(false);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(pre[n])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
