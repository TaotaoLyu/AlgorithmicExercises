// https://ac.nowcoder.com/acm/problem/51001

//monotonous queue  单调队列

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    deque<pair<int,int>> dqe;
    for(int i=0;i<k-1;++i)
    {
        while(dqe.size()&&dqe.back().first>v[i])
            dqe.pop_back();
        dqe.push_back({v[i],i});
    }
    for(int i=k-1;i<n;++i)
    {
        while(dqe.size()&&dqe.front().second<i-k+1)
            dqe.pop_front();
        while(dqe.size()&&dqe.back().first>v[i])
            dqe.pop_back();
        dqe.push_back({v[i],i});
        cout<<dqe.front().first<<" ";
    }
    dqe.clear();
    cout<<endl;
    for(int i=0;i<k-1;++i)
    {
        while(dqe.size()&&dqe.back().first<v[i])
            dqe.pop_back();
        dqe.push_back({v[i],i});
    }
    for(int i=k-1;i<n;++i)
    {
        while(dqe.size()&&dqe.front().second<i-k+1)
            dqe.pop_front();
        while(dqe.size()&&dqe.back().first<v[i])
            dqe.pop_back();
        dqe.push_back({v[i],i});
        cout<<dqe.front().first<<" ";
    } 
    return 0;
}