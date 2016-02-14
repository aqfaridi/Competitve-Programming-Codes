#include<iostream>
#include<cstdio>
using namespace std;
 
int owner[10010];
int s[10010];

int find(int n){
if(owner[n]==n) return n;
return owner[n]=find(owner[n]);
}
 
int main()
{
	 int t,n,q,temp,x,y,ans;
	 arr[0]=0;
	cin>>t;
	while(t--)
	{
        cin>>n;
		for(int i=1;i<n+1;i++)
		{
            cin>>s[i];
			arr[i]=i;
		}
        cin>>q;
		for(int i=0;i<q;i++)
		{
		    cin>>temp;	
			if(temp==0)
			{
                cin>>x>>y;
                int ownerx = find(x);
                int ownery = find(y);
				if(ownerx == ownery)
				{
					cout<<"Invalid query!"<<endl;
					continue;
				}
				if(s[ownerx]>s[ownery])	owner[ownery] = ownerx; 
				else if(s[ownerx]<s[ownery])	owner[ownerx] = ownery;
			}
			else
			{
				scanf("%d",&x);
				ans=find(x);
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
 
 
 
