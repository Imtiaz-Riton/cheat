#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 7;
vector < int > g[M], res;
bool vis[M];


void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v])
            dfs(v);
    }
    res.push_back(u);
}


int main()
{
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        //g[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i);
    }

    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    cout << endl;
    return 0;
}