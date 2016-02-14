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
#define MAX 100010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int arr[MAX],dp[MAX];
deque<int> q;
int main()
{
    int n,d,num1,num2,num3;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    sort(arr,arr+n);
    q.push_back(arr[0]);
    
    int k=0;
    for(int i=1;i<n;i++)
        if(arr[i] != num1)
        {
            q.push_back(arr[i]);
            break;
        }

    dp[k++] = q[1] - q[0] ;

    for(int i=2;i<n;i++)
    {
        if(arr[i] != q[i-1])
        {
            d = arr[i] - q[i-1];
            dp[k++] = d;
            if(arr[i] - num2 != d)
            {
                num3 = arr[i];
                break;
            }
        }
    }
    cout<<3<<endl;    
    cout<<num1<<" "<<num2<<" "<<num3<<endl;
    
    return 0;
}

