#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX 1000000
int dp[MAX];
#define MOD 1000000003LL
using namespace std;
long long find_mod (int a, int b)
{
    long long x = 1, y = a;
        while (b > 0)
        {
                if (b % 2 == 1)
                {
                        x = (x*y)%MOD;
                }
                y = (y*y)%MOD;
                b /= 2;
        }
        return x%MOD;
}
void precompute ()
{
        dp[1] = 1;
        for (int i = 2; i <= MAX; i++)
        {
                int val1 = dp[i-1] % MOD;
                int val2 = find_mod (i, 3);
                dp[i] = (val1 + val2)%MOD;
        }
        for (int i = 2; i <= MAX; i++)
        {
                dp[i] = ((dp[i]) % MOD + (dp[i-1]) % MOD) % MOD;
        }
}
int main()
{
        precompute ();
        int T;
        scanf ("%d", &T);
        for(int i=1;i<MAX;i++)
        {       /*
                long long sum = 0;
                for (int i = 1; i <= N; i++)
                {
                        sum =  (sum % MOD) + (dp[i])%MOD;
                }
                */
                printf ("%d ",dp[i]);
        if(i%100 == 0) printf("\n");
        }
        return 0;
}
 
