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
typedef pair< int, pii > tri;

typedef vector<int> array;
typedef vector<LL> array_LL;
typedef vector<vector<int> > matrix;
typedef vector<vector<LL> > matrix_LL;


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

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
bool satisfy(int a,int b,int c,int d){
    int x = 5*a+b+c-3*d;
    int y = 2*a+b+c-2*d;
    int z = a-b-c+d;

    if(x == 0 && y == 0 && z == 0)  return true;
    else    return false;
}
int cnt[MAX];
multiset<int> s;
multiset<int>::iterator it;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d;
    int x2,x3;
    int p,q,r,ss;
    bool f = 0;
    int n;
    cin>>n;
    if(n == 0){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        cout<<1<<endl;
        cout<<3<<endl;
        cout<<3<<endl;
        return 0;
    }
    if(n == 1){
        cin>>a;
        
        c = 3*a;
        b = a + c;
        x2 = 1;
        x3 = b-1;
        for(int x=1;x<=b;x++){
            x2 = x;
            x3 = b-x;
            s.clear();
            s.insert(a);s.insert(x2);s.insert(x3);s.insert(c);
            it = s.begin();
            p = (*it);it++;
            q = (*it);it++;
            r = (*it);it++;
            ss = (*it);

            if(satisfy(p,q,r,ss)){
                cout<<"YES"<<endl;
                if(p != a) cout<<p<<endl;
                else f = 1;
                if(f || q != a)  cout<<q<<endl;
                else f = 1;
                if(f || r != a)  cout<<r<<endl;
                else f = 1;
                if(f || ss != a)  cout<<ss<<endl;
                return 0;
            }
        }
        
        c = a;
        if(c % 3 == 0){
            a = c/3;
            b = a + c;
            x2 = 1;
            x3 = b-1;
            for(int x=1;x<=b;x++){
                x2 = x;
                x3 = b-x;
                s.clear();
                s.insert(a);s.insert(x2);s.insert(x3);s.insert(c);
                it = s.begin();
                p = (*it);it++;
                q = (*it);it++;
                r = (*it);it++;
                ss = (*it);

                if(satisfy(p,q,r,ss)){
                    cout<<"YES"<<endl;
                    if(p != a) cout<<p<<endl;
                    else f = 1;
                    if(f || q != a)  cout<<q<<endl;
                    else f = 1;
                    if(f || r != a)  cout<<r<<endl;
                    else f = 1;
                    if(f || ss != a)  cout<<ss<<endl;
                    return 0;
                }
            }
        }
        int given = a;

        for(int x=1;x<=100000/3;x++){
            a = x;
            d = 3*x;
            c = 4*x - given;
            s.clear();
            s.insert(a);s.insert(given);s.insert(c);s.insert(d);
            it = s.begin();
            p = (*it);it++;
            q = (*it);it++;
            r = (*it);it++;
            ss = (*it);

            if(satisfy(p,q,r,ss)){
                cout<<"YES"<<endl;
                if(p != given) cout<<p<<endl;
                else f = 1;
                if(f || q != given)  cout<<q<<endl;
                else f = 1;
                if(f || r != given)  cout<<r<<endl;
                else f = 1;
                if(f || ss != given)  cout<<ss<<endl;
                return 0;
            }
        }

        cout<<"NO"<<endl;
    }
    else if(n == 2){
        int g1,g2;
        cin>>g1>>g2;
        cnt[g1] += 1;
        cnt[g2] += 1;
        if(g1 > g2) swap(g1,g2);
        a = g1;
        d = 3*a;
        b = g2;
        c = a+d-b;
                s.clear();
                s.insert(a);s.insert(b);s.insert(c);s.insert(d);
                it = s.begin();
                p = (*it);it++;
                q = (*it);it++;
                r = (*it);it++;
                ss = (*it);

                if(satisfy(p,q,r,ss)){
                    cout<<"YES"<<endl;
                    int ty = 0;
                    if(p != g1 && p!= g2){ty++;  cout<<p<<endl;}
                    if(q != g1 && q!=g2) {ty++; cout<<q<<endl;}
                    if(r != g1 && r!=g2){ty++;  cout<<r<<endl;}
                    if(ss != a && ss!=g2) {ty++; cout<<ss<<endl;}
                    if(ty == 0){
                        cout<<g1<<endl;
                        cout<<g2<<endl;
                    }
                    else if(ty == 1){
                        cout<<p<<endl;
                    }
                    return 0;
                }
       
       a = g1;
       d = g2;
       int total = a+d;
       for(int x=1;x<=100000;x++){
           b = x;
           c = total - b;
                s.clear();
                s.insert(a);s.insert(b);s.insert(c);s.insert(d);
                it = s.begin();
                p = (*it);it++;
                q = (*it);it++;
                r = (*it);it++;
                ss = (*it);

                if(satisfy(p,q,r,ss)){
                    cout<<"YES"<<endl;
                    int ty = 0;
                    if(p != g1 && p!= g2){ty++;  cout<<p<<endl;}
                    if(q != g1 && q!=g2) {ty++; cout<<q<<endl;}
                    if(r != g1 && r!=g2){ty++;  cout<<r<<endl;}
                    if(ss != a && ss!=g2) {ty++; cout<<ss<<endl;}
                    if(ty == 0){
                        cout<<g1<<endl;
                        cout<<g2<<endl;
                    }
                    else if(ty == 1){
                        cout<<p<<endl;
                    }
                    return 0;
                }
       }

       b = g1;
       c = g2;
       for(int x=1;x<=100000/3;x++){
          a = x;
          d = 3*a;
                s.clear();
                s.insert(a);s.insert(b);s.insert(c);s.insert(d);
                it = s.begin();
                p = (*it);it++;
                q = (*it);it++;
                r = (*it);it++;
                ss = (*it);

                if(satisfy(p,q,r,ss)){
                    cout<<"YES"<<endl;
                    int ty = 0;
                    if(p != g1 && p!= g2){ty++;  cout<<p<<endl;}
                    if(q != g1 && q!=g2) {ty++; cout<<q<<endl;}
                    if(r != g1 && r!=g2){ty++;  cout<<r<<endl;}
                    if(ss != a && ss!=g2) {ty++; cout<<ss<<endl;}
                    if(ty == 0){
                        cout<<g1<<endl;
                        cout<<g2<<endl;
                    }
                    else if(ty == 1){
                        cout<<p<<endl;
                    }
                    return 0;
                }
       }

       b = g1;
       d = g2;
       if(d % 3 == 0){
        a = d/3;
        c = a+d-b;
                s.clear();
                s.insert(a);s.insert(b);s.insert(c);s.insert(d);
                it = s.begin();
                p = (*it);it++;
                q = (*it);it++;
                r = (*it);it++;
                ss = (*it);

                if(satisfy(p,q,r,ss)){
                    cout<<"YES"<<endl;
                    int ty = 0;
                    if(p != g1 && p!= g2){ty++;  cout<<p<<endl;}
                    if(q != g1 && q!=g2) {ty++; cout<<q<<endl;}
                    if(r != g1 && r!=g2){ty++;  cout<<r<<endl;}
                    if(ss != a && ss!=g2) {ty++; cout<<ss<<endl;}
                    if(ty == 0){
                        cout<<g1<<endl;
                        cout<<g2<<endl;
                    }
                    else if(ty == 1){
                        cout<<p<<endl;
                    }
                    return 0;
                }
       }
       cout<<"NO"<<endl;
    }
    else if(n == 3){
        int g1,g2,g3;
        cin>>g1>>g2>>g3;
        for(int i=1;i<=1000000;i++){
            s.clear();
            s.insert(g1);s.insert(g2);s.insert(g3);
            s.insert(i);
            it = s.begin();
            a = (*it);it++;
            b = (*it);it++;
            c = (*it);it++;
            d = (*it);
            if(satisfy(a,b,c,d)){
                cout<<"YES"<<endl;
                cout<<i<<endl;
                return 0;
            }
        }

        cout<<"NO"<<endl;
    }
    else if(n == 4){
        cin>>a>>b>>c>>d;
        s.clear();
        s.insert(a);s.insert(b);s.insert(c);s.insert(d);
        it = s.begin();
        a = (*it);it++;
        b = (*it);it++;
        c = (*it);it++;
        d = (*it);
        if(satisfy(a,b,c,d))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0; 
}

