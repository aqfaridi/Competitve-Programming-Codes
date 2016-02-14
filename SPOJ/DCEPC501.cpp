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


int n,dp[100010],arr[100010];
int calc(int i)
{
    if(i>=n)
        return 0;
    int a = arr[i] + ( (dp[i+2] > 0)?dp[i+2]:calc(i+2) );
    int b = arr[i] + arr[i+1] + ( (dp[i+4]>0)?dp[i+4]:calc(i+4) );
    int c = arr[i] + arr[i+1] + arr[i+2] + ( (dp[i+6]>0)?dp[i+6]:calc(i+6) );

    return dp[i] = max(a,max(b,c));
}
int main()
{
    int t;
    t = read_int();
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        n = read_int();
        n = 95000;
        for(int i=0;i<n;i++)
            arr[i] = i;
        write_int(calc(0));
        write_char('\n');
    }
    write_flush();
    return 0;
}


