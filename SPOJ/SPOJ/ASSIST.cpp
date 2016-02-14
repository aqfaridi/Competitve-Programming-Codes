#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 35001
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int arr[MAX],siev[3001];
void sieve()
{
    for(int i=1,factor=2;i<=3000;i++,factor++)
    {
        while(arr[factor]) //until found 1
                factor++;
        siev[i] = factor;
        for(int j=factor+1,countzero=0;j<=MAX;j++)
        {
            if(arr[j])
                    continue;
            countzero++;  // count zero 
            if(countzero % factor == 0)
                    arr[j] = 1;
            
        }
        //cout<<siev[i]<<endl;
    }
}
int main()
{
    int t,n;
    sieve();
    while(1)
    {
        scanf("%d",&n); 
        if(n==0)
            break;
        printf("%d\n",siev[n]);
    }
    return 0;
}

