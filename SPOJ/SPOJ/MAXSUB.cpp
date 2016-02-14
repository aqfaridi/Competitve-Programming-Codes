/**
 * SPOJ Problem Set (classical)
 * 8495. Maximum Subset of Array
 * Problem code: MAXSUB
 *
 *  
 *  Given an array find the sum of the maximum non-empty subset of the
 *  array and also give the count of the subset. A subset of an array
 *  is a list obtained by striking off some numbers.
 *  A non-empty subset implies a subset with at least 1 element in it.
 *
 *   
 *
 *   Given an array find the sum of the maximum non-empty subset of
 *   the array and also give the count of the subset. A subset of an
 *   array is a list obtained by striking off some (possibly none)
 *   numbers.
 *
 *   A non-empty subset implies a subset with at least 1 element in
 *   it.
 *
 *    
 *
 *     
 *     Input
 *
 *     First line contains an integer T which is the number of
 *     integers. Following this T-cases exist.
 *
 *     Each case starts with a line containing an integer n which is
 *     the number of elements in the array.
 *
 *     The next line contains n-integers which contain the value of
 *     this subset.
 *
 *      
 *
 *      T <= 20
 *
 *      n <= 50,000
 *
 *      Each element in the array <= 1000,000,000
 *
 *      Output
 *
 *      For each test case output the value of the maximum subset and
 *      the count of the subsets modulo 1000,000,009
 *
 *      Example
 *
 *      Input:
 *      2
 *      5
 *      1 -1 1 -1 1
 *      6
 *      -200 -100 -100 -400 -232 -450
 *
 *      Output:
 *      3 1
 *      -100 2
 *      */
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MOD 1000000009
using namespace std;
long long int arr[50003];
long long int expo(long long int a,long long int n)
{
    long long int result=1;
    while(n>0)
    {
        if(n%2==1)
            result = (result*a)%MOD;
        a=(a*a)%MOD;
        n/=2;
    }
    return result;
}
 
 
 
int main() {
    int t,n;
    long long int count;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            if(arr[i] == 0)
                count++;
        }
        sort(arr,arr+n);
        if(arr[n-1]<0)
        {
            long long int *location=lower_bound(arr,arr+n,arr[n-1]);
            int index=location -arr;
            printf("%lld %d\n",arr[n-1],n-index);
        }
        else if(arr[n-1]==0)
        {
            printf("0 %lld\n",expo(2,count)-1);
        }
        else
        {
            long long int sum=0;
            long long int *location=upper_bound(arr,arr+n,-1);
            int index=location - arr;
            for(int i=index;i<n;i++)
            {
                sum += arr[i];
            }
            if(count==0)
            {
                printf("%lld 1\n",sum);
            }
            else
            {
                printf("%lld %lld\n",sum,expo(2,count));
            }
        }
    }
    return 0;
}
 

