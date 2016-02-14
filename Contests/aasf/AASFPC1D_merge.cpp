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
int arr[100010],temp[100010],invcnt=0;
void merge(int low1,int up1,int low2,int up2)
{
    int i=low1,j=low2,k=low1,mid=up1;
    while(i<=up1 && j<= up2)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            invcnt += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }
    while(i<=up1)
        temp[k++] = arr[i++];
    while(j<=up2)
        temp[k++] = arr[j++];

    //copying
    for(int x = low1 ;x<k;x++)
        arr[x] = temp[x];
}
void mergesort(int low,int high)
{
    int mid;
    if(low == high)
        return ;
    
    
        mid = (low + high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,mid,mid+1,high);
    
}
using namespace IO;
int main()
{
    int t,n,a,b,size;
    t = read_int();
    while(t--)
    {
        vector< pii > v;
        n = read_int();
        invcnt = 0;
        for(int i=0;i<n;i++)
        {
            a = read_int();
            b = read_int();
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
            arr[i] = v[i].second;

        mergesort(0,n-1);

        write_int(invcnt);
        write_char('\n');        
    }
    write_flush();
    return 0;
}


