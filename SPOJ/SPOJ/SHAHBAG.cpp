/**
 * SPOJ Problem Set (classical)
 * 13707. SHAHBAG
 * Problem code: SHAHBG
 *
 * They say "History repeats itself" and this is what happening in
 * Bangladesh on Feb 2013.  Mass people fought the war in 1971 and now
 * they are rising again to fight war criminals who betrayed the
 * country. In "Shahbag" you can hear the voice of people wanting
 * justice.
 *
 * Shabag protest
 *
 *  
 *
 *  If you go to shahbag you can see many human chains. For this
 *  problem we imagine a straight line going through middle of
 *  shahbag. Each position of the line is marked from 1 to 20000.
 *
 *   
 *
 *   People are forming human chains along the line. Initially every
 *   position is empty. When someone stands in ith  position he holds
 *   hand of people who are standing in his left and right(if there
 *   any) and join there group. If there are no people beside him, he
 *   forms a new group.
 *
 *   When a new people come your job is to mark his position and count
 *   currently how many groups are there in shahbag.
 *
 *   For example suppose:
 *      a man came first and stood in postion 2. Currently there are
 *      only 1 group.
 *         then another man stood in position 4. Currently there are 2
 *         groups.
 *            another man stood in position 3. Now there are only 1
 *            group.
 *
 *            And yes, people wont leave until they get justice, so no
 *            need to worry about that.mi
 *
 *            Input:
 *
 *            There will be a single case. First line will contain an
 *            integer Q which denotes number of people. Next line will
 *            contain Q(1<=Q<=20000) integers pi which denotes
 *            position of i-th people that joined the chain. Each pi
 *            will be distinct and at most 20000.
 *
 *            Output:
 *
 *            For each pi print number of groups currently in shahbag.
 *            In last line print the string "Justice". Dont print any
 *            extra spaces.
 *
 *             
 *
 *             Sample Input:
 *
 *             6
 *             2 4 3 6 7 5
 *
 *              
 *
 *              Sample output:
 *
 *              1
 *              2
 *              1
 *              2
 *              2
*              1
*              Justice
*
*               
*
*               Note:
*
*               This problem is based on true event. You can find the
*               details here.
*
*               Alternate writer: Rashedul Hasan Rijul
*               */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[20010];
int main()
{
    int n,position,groups=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&position);
        arr[position]=1;

        if(arr[position-1] == 0  and arr[position+1] == 0 )
        {
            groups++;
            printf("%d\n",groups);
        }
        else if ((arr[position-1] == 1 and arr[position+1] == 0 )||(arr[position-1] == 0 and arr[position+1] == 1))
        {
            printf("%d\n",groups);
        }
        else if (arr[position-1] == 1 and arr[position+1] ==1 )
        {
            groups--;
            printf("%d\n",groups);
        }

    }
    printf("Justice\n");
    return 0;
}

