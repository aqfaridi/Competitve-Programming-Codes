/**
 * SPOJ Problem Set (classical)
 * 5970. Finding Primes
 * Problem code: FINDPRM
 *
 * One commonly used method to calculate all primes in the range
 * [2..n] is to start with the number 2, mark it as prime, and mark
 * all its multiples (excluding itself) as not prime. Then, we find
 * the next smallest unmarked number, mark it as prime, and mark all
 * its multiples (excluding itself) as not prime. Continuing this way,
 * we get a list of all primes.
 *
 * Now, let us say that we modified the above algorithm, and start
 * with n instead of 2. We mark it as prime, and mark all its factors
 * (excluding itself) as not prime. Then we find the next greatest
 * unmarked number, mark it as prime, and mark all its factors
 * (excluding itself) as not prime. Continuing this way, we get a list
 * of all primes.
 *
 * Now you wonder, given a value of n, how many numbers are such that
 * both the above algorithms will mark them as prime?
 *
 *
 * Input
 *
 *
 * The first line contains T the number of test cases. Each of the
 * next T lines contain an integer n.
 *
 *
 * Output
 *
 * Output T lines, one for each test case, containing the required
 * answer.
 *
 * Example
 *
 * Sample Input :
 * 3
 * 2
 * 4
 * 7
 *
 * Sample Output :
 * 1
 * 1
 * 2
 *
 * Constraints
 *
 * 1 <= T <= 100000
 * 2 <= n <= 10000000
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define Lim 10000020
#define sqrtLim 3163
#define Num 664582
using namespace std;
vector<bool> b((Lim-3)>>1);
vector<int> p(Num);
void opt_sieve()
{
    int cnt=0;
    for(int i=3;i<=sqrtLim;i+=2)
    {
        if(!b[(i-3)>>1])
        {
            for(int j=i*i;j<=Lim;j+=i)
            {
                if(j & 1) //odd multiples
                {
                    b[(j-3)>>1]=1;
                }
            }
        }
    }
    p[1]=2;
    for(int i=0,cnt=2;cnt<Num;i++)
    {
        if(!b[i])
            p[cnt++]=2*i+3;
    }
   
}
int main()
{
    int t,n;
    vector<int>::iterator itlow,ithigh;
    opt_sieve();
    
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        
        //cout<<p[n]<<endl;
        itlow=lower_bound(p.begin(),p.end(),(n/2)+1);
        int start_index=itlow-p.begin();
        
        
        ithigh=lower_bound(p.begin(),p.end(),n);
        int end_index=ithigh-p.begin();
       
       
        if(p[end_index] != n)
            end_index -= 1;
                
       

        printf("%d\n",(end_index - start_index + 1));
         
    }
    return 0;
}

