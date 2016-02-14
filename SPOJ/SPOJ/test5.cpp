#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

int p10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

void calc(int num, int p, int cnt[], int f)
{
    
int n, i;
n = num / p10[p];

for(i=0;i<n;i++)
cnt[i] += p10[p];

for(int x=0;x<10;x++)
    cout<<cnt[x]<<" ";    
cout<<"1"<<endl; 

cnt[i] += num % p10[p] + 1;

for(int x=0;x<10;x++)
    cout<<cnt[x]<<" ";    
cout<<"2"<<endl; 


if(f) cnt[0] -= p10[p];

for(int x=0;x<10;x++)
    cout<<cnt[x]<<" ";    
cout<<"3"<<endl; 


if(p==0) return;
for(i=0;i<10;i++)
cnt[i] += n*p*p10[p-1];

for(int x=0;x<10;x++)
    cout<<cnt[x]<<" ";    
cout<<"4"<<endl; 

if(f) cnt[0] -= (p10[p]-1)/9;

for(int x=0;x<10;x++)
    cout<<cnt[x]<<" ";    
cout<<"5"<<endl; 


calc(num % p10[p], p-1, cnt, 0);
}

int main()
{
int p1, p2, i, a, b, c;
cin>>a;
int cnt1[10] = {1};
int cnt2[10] = {1};

for(int x=0;x<10;x++)
    cout<<cnt1[x]<<" ";    
cout<<endl;    

p1 = (int)floor(log10(a));
calc(a, p1, cnt1, 1);

for(int x=0;x<10;x++)
    cout<<cnt1[x]<<" ";
cout<<endl;  

return 0;
}
