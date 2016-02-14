/**
 * SPOJ Problem Set (classical)
 * 13381. Manku Word
 * Problem code: MAY99_2
 *
 * Manku loves Codechef's Lucky Number and now he decided to start
 * Manku words :)
 *
 * Manku words are those words which have only letters
 * 'm','a','n','k','u'.
 *
 * Generally in english ,
 * a comes before k, k comes before m and so on but in Manku's
 * dictionary 'm' comes before 'a' , 'a' comes before 'n' , 'n' comes
 * before 'k' , 'k' comes before 'u'.
 *
 * Thus according to manku
 *
 * 1st manku word is m
 * 2nd manku word is a
 * 3rd manku word is n
 * 4th manku word is k
 * 5th manku word is u
 * 6th manku word is mm
 * 7th manku word is ma
 *    
 *    and so on ...       
 *
 *
 *    Your task is very simple
 *    For given value of n , write the nth manku word
 *
 *    1<=n<=10^18
 *    Input
 *
 *
 *    First line of input contains an integer t (1<=t<=100)
 *
 *    Each test case contains an integer n
 *    Output
 *
 *    For every test case print the nth manku word on separate line
 *    Example
 *
 *    Input:
 *
 *    5
 *    10
 *    4
 *    16
 *    17
 *    31
 *
 *    Output:
 *
 *    mu
 *    k
 *    nm
 *    na
 *    mmm
 *        */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
string list[]={"m","a","n","k","u"};
int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        string ans="";
        scanf("%lld",&n);
        while(n>0)
        {
            ans += list[(n-1)%5];
            n = (n-1)/5;
        }
        for(long long i=ans.length()-1;i>=0;i--)
            printf("%c",ans[i]);
        
        printf("\n");
    
    }
    return 0;
}

