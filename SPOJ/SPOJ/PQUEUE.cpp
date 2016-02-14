#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <deque>
#include <utility>
using namespace std;
deque<pair<int,int> > q;
int main()
{
    int t,n,pos,count,priority,num,posnum;
    bool b;
    scanf("%d",&t);
    while(t--)
    {
        count = 0;
        q.clear();
        scanf("%d %d",&n,&pos);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&priority);
            //storing priority with corresp position
            q.push_back(make_pair(priority,i));
        }
        while(q.size())
        {
            b = false;
            for(int j=1;j<q.size();j++)
            {
                if((q.front()).first < q[j].first)
                {
                   q.push_back(q.front());
                   q.pop_front();
                   b = true;
                   break;
                }
            }
            if(!b)
            {
                count++;
                if((q.front()).second == pos)
                    break;
                q.pop_front();//size decreases
                
            }
            /**
            for(int x=0;x<q.size();x++)
                cout<<"("<<q[x].first<<" "<<q[x].second<<"),"<<" ";
            cout<<endl;
            **/
        }
        printf("%d\n",count);
    }
    return 0;
}

