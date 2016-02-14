#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000010
using namespace std;
int main()
{
    int n,num,k=0;
    ios::sync_with_stdio(false);
    int LIS[MAX],arr[MAX];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
        LIS[i] = 1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j] && LIS[i] < LIS[j]+1)
                LIS[i] = LIS[j] + 1;
        }
    }
    sort(LIS,LIS+n);
    cout<<LIS[n-1]<<endl;
    return 0;
}

