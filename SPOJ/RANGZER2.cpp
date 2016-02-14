#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long expo(long long a,long long n)
{
    long long result = 1;
    while(n>0)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}
long long ez(int index,int d,char* n);
long long recursion(int index,int d,char* n);
long long noz(char *n,int nb) // no of zeros [1 to n] 
{
    // no of digits in n
    //int d = log10(n); // here d is d-1 actually
    int d = strlen(n);
    if(d==1)
        return 0;
    if(d==2)
        return n[0]-'0' ;
    //cout<<d<<endl;
    d = d-1;
    long long fterm = (expo(10,d-1)*(9*d-10) + 1) / 9;
    //cout<<n[0]-'0';
    d = d+1;
    cout<<fterm<<endl;
    if(log10(nb) == (int)log10(nb))
        return (fterm + d-1);
    fterm += (n[0]-'0') * expo(10,d-2) * (d-1) ;
    cout<<fterm<<endl;
    /*********subtract extra zeros***************/
    long long extra = ez(1,d,n);
    cout<<extra<<endl;
    return (fterm - extra);
}
long long ez(int index,int d,char* n)
{
    long long f;  
    d = d-1;
    if(d==2)
    {
        /**
        int number=0;
        for(int i=0;i<d;i++)
        {
            number = number*10 + (n[index+i]-'0');
        }
        cout<<number<<"num"<<d<<endl;
        //if(log10(number)==(int)log10(number))
        if(number ==0)
        {
            cout<<index<<" "<<index+d-1<<endl;;
            cout<<number<<"here"<<d<<" ";
            return 0;
        }
       **/ 
        return (9 - ((n[index]-'0')*expo(10,d-2)*(d-1)));  
    }
    if(d!=2)
    {
        /**
        int number=0;
        for(int i=0;i<d;i++)
        {
            number = number*10 + (n[index+i]-'0');
        }
        cout<<number<<"num"<<d<<endl;
        //if(log10(number)==(int)log10(number))
        if(number ==0)
        {
            cout<<index<<" "<<index+d-1<<endl;;
            cout<<number<<"here"<<d<<" ";
            return 0;
        }
        **/
        f = 9*expo(10,d-2)*(d-1) ;
        return(f - recursion(index,d,n));
    }
}
long long recursion(int index,int d,char* n)
{
    long long f;
    if(d!=2)
    {
       /** 
        int number=0;
        for(int i=0;i<d;i++)
        {
            number = number*10 + (n[index+i]-'0');
        }
        cout<<number<<"num"<<d<<endl;
        //if(log10(number)==(int)log10(number))
        if(number ==0)
        {
            cout<<index<<" "<<index+d-1<<endl;;
            cout<<number<<"here"<<d<<" ";
            return 0;
        }
        **/
        f = (n[index]-'0') * expo(10,d-2) * (d-1) ;       
        index = index + 1;
        return (f - ez(index,d,n));
    }
}

int main()
{
    int t;
    char a[10],b[10];
    int na,nb,r,cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %s",a,b);
        int stra = strlen(a);
        int strb = strlen(b);
        na = 0 ; nb = 0;
        cnt = 0;
        for(int i=stra-1 ; i>=0 ; i--)
        {
            r = a[i]-'0';
            if(a[i]=='0')
                cnt++;
            na = na*10 + r;
        }
        
        for(int i=strb-1 ; i>=0 ; i--)
        {
            r = b[i]-'0';
            nb = nb*10 + r;
        }
        //cout<<na<<" "<<nb<<endl;
        //cout<<a<<" "<<b<<endl;
        cout<<noz(b,nb) - noz(a,na) + cnt <<endl;
        //cout<<noz("2");
    }
    return 0;
}

