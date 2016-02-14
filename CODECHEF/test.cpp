#include<bits/stdc++.h>
using namespace std;
int elm[110];
int cnt[110];
int ar[200010];
typedef long long int ll;
#define MOD 1000000007
int scan_d() 
{
	int ip=getchar_unlocked(),ret=0,flag=1;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}
	for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';
	return flag*ret;
}
void println_d(int n) 
{
	if(n<0){n=-n;putchar_unlocked('-');}
	int i=10;
	char output_buffer[11];
	output_buffer[10]='\n';
	do{output_buffer[--i]=(n%10)+'0';
		n/=10;}while(n);
	do{putchar_unlocked(output_buffer[i]);
	}while(++i<11);
}
int modpow(ll a , ll b){
	ll x=1;
	while(b>0){
		if(b&1)
			x = (x*a)%MOD;
		a = (a*a)%MOD;
		b >>= 1;
	}
	return (x%MOD);
}
int main(){
	int n,t;
	t = scan_d();
	while(t--){
		n = scan_d();
		int mx = -1;int mn = INT_MAX;
		for(int i=1;i<=n;i++){
			ar[i] = scan_d();
			mx = max(mx,ar[i]);
			mn = min(mn,ar[i]);
		}
		int dmx = mx-mn ;
		int pos ;
		int ans = 0;
		for(int i=(-dmx);i<=dmx;i++){
          for(int j=0;j<=100;j++){elm[j]=0;cnt[j]=0;}
			for(int j=1;j<=n;j++){
				pos = 0;
				int  nm = ar[j]-i;
				if(nm>=0 && nm<=mx)
					pos = (elm[nm] + cnt[nm]);
				ans = (pos+ans)%MOD ;
				elm[ar[j]] = (elm[ar[j]] + pos)%MOD;
				cnt[ar[j]]++;
			}
		}
		int vl;
		vl = modpow(2,n);
		int fans = (vl - (ans+n+1) + MOD)%MOD;
		println_d(fans);
	}
	return 0;
}

