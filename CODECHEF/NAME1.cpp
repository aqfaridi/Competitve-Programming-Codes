#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[26];
int main()
{
    int t,n;
    bool b;
    string A,B,temp;
    scanf("%d",&t);
    while(t--)
    {
        b=true;
        memset(arr,0,sizeof(arr));
        cin>>A>>B;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            for(int j=0;temp[j];j++)
                arr[temp[j]-97]++;
        }
        for(int i=0;A[i];i++)
            if(arr[A[i]-97])
                arr[A[i]-97]--;
        for(int i=0;B[i];i++)
            if(arr[B[i]-97])
                arr[B[i]-97]--;
        
        for(int i=0;i<=25;i++)
        {
            //cout<<arr[i]<<" ";
            if(arr[i])
            {
                printf("NO\n");
                b=false;
                break;
            }
        }
        if(b)
            printf("YES\n");


    }
            
    return 0;
}

