#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()    
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define debug                       if(1)
#define debugoff                    if(0)    

#define MAX 100010
#define MOD 1000000007
vector<int> v,arr,win;
map<int,int> m;
int main()
{
    ios::sync_with_stdio(false);
    int t,n,size;
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.clear();
        m.clear();
        for(int i=1;i<=(1<<n);i++)  
            v.pb(i);
        size = v.size();
        int cnt = 0;
        do
        {
            win.clear();
            for(int i=0;i<v.size();i++)
                win.pb(v[i]);
            size = win.size();
            while(size > 2)
            {
                for(int i=0;i < (win.size())/2;i++)
                {
                    if(win[2*i] > win[2*i+1]) 
                        arr.pb(win[2*i]);
                    else    
                        arr.pb(win[2*i+1]);
                }
                win.clear();
                for(int i=0;i<arr.size();i++)
                    win.pb(arr[i]);
                arr.clear();
                size = win.size();
            }
            size = win.size();
            if(size == 2)
            {
                //cout<<"win1="<<win[0]<<"win2="<<win[1]<<" ";
                if(win[0]==8 || win[1] == 8)
                {
                    //cout<<1<<" ";
                    cnt++;
                }
                m[win[0]]++;
                m[win[1]]++;
            }
        }while(next_permutation(v.begin(),v.end()));
        cout<<cnt<<endl;
        map<int,int>::iterator it = m.begin();
        for(;it != m.end();it++)
            cout << it->first << " " << it->second << endl;;
    }
    return 0; 
}
