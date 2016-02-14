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

int arr[510][510],sum[510][510];
int main()
{
    int n,m,q,x1,y1,x2,y2;
    n = read_int();
    m = read_int();
    q = read_int();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            arr[i][j] = read_int();
    sum[1][1] = arr[1][1];
    for(int i=2;i<=m;i++)
        sum[1][i] = sum[1][i-1] + arr[1][i];
    for(int i=2;i<=n;i++)
        sum[i][1] = sum[i-1][1] + arr[i][1];

    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=n;j++)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] + arr[i][j] - sum[i-1][j-1];
        }
    }
    for(int i=0;i<q;i++)
    {
        x1 = read_int(); y1 = read_int();
        x2 = read_int(); y2 = read_int();
        if(y2>=y1 && x2<x1) swap(x1,x2);
        else if(x2>=x1 && y2<y1) swap(y1,y2);
        else if(x2<x1 && y2<y1){ swap(x1,x2); swap(y1,y2);}
        write_int(sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1]);
        write_char('\n');
    }
    write_flush();       
    return 0;
}


