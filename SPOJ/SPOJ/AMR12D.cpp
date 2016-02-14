/**
 * SPOJ Problem Set (classical)
 * 13043. The Mirror of Galadriel
 * Problem code: AMR12D
 *
 *  
 *  With water from the stream Galadriel filled the basin to the brim,
 *  and breathed on it, and when the water was still again she spoke.
 *  'Here is the Mirror of Galadriel,' she said. 'I have brought you
 *  here so that you may look in it, if you will. For this is what
 *  your folk would call magic, I believe; though I do not understand
 *  clearly what they mean; and they seem also to use the same word of
 *  the deceits of the Enemy. But this, if you will, is the magic of
 *  Galadriel. Did you not say that you wished to see Elf-magic?' -
 *  Galadriel to Frodo and Sam, describing her Mirror.
 *  We call a string S magical if every substring of S appears in
 *  Galadriel's Mirror (under lateral inversion). In other words, a
 *  magical string is a string where every substring has its reverse
 *  in the string.
 *  Given a string S, determine if it is magical or not.
 *  Input (STDIN):
 *  The first line contains T, the number of test cases. The next T
 *  lines contain a string each. 
 *  Output (STDOUT):
 *  For each test case, output "YES" if the string is magical, and
 *  "NO" otherwise.
 *  Constraints:
 *  1 <= T <= 100
 *  1 <= |S| <= 10
 *  S contains only lower-case characters.
 *  Time Limit: 1s
 *  Memory Limit: 64MB
 *  Sample Input:
 *  2
 *  aba
 *  ab
 *  Sample Output:
 *  YES
 *  NO
 *  Notes/Explanation of Sample Input:
 *  For the first test case, the list of substrings are : a, b, ab,
 *  ba, aba. The reverse of each of these strings is present as a
 *  substring of S too.
 *  For the second test case, the list of substring are : a, b, ab.
 *  The reverse of "ab", which is "ba" is not present as a substring
 *  of the string.
 *
 *   
 *
 *   With water from the stream Galadriel filled the basin to the
 *   brim, and breathed on it, and when the water was still again she
 *   spoke. 'Here is the Mirror of Galadriel,' she said. 'I have
 *   brought you here so that you may look in it, if you will. For
 *   this is what your folk would call magic, I believe; though I do
 *   not understand clearly what they mean; and they seem also to use
 *   the same word of the deceits of the Enemy. But this, if you will,
 *   is the magic of Galadriel. Did you not say that you wished to see
 *   Elf-magic?' - Galadriel to Frodo and Sam, describing her Mirror.
 *
 *   We call a string S magical if every substring of S appears in
 *   Galadriel's Mirror (under lateral inversion). In other words, a
 *   magical string is a string where every substring has its reverse
 *   in the string.
 *
 *   Given a string S, determine if it is magical or not.
 *
 *    
 *
 *    Input (STDIN):
 *
 *    The first line contains T, the number of test cases. The next T
*    lines contain a string each. 
*
*     
*
*     Output (STDOUT):
*
*     For each test case, output "YES" if the string is magical, and
*     "NO" otherwise.
*
*      
*
*      Constraints:
*
*      1 <= T <= 100
*
*      1 <= |S| <= 10
*
*      S contains only lower-case characters.
*
*       
*
*       Sample Input:
*
*       2
*
*       aba
*
*       ab
*
*        
*
*        Sample Output:
*
*        YES
*
*        NO
*
*         
*
*         Notes/Explanation of Sample Input:
*
*         For the first test case, the list of substrings are : a, b,
    *         ab, ba, aba. The reverse of each of these strings is
    *         present as a substring of S too.
    *
    *         For the second test case, the list of substring are : a,
    *         b, ab. The reverse of "ab", which is "ba" is not present
    *         as a substring of the string.
    *         */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char str[20];
int main()
{
    int t,l;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        l=strlen(str);
        for(int i=0;i<=(l/2);i++)
        {
            if(str[i] != str[l-i-1])
            {
                printf("NO");
                goto next;
            }
        }
        printf("YES");
        next:
            printf("\n");

    }
    return 0;
}
    
