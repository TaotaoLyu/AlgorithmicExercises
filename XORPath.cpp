#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> tree;
vector<int> D;
vector<bool> vis;
void dfs(int x)
{
    for(auto& p:tree[x])
    {
        if(!vis[p.first])
        {
            D[p.first]=D[x]^p.second;
            vis[p.first]=true;
            dfs(p.first);
        }
    }
}

struct Node
{
    int left_=-1;   //标记0
    int right_=-1;  //标记1
};
vector<Node> arr;
int num=1;
int P_=0;
unsigned int ans=0;
void Insert(int x)
{
    int P=P_;
    for(int i=31;i>=0;--i)
    {
        if(((x>>i)&1)==0)
        {
            if(arr[P].left_==-1)
                arr[P].left_=num++;
            P=arr[P].left_;
        }
        else
        {
            if(arr[P].right_==-1)
                arr[P].right_=num++;
            P=arr[P].right_;
        }
    }
}
unsigned int FindMax(int x)
{
    int P=P_;
    unsigned int ret=0;
    for(int i=31;i>=0;--i)
    {
        if((x>>i)&1)
        {
            if(arr[P].left_!=-1)
            {
                ret=ret|(1<<i);
                P=arr[P].left_;
            }
            else
                P=arr[P].right_;
        }
        else
        {
            if(arr[P].right_!=-1)
            {
                ret=ret|(1<<i);
                P=arr[P].right_;
            }
            else
                P=arr[P].left_;
        }
    }
    return ret;
}
int main()
{
    int n=0;
    cin>>n;
    tree.resize(n);
    arr.resize(3200005);
    D.resize(n);
    vis.resize(n);
    for(int i=0;i<n-1;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        tree[u].push_back({v,w});
        tree[v].push_back({u,w});
    }
    vis[0]=true;
    dfs(0);
    Insert(D[0]);
    for(int i=1;i<D.size();++i)
    {
        int a=D[i];
        ans=max(ans,FindMax(a));
        Insert(a);
    }
    cout<<ans;
    return 0;
}