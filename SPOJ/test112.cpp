#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
int main(){int t,cnt;LL n;while(scanf("%lld",&n)!=EOF){cnt = 0;LL SQR = sqrt(n);for(LL b=SQR;b>=0;b--){LL a = sqrt(n - b*b);if(a>b)break;if(a*a + b*b == n){cnt++;}} cout<<cnt<<endl;}return  0;}
