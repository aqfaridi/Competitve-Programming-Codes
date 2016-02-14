/**
 * SPOJ Problem Set (classical)
 * 8995. CANDY
 * Problem code: LQDCANDY
 *
 * John had a chocolate bar with the size of 2^i. At his birthday
 * party, he shared this chocolate bar to his friend. But his friend
 * just wanted to taste a piece of this chocolate bar which had the
 * length of N (1<=N<=10^18) so that John had to break this chocolate
 * bar into pieces to get the piece for his friend.Unfortunately, this
 * chocolate bar was so breakable that John just can break it into
 * half each time.
 * Help him find the smallest length of the chocolate bar that he
 * needs and the minimum times of breaking the chocolate bar to get
 * the piece for his friend.
 * Input
 *
 * T - the number of test cases
 * In each of the next T lines, there is one numbers N
 * Output
 *
 * For every test case, print one line the length of the chocolate bar
 * and the minimum number of times to break the bar.
 * Example
 *
 * Input:
 * 3
 * 8
 * 5
 * 7
 *
 * Output:
 * 8 0
 * 8 3
 * 8 3
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long expo(long long a,long long n)
{
    long long result=1;
    while(n>0)
    {
        if((n&1))
            result *= a;
        a *= a;
        n >>= 1;
    }
    return result;
}
int main()
{
    int t,l,count;
    long long n,lengthN;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        l=ceil(log2(n));
        lengthN=expo(2,l);
        printf("%lld ",lengthN);
        if(l==log2(n))
            printf("0\n");
        else
        {
            count=0;
            while(n>0)
            {

                lengthN /= 2;
                count++;

                if(n>=lengthN)
                    n -= lengthN;

                //cout<<n<<" "<<lengthN<<endl;
                //if(count==10)
                 //   break;

            }
            printf("%d\n",count);
        }
    }
    return 0;
}

