// https://ac.nowcoder.com/acm/problem/286121


#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

//计算n的余数中大于等于n的有几个
LL count(LL mid,LL n)
{
    LL ret=0;
    //对n进行分段
    for(LL l=1,r;l<=n;l=r+1)
    {
        // n/l是这一段的商
        r=n/(n/l);
        LL k=n/l;//公差
        LL maxnum=n%l;
        if(mid>maxnum) continue;
        // mid有可能比这一段的最小值还小
        ret+=min(r-l+1,(maxnum-mid)/k+1);
    }
    return ret; 
}


int main()
{
    LL n=0,k=0;
    cin>>n>>k;
    LL l=0,r=n-1;
    LL nowk=0;
    while(l<r)
    {
        LL mid=(l+r+1)/2;
        LL total=count(mid,n);
        if(total<k) r=mid-1;
        else
        {
            nowk=total;
            l=mid;
        }    
    }
    LL num=l;
    //计算每段大于num的和
    LL ans=0;
    for(LL l=1,r;l<=n;l=r+1)
    {
        // n/l是这一段的商
        r=n/(n/l);
        LL k=n/l;//公差
        LL maxnum=n%l;
        if(num>maxnum) continue;
        LL total=min(r-l+1,(maxnum-num)/k+1);
        ans+=(2*maxnum-(total-1)*k)*total/2;
    }
    ans-=num*(nowk-k);
    cout<<ans;
    return 0;
}
