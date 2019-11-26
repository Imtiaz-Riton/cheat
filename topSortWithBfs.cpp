#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 7;
vector < int > g[M], res;
int indegree[M];

int main()
{
    //freopen("in.txt", "r", stdin);
    memset(indegree, 0, sizeof indegree);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    for(int i = 1; i <= n; i++){ //1 based graph
        for(int j = 0; j < g[i].size(); i++){
            int v = g[i][j];
            indegree[v]++;
        }
    }
    queue < int > q; // for printing input order use priority_queue.
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            indegree[v]--;
            if(indegree[v] == 0) q.push(v);
        }
    }

    if(res.size() != n) cout << "Topsort Impossible" << endl;
    else{
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << ' ';
    }
    cout << endl;
    return 0;
}