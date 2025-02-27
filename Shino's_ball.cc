// https://ac.nowcoder.com/acm/problem/286117

#include<bits/stdc++.h>
using namespace std;

vector<size_t> v;//往右走
vector<size_t> u;
size_t count_pairs(size_t t)
{
    size_t result=0;
    int p1=0,p2=0;
    for(auto x:v)
    {
        while(p1<u.size()&&u[p1]<x) p1++;
        while(p2<u.size()&& x+t >=u[p2]) p2++;
        result+=(p2-p1);
//         cout<<result<<endl;
    }
    return result;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        int p,vi;
        cin>>p>>vi;
        if(vi>0)
            v.push_back(p);
        else
            u.push_back(p);
    }
//     count_pairs(8);
//     return 0;
    sort(u.begin(),u.end());
    sort(v.begin(),v.end());
    long long l=0,r=INT_MAX;
    if(k>count_pairs(r))
    {
        printf("No");
        return 0;
    }
    while(l<r)
    {
        size_t mid=(l+r)/2;
        size_t num = count_pairs(mid);
//         printf("mid: %d, num: %d\n",mid,num);
        if(num>=k) r=mid;
        else l=mid+1;
    }
    cout<<"Yes\n";
    size_t ans=l;
    if(ans%2==0)
        printf("%d.000000",ans/2);
    else
        printf("%d.500000",ans/2);
    return 0;
}
