#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 300010
using namespace std;
int arr[MAX];
int main()
{
    int i,n,num;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num);
        arr[num] = i; // assign initial positions of book
    }
    for(i=n;i>1;i--)
    {
        if(arr[i] < arr[i-1])
        {
            cout<<i-1<<endl;
            break;
        }
    }
    if(i==1)
        cout<<0<<endl;
    return 0;
}

