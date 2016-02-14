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
 
    inline LL read_int()
    {
        char c;
        LL val = 0;

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

    inline void write_str(char* str)
    {
        for(int i=0;str[i];i++)
            write_char(str[i]);
    }
    inline void write_int(LL n)
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

//file read

#define read_file(x) freopen(x,"r",stdin)
#define write_file(x) freopen(x,"w",stdout)    
#define MAX 1000010
#define MOD 1000000007

int primes[MAX];
void sieve()
{
    primes[0]=primes[1]=1;
    for(int i=2;i*i<=MAX;i++)
    {
        for(int j=i*i;j<=MAX;j+=i)
            primes[j] = 1;
    }
}
long long mulmod(long long a,long long b,long long m)
{
    long long result = 0 ;
    while(b>0)
    {
        if((b&1))
            result = (result + a)%m;
        
        a = (2*a)%m;
        b >>= 1; 
    }
    return result%m;
}
long long modulo(long long a,long long n,long long m)
{
    long long result = 1;
    while(n>0)
    {
        if((n&1))
            result = mulmod(result,a,m);
        
        a = mulmod(a,a,m);
        n>>=1;
    }
    return result%m;
}
bool miller_rabin(long long n,int iteration)
{
    if(n<2)
        return false;
    if(n!=2 && n%2==0)
        return false;
    long long d=n-1;
    while(d%2==0)
        d/=2;
    for(int i=0;i<iteration;i++)
    {
        long long a = (rand() % (n-1) + 1);  
        long long temp = d;  
        long long mod = modulo(a,d,n);
        while(mod!=1 && mod!=(n-1) && temp!=(n-1))
        {
            mod = mulmod(mod,mod,n); 
            temp *= 2;
        }
        if(mod!=(n-1) && temp%2==0)  
            return false;
    }
    return true;

}

vector<LL> v;
int main()
{
    ios::sync_with_stdio(false);
    LL t,size;
    LL n;
    t = read_int();
    while(t--)
    {
        v.clear();
        n = read_int();
        if(n&1)
        {
            write_char('0');
            write_char('\n');
            continue;
        }
        n/=2;
        LL i;
        for(i=1;i*i<n;i++)
        {
            if(n%i==0)
            {
                //cout<<i<<" "<<n/i<<endl;
                if(!miller_rabin(i,3))
                    v.push_back(i);
                if(!miller_rabin(n/i,3))
                    v.push_back(n/i);
                
            }
        }
        if(i*i == n && !miller_rabin(i,3))
            v.push_back(i);
        sort(v.begin(),v.end());
        size = v.size();
        write_int(size);
        write_char(' ');
        for(i=0;i<size;i++)
        {
            write_int(v[i]);
            write_char(' ');
        }
        write_char('\n');
    }
    write_flush();
    return  0;
}


