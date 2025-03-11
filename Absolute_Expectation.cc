// https://ac.nowcoder.com/acm/contest/95336/A



#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod = 1000000007;
LL A;
LL B;

LL mypower(LL a, LL x)
{
    if (x == 1)
        return a;
    LL ret = mypower(a, x / 2);
    ret = (ret * ret) % mod;
    if (x % 2 == 1)
        ret = (ret * a) % mod;
    return ret;
}

LL Sum1(LL a, LL len)
{
    if (len == 0 || a == 0)
        return 0ll;
    LL tmp = (a + len) % mod;
    return (((((a * len) % mod) * tmp) % mod) * A) % mod;
}

LL Sub(LL a, LL b)
{
    return ((a - b) % mod + mod) % mod;
}

LL Sum2(LL n)
{
    LL a = n;
    LL b = n + 1;
    LL c = n - 1;
    return (((((a * b) % mod) * c) % mod) * B) % mod;
}

void solve()
{
    int n = 0;
    cin >> n;
    vector<pair<LL, LL>> v;
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }
    LL ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        auto p1 = v[i], p2 = v[i + 1];
        if (p1.first > p2.first)
            swap(p1, p2);
        LL len1 = p1.second - p1.first + 1;
        LL len2 = p2.second - p2.first + 1;
        LL a = p2.first - p1.first;
        LL ans1 = Sum1(a, len2);
        ans1 = Sub(ans1, Sum1(max(a - len1, 0ll), len2));
        if (a < len1)
        {
            LL d = min(len1 - a, len2);
            ans1 = (ans1 + Sum2(d)) % mod;
            ans1 += Sum1(abs(p2.second - p1.second), d);
            ans1 %= mod;
        }
        LL p = ans1;
        LL q = mypower((len1 * len2) % mod, mod - 2);
        ans += (p * q) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}

int main()
{
    A = mypower(2, mod - 2);
    B = mypower(3, mod - 2);
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}