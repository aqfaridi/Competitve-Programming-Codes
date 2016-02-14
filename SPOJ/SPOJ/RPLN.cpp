/**
 * SPOJ Problem Set (classical)
 * 11772. Negative Score
 * Problem code: RPLN 
 *
 *
 *  
 *
 *   Orianna is a great swimmer and she's going to a swimming
 *   competition this month and needs your help as she is highly
 *   paranoic about the results of the competition.
 *
 *    
 *
 *    The competition consists in some sort of evaluations, every
 *    judge makes a score and, based on that score and the score of
 *    other contestants she will get a score belonging to her results,
 *    those scores are final, meaning that will not change in the
 *    competition.
 *
 *     
 *
 *     Orianna requires this solution with urgency, she is getting
 *     evaluated on a lot of ways and she is very worried about her
 *     results, so she wants to know what is the worst score from an
 *     evaluation A to other evaluation B inclusive.
 *
 *      
 *
 *      INPUT:
 *
 *      The first line of the test data will start with an integer T
 *      representing the T test cases, then, T cases will follow, each
 *      of the cases starts with two integers N and Q, denoting the
 *      number of evaluations Orianna had, then, N integers will
 *      follow denoting the score on each evaluation, after that, Q
 *      queries will begin, each query consist on two integers A and
 *      B.
 *
 *       
 *
 *       OUTPUT:
 *
 *       You must output the string .Scenario #i:., a blank line and
 *       then the result of each query, remember, Orianna is
 *       interested on the worst score from evaluation A to evaluation
 *       B inclusive.
 *
 *        
 *
 *        INPUT
 *         OUTPUT
 *          
 *          2
 *
 *          5 3
 *
 *          1 2 3 4 5
 *
 *          1 5
 *
 *          1 3
 *
 *          2 4
 *
 *          5 3
 *
 *          1 -2 -4 3 -5
 *
 *          1 5
 *
*          1 3
*
*          2 4
*           Scenario #1:
*
*           1
*
*           1
*
*           2
*
*           Scenario #2:
*
*           -5
*
*           -4
*
*           -4
*            
*
*             
*
*             CONSTRAINTS:
*
*              
*
*              1 <= T <= 100
*
*               
*
*               Small input (30%):
    *
        *               1 <= N <= 1,000
                        *
                        *               1 <= Q <= 1,000
                        *
                        *               -10^9 <= Ni <= 10^9
                        *
                        *               1 <= A <= B <= N
                        *
                        *                
                        *
                        *                Large input (70%):
                            *
                                *                1 <= N <= 100,000
                                                 *
                                                 *                1 <=
                                                 *                Q <=
                                                 *                100,000
                                                 *
                                                 *                -10^9
                                                 *                <=
                                                 *                Ni
                                                 *                <=
                                                 *                10^9
                                                 *
                                                 *                1 <=
                                                 *                A <=
                                                 *                B <=
                                                 *                N
                                                 *
                                                 *                 
                                                 *
                                                 *                 Solutions
                                                 *                 rejudged
                                                 *                 due
                                                 *                 to
                                                 *                 weak
                                                 *                 test
                                                 *                 cases.
                                                 *
                                                 *                 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1010
using namespace std;
int arr[MAX];
int tree[3*MAX];
void init(int node,int b,int e)
{
    if(b==e) //leaf node
    {
        tree[node]=arr[b];                
        //cout<<"node:"<<node<<" treenode:"<<tree[node]<<endl;
        return ;
    }
    int mid = (b+e)/2;
    init(2*node,b,mid);
    init(2*node+1,mid+1,e);

    tree[node] = min(tree[2*node],tree[2*node + 1]);
    //cout<<"node:"<<node<<" treenode:"<<tree[node]<<endl;
}
int query(int node,int b,int e,int i,int j)// b and e is range of each level subtrees
{
   
    
    //  i b e j
    if((i < b && j< b) || ( i > e && j > e) ) //out of range
        return INT_MAX;
    if( b>=i && e<=j) // in range
        return tree[node];
    if(b==e)     //leaf node
        return tree[node];

    int mid=(b+e)/2;
    int p1=query(2*node,b,mid,i,j);
    int p2=query(2*node + 1,mid+1,e,i,j);
    
    
    
    if(p1==INT_MAX)
        return p2;
    if(p2==INT_MAX)
        return p1;

    return min(p1,p2);
}
int main()
{
    int t,n,q,cases=0;
    int ii,jj;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        printf("Scenario #%d:\n\n",cases);
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        
        init(1,1,n);
       // for(int i=1;i<=8;i++)
         //   cout<<tree[i]<<" ";
        //cout<<endl;
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&ii,&jj);
            printf("%d\n",query(1,1,n,ii,jj));
        }
        printf("\n");

    }
    return 0;
}
                                                 
