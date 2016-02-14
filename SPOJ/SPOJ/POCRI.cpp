#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
LL g_josephus(LL n,LL k)
{
    if(n==1)
        return 0;//starting index 0
    return (g_josephus(n-1,k) + k)%n;
}
int f_josephus(int n,int k)
{
    if(n==1)
        return 1;
    return ( (f_josephus(n-1,k) + (k-1))%n + 1);
}
int iterative(int n,int k)
{
    int r=0;
    int i=2;
    while(i<=n-1)
    {
        r = (r+k)%i;
        i++;
    }
    return (r+1);
}
int arr[]={1, 18, 10, 11, 7, 17, 11, 15, 29, 5, 21, 13, 26, 14, 11, 23, 22, 9, 73, 17, 42, 7, 98, 15, 61, 22, 84, 24, 30, 9, 38, 15, 54, 27, 9, 61, 38, 22, 19, 178, 38, 53, 79, 68, 166, 20, 9, 22, 7, 21, 72, 133, 41, 10, 82, 92, 64, 129, 86, 73, 67, 19, 66, 115, 52, 24, 22, 176, 10, 57, 137, 239, 41, 70, 60, 116, 81, 79, 55, 102, 49, 5, 22, 54, 52, 113, 15, 66};
int main()
{
    int t,n,k;
    //scanf("%lld",&t);
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        
        
        for(k=1;;k++)
        {
            if(iterative(n,k) == 12)
                break;
        }
        printf("%d\n",k);    
        
    }
    return 0;
}

