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

#define MAX 10010
#define MOD 1000000007
int pre[MAX],post[MAX],in[MAX],idx[MAX];
struct node
{
    int data;
    node* left;
    node* right;
};
int preidx = 0;
node* build_tree(int i,int j)
{
    if(i>j)     return NULL;
    node* temp = new node;
    temp -> data = pre[preidx];
    preidx++;
    int mid = idx[temp -> data];
    temp -> left = build_tree(i,mid-1);
    temp -> right = build_tree(mid+1,j);
    return temp;
}
int verify[MAX],k=0;
void postorder(node* root)
{
    if(root != NULL)
    {
        postorder(root -> left);
        postorder(root -> right);
        verify[k++] = root -> data;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t,n;
    bool flag;
    t = 1;
    while(t--)
    {
        flag = true;
        cin>>n;
        rep(i,n)
            cin>>pre[i];
        rep(i,n)
            cin>>post[i];
        rep(i,n)
        {
            cin>>in[i];
            idx[in[i]] = i;
        }
        node* root = build_tree(0,n-1);
        postorder(root);
        rep(i,n)
        {
            if(post[i] != verify[i])
            {
                flag = false;
                break;
            }
        }
        if(flag) 
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0; 
}
