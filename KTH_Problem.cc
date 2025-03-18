// https://ac.nowcoder.com/acm/contest/95336/F




#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, p, k;
    cin >> n >> p >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        v[i] %= p;
    }
    long long maxk = (n * (n - 1)) / 2;
    if (maxk <= k)
    {
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
                ans.push_back((v[i] + v[j]) % p);
        }
        sort(ans.begin(), ans.end(), greater<int>());
        for (auto x : ans)
            cout << x << " ";
        for (int i = 0; i < (k - maxk); ++i)
            cout << -1 << " ";
        cout << endl;
    }
    else
    {
        sort(v.begin(), v.end());
        int left = 0, right = p - 1;
        while (left < right)
        {

            int mid = (left + right + 1) / 2;
            long long cnt = 0;
            for (int i = 0; i < n; ++i)
            {
                int a = v[i];
                int target = mid - a;
                cnt += lower_bound(v.begin() + i + 1, v.end(), p - a) - lower_bound(v.begin() + i + 1, v.end(), target);
                target = p + mid - a;
                cnt += v.end() - lower_bound(v.begin() + i + 1, v.end(), target);
            }
            if (cnt >= k)
                left = mid;
            else
                right = mid - 1;
        }
        int ansnum = left;
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            int a = v[i];
            int target = ansnum - a;
            auto begin = upper_bound(v.begin() + i + 1, v.end(), target);
            auto end = lower_bound(v.begin() + i + 1, v.end(), p - a);
            while (begin != end)
                ans.push_back((a + *begin) % p), begin++;
            target = p + ansnum - a;
            begin = upper_bound(v.begin() + i + 1, v.end(), target);
            end = v.end();
            while (begin != end)
                ans.push_back((a + *begin) % p), begin++;
        }
        sort(ans.begin(), ans.end(), greater<int>());
        for (auto x : ans)
            cout << x << " ";
        for (int i = 0; i < k - ans.size(); ++i)
            cout << ansnum << " ";
        cout << endl;
    }
}


int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}