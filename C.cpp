#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 7;
int par[M], rnk[M];
bool vis[M];
int res;

void make_set(int x){
    par[x] = x;
    rnk[x] = 0;
}

int fnd(int x){
    if(par[x] == x) return x;
    return par[x] = fnd(par[x]);
}

void make_union(int u, int v){
    int pu = fnd(u);
    int pv = fnd(v);
    //cout << pu << ' ' << pv << endl;
    if(pu == pv){
        res++;
        return;
    }
    else if(rnk[pu] < rnk[pv])
        par[pu] = pv;
    else{
        par[pv] = pu;
        rnk[u] = rnk[u] + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, k, u, v;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        make_set(i);
    for(int i = 0; i < k; i++){
        cin >> u >> v;
        make_union(u, v);
    }
    cout << res << endl;
    return 0;
}