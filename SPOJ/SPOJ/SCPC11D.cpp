/**
 * SPOJ Problem Set (classical)
 * 9754. Egypt
 * Problem code: SCPC11D
 *
 * A long time ago, the Egyptians figured out that a triangle with
 * sides of length 3, 4, and 5 had a right angle as its largest angle.
 * You must determine if other triangles have a similar property.
 * Input
 *
 * Input represents several test cases, followed by a line containing
 * 0 0 0. Each test case has three positive integers, less than
 * 30,000, denoting the lengths of the sides of a triangle.
 * Output
 *
 * For each test case, a line containing "right" if the triangle is a
 * right triangle, and a line containing "wrong" if the triangle is
 * not a right triangle.
 * Example
 *
 * Input:
 * 6 8 10
 * 25 52 60
 * 6 8 10
 * 25 52 60
 * 5 12 13
 * 0 0 0
 * 5 12 13
 * 0 0 0
 *
 * Output:
 * right
 * wrong
 * right
 * */
#include<iostream>
using namespace std;
int main()
{
        int a,b,c;
        while(true)
        {              
            cin>>a>>b>>c;
            if(a==0 && b==0 && c==0)
                  break;
            else if(a*a+b*b==c*c)
                  cout<<"right"<<endl;        
            else if(a*a+c*c==b*b)
                  cout<<"right"<<endl;
            else if(c*c+b*b==a*a)
                  cout<<"right"<<endl;
            else
                  cout<<"wrong"<<endl;
        }
        return 0;
}

