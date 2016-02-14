#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define MAX 1010
using namespace std;
int arr[MAX];
void sieve()
{
    arr[0]=arr[1]=1;
    for(int i=2;i*i<MAX;i++)
    {
        for(int j=i*i;j<MAX;j+=i)
        {
            arr[j]=1;
        }
    }
    
}
int main()
{
    int t;
    int count;
    sieve();
    string str;
    scanf("%d",&t);
    while(t--)
    {
        //memset(arr,0,sizeof(arr));
        count=0;
        cin>>str;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
                count++;
        }
        if(arr[count]==0)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}
