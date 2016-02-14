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
#define pn()				     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 210
#define MOD 1000000007
int perm[MAX],pos[MAX];
int adjMat[MAX][MAX];
int mem[MAX][MAX][MAX];
int floyd(int i,int j,int k){
	if(k == 0)	return adjMat[i][j];

	int& res = mem[i][j][k];
	if(res != -1)	return res;

	res = floyd(i,j,k-1) || (floyd(i,k,k-1) && floyd(k,j,k-1)); 
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	int t,n;
	string str;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>perm[i];
		pos[perm[i]] = i;
	}

	for(int i=0;i<n;i++){
		cin>>str;
		for(int j=0;j<n;j++)
			adjMat[i][j] = (str[j] == 'Y');
	}

	memset(mem,-1,sizeof mem);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			floyd(i,j,n-1);

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			adjMat[i][j] = mem[i][j][n-1];

	/*
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				adjMat[i][j] |= (adjMat[i][k] && adjMat[k][j]);
	for(int i=0;i<n;i++)
		adjMat[i][i] = 0;
	*/		
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(adjMat[pos[perm[i]]][pos[perm[j]]] && perm[j] < perm[i]){
				swap(pos[perm[i]],pos[perm[j]]);
				swap(perm[i],perm[j]);
			}

	for(int i=0;i<n;i++)
		cout<<perm[i]<<" ";
	cout<<endl;

	return 0; 
}