/**
 * SPOJ Problem Set (classical)
 * 10229. Save the Students
 * Problem code: AMR11B
 *
 *  
 *  Hogwarts is under attack by the Dark Lord,
 *  He-Who-Must-Not-Be-Named. To protect the students, Harry Potter
 *  must cast protective spells so that those who are protected by the
 *  spells cannot be attacked by the Dark Lord.
 *  Harry has asked all the students to gather on the vast quidditch
 *  sports field so that he can cast his spells.  The students are
 *  standing in a 2D plane at all grid points - these are the points
 *  (x,y) such that both x and y are integers (positive, negative or
 *  0). Harry's spell can take the shapes of triangle, circle or
 *  square, and all who fall within that shape (including its
 *  boundaries) are protected.
 *  Given the types of spells and the details regarding where Harry
 *  casts the spell, output the number of people saved by Harry's
 *  spells. 
 *  Input (STDIN):
 *  The first line contains the number of test cases T. T test cases
 *  follow.
 *  Each case contains an integer N on the first line, denoting the
 *  number of spells Harry casts. N lines follow, each containing the
 *  description of a spell.
 *  If the ith spell is a triangle, then the line will be of the form
 *  "T x1 y1 x2 y2 x3 y3". Here, (x1,y1), (x2,y2) and (x3,y3) are the
 *  coordinates of the vertices of the triangle.
 *  If the ith spell is a circle, then the line will be of the form "C
 *  x y r". Here, (x,y) is the center and r is the radius of the
 *  circle.
 *  If the ith spell is a square, then the line will be of the form "S
 *  x y l". Here, (x,y) denotes the coordinates of the bottom-left
 *  corner of the square (the corner having the lowest x and y values)
 *  and l is the length of each side.
 *  Output (STDOUT):
 *  Output T lines, one for each test case, denoting the number of
 *  people Harry can save.
 *  Constraints:
 *  All numbers in the input are integers between 1 and 50, inclusive.
 *  The areas of all geometric figures will be > 0.
 *  Time Limit: 3 s
 *  Memory Limit: 32 MBytes
 *  Sample Input:
 *  4
 *  1
 *  C 5 5 2
 *  1
 *  S 3 3 4
 *  1
 *  T 1 1 1 3 3 1 
 *  3
 *  C 10 10 3
 *  S 9 8 4
 *  T 7 9 10 8 8 10
 *  Sample Output:
 *  13
 *  25
 *  6
 *  34
 *
 *   
 *
 *   Hogwarts is under attack by the Dark Lord,
 *   He-Who-Must-Not-Be-Named. To protect the students, Harry Potter
 *   must cast protective spells so that those who are protected by
 *   the spells cannot be attacked by the Dark Lord.
 *
 *   Harry has asked all the students to gather on the vast quidditch
 *   sports field so that he can cast his spells.  The students are
*   standing in a 2D plane at all grid points - these are the points
    *   (x,y) such that both x and y are integers (positive, negative
            *   or 0). Harry's spell can take the shapes of triangle,
    *   circle or square, and all who fall within that shape
    *   (including its boundaries) are protected.
    *
    *   Given the types of spells and the details regarding where
    *   Harry casts the spell, output the number of people saved by
    *   Harry's spells.
    *
    *
    *   Input (STDIN):
        *
            *   The first line contains the number of test cases T. T
                *   test cases follow.
                *
                *   Each case contains an integer N on the first line,
                *   denoting the number of spells Harry casts. N lines
                *   follow, each containing the description of a
                *   spell.
                *
                *   If the ith spell is a triangle, then the line will
                *   be of the form "T x1 y1 x2 y2 x3 y3". Here,
                *   (x1,y1), (x2,y2) and (x3,y3) are the coordinates
                *   of the vertices of the triangle.
                *
                *   If the ith spell is a circle, then the line will
                *   be of the form "C x y r". Here, (x,y) is the
                *   center and r is the radius of the circle.
                *
                *   If the ith spell is a square, then the line will
                *   be of the form "S x y l". Here, (x,y) denotes the
                *   coordinates of the bottom-left corner of the
                *   square (the corner having the lowest x and y
                        *   values) and l is the length of each side.
                *
                *    
                *
                *    Output (STDOUT):
                    *
                        *    Output T lines, one for each test case,
                        *    denoting the number of people Harry can
                             *    save.
                             *
                             *     
                             *
                             *     Constraints:
                             *
                             *     All numbers in the input are
                             *     integers between 1 and 50,
                             *     inclusive.
                             *
                             *     The areas of all geometric figures
                             *     will be > 0.
                             *
                             *      
                             *
                             *      Sample Input:
                             *
                             *      4
                             *
                             *      1
                             *
                             *      C 5 5 2
                             *
                             *      1
                             *
                             *      S 3 3 4
                             *
                             *      1
                             *
                             *      T 1 1 1 3 3 1 
                             *
                             *      3
                             *
                             *      C 10 10 3
                             *
                             *      S 9 8 4
                             *
                             *      T 7 9 10 8 8 10
                             *
                             *       
                             *
                             *       Sample Output:
                             *
                             *       13
                             *
                             *       25
                             *
                             *       6
                             *
                             *       34
                             */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)                             
