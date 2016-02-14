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

#define MAX 300020
#define MOD 1000000007
//vvi a(MAX,inner);
//vvi cumm(MAX,inner);
//vvi cummb(MAX,inner);

int main()
{
    ios::sync_with_stdio(false);
    int n;

    return 0; 
}