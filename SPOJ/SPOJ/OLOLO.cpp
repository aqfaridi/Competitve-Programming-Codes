/**
 * SPOJ Problem Set (classical)
 * 7742. Onotole needs your help
 * Problem code: OLOLO
 *
 *  
 *
 *  Onotole has a lot of pyani. Each pyani has a number, writing on
 *  it. Pyanis with equal numbers are indistinguishable. Onotole knows
 *  everything, so, he knows that each pyani appeared twice, and only
 *  one pyani is unique. He wants to get ........ ......, and he needs
 *  the unique pyani. Given the list of pyanis denote which one of
 *  them appeared once (it is guaranteed that other pyanis appeared
 *  twice).
 *  Input
 *
 *  First line of input contains number of pyanis N<=500 000. Next N
 *  lines contain a single positive integer 1 <= Pi <= 10^9.
 *  Output
 *
 *  Output one positive integer on pyani, which appeared once.
 *  Example
 *
 *  Input:
 *  3
 *  1
 *  8
 *  1
 *  Output:
 *  8
 *
 *  Onotole has found not optimal AC algorithms, so all solutions will
 *  be rejudged. He is watching you.
 *
 *  */
#include<cstdio>
int main()
{
         int n,x,ans=0;
         scanf("%d\n",&n);
         for(int i=0;i<n;i++)
         {
            scanf("%d",&x);
            ans=ans^x;
         }
         printf("%d\n",ans);

         return 0;
}
