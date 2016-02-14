/**
 * SPOJ Problem Set (classical)
 * 10442. Candy Distribution
 * Problem code: CADYDIST
 *
 * Alice is a teacher that loves her students. As the school year
 * reaches its end, she wants to reward all her students with candies
 * for all their hard work.
 *
 * Since each of her classes is unique, she decided she.ll give a
 * different kind of candy for each class, and in order to avoid
 * students being mad at others in their class, she wants to make
 * things fair by giving all students in the same class the same kind
 * of candy.
 *
 * Happily, she went to the candy shop, and fortunately found out that
 * it had N different types of candy, exactly the same number of
 * classes of students she taught!
 *
 * Looking at the prices and paying close attention to the number of
 * students in each class, Alice noted that she could save some money
 * by assigning the types of candy to certain classes. Because she.s a
 * teacher, her income is not that big and saving money is very
 * important to her, so she asked you to write a program to determine
 * the least amount of money she must spend.
 * Input
 *
 * Each test case consists of three lines. The first line contains a
 * positive integer N (1.N.100000). The second line contains N
 * integers Ci, the ith integer indicates the number of students in
 * Alice.s i-th class. The third and last line also contains N
 * integers Pi the ith integer indicates the price of the ith type of
 * candy (1 . Ci, Pi  . 100000).
 *
 * The input ends with a line consisting of a 0, which indicates end
 * of input.
 * Output
 *
 * For each test case, output a line containing the least amount of
 * money Alice must spend.
 * Example
 *
 * Input:
 * 4
 * 1 1 1 1
 * 2 2 2 2
 * 5
 * 10 80 37 22 109
 * 6 8 8 20 15
 * 0
 *
 * Output:
 * 8
 * 2120
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 100010
using namespace std;


int main()
{
   unsigned long long int n,sum,i,j;
   unsigned long long int students[MAX],price[MAX];
        
while(1)
{
    sum=0;
    scanf("%llu",&n);
    if(n==0)
        break;
    for(i=0;i<n;i++)
        scanf("%llu",&students[i]);
    for(j=0;j<n;j++)
        scanf("%llu",&price[j]);

    sort(students,students+n);
    sort(price,price+n);
   
    for(i=0;i<n;i++)
    {
        sum=sum+price[i]*students[n-i-1];
    }
    printf("%llu\n",sum);
}
    return 0;
}

