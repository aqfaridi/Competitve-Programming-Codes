#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 110
using namespace std;
long long int a[MAX];
vector<long long int> v1,v2;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)        
        scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                v1.push_back(a[i]*a[j]+a[k]);
            }
        }

    }
    sort(v1.begin(),v1.end());
    long long count = 0,LB,UB;  
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(a[i])
                    v2.push_back(a[i]*(a[j]+a[k]));
            }
        }

    }
    
    vector<long long int>::iterator it;
    pair<vector<long long int>::iterator,vector<long long int>::iterator> bounds;
    sort(v2.begin(),v2.end());
    for(it = v1.begin();it!=v1.end();it++)
    {
        
        bounds = equal_range(v2.begin(),v2.end(),*it);
        LB = bounds.first - v2.begin();
        UB = bounds.second - v2.begin();
        count += (UB - LB);

    }
    printf("%lld\n",count);

    return 0;
}

