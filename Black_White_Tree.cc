#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int num[200005][2];
LL g[200005][2];
LL f[200005];
vector<int> graph[200005];
map<pair<int, int>, int> query;
pair<LL, LL> ans[200005];

void cut(int x, int y) // x is father, y is chiild
{
    num[x][0] -= num[y][0];
    num[x][1] -= num[y][1];
    g[x][0] -= g[y][0] + num[y][0];
    g[x][1] -= g[y][1] + num[y][1];
    f[x] = f[x] - f[y] 
        - g[x][0] * num[y][1] - g[x][1] * num[y][0] 
        - (g[y][0] + num[y][0]) * num[x][1] - (g[y][1] + num[y][1]) * num[x][0];
}
void link(int x, int y) // x is father, y is chiild
{
    f[x] = f[x] + f[y] 
        + g[x][0] * num[y][1] + g[x][1] * num[y][0] 
        + (g[y][0] + num[y][0]) * num[x][1] + (g[y][1] + num[y][1]) * num[x][0];
    num[x][0] += num[y][0];
    num[x][1] += num[y][1];
    g[x][0] += g[y][0] + num[y][0];
    g[x][1] += g[y][1] + num[y][1];
}
void dfs(int x, int father)
{
    for (auto y : graph[x])
        if (y != father)
            dfs(y, x), link(x, y);
}
void dfs2(int x, int father)
{
    for (auto y : graph[x])
    {
        if (y != father)
        {
            cut(x, y);
            if (query.count(make_pair(x, y)))
                ans[query[make_pair(x, y)]] = {f[x], f[y]};
            else
                ans[query[make_pair(y, x)]] = {f[y], f[x]};
            link(y, x);
            dfs2(y, x);
            cut(y, x);
            link(x, y);
        }
    }
}

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        if (c == 'b')
            num[i][0] = 1;
        else
            num[i][1] = 1;
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        query[make_pair(u, v)] = i;
    }
    dfs(1, 0);
    dfs2(1, 0);
    for (int i = 0; i < n - 1; ++i)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}