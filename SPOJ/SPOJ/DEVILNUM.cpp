#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
string list[]={"1","3"};
long long power(long long a,long long n)
{
    long long result=1;
    while(n>0)
    {
        if((n&1))
            result *= a;
        a*=a;
        n>>=1;
    }
    return result;
}
int main()
{
    int t,num,dig,range,sum;
    int store[150] ;
    scanf("%d",&t);
up:
    while(t--)
    {
        scanf("%d",&num);
        if(num==1)
        {
            printf("1\n");
            continue;}
        dig = log10(num)+1;        
        sum = 2 * (power(2,dig-1) - 1);
        range = power(2,dig);
        int i;
        //cout<<sum<<endl<<range<<endl;
        for(int nn=sum+1,i=0;i<range;i++,nn++)//nth number
        {
            int n=nn;
            string str="";
            while(n>0)
            {
                str = list[(n-1)%2] + str;
                n = (n-1)/2;
            }
            //cout<<str<<endl;
            store[i]=atoi(str.c_str());
        }
        
       
       
        //cout<<store[range-1]<<" ";
        //cout<<endl;        
        int *location = lower_bound(store,store+range,num);
        int index = location - store;
        //cout<<index<<endl;
        
        if(index == 0)
        {
            for(int j=1;j<dig;j++)
                printf("3");
            printf("\n");
            goto up;
        }

        if(store[index] != num)
            index = index-1;
        
        printf("%d\n",store[index]);

    }
    return 0;
   
}
