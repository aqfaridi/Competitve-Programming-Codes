#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n,t,l;
//    char str[100];
    int arr[100];
    scanf("%d",&t);
    while(t--)
    {
    //    scanf("%s",str);
  //      l=strlen(str);
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);//arr[i]=str[i]-'0';
        next_permutation(arr,arr+n);
        for(int i=0;i<n;i++)
            cout<<arr[i];
        cout<<endl;
    }
    return 0;
}

