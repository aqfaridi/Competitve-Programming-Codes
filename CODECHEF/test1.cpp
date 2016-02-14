#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
using namespace std;
 
#define ll long long int
#define form(i,m) for(i=m.begin();i!=m.end();i++)
#define mii map< int,int>
 
 
#define gcu getchar
//#define gcu getchar_unlocked
inline void scan(int &x) {
register int c = gcu();
x = 0;
int neg = 0;
 
for(; ((c<48 || c>57) && c != '-'); c = gcu());
 
if(c=='-') {
neg = 1;
c = gcu();
}
 
for(; c>47 && c<58 ; c = gcu()) {
x = (x<<1) + (x<<3) + c - 48;
}
 
if(neg)
x = -x;
}
 
 
int root(mii m,int x,mii c)
{
int f=m[x];
while(f!=c[f])
{
f=c[f];
}
return f;
}
 
int main() {
ios_base::sync_with_stdio(false);
int t=1;
scan(t);//cin>>t;
while(t--)
{
int n,q;
scan(n);//cin>>n;
map< int,int> m,c;
int s[n+5],mm[n+5];
for(int i=1;i<=n;i++)
{
scan(s[i]);//cin>>s[i];
m[s[i]]=i;
c[i]=i;
mm[i]=i;
}
scan(q);//cin>>q;
while(q--)
{
int ch;
scan(ch);//cin>>ch;
if(!ch)
{
int x,y;
scan(x);scan(y);//cin>>x>>y;
int a,b;
a=root(m,x,c);
b=root(m,y,c);
 
if(a==b) cout<<"Invalid query!\n";
else if(mm[a]>mm[b])
{
c[b]=a;
}
else
{
c[a]=b;
}
}
else
{
int x;
scan(x);//cin>>x;
cout<<root(m,x,c)<<endl;
}
}
}
return 0;
}
