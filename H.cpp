#include<bits/stdc++.h>
using namespace std;
struct mypair
{
    int l;
    int r;
    int num;
};

int main()
{
    int n=0;
    cin>>n;
    vector<mypair> v(n);
    for(int i=0;i<n;++i)
    {
        int l,r;
        cin>>l>>r;
        v[i].l=l;
        v[i].r=r;
        v[i].num=i;
    }
    sort(v.begin(),v.end(),[](const mypair& p1,const mypair&p2){
        if(p1.r!=p2.r) return p1.r<p2.r;
        else
        {
            int len1=p1.r-p1.l+1;
            int len2=p2.r-p2.l+1;
            return len1>len2;
        }
    });
    vector<int> ans(n);
    int i=1;
    for(auto& p:v)
    {
        if(i<p.l||i>p.r)
        {
            cout<<-1;
            return 0;
        }
        ans[p.num]=i++;
    }
    for(auto x:ans) cout<<x<<" ";
}