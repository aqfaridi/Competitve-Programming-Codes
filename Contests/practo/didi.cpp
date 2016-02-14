#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,sum,i;
    scanf("%d",&n);
    sum=0;
    if(n==3){
    	int m=0;
    	for(i=0;i<3;i++){
    		scanf("%d",&x);
    		if(x>m)	m=x;
    	}	
    	cout<<m<<endl;
    }else{
	    for(i=0;i<n;i++){
	    	scanf("%d",&x);
	    	sum+=x;
	    }
	    int y=ceil(sum/3.0);
	    cout<<y<<endl;
    }
    return 0;
}
