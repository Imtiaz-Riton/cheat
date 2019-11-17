#include <bits/stdc++.h>
#define ii pair < int , int > 
#define inf 1 << 29
using namespace std;

const int M = 1e5 + 7;
vector < ii > graph[M];
vector < int > par(M, -1);

void prims(int s){
    vector < int > dis(M, inf);
    vector < bool > inMST(M, false);
    priority_queue < ii, vector < ii > , greater<ii> > pq;
    pq.push({0,s});
    dis[s] = 0;

    while(!pq.empty()){
        ii p = pq.top();
        pq.pop();
        int u = p.second;
        inMST[u] = true;
        for(int i = 0; i < graph[u].size(); i++){
            p = graph[u][i];
            int v = p.first;
            int w = p.second;
            if(inMST[v] == false && w < dis[v]){
                dis[v] = w;
                pq.push({dis[v], v});
                par[v] = u;
            }
        }
    }
}

int main()
{
    //graph 1 indexed based;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int node, edge;
    cin >> node >> edge;

    for(int i = 0; i < edge; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(ii(v,w));
        graph[v].push_back(ii(u,w));
    }
    //source taken 1
    int src;
    cin >> src;

    prims(src);

    for(int i = 2; i <= node; i++)
        cout << par[i] << ' ' << i << endl;

    return 0;
}