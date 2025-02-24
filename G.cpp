#include<bits/stdc++.h>
using namespace std;
bool flag[100005];
int main()
{
    int n=0;
    cin>>n;
    vector<int> num1;
    vector<int> num2;
    for(int i=0;i<n;++i)
    {
        int a=0;
        cin>>a;
        if(a<=n&&flag[a]==false)
            flag[a]=true;
        else
            num2.push_back(a);
    }
    for(int i=1;i<=n;++i)
        if(flag[i]==false) num1.push_back(i);
    sort(num2.begin(),num2.end());
    int len=num1.size();
    int ans=0;
    for(int i=0;i<len-1;++i)
    {
        num2[i+1]=num2[i+1]-(num1[i]-num2[i]);
        ans+=abs(num1[i]-num2[i]);
        num2[i]=num1[i];
    }
    if(num2[len-1]!=num1[len-1])
        cout<<-1;
    else
        cout<<ans;
    return 0;
}