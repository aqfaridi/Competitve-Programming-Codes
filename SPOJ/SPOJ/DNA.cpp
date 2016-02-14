/**
 * SPOJ Problem Set (classical)
 * 13105. DNA
 * Problem code: MUTDNA
 *
 *  
 *  Biologists have discovered a strange DNA molecule, best described
 *  as a sequence of N characters from 
 *  the set {A, B}. An unlikely sequence of mutations has resulted in
 *  a DNA strand consisting only of A.s. 
 *  Biologists found that very odd, so they began studying the
 *  mutations in greater detail.
 *  They discovered two types of mutations. One type results in
 *  changing a single character of the 
 *  sequence (A . B or B . A). The second type changes a whole prefix
 *  of the sequence, specifically 
 *  replacing all characters in positions from 1 to K (for some K
 *  between 1 and N, inclusive) with the other 
 *  character (A with B, B with A).
 *  Compute the least possible number of mutations that could convert
 *  the starting molecule to its end 
 *  state (containing only A characters). Mutations can occur in any
 *  order
 *
 *   
 *
 *   Biologists have discovered a strange DNA molecule, best described
 *   as a sequence of N characters from 
 *
 *   the set {A, B}. An unlikely sequence of mutations has resulted in
 *   a DNA strand consisting only of A's. 
 *
 *   Biologists found that very odd, so they began studying the
 *   mutations in greater detail.
 *
 *   They discovered two types of mutations. One type results in
 *   changing a single character of the 
 *
 *   sequence (A . B or B . A). The second type changes a whole prefix
 *   of the sequence, specifically 
 *
 *   replacing all characters in positions from 1 to K (for some K
 *   between 1 and N, inclusive) with the other 
 *
 *   character (A with B, B with A).
 *
 *   Compute the least possible number of mutations that could convert
 *   the starting molecule to its end 
 *
 *   state (containing only A characters). Mutations can occur in any
 *   order
 *
 *    
 *
 *     
 *     Input
 *
 *      
 *
 *      The first line of input contains the positive integer N (1 . N
 *      . 1 000 000), the length of the molecule.
 *
 *      The second line of input contains a string with N characters,
 *      with each character being either A or B. 
 *
 *      This string represents the starting state of the molecule.
 *
 *       
 *       Output
 *
 *       The first and only line of output must contain the required
*       minimum number of mutations.
*       Example
*
*       Input 1:
*       4
*       ABBA
*
*       Output 1:
*       2
*
*       Input 2:
*       5
*       BBABB
*
*       Output 2:
*       2
*
*       Input 3:
*       12
*       AAABBBAAABBB
*
*       Output 3:
*       4
*       */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 1000010
using namespace std;
char str[MAX];
int main()
{
    int n,flag,count;
    scanf("%d",&n);
    scanf("%s",str);
    flag=0;
    count=0;
    for(int i=n-1;i>=0;i--)
    {
        if(flag==0)
        {
            if(str[i]=='B')
            {
                count++;

                if(str[i] != str[i-1]) 
                    continue;
            
                if(i !=0)
                    while(str[i]==str[i-1])
                        i--;
            flag=1;
            }
        }
        else
        {
            if(str[i]=='A')
            {
                count++;
            
                if(str[i] != str[i-1])
                    continue;
                if(i!=0)
                    while(str[i]==str[i-1])
                        i--;
            
                flag=0;
            }

                        
        }
    }
    printf("%d\n",count);
    return 0;
}

