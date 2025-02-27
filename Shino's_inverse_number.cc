// https://ac.nowcoder.com/acm/problem/286129

#include<bits/stdc++.h>
using namespace std;

//冒泡排序可以消除逆序对

vector<vector<int>> v;
vector<pair<int,int>> ans;

int main()
{
    int n,k;
    cin>>n>>k;
    v.resize(n);
    for(int i=0;i<n;++i)
    {
        int l=0;
        cin>>l;
        for(int j=0;j<l;++j)
        {
            int t=0;
            cin>>t;
            v[i].push_back(t);
        }
    }
    
    sort(v.begin(),v.end(),[](auto& A,auto& B){
       return A[0]<B[0]; 
    });
    
    for(int i=0;i<n;++i)
        for(auto x:v[i])
            ans.push_back({x,i});
    
    int num=0;
    int total=ans.size();
    for(int i=0;i<total;++i)
        for(int j=i+1;j<total;++j)
            if(ans[i].first>ans[j].first) num++;
    
    k-=num;
    
    bool flag=true;
    while(flag)
    {
        flag=false;
        for(int i=0;i<total-1&&k>0;++i)
            if(ans[i].first<ans[i+1].first&&
               ans[i].second!=ans[i+1].second)
                flag=true,k--,swap(ans[i], ans[i+1]);       
    }
    
    if(k==0)
    {
        cout<<"Yes\n";
        for(auto [x,y]:ans)
            cout<<x<<" ";
        return 0;
    }
    cout<<"No";
  
    return 0;
}