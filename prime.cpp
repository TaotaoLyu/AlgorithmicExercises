#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<bool> v(10000000000);
    for(size_t i=2;i<v.size();++i)
    {
        if(v[i]==false)
        {
            v[i]=true;
            for(size_t j=i*2;j<v.size();++j)
                v[j]=true;
        }
    }
    for(size_t i=1000000000;i<v.size();++i)
    {
        if(v[i]==false)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}