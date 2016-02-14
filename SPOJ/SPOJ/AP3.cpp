/*
 *SPOJ Problem Set (classical)
 11066. AP - Complete The Series v2
 Problem code: AP3

 After solving "AP - Complete The Series (easy)" very fast, Lucifer decided to make it little more interesting.

 He said

 He will be give you the 3rd term , 4th last term and the sum of the AP series. You need print length of the series & the series.
 Input

 First line will contain a number indicating the number of test cases.

 Each of the following t lines will have 3 number '3term' ,'4Lastterm' and 'sum'

 3term  - is the 3rd term in of the series and

 4Lastterm  - is the 4th term in of the series and

 sum - is the sum of the series.
 Output

 For each input of the test case, you need to print 2 lines.

 fist line should have 1 value- number of terms in the series.

 2nd line of the output should print the series numbers separated by single space.

  
 Example

  

Input:

1
3 7 55


Output:
10
1 2 3 4 5 6 7 8 9 10

NOTE - In all the test cases all the series elements are positive integers.
The series will have at least 7 elements.
number of test cases <=100.
All the numbers will fit in 64 bits(long long in C)

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    long double  sum,a3,l4,a,b,c,difference,first_term;//for quadratic
    long double  D,n;
    long long int nn,DD,diff,f_term;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%Lf %Lf %Lf",&a3,&l4,&sum);
        a=(a3+l4);
        b=(-1)*(5*l4+7*a3+2*sum);
        c=12*sum;
        D=sqrtl(b*b-4*a*c); //argument long double
        n=((-1)*b+D)/(2*a);
        cout<<n<<endl;

        difference=(l4-a3)/(n-6);
        first_term=(a3-2*difference);

        nn=llrintl(n);
        diff=llrintl(difference);
        f_term=llrintl(first_term);

        for(int i=1;i<=nn;i++)
        {
            cout<<f_term<<" ";
            f_term+=diff;
        }
        cout<<endl;


    }
    return 0;
}

