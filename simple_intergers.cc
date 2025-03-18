// https://ac.nowcoder.com/acm/contest/1032/C


#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL tree_a[100005];
LL tree_b[100005];
LL n,m;
void add(LL *arr,int x,LL d)
{
    while(x<=n)
    {
        arr[x]+=d;
        x+=(x&(-x));
    }
}

LL ask(LL *arr,LL x)
{
    
    LL ret=0;
    while(x>0)
    {
        ret+=arr[x];
        x-=(x&(-x));
    }
    return ret;
}

void C(int l,int r,LL k)//change num
{
    add(tree_a,l,k);
    if(r+1<=n)
        add(tree_a,r+1,-k);
    
    add(tree_b,l,l*k);
    if(r+1<=n)
        add(tree_b,r+1,-(r+1)*k);
}




LL Sum(LL x)
{
    if(x==0) return 0ll;
    return (x+1)*ask(tree_a,x)-ask(tree_b,x);
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        LL t=0;
        cin>>t;
        C(i,i,t);
    }
    while(m--)
    {
        char c;
        cin>>c;
        if(c=='C')
        {
            LL l,r,d;
            cin>>l>>r>>d;
            C(l,r,d);
        }
        else
        {
            LL l,r;
            cin>>l>>r;
            cout<<Sum(r)-Sum(l-1)<<endl;
        }
    }
    return 0;
}





