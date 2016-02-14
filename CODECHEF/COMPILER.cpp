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
    
#define debug                       if(1)
#define debugoff                    if(0)    

#define print(x)                 cerr << x << " ";    
#define pn()                     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007

int main()
{
    ios::sync_with_stdio(false);
    int t,n,left,right,l,i,j;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>str;
        n = str.length();
        left = right = 0;
        for(i=0;i<n;i++)
        {
            if(str[i] == '<')
                left++;
            else if(str[i] == '>')
                right++;
            if(right > left)    break;
        }
        if(right > left)
            cout<<i<<endl;
        else if(right < left)
        {
            l = 0;
            for(j = n-1 ;j>=0;j--)
            {
                if(str[j] == '<')
                    l++;
                else if(str[j] == '>')
                    l--;
               
                if(l == (left-right))   break;
            }
            cout<<j<<endl;
        }
        else
            cout<<n<<endl;
    }
    return 0; 
}
