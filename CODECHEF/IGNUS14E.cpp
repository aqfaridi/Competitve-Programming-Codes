#include<iostream>
#include<cstdio>
#define MAX 310
using namespace std;
struct A
{
	int a[MAX][MAX];
} mt[11];
int fun(int idx , int m)
{
	for(int i = 1 ; i < m ; i++)
		mt[idx].a[0][i] += mt[idx].a[0][i-1] ;
	for(int i = 1 ; i < m ; i++)
		mt[idx].a[i][0] += mt[idx].a[i-1][0];
	for(int i =1 ; i < m ; i++)
	{
		for(int j = 1 ; j < m ; j++)
		{
			mt[idx].a[i][j] = mt[idx].a[i][j] - mt[idx].a[i-1][j-1] + mt[idx].a[i-1][j] + mt[idx].a[i][j-1] ;
		}
	}
	/*for(int i = 0 ; i < m ; i++)
	{
	for(int j = 0 ; j < m ; j++)
	cout << mt[idx].a[i][j] << " " ;
	cout << endl ;
	}
	cout << "############################################################# " << endl ;*/
}
int query(int x1 , int y1 , int x2 , int y2 , int idx)
{
	int ans = 0;
	x1--;y1--;x2--;y2--;
	if(x1 == 0 and y1 != 0)
		ans = mt[idx].a[x2][y2] - mt[idx].a[x2][y1-1] ;
	else if(y1 == 0 and x1 != 0)
		ans = mt[idx].a[x2][y2] - mt[idx].a[x1-1][y2];
	else if(x1 == 0 and y1 == 0)
		ans = mt[idx].a[x2][y2] ;
	else
		ans = mt[idx].a[x2][y2] - mt[idx].a[x2][y1-1] - mt[idx].a[x1-1][y2] + mt[idx].a[x1-1][y1-1] ;
	
	return ans ;
}
int main()
{
	int n , val ,q , x1 , x2 , y1 , y2;
	int finalcount = 0;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n ; j++)
		{
			scanf("%d",&val);
			mt[val].a[i][j] = 1;
		}
	}
	for(int i = 1 ; i <= 10 ; i++)
		fun(i, n);
	scanf("%d",&q);
	while(q--)
	{
		finalcount = 0;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int i = 1 ; i <= 10 ; i++)
		{
			int vall = query(x1,y1,x2,y2,i);
			//cout << "val " << i << " " << vall << endl ;
			if(vall > 0)
				finalcount++ ;
		}
		printf("%d\n",finalcount);
	}
	return 0;
}
