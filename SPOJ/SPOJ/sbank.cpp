#include <iostream>
#include <cstdio>
#include <climits>
#include <utility>
#include <map>
#define MAX 1000010
using namespace std;
map<string,int> m;
int main()
{
    int t,n;
    string str;
    pair<map<string,int>::iterator,bool> ret;
    map<string,int>::iterator it;
    scanf("%d",&t);
    while(t--)
    {
        m.clear();
        scanf("%d",&n);
        getline(cin,str);
        for(int i=0;i<n;i++)
        {
            getline(cin,str);
            ret = m.insert(make_pair(str,1));
            if(ret.second == false)//already present key
                (ret.first)->second += 1;

        }
        for(it = m.begin();it!=m.end();it++)
            cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    return 0;
}

