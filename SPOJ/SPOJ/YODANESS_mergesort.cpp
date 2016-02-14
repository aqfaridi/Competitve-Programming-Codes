#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#define MAX 30001
using namespace std;
char word[21];
long long cnt=0LL;
int arr[MAX],temp[MAX];
map<string,int> m;
void merge(int low1,int up1,int low2,int up2)
{
    int i=low1,j=low2,k=low1,mid=up1;
    while(i<=up1 && j<=up2)
    {
        if(arr[i]<arr[j])
        {
            //descending : find smaller number till now
            cnt += (up2-j+1);
            temp[k++] = arr[i++];
        }
        else
            temp[k++] = arr[j++];

    }
    while(i<=up1)
        temp[k++] = arr[i++];
    while(j<=up2)
        temp[k++] = arr[j++];

    //copying
    for(int x=low1;x<k;x++)
        arr[x] = temp[x];
}
void mergesort(int low,int up)
{
    int mid;
    if(low<up)
    {
        mid = (low+up)/2;
        mergesort(low,mid);
        mergesort(mid+1,up);
        merge(low,mid,mid+1,up);
    }
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        cnt = 0LL;
        scanf("%d",&n);
        for(int i=n;i>0;i--)
        {
            scanf("%s",word);
            m[word] = i;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",word);
            arr[i] = m[word];
        }
        /**
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        **/
        mergesort(0,n-1);
        /**
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        **/
        printf("%lld\n",cnt);
    }
    return 0;
}

