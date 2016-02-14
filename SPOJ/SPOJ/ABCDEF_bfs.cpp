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
void bfs(pair<complex<int>,int> s);
        
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
                {
                    complex<int> c(i,j);
                    pair<complex<int>,int> p = make_pair(c,1);
                    bfs(p);
                }
                //cout<<"i "<<i<<" j "<<j<<"  input i j value "<<input[i][j]<<" and dist  "<<maxx<<endl;;
            }
        }
        cout<<maxx<<endl;


    }
    return 0;
}


void bfs(pair<complex<int>,int> s)
{
    deque< pair<complex<int>,int> > q;
	q.push_back(s);
	while(!q.empty())
	{
		s = q.front();
		q.pop_front();

		if(maxx < s.second)
			maxx = s.second;
		if(real(s.first) < 0 || real(s.first) >= H || imag(s.first) < 0 || imag(s.first) >= W)
			continue; 

		visited[real(s.first)][imag(s.first)] = true;


		complex<int> c1(real(s.first)-1 ,imag(s.first)-1);
		if(!visited[real(c1)][imag(c1)] && input[real(c1)][imag(c1)] == input[real(s.first)][imag(s.first)]+1)
			q.push_back(make_pair(c1,s.second + 1));

		complex<int> c2(real(s.first)-1 ,imag(s.first));

		if(!visited[real(c2)][imag(c2)] && input[real(c2)][imag(c2)] == input[real(s.first)][imag(s.first)]+1)	
			q.push_back(make_pair(c2,s.second + 1));


		complex<int> c3(real(s.first)-1 ,imag(s.first)+1);

	    
		if(!visited[real(c3)][imag(c3)] && input[real(c3)][imag(c3)] == input[real(s.first)][imag(s.first)]+1)	
			q.push_back(make_pair(c3,s.second + 1));

		complex<int> c4(real(s.first) ,imag(s.first)-1);


		if(!visited[real(c4)][imag(c4)] && input[real(c4)][imag(c4)] == input[real(s.first)][imag(s.first)]+1)	
			q.push_back(make_pair(c4,s.second + 1));


		complex<int> c5(real(s.first) ,imag(s.first)+1);


		if(!visited[real(c5)][imag(c5)] && input[real(c5)][imag(c5)] == input[real(s.first)][imag(s.first)]+1)	
			q.push_back(make_pair(c5,s.second + 1));


		complex<int> c6(real(s.first)+1 ,imag(s.first)-1);


		if(!visited[real(c6)][imag(c6)] && input[real(c6)][imag(c6)] == input[real(s.first)][imag(s.first)]+1)	
			q.push_back(make_pair(c6,s.second + 1));


		complex<int> c7(real(s.first)+1 ,imag(s.first));

		if(!visited[real(c7)][imag(c7)] && input[real(c7)][imag(c7)] == input[real(s.first)][imag(s.first)]+1)	
			q.push_back(make_pair(c7,s.second + 1));

		complex<int> c8(real(s.first)+1 ,imag(s.first)+1);

		

		if(!visited[real(c8)][imag(c8)] && input[real(c8)][imag(c8)] == input[real(s.first)][imag(s.first)]+1)	
			q.push_back(make_pair(c8,s.second + 1));

	}

}
