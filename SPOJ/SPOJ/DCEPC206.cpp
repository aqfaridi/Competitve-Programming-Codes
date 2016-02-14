#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 200010
using namespace std;
int arr[MAX],temp[MAX];
long long int sum;
//calculating invcnt while merging
void merge(int low1,int up1,int low2,int up2)
{
    int i=low1,j=low2,k=low1,mid=up1;

    while(i<=up1 && j<=up2)  // if anyone list exhausted
    {
        if(arr[i]<arr[j])
        {
            //since he is noting down lesser number
            sum += (long long int)(up2-j+1)*arr[i];
            temp[k++]=arr[i++];
        }
        else                
            temp[k++] = arr[j++];
         
        
    }
    while(i<=up1)
        temp[k++]=arr[i++];
    while(j<=up2)
        temp[k++]=arr[j++];

    //copying
    for(int x=low1;x<k;x++)
        arr[x] = temp[x];

}
void mergesort(int low,int up) // 0-7
{
    int mid;
    if(low<up)
    {
        mid = (low+up)/2;   // 3
        mergesort(low,mid);  //0-3  => 0-1 & 2-3
        mergesort(mid+1,up); //4-7  => 4-5 & 6-7
        merge(low,mid,mid+1,up);
    }
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        sum = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        mergesort(0,n-1);
        /**
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        **/
        printf("%lld\n",sum);
    }
    return 0;
}

