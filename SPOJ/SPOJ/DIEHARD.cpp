#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <utility>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#define MAX 1000010
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int main()
{
    int t,H,A,oddeven,result;
    scanf("%d",&t);
    while(t--)
    {
        oddeven = 1;
        result = 0;
        scanf("%d %d",&H,&A);
        while(H>0 && A>0)
        {
            if((oddeven&1))
            {
                //alternately to go air 
                H+=3; A+=2; 
                result += 1;
                oddeven += 1;

            }
            else
            {
                if((H-5>0) && (A-10>0))
                {
                    H-=5;A-=10;
                    oddeven += 1;
                }
                else
                {
                    H-=20;A+=5;
                    oddeven += 1;
                }
                
                if(H>0 and A>0)
                    result += 1;
            }

        }

        printf("%d\n",result);
        
    }
    return 0;
}

