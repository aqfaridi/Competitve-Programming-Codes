#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <complex>
#include <algorithm>
#include <map>
#include <deque>
#include <utility>
#include <climits>
#include <vector>
using namespace std;
deque<pair<complex<int>,int> > q;
int visited[9][9];
int bfs(pair<complex<int>,int> s,pair<complex<int>,int> d)//source destination
{
       
    
    q.push_back(s);
    //it is not necessary to track visited or (in the queue)
    //since it can again be visited
    while(!q.empty())
    {
        s = q.front();//pair
        q.pop_front();
        if(real(s.first) == real(d.first) && imag(s.first) == imag(d.first))
            return s.second;
        if(real(s.first) < 1 || real(s.first) > 8 || imag(s.first) < 1 || imag(s.first) > 8)
            continue; // out of boundary

        visited[real(s.first)][imag(s.first)] = true;

        //adjacent 8 nodes ==>> we already node to be pushed in queue
        complex<int> c1(real(s.first)+1 ,imag(s.first)+2);
        if(!visited[real(c1)][imag(c1)])
            q.push_back(make_pair(c1,s.second + 1));
                
        complex<int> c2(real(s.first)+2 ,imag(s.first)+1);
        
        if(!visited[real(c2)][imag(c2)])
            q.push_back(make_pair(c2,s.second + 1));


        complex<int> c3(real(s.first)+2 ,imag(s.first)-1);
        
        if(!visited[real(c3)][imag(c3)])
            q.push_back(make_pair(c3,s.second + 1));
        
        complex<int> c4(real(s.first)+1 ,imag(s.first)-2);
        
        if(!visited[real(c4)][imag(c4)])
            q.push_back(make_pair(c4,s.second + 1));


        complex<int> c5(real(s.first)-1 ,imag(s.first)-2);
        
        if(!visited[real(c5)][imag(c5)])
            q.push_back(make_pair(c5,s.second + 1));

        
        complex<int> c6(real(s.first)-2 ,imag(s.first)-1);
        
        if(!visited[real(c6)][imag(c6)])
            q.push_back(make_pair(c6,s.second + 1));
    

        complex<int> c7(real(s.first)-2 ,imag(s.first)+1);
        
        if(!visited[real(c7)][imag(c7)])
            q.push_back(make_pair(c7,s.second + 1));
    
        complex<int> c8(real(s.first)-1 ,imag(s.first)+2);
        
        if(!visited[real(c8)][imag(c8)])
            q.push_back(make_pair(c8,s.second + 1));

    }

}
int main()
{
    //ios::sync_with_stdio(false);
    int t,x1,y1,x2,y2;
    map<char,int> m;
    char ch = 'a';
    char str1[2],str2[2];
    for(int i=1;i<=26;i++)
    {
        m.insert(make_pair(ch,i));
        ch++;
    }

    pair<complex<int>,int> p1,p2;
    scanf("%d",&t);
    while(t--)
    {

        memset(visited,0,sizeof visited);
        q.clear();
        scanf("%s %s",str1,str2);
        x1 = m[str1[0]];
        y1 = str1[1]-'0';
        x2 = m[str2[0]];
        y2 = str2[1]-'0';

        complex<int> c1(x1,y1);
        complex<int> c2(x2,y2);
        p1 = make_pair(c1,0);
        p2 = make_pair(c2,0);
        //cout<<x1<<" "<<y1<<endl;
        //cout<<x2<<" "<<y2<<endl;
        printf("%d\n",bfs(p1,p2)); 
       
    }
    return 0;
}

