/**
 * SPOJ Problem Set (classical)
 * 9448. Swarm of Polygons
 * Problem code: SWARM
 *
 * There is a regular n-gon. Some points are marked on each of its
 * sides. There are x1 point marked on the first side, x2 . on the
 * second, ., xn . on the nth. The marked points do not coincide with
 * the vertices of the n-gon. You can choose no more than one of the
 * marked points from each side and form a convex non-degenerate
 * polygon by connecting all those points with lines. Now your task is
 * to find the number of different k-gons that can be formed that way.
 * Input
 *
 * The first line of input file contains positive integer t . the
 * amount of test cases. Next t lines contain six integers each: n, k,
 * a, b, c, m. Here n is the number of sides of the initial n-gon. The
 * amount of marked points on the first side of this n-gon is x1 = a,
 * the amount of the marked points on the following sides is xi =
 * (b*xi-1 + c) mod m, for i > 1.
 * Constraints
 *
 * 1 <= t <= 30
 * 3 <= n <= 109
 * 3 <= k <= 20
 * 1 <= b, c, m <= 106
 * 0 <= a < m
 * Output
 *
 * For each test case output the number of k-gons that can be formed
 * modulo 1000000007.
 * Example
 *
 * Input:
 * 2
 * 4 3 1 2 2 191
 * 10 5 1 113 157 999991
 *
 * Output:
 * 1228
 * 328836201
 *
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MOD 1000000007
using namespace std;
long long expo(long long a,long long n,long long mod)
{
    long long result = 1;
    while(n>0)
    {   
        if((n&1))
            result =((result%mod)*a)%mod;
        
        a = (a*a) % mod;
        n /= 2;
    }
    return result % mod;
}
int main()
{
    int t;
    long long n,k,a,b,c,m,total,Nr,Dr,Nra;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld %lld %lld",&n,&k,&a,&b,&c,&m);
        long long arr[n];
        long long nCrs[n];
        arr[0]=a;
        total=a;
                                 // a.(a-1)...(a-k+1) and k!
        Dr=1;
        for(int i=k;i>=1;i--)
            Dr = (Dr*i) % MOD;
        
        Nra=1;
        for(int i=a;i>=(a-k+1);i--)
            Nra = (Nr*i) % MOD;

        
        Dr=expo(Dr,MOD-2,MOD);

        Nra=(Nra*Dr) % MOD;

        nCrs[0]=(expo(2,arr[0],MOD)%MOD - 1%MOD + MOD)%MOD;
         
                
        for(int i=1;i<n;i++)
        {
            
            arr[i]=((arr[i-1]*b)%m + c%m) % m; //no. points on each side //...........................:)
            
            nCrs[i]=(expo(2,arr[i],MOD)%MOD -1%MOD + MOD)%MOD;
            
            /*
            for(int j=arr[i];j>=1;j--)
                Nra= (Nra*j) % MOD;
            
            Nra = (Nra*Dr) % MOD;
            
            if(arr[i]>=k)
                nCrs[i]=Nra;
            else 
                nCrs[i]=0;
            */
        
            total += arr[i];
                                                            //cout<<total<<" ";
        }

                                                            // cout<<total<<endl;
        Nr=1;
        for(int i=total;i>=(total-k+1);i--)
            Nr = (Nr*i) % MOD;
        
                                                            //cout<<Dr<<"   "<<Nr<<endl;
        Nr=(Nr*Dr);
                                                            //cout<<Nr<<endl;        
        for(int i=0;i<n;i++)
            Nr = (Nr%MOD - nCrs[i]%MOD + MOD)%MOD;
        
        cout<<endl;
        
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        for(int j=0;j<n;j++)
            cout<<nCrs[j]<<" ";
        cout<<endl;

        printf("%lld\n",Nr);
                
    }

    return 0;
}

