#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<vector<pair<int,int>>> query;
vector<int> ans;
vector<int> flag;
vector<int> vis;
vector<int> ufs;//父亲为零就是根


int FindRoot(int x)
{
    if(ufs[x]==0) return x;
    if(ufs[x])
    {
        int t=FindRoot(ufs[x]);
        ufs[x]=t;
    }
    return ufs[x];
}
void dfs(int x)
{
    flag[x]=1;
    for(auto [y,id]:query[x])
    {
        if(flag[y]==1) ans[id]=y;
        else if(flag[y]==2) ans[id]=FindRoot(y);
    }
    for(auto y:g[x])
    {
        if(!vis[y])
        {
            vis[y]=true;
            dfs(y);
            ufs[y]=x;
        }
    }
    flag[x]=2;
}
int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    g.resize(n+1);
    flag.resize(n+1);
    vis.resize(n+1);
    ufs.resize(n+1);
    query.resize(n+1);
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans.resize(m);
    for(int i=0;i<m;++i)
    {
        int x,y;
        cin>>x>>y;
        //cout<<i<<endl;
        query[x].push_back({y,i});
        query[y].push_back({x,i});
    }
    vis[s]=true;
    dfs(s);
    for(auto e:ans)
        cout<<e<<endl;
    return 0;
}