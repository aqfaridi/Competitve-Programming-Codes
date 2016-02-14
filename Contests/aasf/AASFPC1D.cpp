#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define gc getchar_unlocked
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

    inline void write_str(char* str)
    {
        for(int i=0;str[i];i++)
            write_char(str[i]);
    }
    inline void write_int(int n)
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
int *tree;
int MAX;
void update(int idx,int val)
{
    while(idx <= MAX)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int main()
{
    int t,n,a,b,size,cnt;
    readNat(&t);
    while(t--)
    {
        vector< pii > v;
        readNat(&n);
        tree = new int[n+1];
        memset(tree,0,sizeof(int)*(n+1));
        MAX = n;
        cnt = 0;
        for(int i=0;i<n;i++)
        {
            readNat(&a);
            readNat(&b);
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end());
        size = v.size();
        for(int i=0;i<size;i++)
        {
            update(v[i].second,1);
            cnt += read(MAX) - read(v[i].second);            
        }
        write_int(cnt);
        write_char('\n');        
        delete[] tree;
    }
    write_flush();
    return 0;
}


