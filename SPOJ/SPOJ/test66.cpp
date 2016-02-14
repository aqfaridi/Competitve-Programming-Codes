#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX 1000000
long long dp[MAX];
long long dp2[MAX];
#define MOD 1000000003LL
using namespace std;
long long find_mod (long long a, long long b)
{
    long long x = 1, y = a;
	while (b > 0)
	{
		if (b % (long long)2 == 1)
		{
			x = (x*y)%MOD;
		}
		y = (y*y)%MOD;
		b /= (long long)2;
	}
	return x%MOD;
}
void precompute ()
{
	dp[1] = 1;
	dp2[1] = 1;
	for (long long i = 2; i <= MAX; i++)
	{
		long long val1 = dp[i-1] % MOD;
		long long val2 = find_mod (i, 3);
		dp[i] = (val1 + val2)%MOD;
	}
	for (long long i = 2; i <= MAX; i++)
	{
		dp[i] = ((dp[i]) % MOD + (dp[i-1]) % MOD) % MOD;
	}
}
int main()
{
	precompute ();
	int T;
    for(int i=1;i<MAX;i++)
    {
		printf ("%lld\n",dp[i]);
    }	
	return 0;
}

