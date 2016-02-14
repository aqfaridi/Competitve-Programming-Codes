/**
 * SPOJ Problem Set (classical)
 * 9788. Friends of Friends
 * Problem code: FACEFRND
 *
 * Bob uses a social networking site almost all the time. He was
 * wondering what are Friends of Friends in that social networking
 * site? If .X. is his friend, and .Y. is X.s friend but .Y. is not
 * his friend, then .Y. is called his friend of friend. You have to
 * find how many friends of friends Bob has. (Each user in that social
 * networking site has a unique 4-digit ID number)
 * Input
 *
 * First line contains a integer .N. (1<=N<=100) the number of friends
 * in Bob's Profile. Then follow N lines.
 *
 * First Integer in each line is the ID number of Bob's friend, then
 * an integer .M. (1<=M<=100) is the number of people in his friend
 * list. Then follow M integers in that line, denoting the ID number
 * of friends in his friend list (excluding Bob). 
 * Output
 *
 * Output a single integer denoting Bob's number of friends of
 * friends.
 *
 * Example
 *
 * Input:
 *
 * 3
 *
 * 2334 5 1256 4323 7687 3244 5678
 *
 * 1256 2 2334 7687
 * 4323 5 2334 5678 6547 9766 9543
 *
 *
 * Output:
 *
 * 6
 * */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int friends[101],frndoffrnd[101]; 
int main()
{
    int n,m,sum_m=0,count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&friends[i]);
        scanf("%d",&m); 
        for(int j=0;j<m;j++)
        {
            scanf("%d",&frndoffrnd[sum_m++]);
        }

    }
    sort(frndoffrnd,frndoffrnd+sum_m);
//    for(int i=0;i<sum_m;i++)
  //      cout<<frndoffrnd[i]<<" ";
    //cout<<endl;
    for(int i=0;i<sum_m-1;i++)
    {
        while(frndoffrnd[i] == frndoffrnd[i+1])
        {
            frndoffrnd[i]=0;
            i++;
        }
    }

//    for(int i=0;i<sum_m;i++)
  //      cout<<frndoffrnd[i]<<" ";
    //cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<sum_m;j++)
        {
            if(friends[i] == frndoffrnd[j])
                frndoffrnd[j]=0;

        }
    }
    for(int i=0;i<sum_m;i++)
    {
        if(frndoffrnd[i] != 0)
            count++;
    }
    printf("%d\n",count);

    return 0;
}

