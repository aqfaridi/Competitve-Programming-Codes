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
int main()
{
    ios::sync_with_stdio(false);
    int minn,posi,posj,shifts,n,l=0,r=0,cost,left = 0,right = 0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n/2;i++){
        left += arr[i];
        right += arr[n-i+1];
    }

    if(right >= left)
    {
        if(arr[n/2+1]>arr[1]){
            cout<<2<<endl;
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<n<<endl;
            return 0;
        }



        minn = arr[1];
        posi = 1;
        for(int i=1;i<=n/2;i++)
            if(arr[i] < minn){
                minn = arr[i];
                posi = i;
            }
        
        
        for(int j=n/2+1;j<=n;j++)
            if(arr[j] > minn)
            {  posj = j;break;}
        //trace2(posi,posj);

        shifts = 1+(posj-n/2);
        cost = 0;
        if(posi == n/2)
        {
            shifts--;
            cout<<shifts<<endl;
        }
        else{
            cout<<shifts<<endl;
            cost += (n/2 - posi + 1);
            cout<<posi<<" "<<n/2<<endl;
        }
       
        swap(arr[posi],arr[posj]);
        for(int i=1;i<shifts;i++){
            cout<<n/2<<" "<<posj<<endl;
            cost += (posj - n/2 + 1);
            posj--;
        }

        //swap(arr[posi],arr[posj]);
        for(int i=1;i<=n/2;i++){
            l += arr[i];
            r += arr[n-i+1];
        }

        assert(abs(r-l) < abs(right-left));
        assert(cost <= 2*n);
    }
    else
    {

        if(arr[n/2+1]<arr[1]){
            cout<<2<<endl;
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<n<<endl;
            return 0;
        }


        minn = arr[n/2+1];
        posj = n/2+1;
        for(int i=n/2+1;i<=n;i++)
            if(arr[i] < minn){
                minn = arr[i];
                posj = i;
            }
        
        
        for(int j=1;j<=n/2;j++)
            if(arr[j] > minn)
            {  posi = j;break;}

        //trace2(posi,posj);
        swap(arr[posi],arr[posj]);

        shifts = 1+(posj-n/2);
        cost = 0;
        if(posi == n/2)
        {
            shifts--;
            cout<<shifts<<endl;
        }
        else{
            cout<<shifts<<endl;
            cout<<posi<<" "<<n/2<<endl;
            cost += (n/2 - posi + 1);
        }
        for(int i=1;i<shifts;i++){
            cout<<n/2<<" "<<posj<<endl;
            cost += (posj - n/2 + 1);
            posj--;
        }

                 
        for(int i=1;i<=n/2;i++){
            l += arr[i];
            r += arr[n-i+1];
        }
        assert(abs(r-l) < abs(right-left));
        assert(cost <= 2*n);
    }
    return 0; 
}
