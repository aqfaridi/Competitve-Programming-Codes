/**
 * SPOJ Problem Set (classical)
 * 4565. What is your Logo
 * Problem code: ANARC05I
 *
 *  
 *
 *  English     Vietnamese
 *
 *  Imagine a 2D diagram drawn in the following way: Starting at the
 *  origin, you.re given a sequence of letters which is entirely made
 *  of the following four letters .U., .D., .L.,and .R..A .U. is an
 *  instruction for you to move one unit upward and drawing a segment
 *  at the same time. Similarly, .D. is for moving down, .L. for left,
 *  and .R. for right.
 *
 *  For example, .gure (a) is drawn by giving the sequence .UURDLL.
 *  while .gure (b) is the result of .UURRRDLLLLUURRRDDD. (in both
 *  .gures, the starting point is identi.ed by a small circle.)
 *
 *
 *  While segments are allowed to intersect, they.re not allowed to
 *  overlap. In other words, any two segments will have, at most, one
 *  point in common. We.re interested in knowing the number of closed
 *  polygons, not containing any lines inside, in such diagrams.
 *  Figure (a), has only one closed polygon while .gure (b) has three.
 *  Write a program to do exactly that.
 *
 *   
 *
 *   Input
 *
 *   Your program will be tested on one or more test cases. Each test
 *   case is speci.ed on a separate line. The diagram is speci.ed
 *   using a sequence made entirely of (U|D|L|R) and terminated by the
 *   letter .Q.. All letters are capital letters. None of the segments
 *   in a test case will overlap.
 *
 *
 *   The end of test cases is identi.ed by the letter .Q. on a line by
 *   itself.
 *
 *   Length of each sequence is smaller than 1000.
 *   Output
 *
 *   For each test case, write the answer on a separate line.
 *   Sample
 *
 *   input
 *   UURDLLQ
 *   UURRRDLLLLUURRRDDDQ
 *   Q
 *
 *   output
 *   1
 *   3
 *   */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int X[1001],Y[1001];
int main() {
    int l,x,y,count,temp;
    string str;
    while(1)
    {
        cin>>str;
        x=0;y=0;
        count=0;
        if(str[0]=='Q')
            break;
            
        l=str.length();
        X[l-1]=0;Y[l-1]=0;

        for(int i=0;i<l-1;i++)
        {
            if(str[i]=='L')
                x--;
            else if(str[i]=='R')
                x++;
            else if(str[i]=='U')
                y++;
            else if(str[i]=='D')
                y--;
                
            X[i]=x; 
            Y[i]=y;
        }



        for(int i=0;i<l;i++)
        {
            for(int j=i+1;j<l;j++)
            {
                if(X[j]==X[i] && Y[j]==Y[i])
                {
                    count++;
                    break; //only one point of intersection is there 
                } 
                  
            }
        }
        printf("%d\n",count);


    }           
    return 0;
}


