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
int dp[100010];
string str;

int main(){
	ios::sync_with_stdio(false);
    int t,l,k;
    while(cin>>str){
        memset(dp,0,sizeof(dp));
        cin>>k;
        l = str.length();
        for(int i=0;i<l;i++){
            if(isdigit(str[i])){
                dp[i+1] = (str[i]-'0')*dp[i];
            }
            else
                dp[i+1] = dp[i] + 1;
        }

        int b = true;
        int idx = 0;
        for(int i=l-1;i>=0;i--){
            if(b && isdigit(str[i])){
                int n = 0;
                while(isdigit(str[i])){
                    n = n*10 + (str[i] - '0');
                    i--;
                }
                	i++;
                k=k%dp[i-1];
                b=0;
                if(k==0){
                    cout<<str[i-1]<<endl;
                    break;
                }
            }
            else if(isdigit(str[i])){	
                b=1;
                if(k==dp[i]){
                    
                cout<<str[i]<<endl;
                break;
                }
                
            }
        }
            
    }
    

	return 0;
}