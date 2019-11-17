#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 7;
int par[M], cost, rnk[M];
struct Edge{
    int u, v, w;
};

bool way(Edge e1, Edge e2){
    return e1.w < e2.w;
}

int Find(int x){
    if(par[x] == x) return x;
    return par[x] = Find(par[x]);
}

void makeUnion(int x, int y, int w){
    int roota = Find(x);
    int rootb = Find(y);
    if(roota == rootb) return;
    if(rnk[roota] < rnk[rootb]){
        par[roota] = rootb;
        cost += w;
    }
    else{
        par[rootb] = roota;
        rnk[x] = rnk[x] + 1;
        cost += w;
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int node, e;
    cin >> node >> e;

    for(int i = 1; i <= node; i++){
        par[i] = i;
        rnk[i] = 0;
    }

    Edge edge[M];

    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }

    sort(edge, edge + e, way);

    cost = 0;
    for(int i = 0; i < e; i++){
        int u = edge[i].u;
        int v = edge[i].v;
        makeUnion(u, v, edge[i].w);
    }

    cout << cost << endl;

    return 0;
}