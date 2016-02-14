/**
 * SPOJ Problem Set (classical)
 * 9734. Hacking the random number generator
 * Problem code: HACKRNDM
 *
 * You recently wrote a random number generator code for a web
 * application and now you notice that some cracker has cracked it. It
 * now gives numbers at a difference of some given value k more
 * predominantly. You being a hacker decide to write a code that will
 * take in n numbers as input and a value k and find the total number
 * of pairs of numbers whose absolute difference is equal to k, in
 * order to assist you in your random number generator testing.
 *
 * NOTE: All values fit in the range of a signed integer, n,k>=1
 * Input
 *
 * 1st line contains n & k.
 * 2nd line contains n numbers of the set. All the n numbers are
 * assured to be distinct.
 * Output
 *
 * One integer saying the no of pairs of numbers that have a diff k.
 * Example
 *
 * Input:
 * 5 2
 * 1 5 3 4 2
 *
 * Output:
 * 3
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,k,var,count=0;
    bool b;
    scanf("%d %d",&n,&k);
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&var);
        arr[i]=var;
    }

    sort(arr.begin(),arr.end());
    vector<int>::iterator it=arr.begin();;
     
   
    for(int i=0;i<n;i++)
    {
        b=false;
        b=binary_search(it++,arr.end(),(arr[i]+k));
        if(b)
            count++;
    }
    printf("%d\n",count);

    return 0;
}

