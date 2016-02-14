#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_1(i, a, b) for (int i=int(a);i<=int(b);++i)
#define DWN_1(i, b, a) for (int i=int(b);i>=int(a);--i)
#define REP_C(i, n) for (int n____=int(n),i=0;i<n____;++i)
#define FOR_C(i, a, b) for (int b____=int(b),i=a;i<b____;++i)
#define DWN_C(i, b, a) for (int a____=int(a),i=b-1;i>=a____;--i)
#define REP_N(i, n) for (i=0;i<int(n);++i)
#define FOR_N(i, a, b) for (i=int(a);i<int(b);++i)
#define DWN_N(i, b, a) for (i=int(b-1);i>=int(a);--i)
#define REP_1_C(i, n) for (int n____=int(n),i=1;i<=n____;++i)
#define FOR_1_C(i, a, b) for (int b____=int(b),i=a;i<=b____;++i)
#define DWN_1_C(i, b, a) for (int a____=int(a),i=b;i>=a____;--i)
#define REP_1_N(i, n) for (i=1;i<=int(n);++i)
#define FOR_1_N(i, a, b) for (i=int(a);i<=int(b);++i)
#define DWN_1_N(i, b, a) for (i=int(b);i>=int(a);--i)
#define REP_C_N(i, n) for (n____=int(n),i=0;i<n____;++i)
#define FOR_C_N(i, a, b) for (b____=int(b),i=a;i<b____;++i)
#define DWN_C_N(i, b, a) for (a____=int(a),i=b-1;i>=a____;--i)
#define REP_1_C_N(i, n) for (n____=int(n),i=1;i<=n____;++i)
#define FOR_1_C_N(i, a, b) for (b____=int(b),i=a;i<=b____;++i)
#define DWN_1_C_N(i, b, a) for (a____=int(a),i=b;i>=a____;--i)

#define ECH(it, A) for (typeof(A.begin()) it=A.begin(); it != A.end(); ++it)
#define DO(n) while(n--)
#define DO_C(n) int n____ = n; while(n____--)
#define TO(i, a, b) int s_=a<b?1:-1,b_=b+s_;for(int i=a;i!=b_;i+=s_)
#define TO_1(i, a, b) int s_=a<b?1:-1,b_=b;for(int i=a;i!=b_;i+=s_)
#define SQZ(i, j, a, b) for (int i=int(a),j=int(b)-1;i<j;++i,--j)
#define SQZ_1(i, j, a, b) for (int i=int(a),j=int(b);i<=j;++i,--j)
#define REP_2(i, j, n, m) REP(i, n) REP(j, m)
#define REP_2_1(i, j, n, m) REP_1(i, n) REP_1(j, m)

#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define BSC(A, X) fP(ALL(A), X) // != A.end()
#define CTN(T, x) (T.fP(x) != T.end())
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

#define Rush int T____; RD(T____); DO(T____)
#pragma comment(LNKer, "/STACK:36777216")
//#pragma GCC optimize ("O2")
#define Ruby system("ruby main.rb")
#define Haskell system("runghc main.hs")
#define Pascal system("fpc main.pas")

typedef long long LL;
typedef double DB;
typedef unsigned UINT;
typedef unsigned long long ULL;

typedef vector<int> VI;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VD;
typedef set<int> SI;
typedef set<string> SS;
typedef set<LL> SL;
typedef set<DB> SD;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<LL, int> MLI;
typedef map<DB, int> MDI;
typedef map<int, bool> MIB;
typedef map<string, bool> MSB;
typedef map<LL, bool> MLB;
typedef map<DB, bool> MDB;
typedef pair<int, int> PII;
typedef pair<int, bool> PIB;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
typedef set<PII> SII;
typedef map<PII, int> MPIII;
typedef map<PII, bool> MPIIB;

/** I/O Accelerator **/

/* ... :" We are I/O Accelerator ... Use us at your own risk ;) ... " .. */

template<class T> inline void RD(T &);
template<class T> inline void OT(const T &);

