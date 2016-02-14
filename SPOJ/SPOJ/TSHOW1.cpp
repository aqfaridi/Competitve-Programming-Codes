/**
 * SPOJ Problem Set (classical)
 * 11354. Amusing numbers
 * Problem code: TSHOW1
 *
 * Amusing numbers are numbers consisting only of digits 5 and 6.Given
 * an integer k , display the kth amusing number.
 * Input
 *
 * FIrst line consists of integer N representing number of test cases
 *
 * Next N lines consist of N integers (1<=k<=10^15)
 * Output
 *
 * N lines each displaying corresponding kth amusing number
 * Example
 *
 * Input:
 * 2
 * 1
 * 5
 * Output:
 * 5
 * 65 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string list[]={"5","6"};
int main() {
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        string ans="";
        while(n>0)
        {
            ans += list[(n-1)%2];
            n= (n-1)/2;
        }

        for(int i=ans.length()-1;i>=0;i--)
            printf("%c",ans[i]);
        printf("\n");    
    }

    return 0;
}

