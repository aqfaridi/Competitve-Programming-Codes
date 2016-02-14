#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <complex>
#include <numeric>
#include <functional>
#include <sstream>
#include <algorithm>
#define MAX 55
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int input[MAX][MAX],visited[MAX][MAX];
int H,W,maxx=0;
void DFS(int i,int j,int dist)
{
    
    /** 8 directions **/
    if( i >=H || j >= W || j <0 || i<0 ) 
            return ;

    visited[i][j] = 1;

    if(dist > maxx)
        maxx = dist;

    if(visited[i+1][j]==0 && input[i][j] == input[i+1][j]-1)
        DFS(i+1,j,dist+1);

    if(visited[i][j+1]==0 && input[i][j] == input[i][j+1]-1)
        DFS(i,j+1,dist+1);
    
    if(visited[i+1][j+1]==0 && input[i][j] == input[i+1][j+1]-1)
        DFS(i+1,j+1,dist+1);

    if(visited[i+1][j-1]==0 && input[i][j] == input[i+1][j-1]-1)
        DFS(i+1,j-1,dist+1);

    if(visited[i-1][j]==0 && input[i][j] == input[i-1][j]-1)
        DFS(i-1,j,dist+1);

    if(visited[i-1][j+1]==0 && input[i][j] == input[i-1][j+1]-1)
        DFS(i-1,j+1,dist+1);


    if(visited[i-1][j-1]==0 && input[i][j] == input[i-1][j-1]-1)
        DFS(i-1,j-1,dist+1);

    
    if(visited[i][j-1]==0 && input[i][j] == input[i][j-1]-1)
        DFS(i,j-1,dist+1);

    visited[i][j] = 0;
}
int main()
{
   
    char ch;
    string str;
    while(1)
    {
        scanf("%d %d",&H,&W);
        if(H==0 && W==0)
            break;
        maxx=0; 
        memset(visited,0,sizeof visited);
        for(int i=0;i<H;i++)
        {    
            cin>>str;
            for(int j=0;j<W;j++) 
                input[i][j] = str[j] - 'A';
        }

        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                //cout<<input[i][j]<<" ";
                
                if(input[i][j]==0)
                    DFS(i,j,1);
                //cout<<"i "<<i<<" j "<<j<<"  input i j value "<<input[i][j]<<" and dist  "<<maxx<<endl;;
            }
        }
        cout<<maxx<<endl;


    }
    return 0;
}

