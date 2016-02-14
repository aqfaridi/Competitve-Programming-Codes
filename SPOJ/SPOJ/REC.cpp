#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 110
using namespace std;

void rightshift(char *str)
{
    int lastlen = strlen(str);
    int i, mod, div, f, a, j;
    for(i=j=f=mod=0; str[i]; i++)
    {
        a = str[i]-'0';
        div = (mod*10 + a)>>1;
        mod = (mod*10 + a)&1;
        if(div) 
            f = 1;
        if(f) 
            str[j++] = div + '0';
    }
    if(!j)
        str[j++] = '0';
    str[j] = 0;
    lastlen = j;
}

int bigmod(char *str, int m)
{
    int i, mod;
    for(i=mod=0; str[i]; i++)
        mod = (mod*10 + str[i]-'0') % m;
    return mod;
}

inline bool isodd(char *n)
{
    int lastlen = strlen(n);
    return ((n[lastlen-1]-'0') & 1);
}
void multiply(long long a[][2],long long b[][2],long long m)
{
    long long C[2][2]={0};
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                C[i][j] = (C[i][j]%m + (a[i][k]*b[k][j])%m)%m ;
            }
        }
    }
    //copying
    memcpy(a,C,sizeof(C));
            
}
bool isZero(char* n)
{
    /**
    int l = strlen(n);
    for(int i=0;i<l;i++)
        if(n[i] != 0)
            return false;
    return true;
    **/
    int t = atoi(n);
    if(t==0)
        return true;
    else
        return false;

}
long long result[2][2],unity[2][2]={{1,0},{0,1}};
void expo(long long a[][2],char* n,long long m)
{
    memcpy(result,unity,sizeof(unity));
 cout<<n<<endl;
 rightshift(n);
 cout<<n<<endl;
 /**
 cout<<!isZero(n)<<endl;
 rightshift(n); 
 rightshift(n);
 cout<<n<<endl;
 cout<<isZero(n)<<endl;
 **/
    while(!isZero(n))
    {
        if(isodd(n))
            multiply(result,a,m);
        multiply(a,a,m);
        rightshift(n);
        //cout<<n<<" "; 
     }
     
}
int main()
{
    long long t,AA,BB,m;
    char A[MAX],B[MAX],n[MAX];
    long long Gn;
    scanf("%lld",&t);
    while(t--)
    {
       
        scanf("%s %s %s %lld",A,B,n,&m);   
        AA = bigmod(A,m);
        BB = bigmod(B,m);
        long long M[2][2]={{AA,1},{0,1}};
        expo(M,n,m);
        printf("%lld\n",(result[0][0]%m + (BB*result[0][1])%m)%m);

    }
    return 0;
}

