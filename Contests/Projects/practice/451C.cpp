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

int main()
{
    ios::sync_with_stdio(false);
    int t,n,k,d1,d2,t1,t2,t3;    
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>d1>>d2;

        if(n%3 != 0)
        {
            cout<<"no"<<endl;
            continue;
        }

                    if (k == n && (d1 != 0 || d2 != 0)) {
                                    cout << "no" << endl;
                                                continue;
                                                        }
        t1 = (d2+k+2*d1)/3;
        t2 = (d2+k-d1)/3;
        t3 = (k-d1-2*d2)/3;

        //cout<<t1<<" "<<t2<<" "<<t3<<endl;
        if(t1 <= n/3 && t2 <= n/3 && t3 <= n/3)
        if(t1 >= 0 && t2 >= 0 && t3>=0  && t1+t2+t3==k)
        {
            if((n/3-t1)>=0 && (n/3 - t2)>=0 &&  (n/3 - t3) >=0)
            if((n/3-t1) + (n/3 - t2) + (n/3 - t3) == (n-k))
            {                
                cout<<"yes"<<endl;
                continue;
            }
        }


        d1 = -d1;
        t1 = (d2+k+2*d1)/3;
        t2 = (d2+k-d1)/3;
        t3 = (k-d1-2*d2)/3;


        //cout<<t1<<" ^ "<<t2<<" "<<t3<<endl;

        if(t1 <= n/3 && t2 <= n/3 && t3 <= n/3)
        if(t1 >= 0 && t2 >= 0 && t3>=0  && t1+t2+t3==k)
        {

            if((n/3-t1)>=0 && (n/3 - t2)>=0 &&  (n/3 - t3) >=0)
            if((n/3-t1) + (n/3 - t2) + (n/3 - t3) == (n-k))
            {
                cout<<"yes"<<endl;
                continue;
            }
        }

        d2 = -d2;
        d1 = -d1;
        t1 = (d2+k+2*d1)/3;
        t2 = (d2+k-d1)/3;
        t3 = (k-d1-2*d2)/3;


        //cout<<t1<<" * "<<t2<<" "<<t3<<endl;
        
        if(t1 <= n/3 && t2 <= n/3 && t3 <= n/3)
        if(t1 >= 0 && t2 >= 0 && t3>=0  && t1+t2+t3==k)
        {

            if((n/3-t1)>=0 && (n/3 - t2)>=0 &&  (n/3 - t3) >=0)
            if((n/3-t1) + (n/3 - t2) + (n/3 - t3) == (n-k))
            {
                cout<<"yes"<<endl;
                continue;
            }
        }
        
        d1 = -d1;

        t1 = (d2+k+2*d1)/3;
        t2 = (d2+k-d1)/3;
        t3 = (k-d1-2*d2)/3;

        //cout<<t1<<" $ "<<t2<<" "<<t3<<endl;
        
        if(t1 <= n/3 && t2 <= n/3 && t3 <= n/3)
        if(t1 >= 0 && t2 >= 0 && t3>=0  && t1+t2+t3==k)
        {
            
            if((n/3-t1)>=0 && (n/3 - t2)>=0 &&  (n/3 - t3) >=0)
            if((n/3-t1) + (n/3 - t2) + (n/3 - t3) == (n-k))
            {
                cout<<"yes"<<endl;
                continue;
            }
        }

        cout<<"no"<<endl;

    }
    return 0; 
}