using namespace std;
int arr[1000][1000];//consider origin at O(500,500)
int square(int x,int y,int side)
{
    int count=0;
    for(int i=x;i<=(x+side);i++)
    {
        for(int j=y;j<=(y+side);j++)
        {
            if(!arr[i][j])
            {
                arr[i][j]=1;
                count++;
            }
        }
    }
    return count;
}
int circle(int x,int y,int r)
{
    int count=0;
    for(int i=(x-r);i<=(x+r);i++)
    {
        for(int j=(y-r);j<=(y+r);j++)
        {
            //check each point whether inside circle
            if(!arr[i][j])
            {
                if((i-x)*(i-x) + (j-y)*(j-y) <= r*r)
                {
                    arr[i][j]=1;
                    count++;
                }
            }
        }
    }
    return count;
}
int triangle(int x1,int y1,int x2,int y2,int x3,int y3)
{
    int count=0,a1,a2,a3;
    int xmin,xmax,ymin,ymax;
    // A=area of whole triangle
    int A = abs( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) ) ;
    xmin = min(min(x1,x2),x3);
    xmax = max(max(x1,x2),x3);
    ymin = min(min(y1,y2),y3);
    ymax = max(max(y1,y2),y3);
    for(int i=xmin;i<=xmax;i++)
    {
        for(int j=ymin;j<=ymax;j++)
        {
            if(!arr[i][j])
            {
                a1 = abs(i*(y2-y3) + x2*(y3-j) + x3*(j-y2)) ;
                a2 = abs(x1*(j-y3) + i*(y3-y1) + x3*(y1-j)) ;
                a3 = abs(x1*(y2-j) + x2*(j-y1) + i*(y1-y2)) ;
                if(a1+a2+a3 == A)
                {
                    arr[i][j]=1;
                    count++;
                }

            }
        }
    }
    return count;
}
int main()
{
    int t,N,x,y,r,x1,x2,x3,y1,y2,y3,side,ans;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&N);
        memset(arr,0,sizeof(arr));    
        while(N--)
        {
            //cout<<"in while"<<endl;
            //scanf("%c",&ch);
            //ch=getchar();
            cin>>ch;
            if(ch=='C')
            {
                scanf("%d %d %d",&x,&y,&r);
                ans += circle(x+500,y+500,r);
            }
            else if(ch=='S')
            {
                scanf("%d %d %d",&x,&y,&side);
                ans += square(x+500,y+500,side);
                        
            }
            else if(ch=='T')
            {
                scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
                //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
                ans += triangle(x1+500,y1+500,x2+500,y2+500,x3+500,y3+500);
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
                             
