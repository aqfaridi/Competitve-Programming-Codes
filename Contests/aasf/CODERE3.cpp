#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <climits>

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

int arr[1010],lis[1010],lisb[1010];
int main()
{
    int t,n,maxx;
    t = read_int();
    while(t--)
    {
        n = read_int();
        for(int i=0;i<n;i++)
        {
            arr[i] = read_int();
            lis[i] = lisb[i] = 1;
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((arr[i] > arr[j]) && (lis[i] < lis[j]+1))
                    lis[i] = lis[j] + 1;                    
            }
        }        
        reverse(arr,arr+n);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((arr[i] > arr[j]) && (lisb[i] < lisb[j]+1))
                    lisb[i] = lisb[j] + 1;                    
            }
        }
        reverse(lisb,lisb+n);
       
        maxx = -INT_MAX;
        for(int i=0;i<n;i++)
        {
            maxx = max(maxx,lis[i]+lisb[i]-1);
        }
        
        write_int(maxx);
        write_char('\n');

    }
    write_flush();
    return 0;
}


