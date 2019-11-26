#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 7;
vector < int > g[M];
int dis[M], low[M], dfsTime;
bool isCutPoint[M];

void findCut(int u, int par){
    int child = 0;
    dis[u] = low[u] = ++dfsTime;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(v == par) continue;
        if(dis[v] != -1) low[u] = min(low[u], dis[v]);
        else{
            child++;
            findCut(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dis[u]) isCutPoint[u] = true;
        }
    }
    if(par == -1) isCutPoint[u] = (child > 1);
}

int main()
{
    freopen("in.txt", "r", stdin);
    memset(dis, -1, sizeof dis);
    memset(low, 0, sizeof low);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int root;
    cin >> root;

    findCut(root, -1);
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(isCutPoint[i]) res++;
    }

    cout << res << endl;

    return 0;
}