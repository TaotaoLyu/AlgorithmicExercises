#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int id;
    int child[26];
};

int cnt[100005];   //
Node tree[1000005];
int n,m;
int root=1;
int num=1;
void add(int x,int k)
{
    while(x<=n)
    {
        cnt[x]+=k;
        x+=(x&(-x));
    }
}
int ask(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=cnt[x];
        x-=(x&(-x));
    }
    return ret;
}

void InsertTree(string& s,int id)
{
    int rt=root;
    for(auto c:s)
    {
        if(tree[rt].child[c-'a']==0)
        {
            tree[rt].child[c-'a']=++num;
            rt=tree[rt].child[c-'a'];
            tree[rt].id=id;
            add(id,1);
        }
        else
        {
            rt=tree[rt].child[c-'a'];
            add(tree[rt].id,-1);
            tree[rt].id=id;
            add(id,1);
        }
    }   
}
int main()
{
    cin>>n>>m;
    vector<string> v(n+1);
    vector<int> ans(m);
    for(int i=1;i<=n;++i) cin>>v[i];
    // [left,id]
    vector<vector<pair<int,int>>> query(n+1,vector<pair<int,int>>());
    for(int i=0;i<m;++i)
    {
        int l,r;
        cin>>l>>r;
        query[r].push_back({l,i});
    }
    vector<pair<int,int>> stk; //[id,len]
    for(int i=1;i<=n;++i)
    {
        int len=v[i].size();
        while(stk.size()&&stk.back().second<=len)
            stk.pop_back();
        stk.push_back({i,len});
        InsertTree(v[i],i);
        for(auto &[l,id]:query[i])
        {
            int maxlen=lower_bound(stk.begin(),stk.end(),make_pair(l,0))->second;
            ans[id]=(ask(i)-ask(l-1))*2-maxlen;
        }
        
    }
    for(auto e:ans)
        cout<<e<<"\n";
    return 0;
}







