/**
 * SPOJ Problem Set (classical)
 * 11932. Amz Rock
 * Problem code: AMZRCK
 *
 * To many people in many cultures, music is an important part of
 * their way of life.
 *
 *  
 *  AmzMohammad is a fan of rock music. and he have n rock tracks
 *  (labled from 1 to n) now he wanna select a playlist.
 *  in his opinion a good playlist is one that have no two successive
 *  tracks.
 *  in how many ways?
 *
 *   
 *
 *   AmzMohammad is a fan of rock music. and he have n rock tracks
 *   (labled from 1 to n) now he wanna select a playlist.
 *
 *   in his opinion a good playlist is one that have no two successive
 *   tracks.
 *
 *   in how many ways?
 *
 *    
 *
 *     
 *
 *      
 *      Input
 *
 *      first line = number of test cases
 *
 *      each testcase in an integer n(number of tracks)
 *      Output
 *
 *      Output number of good playlists he can make.
 *
 *      answer is less than 1000000000. it is the only constraint :)
 *      Example
 *
 *      Input:
 *       2
 *
 *       1
 *
 *       2
 *
 *       Output:
 *       2
 *
 *       3
 *
 *       note: a good play list may consist 0 track :)
 *
 *       note 2: how many persian rock tracks we have?
 *       */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long fibo(long long n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return 2;
    else
        return fibo(n-1) + fibo(n-2);
}
int main()
{
    long long t,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        printf("%lld\n",fibo(n));
    }
    return 0;
}

