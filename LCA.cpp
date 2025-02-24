#include<bits/stdc++.h>
using namespace std;

int n,m,s;
vector<int> g[500005];
int f[500005][40];
int deepth[500005];
bool vis[500005];
int t=0;
void Init()
{
    //g.resize(n+1);
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    t=log(n)/log(2);
    //f.resize(n+1,vector<int>(t+1));
    //deepth.resize(n+1);
    //vector<bool> vis(n+1);
    queue<int> qe;
    deepth[s]=1;
    qe.push(s);
    vis[s]=true;
    while(!qe.empty())
    {
        int u=qe.front();
        qe.pop();
        for(auto v:g[u])
        {
            if(!vis[v])
            {

                deepth[v]=deepth[u]+1;
                f[v][0]=u;
                for(int i=1;i<=t;++i)
                    f[v][i]=f[f[v][i-1]][i-1];
                vis[v]=true;
                qe.push(v);
            }
        }
    }    
}


int Lcd(int x,int y)
{
    if(deepth[x]<deepth[y]) swap(x,y);
    for(int i=t;i>=0;--i)
    {
        if(deepth[f[x][i]]>=deepth[y]) x=f[x][i];
    }
    if(x==y) return y;
    for(int i=t;i>=0;--i)
    {
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    }
    return f[x][0];
}
int main()
{
    cin>>n>>m>>s;
    Init();
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        cout<<Lcd(x,y)<<endl;
    }
    return 0;
}