inline int RD(){ int x; RD(x); return x;}
template<class T> inline T& _RD(T &x){ RD(x); return x;}
inline void RC(char &c){scanf(" %c", &c);}
inline char RC(){ char x; RC(x); return x;}
inline void RS(char *s){scanf("%s", s);}

template<class T0, class T1> inline void RD(T0 &x0, T1 &x1){RD(x0), RD(x1);}
template<class T0, class T1, class T2> inline void RD(T0 &x0, T1 &x1, T2 &x2){RD(x0), RD(x1), RD(x2);}
template<class T0, class T1, class T2, class T3> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3){RD(x0), RD(x1), RD(x2), RD(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6);}
template<class T0, class T1> inline void OT(T0 &x0, T1 &x1){OT(x0), OT(x1);}
template<class T0, class T1, class T2> inline void OT(T0 &x0, T1 &x1, T2 &x2){OT(x0), OT(x1), OT(x2);}
template<class T0, class T1, class T2, class T3> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3){OT(x0), OT(x1), OT(x2), OT(x3);}
template<class T0, class T1, class T2, class T3, class T4> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6){OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);}

template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T0, class T1> inline void RST(T0 &A0, T1 &A1){RST(A0), RST(A1);}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3){RST(A0), RST(A1), RST(A2), RST(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5), RST(A6);}


template<class T> inline void CLR(priority_queue<T, vector<T>, less<T> > &Q){
    while (!Q.empty()) Q.pop();
}

template<class T> inline void CLR(priority_queue<T, vector<T>, greater<T> > &Q){
    while (!Q.empty()) Q.pop();
}

template<class T> inline void CLR(T &A){A.clear();}
template<class T0, class T1> inline void CLR(T0 &A0, T1 &A1){CLR(A0), CLR(A1);}
template<class T0, class T1, class T2> inline void CLR(T0 &A0, T1 &A1, T2 &A2){CLR(A0), CLR(A1), CLR(A2);}
template<class T0, class T1, class T2, class T3> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3){CLR(A0), CLR(A1), CLR(A2), CLR(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void CLR(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){CLR(A0), CLR(A1), CLR(A2), CLR(A3), CLR(A4), CLR(A5), CLR(A6);}
template<class T> inline void CLR(T &A, int n){REP(i, n) CLR(A[i]);}
template<class T> inline void FLC(T &A, int x){memset(A, x, sizeof(A));}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, int x){FLC(A0, x), FLC(A1, x);}
template<class T0, class T1, class T2> inline void FLC(T0 &A0, T1 &A1, T2 &A2){FLC(A0), FLC(A1), FLC(A2);}
template<class T0, class T1, class T2, class T3> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3){FLC(A0), FLC(A1), FLC(A2), FLC(A3);}
template<class T0, class T1, class T2, class T3, class T4> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4);}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5);}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void FLC(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5, T6 &A6){FLC(A0), FLC(A1), FLC(A2), FLC(A3), FLC(A4), FLC(A5), FLC(A6);}

template<class T> inline void SRT(T &A){sort(ALL(A));}
template<class T, class C> inline void SRT(T &A, C B){sort(ALL(A), B);}

/** Add - On **/

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const DB EPS = 1e-9;
const DB OO = 1e15;
const DB PI = 3.14159265358979323846264; //M_PI;

// <<= ` 0. Daily Use .,

template<class T> inline void checkMin(T &a,const T b){if (b<a) a=b;}
template<class T> inline void checkMax(T &a,const T b){if (b>a) a=b;}
template <class T, class C> inline void checkMin(T& a, const T b, C c){if (c(b,a)) a = b;}
template <class T, class C> inline void checkMax(T& a, const T b, C c){if (c(a,b)) a = b;}
template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> inline T min(T a, T b, T c, T d){return min(min(a, b), min(c, d));}
template<class T> inline T max(T a, T b, T c, T d){return max(max(a, b), max(c, d));}
template<class T> inline T sqr(T a){return a*a;}
template<class T> inline T cub(T a){return a*a*a;}
int Ceil(int x, int y){return (x - 1) / y + 1;}

