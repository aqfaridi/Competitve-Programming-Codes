/**
 * SPOJ Problem Set (classical)
 * 24. Small factorials
 * Problem code: FCTRL2
 *
 * You are asked to calculate factorials of some small positive
 * integers.
 * Input
 *
 * An integer t, 1<=t<=100, denoting the number of testcases, followed
 * by t lines, each containing a single integer n, 1<=n<=100.
 * Output
 *
 * For each integer n given at input, display a line with the value of
 * n!
 * Example
 * Sample input:
 *
 * 4
 * 1
 * 2
 * 5
 * 3
 *
 * Sample output:
 *
 * 1
 * 2
 * 120
 * 6
 *
 *
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000
int arr[MAX];
int len=0;
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        len=0;
        scanf("%d",&n);
        int fact[MAX]={0};
        fact[0]=1;
        for(int m=2;m<=n;m++)
        {
            int carry=0,i;
            for(int j=0;j<=len;j++)
                arr[j]=fact[j];
            for(i=0;i<=len;i++)
            {
                fact[i]=(arr[i]*m + carry)%10;
                carry=(arr[i]*m + carry)/10;
            }
            if(carry!=0)
            {
                while(carry!=0)
                {
                    fact[i]=carry%10;
                    carry/=10;
                    i++;
                }
            }
            len=i-1;
        }
        for(int i=len;i>=0;i--)
        {
            cout<<fact[i];
        }
        cout<<endl;
    }
    return 0;
}

