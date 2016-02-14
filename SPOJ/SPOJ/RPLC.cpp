/**
 * SPOJ Problem Set (classical)
 * 11373. Coke madness
 * Problem code: RPLC
 *
 * David likes coke, lets say he likes it a lot... One day he was
 * walking by a narrow street when he sees a lot of bottles of cokes,
 * from different brands, he wants to drink it all, but he noticed
 * that one brand gives him power, the other brand weaken him, now, he
 * can wait and regain more energy, but he don't want to do that, he
 * will wait at the beginning and, when he has the sufficient energy
 * he will drink all the cokes in the street.
 *
 *
 * Please, help him find when he will be in the perfect moment to
 * drink all the cokes.
 *
 *  
 *
 *  INPUT:
 *
 *  Will start with an integer T denoting the number of test cases,
 *  then, T lines will follow, for each test case, there will be an
 *  integer N, then, in the next line will be N integers, this will be
 *  the number of cokes, and the values of the cokes in the floor (the
 *  positive one gives energy, the negative ones will take his
 *  energy).
 *
 *   
 *
 *   OUTPUT:
 *
 *   Each test case will output the string .Scenario #i: . where i is
 *   the number of test case analyzed, followed by the minimum energy
 *   required by David to pass the street.
 *
 *    
 *
 *    INPUT
 *      
 *
 *      OUTPUT
 *
 *      2
 *
 *      5
 *
 *      4 -10 4 4 4
 *
 *       
 *
 *       5
 *
 *       1 2 3 4 5
 *          
 *
 *          Scenario #1: 7
 *
 *          Scenario #2: 1
 *
 *
 *          .Blank line between test cases for clarification and
 *          separation.
 *
 *          .The life of David should never reach 0 or less.
 *
 *           
 *
 *           CONSTRAINTS:
 *
 *           1<=N<=1000000
*
*           -10000000<=Ni<=10000000
*           */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    long long sum,minhealth,n,var,cases=0;;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        sum=0;minhealth=1;
        scanf("%lld",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&var);
            sum += var;
            if(sum < 0)
            {
                minhealth += abs(sum);
                sum=0;
            }

        }
        printf("Scenario #%lld: %lld\n",cases,minhealth);
    }
    return 0;
}

