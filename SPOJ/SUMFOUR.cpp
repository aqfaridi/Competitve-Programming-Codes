#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#define MAX 50010
typedef long long int LL;
using namespace std;
int main()
{
    int n;
    LL a[MAX],b[MAX],c[MAX],d[MAX];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld %lld %lld %lld",&a[i],&b[i],&c[i],&d[i]);
    }
    //considering all possible pairs
    //of a and b 
    vector<int> v1(n*n),v2(n*n);
    //O(n^2)
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            v1[i*n + j] = a[i] + b[j] ; 
            v2[i*n + j] = (-1)*(c[i] + d[j]) ;    
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    //O(n^2) * log(n^2)
    LL LB,UB,range,count=0;
    pair<vector<int>::iterator,vector<int>::iterator> bounds;    
    for(int i=0;i<n*n;i++)
    {
        bounds = equal_range(v2.begin(),v2.end(),v1[i]);
        LB = bounds.first - v2.begin();
        UB = bounds.second - v2.begin();
        range = UB - LB ;
        count += range;
    }
    printf("%lld\n",count);
    return 0;
}

