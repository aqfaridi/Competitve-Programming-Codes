#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define X first
#define Y second
#define all(v)                      v.begin(),v.end() 
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define _ ios::sync_with_stdio(false);cin.tie(0);

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 1010
#define MOD 1000000007
string s1,s2;
pii mem[MAX][MAX];
pii solve(int i,int j){
  if(i > j) return mp(i,0);
  if(i == j)  return mp(i,1);

  pii& res = mem[i][j];
  if(res.second != -1) return res;

  if(s1[i] == s1[j]){    
    pii t = solve(i+1,j-1);
    res = mp(t.first,t.second + 2);
  }
  else{
    pii p = solve(i+1,j);
    pii q = solve(i,j-1);
    if(p.second > q.second)
      res = p;
    else
      res = q;
  }

  return res;    
}

pii solve2(int i,int j){
  if(i > j) return mp(i,0);
  if(i == j)  return mp(i,1);

  pii& res = mem[i][j];
  if(res.second != -1) return res;

  if(s2[i] == s2[j]){    
    pii t = solve2(i+1,j-1);
    res = mp(t.first,t.second + 2);
  }
  else{
    pii p = solve2(i+1,j);
    pii q = solve2(i,j-1);
    if(p.second > q.second)
      res = p;
    else
      res = q;
  }

  return res;    
}
int main()
{_
  int t,n;
  cin>>t;
  while(t--)
  {
    cin>>s1>>s2;
    
    for(int i=0;i<1010;i++)
      for(int j=0;j<1010;j++)
        mem[i][j].second = mem[i][j].first = -1;
    

    pii p = solve(0,s1.length()-1);
    char ch = s1[p.first];

    for(int i=0;i<1010;i++)
      for(int j=0;j<1010;j++)
        mem[i][j].second = mem[i][j].first = -1;
      
    pii q = solve2(0,s2.length()-1);
    char ch2 = s2[q.first];

    if(!(p.second&1) && !(q.second&1)) cout<<p.second+q.second<<endl;
    else if(!(p.second&1) && (q.second&1))  cout<<p.second+q.second<<endl;
    else if((p.second&1) && !(q.second&1))  cout<<p.second+q.second<<endl;
    else{
      if(ch == ch2)
        cout<<p.second+q.second<<endl;
      else
        cout<<p.second+q.second-1<<endl;
    }
  }
  return 0; 
}
