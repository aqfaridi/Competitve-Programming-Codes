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
#include <climits>
#include <cassert>

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
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
int arr[MAX];
vector< pii > v;
map<int,int> m;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    v.pb(mp(-1,-1));
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        v.pb(mp(arr[i],i));
    }
    sort(v.begin(),v.end());

    for(int i=1;i<=n;i++)
    {
        pii p = v[i];
        m[p.second] = i;
    }
    
    bool b = true;int last=1,frst=1,k = 0;
    for(int i=1;i<=n && b;i++)
    {
        if(i == v[i].second)
            continue;
        else
        {        
            if(k == 1)
            {
                b   = false;
                break;
            }
            frst = i;
            last = m[i];
            if(v[i].second != last) 
            {
                b = false;
                break;
            }

            for(int j=last;j>i;j--)
                if(v[j].second == v[j-1].second-1)
                    continue;
                else{                  
                    b = false;
                    break;
                }

            i = last+1;
            k = 1;
        }
    }

    if(b){
        cout<<"yes"<<endl;
        cout<<frst<<" "<<last<<endl;
    }
    else
        cout<<"no"<<endl;












/*
    bool flag = true;
    int k = 0,pos_i=0,pos_j=0;
    for(int i=0;i<n;i++)
    {
        if((i+1 < n) && arr[i+1] < arr[i])
        {
            cout<<arr[i]<<" "<<k<<endl;
            if(k > 0){flag = false;break;}            
            pos_i = i;            
            while((i+1)<n && arr[i+1] < arr[i])
            {
                cout<<arr[i]<<endl;
                flag = true;
                i++;k++;
            }
            
            if(arr[pos_i] - 1 == arr[i])
                flag = true;
            else
            {
                flag = false;
                break;
            }
            cout<<i<<endl;
            pos_j = i;
        }
    }

    cout<<pos_i<<" "<<pos_j<<endl;


    if(!flag)
        cout<<"no"<<endl;
    else
    {
        cout<<"yes"<<endl;
        cout<<pos_i+1<<" "<<pos_j+1<<endl;
    }
*/
    return 0; 
}
