#include <iostream>
#include<algorithm>
using namespace std;
#define MAX 1100001
long long M[MAX+1],store[MAX+1];
void Fibo()
{
    M[1]=0;M[2]=1;
    for(int i=3;i<=MAX;i++)
    	M[i]=(M[i-1]+M[i-2])%100000;
}
int main()
{
	ios::sync_with_stdio(false);
	int cases=0,k;
	Fibo();
	int t,A,B;
	cin>>t;
	while(t--)
	{
		cases++;
	    cin>>A>>B;
	    cout<<"Case "<<cases<<": ";
        k=0;
	    for(int i=A;i<=A+B;i++)
	        store[k++]=M[i];

        if(k>=100)
        {
	        partial_sort(store,store+100,store+k);
	    	cout<<store[0];
	    	for(int i=1;i<=99;i++)
	    		cout<<" "<<store[i];
	    }
	    else
	    {
            sort(store,store+k);
	    	cout<<store[0];
	    	for(int i=1;i<k;i++)
	    		cout<<" "<<store[i];
	    }
	    cout<<endl;
	}		

	return 0;
}
