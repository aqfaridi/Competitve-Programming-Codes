/**
 * SPOJ Problem Set (classical)
 * 3638. Word Counting
 * Problem code: WORDCNT
 *
 * English  Vietnamese
 *
 * Nguyen is writing a small software for counting words in a string.
 * He becomes bored after finishing the software very fast. He now
 * wants to find the number of words P in the longest consecutive
 * sequence of words of the same length.
 *
 * Given a string containing only characters a...z and spaces (ASCII
 * code is 32), a word is defined to be the longest sequence of
 * non-space characters. Your task is to write a program to help
 * Nguyen find the number P.
 * Input
 *
 * The input file consists of several data sets. The first line of the
 * input file contains the number of data sets which is a positive
 * integer and is not bigger than 20. The following lines describe the
 * data sets.
 *
 * For each data test, there is one single line containing the string
 * to count words. There are less than 1000 words in the string. The
 * length of each word does not exceed 20 characters.
 * Output
 *
 * For each data test, write in one line the number P Nguyen wants to
 * find.
 * Example
 *
 * Sample Input
 * 2
 * a aa bb cc def ghi
 * a a a a a bb bb bb bb c c    
 *
 * Sample Output
 * 3
 * 5
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[1010];
char str[50000];
int main()
{
    int t,index,count,max;
    char ch;
    char *p;
    scanf("%d",&t);
    ch=getchar();
    while(t--)
    {
        gets(str);
        //cout<<str;
       // ch=getchar();
        
        p=strtok(str," ");
        index=0;
        arr[index]=strlen(p);
               
        while(p != NULL)
        {
            
            
            //cout<<p<<" ";
            p=strtok(NULL," ");
            if(p != NULL)
                arr[++index]=strlen(p);
           
        }
       
        max=0;
        for(int i=0;i<=index;i++)
        {
           // cout<<arr[i]<<" ";
           count=1;
           while(arr[i]==arr[i+1])
               {count++;i++;}
           
           if(count > max)
               max=count;
        }
        printf("%d\n",max);

    }
    return 0;
}

