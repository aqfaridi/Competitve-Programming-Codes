#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000010
#define sqrtLIM 1000
using namespace std;
int arr[MAX];
void factorsieve()
{
    for(int i=1;i<MAX;i++)
        arr[i] = ((i&1))?i:2;

    for(int i=3;i<sqrtLIM;i+=2)
    {
        if(arr[i]==i)
        {
            for(int j=i;j<MAX;j+=i)
                if(arr[j]==j)
                    arr[j]=i;
        }
    }

}
long long nod(long long n)
{
    long long temp,count,nod=1;

    temp = arr[n];
    n /= arr[n];
    count=1;
    while(arr[n] != 1)
    {
        if(arr[n] == temp)
            count++;
        else
        {
            nod *= (count+1);
            temp = arr[n];
            count = 1;
        }
        n /=arr[n];

    }
    nod *= (count + 1);
   // cout<<nod<<" ";
    return nod;
    
}
int main()
{
    long long count=0,a,b,c,n,NOD;
    factorsieve();
    /*
    cout<<"start";
    for(int i=0;i<500;i++)
        cout<<arr[i]<<" ";
    */
    //long long temp;
    for(int i=2;i<1000001;i++)
    {
        n = i;
        NOD = nod(n);
        //temp=NOD;
        a=arr[NOD];
        NOD /= arr[NOD];
        b = arr[NOD];
        NOD /= arr[NOD];
        c = arr[NOD];
        if(a==b)
            continue;
        if(c != 1)
            continue;
        if(c==1 && b==1)
            continue;
        
        count++;
        if((count%9)==0)
             printf("%d\n",i);

    }
    
    return 0;
}

