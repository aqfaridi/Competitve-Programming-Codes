/**
 * SPOJ Problem Set (classical)
 * 739. The Moronic Cowmpouter
 * Problem code: NEG2
 *
 * Inexperienced in the digital arts, the cows tried to build a
 * calculating engine (yes, it's a cowmpouter) using binary numbers
 * (base 2) but instead built one based on base negative 2! They were
 * quite pleased since numbers expressed in base -2 do not have a sign
 * bit.
 *
 * You know number bases have place values that start at 1 (base to
 * the 0 power) and proceed right-to-left to base^1, base^2, and so
 * on. In base -2, the place values are 1, -2, 4, -8, 16, -32, ...
 * (reading from right to left). Thus, counting from 1 goes like this:
 * 1, 110, 111, 100, 101, 11010, 11011, 11000, 11001, and so on.
 *
 * Eerily, negative numbers are also represented with 1's and 0's but
 * no sign. Consider counting from -1 downward: 11, 10, 1101, 1100,
 * 1111, and so on.
 *
 * Please help the cows convert ordinary decimal integers (range
 * -2,000,000,000 .. 2,000,000,000) to their counterpart
 *  representation in base -2.
 *  Input
 *
 *  A single integer to be converted to base -2
 *  Output
 *
 *  A single integer with no leading zeroes that is the input integer
 *  converted to base -2. The value 0 is expressed as 0, with exactly
 *  one 0.
 *  Example
 *
 *  Input:
 *  -13
 *
 *  Output:
 *  110111
 *  */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
string negbinary(int n)
{
    int rem;string s;
    while(n!=0)
    {
        rem = n % (-2);
        n /= (-2);
        if(rem < 0)
        {
            n++;
            rem+=2;
        }
        
        s.push_back(rem + '0'); //character
    }
    if(s.size()==0)
        s.push_back('0');
    else
        reverse(s.begin(),s.end());

    return s;
}
int main()
{
    int n,rem;
    float q;
    string s="";
    scanf("%d",&n);
   
    cout<<negbinary(n)<<endl;

    
    return 0;
}

