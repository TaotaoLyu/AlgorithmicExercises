#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        int num1=0; //奇数
        int num2=0; //偶数
        int n=0;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            int a=0;
            cin>>a;
            if(a%2==0) ++num2;
            else ++num1;
        }
        if(num2==0) cout<<n-1<<endl;
        else if(num1==0) cout<<1<<endl;
        else
        {
            cout<<num1+1<<endl;;
        }
    }
    return 0;
}