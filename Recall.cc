#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool> vis(n + 1);
    vector<pair<int, int>> vp;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i] == false)
        {
            int cnt = 0;
            int min_idx = i;
            queue<int> qe;
            qe.push(i);
            vis[i] = true;
            while (!qe.empty())
            {

                cnt++;
                int u = qe.front();
                qe.pop();
                min_idx = min(min_idx, u);
                for (auto v : g[u])
                {
                    if (vis[v] == false)
                    {
                        qe.push(v);
                        vis[v] = true;
                    }
                }
            }
            vp.push_back({cnt, min_idx});
        }
    }
    sort(vp.begin(), vp.end(), [](auto &p1, auto &p2)
         {
        if(p1.first!=p2.first)
            return p1.first>p2.first;
        else
            return p1.second<p2.second; });
    vis.clear();
    vis.resize(n + 1, false);
    int ans = 0;
    for (int i = 0; i < min(k, (int)vp.size()); ++i)
        ans += vp[i].first;
    cout << ans << endl;
    priority_queue<int, deque<int>, greater<int>> pq;
    for (int i = 0; i < min((int)vp.size(), k); ++i)
    {

        pq.push(vp[i].second);
        vis[vp[i].second] = true;
    }
    k -= vp.size();
    int cnt = 1;
    while (!pq.empty())
    {
        if (pq.top() != cnt && k > 0)
        {
            k--;
            pq.push(cnt);
            vis[cnt] = true;
        }
        int u = pq.top();
        pq.pop();
        cout << u << " ";
        cnt++;
        for (auto v : g[u])
        {
            if (vis[v] == false)
            {
                pq.push(v);
                vis[v] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}