
// https://ac.nowcoder.com/acm/contest/1032/A

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL cnt[200005];// this is tree
int n=0;


void add(int x) //update tree
{
    while(x<=n)
    {
        cnt[x]++;
        x+=(x&(-x));
    }
}
LL preSum(int x)
{
    LL ret=0;
    while(x)
    {
        ret+=cnt[x];
        x-=(x&(-x));
    }
    return ret;
}

pair<LL,LL> ansleft[200005];// [small,big]
pair<LL,LL> ansright[200005];// [small,big]
int main()
{
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;++i)
    {
        add(v[i]);
        ansleft[i].first=preSum(v[i]-1);
        ansleft[i].second=i-ansleft[i].first;
    }
    memset(cnt,0,sizeof cnt);
    for(int i=n-1;i>=0;--i)
    {
        add(v[i]);
        ansright[i].first=preSum(v[i]-1);
        ansright[i].second=n-1-i-ansright[i].first;
    }
    LL ans1=0,ans2=0;
    for(int i=0;i<n;++i)
    {
        ans1+=ansleft[i].second*ansright[i].second;
        ans2+=ansleft[i].first*ansright[i].first;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}