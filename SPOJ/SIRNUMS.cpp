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
bool check(string str,int x)
{
    string sub;
    int l = str.length(),z,carry=0,rem;
    sub = "";
    sub += str[l-1];
    sub += str.substr(0,l-1);
    sub[l] = '\0';
    //trace2(str,sub);
    for(int i=l-1;i>=0;i--)
    {
        z = (str[i]-'0')*x;
        rem = (z+carry)%10;
        carry = (z+carry)/10;
        //trace2(rem,sub[i]);
        if(rem != (sub[i]-'0'))
            return false;
    }
    if(carry != 0)
        return false;
    return true;
}
set<string> myset;
set<string>::iterator it;
int main()
{
    ios::sync_with_stdio(false);
    LL t,n,carry,x,p,z,rem;
    string str;
    cin>>t;
    while(t--)
    {
        myset.clear();
        cin>>p>>x;
        if(p==1 && x>1)
        {
            cout<<"Impossible"<<endl;
            continue;
        }
        if(p==1 && x==1)
        {
            cout<<1<<endl;
            continue;
        }
        str.resize(p);
        for(int ld=1;ld<=9;ld++)
        {
            str[p] = '\0';
            str[p-1] = ld+'0';
            carry = 0;
            for(int i=p-1;i>0;i--)
            {
                z = (str[i]-'0')*x;
                rem = (z+carry)%10;
                carry = (z+carry)/10;
                str[i-1] = rem+'0';
            }
            if(str[0] == '0')
                continue;          
            //cout<<str<<endl; 
            if(check(str,x))
                myset.insert(str);
        }        
        if(myset.size() == 0)
            cout<<"Impossible"<<endl;
        else
        {
            it = myset.begin();
            cout<<(*it)<<endl;
        }
    }
    return 0; 
}
