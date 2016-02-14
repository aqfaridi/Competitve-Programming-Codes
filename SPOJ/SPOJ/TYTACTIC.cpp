#include<cstdio>
#include<iostream>
#include<cstring>
#include<sstream>
#include<stdlib.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<queue>
#include<iomanip>
#include<ctype.h>
#include<complex>
#include<utility>
#include<functional>
#include<bitset>
#include<numeric>
#include<cassert>
#include<limits>

using namespace std;


#define FOR(k,x,n) for(long long  k=x;k<n;k++)
#define SORT(x) sort(x.begin(),x.end())
#define READI(x) scanf("%d",&x)
#define PRINTI(x) printf("%d",x)
#define REVERSE(x) reverse( x.begin(),x.end() )

using namespace std;

typedef long long llong;
typedef vector<llong> VL;

class BinaryIndexedTreeRange {
   long long  N;
   VL tree1, tree2;
public:
   BinaryIndexedTreeRange(long long  _N) : N(_N), tree1(_N+1), tree2(_N+1) {}

   void update(long long  idx, long long val) {
      for (long long  i = idx; i <= N; i += (i & -i)) {
         tree1[i] += val*(i-idx+1);
         tree2[i] += val;
      }
   }

   void update(long long  a, long long  b, long long val) {
      update(a, val);
      update(b+1, -val);
   }

   long long get_cumfreq(long long  idx) {
      long long sum = 0;
      for (long long  i = idx; i > 0; i -= (i & -i)) {
         sum += tree1[i];
         sum += tree2[i]*(idx-i);
      }
      return sum;
   }

   long long get_freq(long long  idx) {
      if (idx <= 0) return 0;

      long long sum = tree1[idx];
      long long  z = idx - (idx & -idx);
      --idx;
      for (long long  i = idx; i != z; i -= (i & -i)) {
         sum -= tree1[i];
         sum -= tree2[i]*(idx-i);
      }
      for (long long  i = z; i > 0; i -= (i & -i))
         sum += tree2[i];
      return sum;
   }
};

 BinaryIndexedTreeRange Tree(1000000);
long long summ = 0;

    vector<int> adjList[100010];
void recursion(int a)
{
    for(int i=0;i<adjList[a].size();i++)
    {
        summ += Tree.get_freq(adjList[a][i]);
        recursion(adjList[a][i]);
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m;

    cin>>n>>m;

//    vector<int> adjList[100010];
    int u,v;
    for(int k=0;k<n;k++){

    int x;
    cin>>x;
    Tree.update(k+1,k+1,x);

    }
    for(int i=1;i<=n-1;i++)
    {
        cin>>u>>v;
        adjList[u].push_back(v);
    }   
    for(int k=0;k<m;k++){

    int  a ,b , res;
    char op;
    cin>>op;

    if(op=='U'){

    cin>>a>>b;
    res = Tree.get_freq(a);
    Tree.update( a,a,b-res );

    }
    
    if(op=='Q'){

    cin>>a;
    recursion(a);
    cout<<summ + Tree.get_freq(a)<<endl;
  

    }
    }


    return 0;
}
