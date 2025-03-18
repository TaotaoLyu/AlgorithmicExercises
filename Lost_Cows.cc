// https://ac.nowcoder.com/acm/contest/1032/D

#include<bits/stdc++.h>
using namespace std;

int tree_a[10000];

void change(int x,int d)
{
    while(x<10000)
    {
        tree_a[x]+=d;
        x+=(x&(-x));
    }
}
int ask(int x)
{
    
    int ret=0;
    while(x>0)
    {
        ret+=tree_a[x];
        x-=(x&(-x));
    }
    return ret;
}

int main()
{
    int n=0;
    cin>>n;
    vector<int> v(n+1);
    vector<int> ans(n+1);
    for(int i=2;i<=n;++i)
        cin>>v[i];
    for(int i=1;i<=n;++i)
        change(i,1);
    for(int i=n;i>=1;--i)
    {
        int num=v[i]+1;
        int l=1,r=n;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(ask(mid)>=num)
                r=mid;
            else
                l=mid+1;
        }
        ans[i]=l;
        change(l, -1);
    }
    for(int i=1;i<=n;++i)
    {
        cout<<ans[i]<<'\n';
    }     
    return 0;
}