// <<= ` 1. Bitwise Operation .,
inline bool _1(int x, int i){return x & 1<<i;}
inline bool _1(LL x, int i){return x & 1LL<<i;}
inline LL _1(int i){return 1LL<<i;}
//inline int _1(int i){return 1<<i;}
inline LL _U(int i){return _1(i) - 1;};
//inline int _U(int i){return _1(i) - 1;};


template<class T> inline T low_bit(T x) {
    return x & -x;
}

template<class T> inline T high_bit(T x) {
    T p = low_bit(x);
    while (p != x) x -= p, p = low_bit(x);
    return p;
}

inline int count_bits(int x){
    x = (x & 0x55555555) + ((x & 0xaaaaaaaa) >> 1);
    x = (x & 0x33333333) + ((x & 0xcccccccc) >> 2);
    x = (x & 0x0f0f0f0f) + ((x & 0xf0f0f0f0) >> 4);
    x = (x & 0x00ff00ff) + ((x & 0xff00ff00) >> 8);
    x = (x & 0x0000ffff) + ((x & 0xffff0000) >> 16);
    return x;
}

inline int count_bits(LL x){
    x = (x & 0x5555555555555555LL) + ((x & 0xaaaaaaaaaaaaaaaaLL) >> 1);
    x = (x & 0x3333333333333333LL) + ((x & 0xccccccccccccccccLL) >> 2);
    x = (x & 0x0f0f0f0f0f0f0f0fLL) + ((x & 0xf0f0f0f0f0f0f0f0LL) >> 4);
    x = (x & 0x00ff00ff00ff00ffLL) + ((x & 0xff00ff00ff00ff00LL) >> 8);
    x = (x & 0x0000ffff0000ffffLL) + ((x & 0xffff0000ffff0000LL) >> 16);
    x = (x & 0x00000000ffffffffLL) + ((x & 0xffffffff00000000LL) >> 32);
    return x;
}

int reverse_bits(int x){
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xaaaaaaaa);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xcccccccc);
    x = ((x >> 4) & 0x0f0f0f0f) | ((x << 4) & 0xf0f0f0f0);
    x = ((x >> 8) & 0x00ff00ff) | ((x << 8) & 0xff00ff00);
    x = ((x >>16) & 0x0000ffff) | ((x <<16) & 0xffff0000);
    return x;
}

LL reverse_bits(LL x){
    x = ((x >> 1) & 0x5555555555555555LL) | ((x << 1) & 0xaaaaaaaaaaaaaaaaLL);
    x = ((x >> 2) & 0x3333333333333333LL) | ((x << 2) & 0xccccccccccccccccLL);
    x = ((x >> 4) & 0x0f0f0f0f0f0f0f0fLL) | ((x << 4) & 0xf0f0f0f0f0f0f0f0LL);
    x = ((x >> 8) & 0x00ff00ff00ff00ffLL) | ((x << 8) & 0xff00ff00ff00ff00LL);
    x = ((x >>16) & 0x0000ffff0000ffffLL) | ((x <<16) & 0xffff0000ffff0000LL);
    x = ((x >>32) & 0x00000000ffffffffLL) | ((x <<32) & 0xffffffff00000000LL);
    return x;
}


// <<= ' A. Random Event ..

inline int rand32(){return (bool(rand() & 1) << 30) | (rand() << 15) + rand();}
inline int random32(int l, int r){return rand32() % (r - l + 1) + l;}
inline int random(int l, int r){return rand() % (r - l + 1) + l;}
int dice(){return rand() % 6;}
bool coin(){return rand() % 2;}

// <<= ' 0. I/O Accelerator interface .,

template<class T> inline void RD(T &x){
    //cin >> x;
    //scanf("%d", &x);

    char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
}

template<class T> inline void OT(const T &x){
    printf("%d\n", x);
}

/* .................................................................................................................................. */

const int N = 100009, M = 2 * N;

