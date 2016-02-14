#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000001
using namespace std;
int a[MAX];

void factorsieve()
{
    for(int i=1;i<MAX;i++)
                    a[i]=i;

    for(int i=2;i*i<=MAX;i++)
    {
        if(a[i] == i)
        {
            for(int j=i*i;j<MAX;j+=i)
            {
                if(a[j] == j)
                {
                    a[j]=i;
                }
                 }
        }

    }
}

int main()
{
    int cases=0,aa,b,cnt,n,nod,count,temp,k;
    int arr1[MAX],arr2[MAX]; 
    factorsieve();
    while(1)
    {
        cases++;
        
        cnt=0;
        scanf("%d %d",&aa,&b);
        if(aa==0 && b==0)
            break;
       
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        
            n=aa; 
            nod=1;
          //  if(n==1 && k==1)
          //      cnt++;

            temp=a[n];
            n/=a[n];
            count=1;
            int i=0;
            while(a[n]!=1)
            {

                if(temp == a[n])
                    count++;
                else
                {
                    arr1[temp]=count;
                    temp=a[n];
                    
                    //nod*=(count+1);
                    count=1;
                }
                n/=a[n];
            }
            //nod*=(count+1);
            arr1[temp]=count;
            
            n=b; 
            nod=1;
          //  if(n==1 && k==1)
          //      cnt++;

            temp=a[n];
            n/=a[n];
            count=1;
            int j=0;
            while(a[n]!=1)
            {

                if(temp == a[n])
                    count++;
                else
                {
                    
                    arr2[temp]=count;
                    temp=a[n];
                    //nod*=(count+1);
                    count=1;
                }
                n/=a[n];
            }
            //nod*=(count+1);
            arr2[temp]=count;

            int nonzero=0;
            for(int i=0;i<MAX;i++)
            {
               // cout<<arr1[i]<<" ";
               if(arr1[i])
                    nonzero++;

                cnt += abs(arr1[i] - arr2[i]);
            }
            printf("%d. %d:%d\n",cases,nonzero,cnt);
    }
    return 0;
}


