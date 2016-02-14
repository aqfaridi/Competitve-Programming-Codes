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
int A[1010],B[1010];
int main()
{
    ios::sync_with_stdio(false);
    int t;
    LL n,a,b,temp,cases=0,k=0;
    double i,j;
    cin>>t;
    while(t--)
    {
        cases++;
        k = 0;
        cin>>n;
        b = sqrt(sqrt(n));
        b += 1;
        cout<<"Case #"<<cases<<":"<<endl;
        for(i=1;i<=b;i++)
        {
            j = sqrt((n/(i*i -1.0)) + 1.0);
            temp = (LL)j;
            if(j - temp == 0)
            {
                A[k] = i;
                B[k++] = j;
            }
        }
        if(k > 0)
        {
            cout<<n;
            rep(i,k)
                cout<<"=("<<A[i]<<"^2-1)*("<<B[i]<<"^2-1)";
        }
        else
            cout<<"For n="<<n<<" there is no almost square factorisation.";

        cout<<endl;
    }
    return 0; 
}
