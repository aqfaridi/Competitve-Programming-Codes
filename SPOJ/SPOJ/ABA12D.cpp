/**
 * SPOJ Problem Set (classical)
 * 10395. Sum of divisors!
 * Problem code: ABA12D
 *
 * Note: 
 * If you really want to learn something by solving this problem,
 * don't hard code! 
 * There is a nice logic behind this!
 *
 * ---
 *
 *  Kartheeswaran was recently reading an article on perfect numbers,
 *  whose sum of divisors equals twice the number. He was intrigued by
 *  them and decided to generate them but to his disappointment they
 *  turned out to be quite rare. So he decided to look out for a
 *  different property related to sum of divisors. What is more
 *  interesting than a number being a prime? So he decided to look out
 *  for numbers whose sum of divisors is a prime number and he was the
 *  inventor of these special numbers he gave them the name K-numbers.
 *  Given a range [A,B] you are expected to find the number of
 *  K-numbers in this range.
 *  Input
 *
 *  The first line of input indicates the number of test cases T.
 *  Then in the following T lines there will be a pair of integers A
 *  and B.
 *  Output
 *
 *  Output T lines each containing a single integer .c. which denotes
 *  the number of K-numbers which lie in the interval [A,B] inclusive
 *  of the end points.
 *  Constraints:
 *  1<=T<=10000
 *  1<=A<=B<=10^6
 *  Example
 *
 *  Input:
 *  2
 *
 *  1 5
 *
 *  9 10
 *
 *  Output:
 *  2
 *
 *  1
 *
 *  Explanation of sample case:
 *  1) In the range [1,5] the K-numbers are 2 and 4 because
 *  Divisors of 2 are 1 and 2 which sum up to 3, which is a prime.
 *  Divisors of 4 are 1,2 and 4 which sum up to 7, which is a prime.
 *   
 *
 *   2) The K-number in the range [9,10] is 9.
 *   */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[38]={2, 4, 9, 16, 25, 64, 289, 729, 1681, 2401, 3481, 4096, 5041, 7921, 10201, 15625, 17161, 27889, 28561, 29929, 65536, 83521, 85849, 146689, 262144, 279841, 458329, 491401, 531441, 552049, 579121, 597529, 683929, 703921, 707281, 734449, 829921, 1190281};
int main()
{
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        int* location1=lower_bound(arr,arr+38,a);
        int index1=location1 - arr;

        int *location2=lower_bound(arr,arr+38,b);
        int index2=location2 - arr;
        
        if(arr[index2]!=b)
            index2=index2-1;
                
        printf("%d\n",index2-index1+1);


    }
    return 0;
}

