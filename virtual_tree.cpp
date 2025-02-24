#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> g;
//vector<int> dist;
vector<int> deepth;
vector<vector<int>> lcd_array;
vector<vector<int>> st;
vector<int> dfs_p;
vector<int> dfs_cmp;

int n=0;
int log_t=0;
vector<bool> vis;
void dfs(int x)
{
    vis[x]=true;
    dfs_p.push_back(x);
    for(auto [y,w]:g[x])
        if(!vis[y])
        {
            //dist[y]=dist[x]+w;
            deepth[y]=deepth[x]+1;
            lcd_array[y][0]=x;
            st[y][0]=w;
            for(int i=1;i<=log_t;++i)
            {
                lcd_array[y][i]=lcd_array[lcd_array[y][i-1]][i-1];
                st[y][i]=min(st[y][i-1],st[lcd_array[y][i-1]][i-1]);
            }
            dfs(y);
        }
}
int Lcd(int x,int y)
{
    if(deepth[x]<deepth[y]) swap(x,y);
    for(int i=log_t;i>=0;--i)
    {
        if(deepth[lcd_array[x][i]]>=deepth[y])
            x=lcd_array[x][i];
    }
    if(x==y) return y;
    for(int i=log_t;i>=0;--i)
    {
        if(lcd_array[x][i]!=lcd_array[y][i])
            x=lcd_array[x][i],y=lcd_array[y][i];
    }
    return lcd_array[x][0];
}
void Init()
{
    dfs_cmp.resize(n+1);
    for(int i=0;i<dfs_p.size();++i)
        dfs_cmp[dfs_p[i]]=i;
}

bool cmp_function(int x,int y)
{
    return dfs_cmp[x]<dfs_cmp[y];
}
unordered_map<int,vector<int>> ump; //存虚树
unordered_set<int> tmp;    //存关键节点
vector<size_t> dp;
void solve_dfs(int x)
{
    size_t ret=0;
    for(auto v:ump[x])
    {
        solve_dfs(v);
        //int d= INT_MAX;
        int len=log(deepth[v]-deepth[x])/log(2);
        int targetdeepth=deepth[x]+(1<<len);
        int targetpoint=v;
        for(int i=log_t;i>=0;--i)
        {
            if(deepth[lcd_array[targetpoint][i]]>=targetdeepth) 
                targetpoint=lcd_array[targetpoint][i];
        }
        size_t d=min(st[v][len],st[targetpoint][len]);
        if(tmp.count(v))
        {
            ret=ret+d;
        }
        else
            ret=ret+min(dp[v],d);
    }
    dp[x]=ret;
}




void solve(vector<int>& v)
{
    tmp=unordered_set(v.begin(),v.end());
    sort(v.begin(),v.end(),cmp_function);
    //求最小公共祖先
    int l=v.size();
    for(int i=0;i<l-1;++i)
        v.push_back(Lcd(v[i],v[i+1]));
    v.push_back(1);
    sort(v.begin(),v.end(),cmp_function);
    int left=0,right=1;
    while(right<v.size())
    {
        if(v[right]!=v[left])
            v[++left]=v[right];
        right++;
    }
    v.resize(left+1);

    for(int i=0;i<v.size()-1;++i)
    {
        int father=Lcd(v[i],v[i+1]);
        ump[father].push_back(v[i+1]);
    }
    solve_dfs(1);
    cout<<dp[1]<<endl;
}


int main()
{
    cin>>n;
    log_t=log(n)/log(2);
    g.resize(n+1);
    vis.resize(n+1);
    //dist.resize(n+1);
    deepth.resize(n+1);
    st.resize(n+1,vector<int>(30));
    dp.resize(n+1);
    lcd_array.resize(n+1,vector<int>(30));
    for(int i=1;i<n;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    deepth[1]=1;
    dfs(1);
    Init();
    int m=0;
    cin>>m;
    for(int i=0;i<m;++i)
    {
        vector<int> v;
        int k=0;
        cin>>k;
        //cout<<"hello\n";
        for(int j=0;j<k;++j)
        {
            int h=0;
            cin>>h;
            v.push_back(h);
        }
        //cout<<"world\n";
        solve(v);
        ump.clear();
        tmp.clear();
    }
    return 0;
}