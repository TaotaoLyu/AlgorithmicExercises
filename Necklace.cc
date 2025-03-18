#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL f[151][151][151][3][3];
LL cnt[3];
LL n, m;
map<string, LL> mp;
void dp()
{
    for (LL len = 3; len <= n; ++len)
    {
        for (LL i = 0; i <= len; ++i)
        {
            if (cnt[0] < i) continue;
            for (LL j = 0; j <= len - i; ++j)
            {
                if (cnt[1] < j) continue;
                LL k = len - i - j;
                if (k < 0 || cnt[2] < k)continue;
                LL tmp[3] = { i,j,k };
                for (LL plast = 0; plast < 3; ++plast)
                {
                    for (LL last = 0; last < 3; ++last)
                    {
                        tmp[plast]--;
                        tmp[last]--;
                        if (tmp[last] < 0 || tmp[plast] < 0)
                        {
                            tmp[last]++;
                            tmp[plast]++;
                            continue;
                        }
                        tmp[last]++;
                        tmp[plast]++;
                        //f[i][j][k][plast][last]=0;// ?
                        tmp[last]--;
                        LL ans = LLONG_MIN;
                        for (LL pplast = 0; pplast < 3; ++pplast)
                        {
                            if (tmp[pplast] == 0) continue;
                            if (f[tmp[0]][tmp[1]][tmp[2]][pplast][plast] != LLONG_MIN)
                            {
                                string s;
                                s += ('a' + pplast);
                                s += ('a' + plast);
                                s += ('a' + last);
                                LL t = f[tmp[0]][tmp[1]][tmp[2]][pplast][plast];
                                auto it=mp.find(s);
                                if (it!=mp.end())
                                {
                                    t += it->second;
                                }
                                ans = max(ans, t);
                            }
                        }
                        f[i][j][k][plast][last] = ans;
                        tmp[last]++;
                    }
                }
            }
        }




    }


}


struct Node
{
    LL i;
    LL j;
    LL k;
    LL plast;
    LL last;
};


LL FindMax(LL plast_, LL last_, Node& node, LL& val)
{
    LL ret = LLONG_MIN;
    string s1;
    string s2;
    for (LL i = 0; i <= n; ++i)
    {
        for (LL j = 0; j <= n - i; ++j)
        {
            LL k = n - i - j;
            for (LL last = 0; last < 3; ++last)
            {
                for (LL plast = 0; plast < 3; ++plast)
                {
                    //ret = max(ret, f[i][j][k][plast][last]);
                    if (f[i][j][k][plast][last] != LLONG_MIN)
                    {

                        LL tmp = f[i][j][k][plast][last];
                        LL tp = tmp;
                        s1.clear();
                        s1 += (char(plast) + 'a');
                        s1 += (char(last) + 'a');
                        s1 += (char(plast_) + 'a');
                        s2.clear();
                        s2 += (char(last) + 'a');
                        s2 += (char(plast_) + 'a');
                        s2 += (char(last_) + 'a');
//                         if (mp.count(s1)) tmp += mp[s1];
//                         if (mp.count(s2)) tmp += mp[s2];
                        auto it=mp.find(s1);
                        if(it!=mp.end())
                            tmp+=it->second;
                        it=mp.find(s2);
                        if(it!=mp.end())
                            tmp+=it->second;
                        if (tmp > ret)
                        {
                            ret = tmp;
                            node = { i,j,k,plast,last };
                            val = tp;
                        }
                    }

                }
            }
        }
    }
    return ret;
}
void Init(LL* f_)
{
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            for (int k = 0; k <= n; ++k)
                for (int a = 0; a < 3; ++a)
                    for (int b = 0; b < 3; ++b)
                        f[i][j][k][a][b] = LLONG_MIN;
}


void solve()
{
    memset(cnt, 0, sizeof cnt);
    mp.clear();
    cin >> n >> m;
    Init((LL*)f);
    string s;
    cin >> s;
    for (auto c : s)
        cnt[c - 'a']++;
    for (LL i = 0; i < m; ++i)
    {
        string t;
        cin >> t;
        LL val;
        cin >> val;
        mp[t] = val;
    }
    LL ans = LLONG_MIN;
    Node node;
    LL val;
    LL b1 = -1;
    LL b2 = -1;
    for (LL i = 0; i < 3; ++i)
    {
        for (LL j = 0; j < 3; ++j)
        {
            LL tmp[3] = { 0,0,0 };
            tmp[i]++;
            tmp[j]++;
            bool flag = false;
            for(LL k=0;k<3;++k)
                if (tmp[k] > cnt[k])
                {
                    flag = true;
                }
            if (flag) continue;

            Init((LL*)f);
         
            f[tmp[0]][tmp[1]][tmp[2]][i][j] = 0;
            dp();
            Node node_;
            LL val_;
            LL t = FindMax(i, j, node_, val_);
            if (t > ans)
            {
                ans = t;
                val = val_;
                node = node_;
                b1 = i;
                b2 = j;
            }
        }
    }
    string as;
    as += (node.last + 'a');
    as += (node.plast + 'a');

    LL tmp[3] = { 0,0,0 };
    tmp[b1]++;
    tmp[b2]++;
    Init((LL*)f);
    f[tmp[0]][tmp[1]][tmp[2]][b1][b2] = 0;
    dp();
    string ts;
    string tmps;
    for (LL i = 0; i < n - 2; ++i)
    {
        LL tnode[3] = { node.i,node.j,node.k };
        tnode[node.last]--;
        node.i = tnode[0];
        node.j = tnode[1];
        node.k = tnode[2];
        ts.clear();
        ts += (node.plast + 'a');
        ts += (node.last + 'a');
        node.last = node.plast;
        for (LL c = 0; c < 3; ++c)
        {

            LL target = val;
            tmps.clear();
            tmps += (c + 'a');
            tmps = tmps + ts;
//             if (mp.count(tmps)) target -= mp[tmps];
            auto it=mp.find(tmps);
            if(it!=mp.end())
                target-=it->second;
            
            
            if (f[node.i][node.j][node.k][c][node.last] == target)
            {
                node.plast = c;
                as += (node.plast + 'a');
                val = target;
                break;
            }
        }
    }
    reverse(as.begin(), as.end());
    cout << ans << endl;
    cout << as << endl;
}
int main()
{
    LL t = 0;
    cin >> t;
    while (t--)
        solve();
    return 0;
}