struct Rec{
    int id, pos, val;
    Rec(int _id, int _pos, int _val):id(_id), pos(_pos), val(_val){};
}; vector<Rec> L[N];
// Host info

int hd[N], prd[M], suc[M], to[M];
// Adjcent List .. .

int sz[N]; bool vis[N], black[N];
// Vertex

int n, c, _c;

#define lx (x<<1)
#define rx (lx|1)
#define y (x>>1)


struct Heap{

    VI B; int *H, *P;
    int n;

private:

    inline int A(int x){return B[H[x]];}

    void Swap(int a, int b){
        swap(H[a], H[b]);
        P[H[a]] = a, P[H[b]] = b;
    }

    inline void Up(int x){
        while (A(y) > A(x)){
            Swap(x, y), x = y;
        }
    }

    inline void Down(int x){

        int h = x; while (true){
            if (lx <= n && A(lx) < A(h)) h = lx;
            if (rx <= n && A(rx) < A(h)) h = rx;
            if (h == x) break;
            Swap(h, x), x = h;
        }
    }

public:

    void Build(){
        n = SZ(B); H = new int[n], P = new int[n]; --n;
        FOR_1(i, 0, n) H[i] = P[i] = i; DWN_1(i, n>>1, 1) Down(i);
    }

    void Update(int x, int v){
        if (B[x] > v) B[x] = v, Up(P[x]);
        else B[x] = v, Down(P[x]);
    }

    int top(){
        return A(1);
    }

} H[2*N], Q;

#undef y

inline void del(int x){
    if (x == hd[to[x^1]]) prd[hd[to[x^1]] = suc[x]] = 0;
    else suc[prd[suc[x]] = prd[x]] = suc[x];
}

#define TRA(i, x) for(int i=hd[x];i;i=suc[i])
#define v to[i]
#define t abs(nn - (sz[v]<<1))

void dfs1(int u, int nn){

    vis[u] = true, sz[u] = 1;

    TRA(i, u) if (!vis[v]){
        dfs1(v, nn), sz[u] += sz[v];
        if (t < _c) _c = t, c = i;
    }
    vis[u] = false;
}

#undef t

void dfs2(int u, int d = 0){

    vis[u] = true, sz[u] = 1;
    L[u].PB(Rec(c, SZ(H[c].B), d)); H[c].B.PB(INF);

    TRA(i, u) if (!vis[v]){
        dfs2(v, d + 1);
        sz[u] += sz[v];
    }
    vis[u] = false;
}

#undef v
#define v to[c]

// Divide && Conquer by Edge ..
void DCE(int u = 1, int nn = n){
    _c = INF, dfs1(u, nn); if (_c != INF){
        int w = v; del(c), del(c^1), dfs2(v), c ^= 1; dfs2(v);
        DCE(v, sz[v]); DCE(w, sz[w]);
    }
}

#undef v

#define a L[u][i].id
#define b L[u][i].pos
#define c L[u][i].val

void Modify(int u){
    if (!black[u]) REP(i, SZ(L[u])) H[a].Update(b, INF);
    else REP(i, SZ(L[u])) H[a].Update(b, c);
    black[u] ^= 1;
}

int Query(int u){
    if (!black[u]) return 0;
    int res = INF; REP(i, SZ(L[u])) checkMin(res, c + 1 + H[a^1].top());
    return res == INF ? -1 : res;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif

    FOR_C(i, 2, _RD(n) << 1){
        RD(to[i], to[i|1]);
        prd[hd[to[i^1]]] = i, suc[i] = hd[to[i^1]], hd[to[i^1]] = i, ++i;
        prd[hd[to[i^1]]] = i, suc[i] = hd[to[i^1]], hd[to[i^1]] = i;
    }

    FLC(black, true); FOR(i, 2, n << 1) H[i].B.PB(-INF); // offset .. .
    DCE(); FOR(i, 2, 2 * n) H[i].Build(); // divide && conquer by edge ..

    Rush{
        if (RD()) OT(Query(RD()));
        else Modify(RD());
    }
}