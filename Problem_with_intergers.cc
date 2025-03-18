
// https://ac.nowcoder.com/acm/contest/1032/B



#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL tree_arr[500005];
LL a[500005];
int n,m;

void add(int x,int k)
{
    while(x<=n)
    {
        tree_arr[x]+=k;
        x+=(x&(-x));
    }
}


LL ask(int x)
{
    LL ret=0;
    while(x>0)
    {
        ret+=tree_arr[x];
        x-=(x&(-x));
    }
    return ret;
}



int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    while(m--)
    {
        char c;
        cin>>c;
        if(c=='Q')
        {
            LL x;
            cin>>x;
            cout<<a[x]+ask(x)<<endl;
        }
        else
        {
            LL l,r,d;
            cin>>l>>r>>d;
            add(l,d);
            if(r+1<=n)
                add(r+1,-d);
        }     
    }
    return 0;
}