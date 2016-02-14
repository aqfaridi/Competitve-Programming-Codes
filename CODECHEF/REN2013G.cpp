#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define MAX 100010
#define MOD 1000000007    
vector< pii > v;
bool cmp(pii a,pii b)
{
    if(a.first==b.first)
        return a.second < b.second;
    else
        return a.first < b.first;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,a,b,va,vb,ta,tb;
    bool f;
    LL sum;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        if(abs(a)==abs(b))
            v.push_back(make_pair(a,b));
    }
    
    cin>>va>>vb;
    if(abs(va)==abs(vb))
    {
       v.push_back(make_pair(va,vb));       
       sort(v.begin(),v.end(),cmp);
       if(va>=0 && vb>=0)
       {
            ta = tb = sum = 0;
            for(int i=0,j=0;i<=va;i++,j++)
                {
                    f = binary_search(v.begin(),v.end(),make_pair(i,j),cmp);
                    if(f)
                    {
                        sum += (i-ta)*(i-ta) + (j-tb)*(j-tb);    
                        ta = i;tb = j;    
                    }
                }
       }

       else if(va<0 && vb>0)
       {
            ta = tb = sum = 0;
            for(int i=-1,j=1;i>=va;i--,j++)             
                {
                    f = binary_search(v.begin(),v.end(),make_pair(i,j),cmp);
                    if(f)
                    {
                        sum += (i-ta)*(i-ta) + (j-tb)*(j-tb);   
                        ta = i;tb = j;    
                    }
                }
       }
       else if(va>0 && vb<0)
       {
            ta = tb = sum = 0;
            for(int i=1,j=-1;i<=va;i++,j--)
                {
                    f = binary_search(v.begin(),v.end(),make_pair(i,j),cmp);
                    if(f)
                    {
                        sum += (i-ta)*(i-ta) + (j-tb)*(j-tb);  
                        ta = i;tb = j;    
                    }
                }
       }
        else if(va<0 && vb<0)
        {
             ta = tb = sum = 0;
             for(int i=-1,j=-1;i>=va;i--,j--)
                 {
                     f = binary_search(v.begin(),v.end(),make_pair(i,j),cmp);
                     if(f)
                     {
                         sum += (i-ta)*(i-ta) + (j-tb)*(j-tb);    
                         ta = i;tb = j;    
                     }
                 }
        }

        cout<<sum<<endl;
    }
    else
    {
        cout<<(va*va + vb*vb)<<endl;
    }
    return 0;
}
