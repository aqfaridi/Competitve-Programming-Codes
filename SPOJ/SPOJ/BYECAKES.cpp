/**
 * SPOJ Problem Set (classical)
 * 7185. Bye Bye Cakes
 * Problem code: BYECAKES
 *
 * John is moving to a different city and he wants to use all his
 * perishable food before doing it,
 * to avoid wasting. Luckily all he has now is eggs, flour, sugar and
 * milk, so he is going to make
 * his famous cakes and give them to his friends as a goodbye gift.
 * John only knows how to make an entire cake and not half a cake, a
 * third of a cake, or any
 * other portion. So, he will buy whatever is needed of each
 * ingredient so that he can make an
 * integer number of cakes and have nothing left. Of course, he wants
 * to spend as little money as
 * possible. You must help John to decide how much he should buy of
 * each ingredient.
 * Input
 *
 * The input contains several test cases. Each test case is described
 * in a single line that contains
 * eight integers E, F , S, M , E' , F' , S' and M' separated by
 * single spaces. Values E and E' are
 * numbers of eggs, F and F' are grams of flour, S and S' are grams of
 * sugar, and M and M' are
 * centiliters of milk. For each ingredient, X is the amount John has
 * (0 . X . 1000), while X' is
 * the amount needed to make a single cake (1 . X . 1000). The last
 * line of the input contains
 * the number .1 eight times separated by single spaces and should not
 * be processed as a test
 * case.
 * Output
 *
 * For each test case output a single line with four non-negative
 * integers separated by single spaces,
 * representing the amount of each ingredient John needs to buy, in
 * the same order and units as
 * the input.
 * Example
 *
 * Input:
 * 2 3 4 5 1 1 1 1
 * 3 6 9 0 1 2 3 4
 * -1 -1 -1 -1 -1 -1 -1 -1
 *  Output:
 *  3 2 1 0
 *  0 0 0 12
 *  */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int input[8],mod[4],divide[4];
int main()
{
int max,max_cakes,pos;    
while(1)
{
    for(int i=0;i<8;i++)
    {
        scanf("%d",&input[i]);               
    }
    
    if(input[0]==-1)
        break;

    max=0;pos=0;max_cakes=0;
    for(int i=0;i<4;i++)
    {
        divide[i]=input[i]/input[i+4];
        mod[i]=input[i]%input[i+4];

        if(divide[i]>max || (divide[i] >= max && mod[i]!=0))
        {max=divide[i];pos=i;}
    }
    //cout<<mod[pos]<<" "<<pos<<endl;    
    max_cakes = max + ((mod[pos]!=0)?1:0);
    //cout<<max_cakes<<endl;
    for(int i=0;i<4;i++)
    {
        input[i]=(max_cakes*input[i+4] - input[i]); 
        printf("%d ",input[i]);
    }
    printf("\n");

}
    return 0;
}

