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
    while(t--)
    {
        scanf("%d",&num);
              
        dig = log10(num)+1;        
        sum = 2 * (power(2,dig) - 1);
                
        int minnum=0,maxnum=0;
        for(int i=0;i<dig;i++)
        {
            minnum = minnum*10 + 3;
            maxnum = maxnum*10 + 1;
        }
        
        maxnum = maxnum*10 + 1;
        
        if((num > minnum) && (num < maxnum))          
        {        
            printf("%d\n",minnum);
            continue;
        }
     
        for(int nn=sum;1;nn--)//nth number
        {
            int n=nn;
            string str="";
            while(n>0)
            {
                str = list[(n-1)%2] + str;
                n = (n-1)/2;
            }
            //cout<<str<<endl;
            int a=atoi(str.c_str());
            
            if(a <= num)
            {
                printf("%d\n",a);
                break;
            }
        }

    }
    return 0;
   
}
