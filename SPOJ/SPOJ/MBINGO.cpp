/**
 *
 SPOJ Problem Set (classical)
 7745. Bingo!
 Problem code: MBINGO

  

  

 English    Vietnamese

  
 Albert, Charles and Mary invented a new version of the classical game Bingo. In traditional
 Bingo the game is presided over by a non-player known as the caller. At the beginning of the
 game each player is given a card containing a unique combination of numbers from 0 to N
 arranged in columns and rows. The caller has a bag containing N + 1 balls, numbered from 0
 to N. On each turn, the caller randomly selects a ball from the bag, announces the number of
 the drawn ball to the players, and sets the ball aside so that it cannot be selected again. Each
 player searches his card for the called number and marks it if he .nds it. The .rst player who
 marks a complete pre-announced pattern on the card (for example, a full horizontal line) wins
 a prize.
 In the Albert-Charles-Mary version, on each turn, the caller draws a .rst ball, returns it to
 the bag, draws a second ball, returns it to the bag, and then calls out the absolute di.erence
 between the two ball numbers. To generate even more excitement, before the game started a
 possibly empty subset of balls is removed from the bag, in such a way that at least two balls
 remain there. They would like to know if every number from 0 to N may still be called out
 with the new drawing method considering the balls that were left in the bag.
 Input
 Each test case is given using exactly two lines. The .rst line contains two integers N and B.
 The meaning of N was described above (1 . N . 90), while B represents the number of balls
 which remained in the bag (2 . B . N + 1). The second line contains B distinct integers bi,
 indicating the balls which remained in the bag (0 . bi . N).
 The last test case is followed by a line containing two zeros.
 Output
 For each test case output a single line containing a single uppercase .Y. if is possible to call out
 every number from 0 to N, inclusive, or a single uppercase .N. otherwise.

 Albert, Charles and Mary invented a new version of the classical game Bingo. In traditional Bingo the game is presided over by a non-player known as the caller. At the beginning of the game each player is given a card containing a unique combination of numbers from 0 to N arranged in columns and rows. The caller has a bag containing N + 1 balls, numbered from 0 to N. On each turn, the caller randomly selects a ball from the bag, announces the number of the drawn ball to the players, and sets the ball aside so that it cannot be selected again. Each player searches his card for the called number and marks it if he .nds it. The .rst player who marks a complete pre-announced pattern on the card (for example, a full horizontal line) wins a prize.

 In the Albert-Charles-Mary version, on each turn, the caller draws a .rst ball, returns it to the bag, draws a second ball, returns it to the bag, and then calls out the absolute di.erence between the two ball numbers. To generate even more excitement, before the game started a possibly empty subset of balls is removed from the bag, in such a way that at least two balls remain there. They would like to know if every number from 0 to N may still be called out with the new drawing method considering the balls that were left in the bag.
 Input

 Each test case is given using exactly two lines. The .rst line contains two integers N and B. The meaning of N was described above (1 . N . 90), while B represents the number of balls which remained in the bag (2 . B . N + 1). The second line contains B distinct integers bi, indicating the balls which remained in the bag (0 . bi . N). The last test case is followed by a line containing two zeros.
 Output

 For each test case output a single line containing a single uppercase .Y. if is possible to call out every number from 0 to N, inclusive, or a single uppercase .N. otherwise.
 Sample input

 6 7

 2 1 3 4 0 6 5

 5 4

 5 3 0 1

 5 3

 1 5 0

 0 0

  

  
 Output for the sample input

  

 Y

Y

N

 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 95 
using namespace std;
int arr[MAX],sieve[MAX];
int main()
{
    int n,b,count;
    while(1)
    {
        scanf("%d %d",&n,&b);
        if(n==0 && b==0)
            break;

        memset(sieve,0,sizeof(sieve));
        for(int i=0;i<b;i++)
            scanf("%d",&arr[i]);
        
        //considering all pairs
        for(int i=0;i<b;i++)
            for(int j=0;j<b;j++)
                sieve[abs(arr[i]-arr[j])]=1;
        count=0;    
        for(int i=0;i<=n;i++)
            if(sieve[i])
                count++;
    
      //  for(int i=0;i<=n;i++)
       //     cout<<sieve[i]<<" ";
       // cout<<endl;
        if(count==n+1) // n+1 balls
            printf("Y\n");
        else
            printf("N\n");
        
    }
    
    return 0;
}

