/**
 * SPOJ Problem Set (classical)
 * 54. Julka
 * Problem code: JULKA
 * Julka surprised her teacher at preschool by solving the following
 * riddle:
 * Klaudia and Natalia have 10 apples together, but Klaudia has two
 * apples more than Natalia. How
 * many apples does each of he girls have?
 * Julka said without thinking: Klaudia has 6 apples and Natalia 4
 * apples. The teacher tried to check if
 * Julka’s answer wasn’t accidental and repeated the riddle every time
 * increasing the numbers. Every
 * time Julka answered correctly. The surprised teacher wanted to
 * continue questioning Julka, but with
 * big numbers she could’t solve the riddle fast enough herself. Help
 * the teacher and write a program
 * which will give her the right answers.
 * Task
 * Write a program which
 * reads from standard input the number of apples the girls have
 * together and how many more
 * apples Klaudia has,
 * counts the number of apples belonging to Klaudia and the number of
 * apples belonging to Natalia,
 * writes the outcome to standard output
 * Input
 * Ten test cases (given one under another, you have to process all!).
 * Every test case consists of two
 * lines. The first line says how many apples both girls have
 * together. The second line says how many
 * more apples Klaudia has. Both numbers are positive integers. It is
 * known that both girls have no more
 * than 10 100 (1 and 100 zeros) apples together. As you can see
 * apples can be very small.
 * Output
 * For every test case your program should output two lines. The first
 * line should contain the number of
 * apples belonging to Klaudia. The second line should contain the
 * number of apples belonging to
 * Natalia.
 * Example
 * Input:
 * 10
 * 2
 * [and 9 test cases more]
 * Output:
 * 6
 * 4
 * [and 9 test cases more]
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char str_n[101],str_m[101];
int a[101],b[101],sub[101],n[101],m[101];
int main()
{
    
    int l1,l2,carry;
    while(scanf("%s %s",str_n,str_m))
    {
        
        l1=strlen(str_n);
        l2=strlen(str_m);
        
        for(int i=0;i<l1;i++)
        {     n[i]=str_n[i]-'0';cout<<n[i];}
       
        cout<<endl;

        for(int i=0;i<l2;i++)
        { m[i]=str_m[i]-'0';cout<<m[i];}
        
        cout<<endl;

        for(int i=l1-1;i>=0;i--)
        {
            if((i-l2+1)>0)
            {
                if((n[i]-m[i-l2+1]) < 0)
                {
                    sub[i]=(n[i]+10 - m[i-l2+1]);
                    n[i-1]=n[i-1]-1;
                }
                sub[i]=(n[i] - m[i-l2+1]);
            }
            else 
            {
                sub[i]=n[i];
            }
        }
        for(int i=0;i<l1;i++)
            cout<<sub[i];
        cout<<endl;
        carry=0;
        for(int i=0;i<=l1-1;i++)
        {
                b[i]=(sub[i]+carry*10)/2;
                carry=(sub[i]+carry)%2;
        }
        for(int i=l1-1;i>=0;i--)
        {
            if(n[i]-b[i] < 0)
            {
                n[i]=n[i]+10;
                n[i-1]--;

            }
            a[i]=n[i]-b[i];
        }
        //display
        for(int i=0;i<l1;i++)
            printf("%d ",a[i]);
        printf("\n");

        for(int i=0;i<l1;i++)
            printf("%d ",b[i]);
        printf("\n");
        

    }

    return 0;
}

