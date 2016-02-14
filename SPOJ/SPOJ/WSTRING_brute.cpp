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
#define MAX 10020
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
int alphacnt[26];
int lft[MAX];
int rght[MAX];
int mid[MAX];
deque<int> q;
vector<pair<int,int> > v;
int main()
{
      string str;
      int t,l,maxx,hashcnt;
      scanf("%d",&t);
      while(t--)
      {
          cin>>str;
          v.clear();
          q.clear();
          memset(lft,0,sizeof(lft));
          memset(rght,0,sizeof(rght));
          memset(mid,0,sizeof(mid));
          memset(alphacnt,0,sizeof(alphacnt));
          l = str.length();
          maxx = 0;
          for(int i=0;i<l;i++)
          {
            if(str[i] != '#')
            {
                alphacnt[str[i]-'a'] += 1;
                if(alphacnt[str[i]-'a'] > maxx)
                    maxx = alphacnt[str[i]-'a'];
            }
            lft[i] = maxx;                
          }
          memset(alphacnt,0,sizeof(alphacnt));
          maxx = 0;
          for(int i=l-1;i>=0;i--)
          {
            if(str[i] != '#')
            {
                alphacnt[str[i]-'a'] += 1;
                if(alphacnt[str[i]-'a'] > maxx)
                    maxx = alphacnt[str[i]-'a'];
            }
            rght[i] = maxx;                
          }
          /**
          for(int i=0;i<l;i++)
              cout<<lft[i]<<" ";
          cout<<endl;
          for(int i=0;i<l;i++)
              cout<<rght[i]<<" ";
          cout<<endl;
          **/
          int cntt = 0;
          for(int i=0;i<l;i++)
              if(str[i]=='#')
                  cntt++;
          if(cntt == l)
          {
              cout<<0<<endl;
              continue;
          }
          int x = 0;

          while(str[x] != '\0' && str[x]=='#')
              x++;
          for(;x<l;x++)
          {
              hashcnt = 0;
              if(str[x] == '#')
                  while(str[x]=='#')
                  {
                      hashcnt++;
                      x++;
                  }
             
              if(hashcnt == 1)
                  v.push_back(make_pair(x-1,1));
                 // cout<<q.back()<<" ";
              
                 // cout<<q.size()<<"s ";
              

              else if (hashcnt >=2)
                    v.push_back(make_pair(x-1,-1));

              /*
              if(q.size()==3)
              {
                  while(!q.empty())
                  {
                     v.push_back(q.front());
                     q.pop_front();
                  }
              }*/
             
 
          }
          //cout<<endl;
          //if(str[l-1]=='#')
            //  v[v.size()-1] = -1;

          maxx = 0;
          memset(alphacnt,0,sizeof(alphacnt));
          for(int i=0;i<l;i++)
          {
            if(str[i] != '#')
            {
                alphacnt[str[i]-'a'] += 1;
                if(alphacnt[str[i]-'a'] > maxx)
                    maxx = alphacnt[str[i]-'a'];
            }
            else
            {
                while(i<l && str[i]=='#')
                {
                    mid[i] = maxx;
                    i++;
                }

                maxx = 0;
                memset(alphacnt,0,sizeof(alphacnt));
                i -= 1;
            }
          }
         /** 
          for(int i=0;i<l;i++)
              cout<<mid[i]<<" ";
          cout<<endl;
          **/
          maxx = 0;
          int temp;
          bool flag=false;
          if(v.size() < 3)
          {
              cout<<0<<endl;
              continue;
          }
          for(int i=0;i<v.size();i++)
          {
              //cout<<v[i]<<" ";
              if(i+1 < v.size() && i+2 < v.size())
                if(v[i+1].second > 0)
                 {
                    temp = lft[v[i].first] + mid[v[i+1].first] +  mid[v[i+2].first] + rght[v[i+2].first] ;   
                    flag = true;
                    if(temp > maxx)
                        maxx = temp;
                }
          }
          if(flag)
            cout<<maxx+3<<endl;
          else
            cout<<0<<endl;  
         
      }

}

