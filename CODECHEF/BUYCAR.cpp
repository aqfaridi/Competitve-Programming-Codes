#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath> 
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int main()
{
    int t,n;
    int cost,tax;
    double taxx;
    cin>>t;
    while(t--)
    {
        cost = tax = 0;
        cin>>n;
        map<double,string> m;
        string str,name,cst1,cst,tx,sub;
        char ch = getchar();
        for(int i=0;i<n;i++)
        {
            tax = 0;
            getline(cin,str);
            stringstream ss(str);
            ss>>name;
            ss>>cst;
            ss>>tx;
            cst1 = cst.substr(1);
            stringstream os(cst1);
            os>>cost;
            int l = tx.length();
            for(int i=0;i<l-1;i++)
                tax = tax*10 + (tx[i]-'0');
            taxx = ((1.0*tax)/100 * (1.0*cost));
            m[taxx+cost] = name;
            cout<<name<<" "<<taxx+cost<<endl;
        }
        map<double,string>::iterator it; 
    //    it = m.end();it--;
      //  cout<<it->second<<endl;
        
        for(it=m.begin();it!=m.end();it++)
        {
            cout<<it->first<<" "<<it->second<<endl;
        }
        
        
    }
    return 0;
}
