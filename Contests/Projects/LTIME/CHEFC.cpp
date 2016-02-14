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
typedef pair<int,pair<int,int> > tri;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;
typedef vector< pii > vpii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define fore(i,a,b)                 for(int i=a;i<=b;i++)
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

ostream& operator<<(ostream& out,vi& v)
{
    for(int x=0;x<v.size();x++)
        out << v[x];
    out << endl;
    return out;
}
ostream& operator<<(ostream& out,vvi& v)
{
    int n = v.size();
    int m = v[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            out<<v[i][j]<<" ";
        out<<endl;
    }
    return out;
}

void print_arr(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void print_arr2d(int arr2[][20],int n,int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<arr2[i][j]<<" ";
        cout<<endl;
    }
}

void print_vi(vi& v,int n)
{
    for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void print_vii(vvi& v,int n,int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<v[i][j]<<" ";
        cout<<endl; 
    }
}

string end = "============******=============\n";

#define MAX 100020
#define MOD 1000000007
//vvi a(MAX,inner);
//vvi cumm(MAX,inner);
//vvi cummb(MAX,inner);
int arr[MAX],mark1[MAX],mark2[MAX],mark3[MAX];
int main()
{
    ios::sync_with_stdio(false);
    int n,q,l,r,d,p,c;
    
    cin>>n;
    rep(i,n)    cin>>arr[i];
    if(n >= 100){
                cin>>q;
        while(q--){
            cin>>c;
            if(c == 1){
                cin>>l>>r>>p;
                l -= 1 ;
                r -= 1 ;
                for(int i=l;i<=r;i++)
                    if(arr[i]%p == 0)
                        arr[i] /= p;
            }
            else{
                cin>>l>>d;
                l -= 1;
                arr[l] = d;
            }
        }
        
    }
    
    else
    {
    
        cin>>q;
        while(q--){
            cin>>c;
            if(c == 1){
                cin>>l>>r>>p;
                l -= 1 ;
                r -= 1 ;
                if(p == 2){
                    mark1[l]++;mark1[r+1]--;
                }
                else if(p == 3){
                    mark2[l]++;mark2[r+1]--;
                }
                else if(p == 5){
                    mark3[l]++;mark3[r+1]--;
                }
            }
            else{
                cin>>l>>d;
                l -= 1;
                arr[l] = d;
                mark1[l] = mark2[l] = mark3[l] = 0;
            }
        }
        
        for(int i=1;i<MAX;i++){
            mark1[i] += mark1[i-1];
            mark2[i] += mark2[i-1];
            mark3[i] += mark3[i-1];
        }
        int cnt1 = 0,cnt2 = 0,cnt3 = 0;
        for(int i=0;i<n;i++){
            cnt1 = 0 ; cnt2 = 0;cnt3 = 0;
            if(mark1[i])
                while(arr[i]%2 == 0 && cnt1 < mark1[i]){
                    cnt1++;
                    arr[i] /= 2;
                }   
            
            if(mark2[i])
                while(arr[i]%3 == 0 && cnt2 < mark2[i]){
                    cnt2++;
                    arr[i] /= 3;
                } 
                
            if(mark3[i])
                while(arr[i]%5 == 0 && cnt3 < mark3[i]){
                    cnt3++;
                    arr[i] /= 5;
                }     
        }
        
    }    
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
            
        cout<<endl;
    
    
    
    return 0; 
}