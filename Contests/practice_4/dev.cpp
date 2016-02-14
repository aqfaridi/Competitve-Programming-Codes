#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <cassert>
#include <vector>                              
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <ctime>
#include <stack>
#include <set>                                                          
#include <map>
using namespace std;
 
#define ll long long
#define ull unsigned ll                                                
#define inf 1000000000
#define INF 1000000000000000000ll
#define mp make_pair                                                                                 
#define pb push_back                                                 
#define F first
#define S second                                                                    
 
int n;	
int a[55];
int win;
long double cnt;
ll C[55][55];
long double SUM = 0, CNT = 0;
 
bool one(int mask, int pos){
	return (mask >> pos) & 1;
}
 
long double dp[55][(1 << 18) + 5];
long double d[40][40];
int spaces[55];
 
inline long double calc(const int &mx){
	spaces[0] = 1;
	for(int i = 1;i <= mx;++ i)
		spaces[i] = spaces[i - 1] + a[i];
	memset(d, 0, sizeof d);
	d[0][0] = 1;
	for(int it = 1;it <= mx;++ it){
		for(int cnt_pos = 1;cnt_pos <= a[it];++ cnt_pos){
			for(int cnt_bad = 0;cnt_bad <= spaces[it - 1];++ cnt_bad){
				if(!d[it - 1][cnt_bad])
					continue;
				for(int cur_bad = 0;cur_bad <= min(cnt_pos, cnt_bad);++ cur_bad){						
					int cur_good = cnt_pos - cur_bad;
					int cnt_good = spaces[it - 1] - cnt_bad;
					d[it][cnt_bad - cur_bad + a[it] - cnt_pos] += d[it - 1][cnt_bad] * C[a[it] - 1][cnt_pos - 1] * C[cnt_good][cur_good] * C[cnt_bad][cur_bad];
				}
			}
		}		
	}
	return d[mx][0];
	
}
 
inline long double solo(const int &n){
	long double res = 1;
	for(int i = 1;i <= n;++ i)
		res *= i;
	int cur = 0;
	for(int i = 1;i <= n;++ i){
		if(a[i] == a[i - 1]){
			++ cur;
			res /= cur;
		}
		else {
			cur = 1;
		}
	}
	return res;
}
  
int mx;

void rec(const int &pos = 1, const int &last = 1, const int &sum = 0){
	if(sum == n){
	    mx = a[pos - 1];
		win = pos - 1;
	    for(int i = pos - 1;i >= 1;-- i){            
	    	if(a[i] != mx){                          
	    		win = pos - i - 1;
	    		break;
	    	}
	    }
	    for(int i = pos;i <= n;++ i)
	    	a[i] = 0;
		cnt = calc(pos - 1);  
		cout<<cnt<<endl; 
	    cnt *= solo(pos - 1);
	    cnt *= C[n][pos - 1];
	    SUM += cnt * win;
	    CNT += cnt;
		return ;
	}
	for(int i = last;sum + i <= n && i <= n / 2 + (n & 1);++ i){
	    a[pos] = i;
		rec(pos + 1, i, sum + i);
	}
}

double ans[] = {0, 1.000000, 2.000000, 2.000000, 1.777778, 1.656250, 1.660800, 1.733668, 1.828592, 1.920742, 1.999589, 2.062219, 2.109256, 2.142717, 2.164972, 2.178301, 2.184725, 2.185964, 2.183446, 2.178343, 2.171597, 2.163963, 2.156033, 2.148263, 2.141000, 2.134497, 2.128932, 2.124422, 2.121035, 2.118798, 2.117709, 2.117741, 2.118848, 2.120971, 2.124043, 2.127988, 2.132728};
int t;
 
int main(){	                      

	scanf("%d", &t);
	C[0][0] = 1;
	for(int i = 1;i <= 36;++ i){
	    C[i][0] = C[i][i] = 1;
		for(int j = 0;j < i;++ j)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];					
	}
	while(t --){
		scanf("%d", &n);
		rec();
		cout<<SUM<<" "<<CNT<<endl;
		printf("%.6lf\n", ans[n]);
	}
	return 0;
} 