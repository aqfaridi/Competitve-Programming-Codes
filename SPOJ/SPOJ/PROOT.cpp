/*******************************
// Author : Abdul Qadir Faridi
// IPG-3rd yr
// Institute : ABV-IIITM,Gwalior
*********************************/

//header files

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>

//Preprocessor directives

#define MAX 1000010
#define MOD 1000000007
#define gc getchar_unlocked

//macros input-output

#define si(n)                       scanf("%d",&n)
#define sll(n)                      scanf("%lld",&n)
#define sf(n)                       scanf("%f",&n)
#define ss(str)                     scanf("%s",str)
#define sd(n)                       scanf("%lf",&n)
#define INF                         INT_MAX
#define LINF                        (LL)1e18
#define maX(a,b)                    ((a)>(b)?(a):(b))
#define miN(a,b)                    ((a)<(b)?(a):(b))
#define abS(x)                      ((x)<0?-(x):(x))
#define    forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define pn()                        printf("\n")
#define pi(n)                       printf("%d",n)
#define pll(n)                      printf("%lld",n)
#define pd(n)                       printf("%lf",n)
#define ps(str)                     printf("%s",str)

//macros stl

#define mp                          make_pair
#define tri(a,b,c)                  mp(a,mp(b,c))
#define pb                          push_back
#define fill(a,v)                   memset(a,v,sizeof a)
#define all(x)                      x.begin(),x.end()
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define findval(arr,val)            (lower_bound(all(arr)),val)-arr.begin()
#define clr(a)                      memset(a,0,sizeof a)

//Translator

bool isUpperCase(char c){return c>='A' && c<='Z';}
bool isLowerCase(char c){return c>='a' && c<='z';}
bool isLetter(char c){return c>='A' && c<='Z' || c>='a' && c<='z';}
bool isDigit(char c){return c>='0' && c<='9';}
char toLowerCase(char c){return (isUpperCase(c))?(c+32):c;}
char toUpperCase(char c){return (isLowerCase(c))?(c-32):c;}

//debug

#define debug                       if(1)
#define debugoff                    if(0)    

//constants

#define PI                          M_PI
#define E                           M_E
using namespace std;

//typedef

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<int,pii> tri;

//FAST IO
#define sync ios::sync_with_stdio(false);
#define untie cin.tie(NULL);
#define endll '\n'
//#define input(n) readInt(&n)

inline void readNat(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());//ignore whitespace in front
    //2x + 8x = 10x  optimisation
         for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}
inline void readInt(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void read_string(char *str)
{
      register char c = 0;
       register int i = 0;
 
    while (c < 33)
        c = getchar_unlocked();
 
    while (c != '\n') 
    {
        str[i] = c;
        c = getchar_unlocked();
        i = i + 1;
    }
 
    str[i] = '\0';
}
namespace IO
{
    const int SIZE = 1 << 19;
    char buff[SIZE], *p = buff + SIZE;
     char buf2[SIZE];
    int bufL2 = 0;

    inline char read_char()
    {
           if( p == buff + SIZE ) //only once check (whole i/p file)
           {
             fread( buff, 1, SIZE, stdin );
               p = buff;
        }
        return *(p++);//further invokes from buff ptr
    }
 
    inline int read_int()
    {
        char c;
        int val = 0;

        do 
        {
            c = read_char() ;
        }while( c < '-' ) ;//this while loop will continue until it finds '-' or ' ' or '\n'
        
        if( c == '-' ) 
        {
            //this means the current integer is negative
            for( c = read_char() ; c >= '0' ; c = read_char() ) 
            {
                val = val * 10 + ( c - '0' ) ;//get the integer
            }
            return - val ;//return the negative number
        }
        else 
        {
            for( ; c >= '0' ; c = read_char() ) 
            {
                val = val * 10 + ( c - '0' ) ;
            }
            return val ;//return the positive number

        }
      
    }
    inline void write_flush() 
    {
        fwrite( buf2 , sizeof( char ) , bufL2 , stdout ) ;//flushes output to stdout
        bufL2 = 0 ;//pointer returns to the beginning since output buffer array(buf2) has been flushed
    }

    inline void write_char( char c ) 
    {
        buf2[ bufL2++ ] = c ;//bufL2 points to current index in the output buffer array(buf2)  
        if( bufL2 == SIZE ) 
        {
            //array full so let's flush it
            write_flush() ;
        }
    }

    inline void write_str( char* str)
    {
        for(int i=0;str[i];i++)
            write_char(str[i]);
    }
    inline void write_int( int n ) 
    {
        //recursive function to load the number to output buffer array(buf2)
        if( n >= 10 ) 
        {
            write_int( n / 10 ) ;
        }
            write_char( '0' + n % 10 ) ;
    }
    
    inline void write_Int(int n)
    {
        if(n<0)
        {
            write_char('-');
            write_flush();
            n *= (-1);
        }
        write_int(n);
    }
}

using namespace IO;
int etf(int n)
{
    LL phi = n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            phi -= phi/i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        phi -= phi/n;
   
    return (int)phi;
}
vector<int> v;
void prime_factorize(int n)
{
    for(LL i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.pb(i);
            while(n%i==0)
                n/=i;   
        }        
    }
    if(n>1)
        v.pb(n);
}
LL expo(int a,int n,int m)
{
    LL A = a;
    LL result = 1;
    while(n>0)
    {
        if((n&1))
            result = (result*A)%m;
        A = (A*A)%m;
        n>>=1;
    }
    return result%m;
}
int main()
{
    int p,m,g,size,rem;
    while(1)
    {
        p = read_int();
        m = read_int();
        if(p==0 && m==0)
            break;
        v.clear();
        //calc phi(n) => phi(p)
        //prime factorize phi(n)
        int phi = p-1;//since p is prime [phi(p) = p-1]
        prime_factorize(phi);
        rep(i,m)
        {
            g = read_int();
            //cout<<phi<<endl;
            size = v.size();   
            int j;
            for(j=0;j<size;j++)
            {
                //cout<<v[j]<<" ";
                rem = expo(g,phi/v[j],p);
                if(rem == 1)
                    break;
            }
            if(j==size)
                write_str("YES\n");
            else
                write_str("NO\n");

        }
    }
    write_flush();
    return  0;
}


