#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int left_=-1;   //标记0
    int right_=-1;  //标记1
};
Node arr[325];
int num=1;
int P_=0;
unsigned int ans=0;
void Insert(int x)
{
    int P=P_;
    for(int i=31;i>=0;--i)
    {
        if(((x>>i)&1)==0)
        {
            if(arr[P].left_==-1)
                arr[P].left_=num++;
            P=arr[P].left_;
        }
        else
        {
            if(arr[P].right_==-1)
                arr[P].right_=num++;
            P=arr[P].right_;
        }
    }
}
unsigned int FindMax(int x)
{
    int P=P_;
    unsigned int ret=0;
    for(int i=31;i>=0;--i)
    {
        if((x>>i)&1)
        {
            if(arr[P].left_!=-1)
            {
                ret=ret|(1<<i);
                P=arr[P].left_;
            }
            else
                P=arr[P].right_;
        }
        else
        {
            if(arr[P].right_!=-1)
            {
                ret=ret|(1<<i);
                P=arr[P].right_;
            }
            else
                P=arr[P].left_;
        }
    }
    return ret;
}
int main()
{
    int n=0;
    cin>>n;
    int a=0;
    cin>>a;
    Insert(a);
    for(int i=1;i<n;++i)
    {
        cin>>a;
        ans=max(ans,FindMax(a));
        Insert(a);
    }
    cout<<ans;
    return 0;
}