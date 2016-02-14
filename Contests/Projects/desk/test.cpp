#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
int main()
{
multiset<long long int> s;
std::multiset<long long int>::iterator it;
int t;
long long int x,k;
scanf("%d",&t);
for(int i=0;i<2*t;i++)
{
char ch;
int count=0;
int index=0;
scanf("%c",&ch);
switch(ch)
{
case 'I':scanf("%lld",&x);
if(s.count(x)==0)
{
s.insert(x);
}

break;
case 'D':scanf("%lld",&x);
if(s.count(x)==1)
{
s.erase(x);
}
break;
case 'K':scanf("%lld",&x);

for ( it=s.begin(); it!=s.end(); ++it)
{
if(x>s.size())
{
printf("invalid\n");
}
else
{
count++;
if(count==x)
cout<<*it<<endl;
}
}
count=0;
break;
case 'C' :scanf("%lld",&x);

for ( it=s.begin(); it!=s.end(); ++it)
{
if(*it<x)
index++;
}
cout<<index<<endl;
index=0;
break;


}
}
return 0;
}