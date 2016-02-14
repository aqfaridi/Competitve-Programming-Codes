/**
 * SPOJ Problem Set (classical)
 * 9032. Cube Free Numbers
 * Problem code: CUBEFR
 *
 *  
 *
 *  A cube free number is a number who.s none of the divisor is a cube
 *  number( A cube number is a cube of a integer like 8(2*2*2) ,
 *  27(3*3*3) ). So cube free numbers are
 *  1,2,3,4,5,6,7,9,10,11,12,13,14,15,17,18 etc(we will consider 1 as
 *  cube free). 8,16,24,27,32 etc are not cube free number. So the
 *  position of 1 among the cube free numbers is 1, position of 2 is
 *  2, 3 is 3 and position of 10 is 9. Given a positive number you
 *  have to say if its a cube free number and if yes then tell its
 *  position among cube free numbers.
 *
 *  Input:
 *
 *  First line of the test case will be the number of test case
 *  T(1<=T<=100000) . Then T lines follows. On each line you will find
 *  a integer number n(1<=n<=1000000).
 *
 *  Output:
 *
 *  For each input line, print a line containing .Case I: ., where I
 *  is the test case number. Then if it is not a cube free number then
 *  print .Not Cube Free.. Otherwise print its position among the cube
 *  free numbers.
 *
 *  Sample Input:
 *
 *  10
 *
 *  1
 *
 *  2
 *
 *  3
 *
 *  4
 *
 *  5
 *
 *  6
 *
 *  7
 *
 *  8
 *
 *  9
 *
 *  10
 *
 *  Sample Output:
 *
 *  Case 1: 1
 *
 *  Case 2: 2
 *
 *  Case 3: 3
 *
 *  Case 4: 4
 *
 *  Case 5: 5
 *
 *  Case 6: 6
 *
 *  Case 7: 7
 *
 *  Case 8: Not Cube Free
*
*  Case 9: 8
*
*  Case 10: 9
*  */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX 1000000
#define size 831911
using namespace std;
long long int primecube[26]={8,27,125,343,1331,2197,4913,6859,12167,24389,29791,50653,68921,79507,103823,148877,205379,226981,300763,357911,389017,493039,571787,704969,912673,1030301};//25 primecubes

int arr[size];
bool b[MAX];
void cubesieve()
{
    int cnt,count=0;
    for(int i=1;i<MAX;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(i % primecube[j] ==0)
                b[i]=1;
        }
    }
    for(int i=1,cnt=1;i<MAX;i++)
    {
        if(!b[i])
          arr[cnt++]=i;
    }
    
}
int main()
{
    cubesieve();
    /*
    for(int i=0;i<100;i++)
        cout<<arr[i]<<" ";
   */
    int t,n,cases=0;
    
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%d",&n);
    /*    
        for(int i=0;i<26;i++)
        {
            if(n % primecube[i] == 0)
            {
                printf("Case %d: Not Cube Free\n",cases);
                b=false;
                break;
            }
        }
    */    
    
    
          
         int *location=lower_bound(arr,arr+size,n);
         int index=location-arr;
         if(arr[index]==n)
            printf("Case %d: %d\n",cases,index);   
         else 
            printf("Case %d: Not Cube Free\n",cases);
    
           
    }
    return 0;
}

