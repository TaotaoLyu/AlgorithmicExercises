// https://ac.nowcoder.com/acm/problem/51042

#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
vector<long long> prime;
const int N = 100000;

long long arr[N];

void Init()
{
    for (int i = 2; i < N; ++i)
    {
        if (arr[i] == 0)
            prime.push_back(i);
        for (auto x : prime)
        {
            if (x * i < N)
                if (arr[x * i] > x|| arr[x * i]==0)
                    arr[x * i] = x;
                else break;
        }
    }
}

int main()
{
    Init();
    LL l, r;
    while (cin >> l >> r)
    {
        vector<bool> v(r - l + 1);
        LL begin = 0;
        while (begin<prime.size()&&prime[begin] < r)
        {
            LL t = l / prime[begin];
            if (l % prime[begin] != 0) t++;
            for (LL i = max(t,2ll); i * prime[begin] <= r; ++i)
            {
                v[i * prime[begin] - l] = true;
            }
            begin++;
        }
        if (l == 1) v[0] = true;
        long long p1 = 0;
        while (v[p1]) p1++;
        long long p2 = p1+1;
        LL maxans = 0;
        pair<LL, LL> maxpair;
        pair<LL, LL> minpair;
        LL minans = LONG_MAX;
        while (p1 < v.size())
        {
            while (p2 < v.size() && v[p2])
                p2++;
            if (p2 >= v.size()) break;
            if (p2 - p1 > maxans)
            {
                maxans = p2 - p1;
                maxpair = { p1 + l,p2 + l };
            }
            if (p2 - p1 < minans)
            {
                minans = p2 - p1;
                minpair = { p1 + l,p2 + l };
            }
            p1 = p2;
            p2 = p1 + 1;
        }
        if (maxans == 0 && minans == LONG_MAX)
            cout << "There are no adjacent primes.\n";
        else
            printf("%d,%d are closest, %d,%d are most distant.\n",
                minpair.first, minpair.second, maxpair.first, maxpair.second);
    }
    return 0;
}