// https://ac.nowcoder.com/acm/contest/95335/B

#include<bits/stdc++.h>
using namespace std;
vector<int> prime;
int arr[200005];
void init()
{
    for(int i=2;i<200005;++i)
    {
        if(arr[i]==0)
            prime.push_back(i);
        for(auto x:prime)
        {
            if(x*i<200005)
            {
                if(x<arr[x*i]||arr[x*i]==0)
                    arr[x*i]=x;
            }
            else break;
        }
    }
}
bool isprime(int x)
{
    return !arr[x];
}
bool vis[100005];
int main()
{
    init();
    //cout<<arr[4]<<endl;
    vector<int> ans;
    int n=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    list<int> lt;
    lt.push_back(0);
    for(int i=1;i<n;++i)
    {
        while(lt.size())
        {
            if(isprime(v[i]+v[lt.back()]))
            {   
                //cout<<i<<" "<<lt.back()<<endl;
                ans.push_back(lt.back()),lt.pop_back();
            }
            else break;
        }
        lt.push_back(i);
    }
    //cout<<lt.size()<<endl;
    int p=0;
    while(lt.size()!=1&&p<n)
    {
        if(lt.front()==p) lt.pop_back();
        while(lt.size())
        {
            if(isprime(v[p]+v[lt.back()]))
                ans.push_back(lt.back()),lt.pop_back();
            else break;
        }
        lt.push_back(p);
        p++;
    }
    if(lt.size()==1)
    {
        cout<<"Yes\n";
        vector<int> ret;
        ret.push_back(lt.back());
        vis[lt.back()]=true;
        for(int i=ans.size()-1;i>=0;--i)
        {
            if(vis[ans[i]]==false)
            {
                vis[ans[i]]=true;
                ret.push_back(ans[i]);
            }
        }
        for(int i=ret.size()-1;i>=0;--i)
            cout<<ret[i]<<" ";
    }
    else
    {
        cout<<"No";
    }
    
    
    return 0;
}