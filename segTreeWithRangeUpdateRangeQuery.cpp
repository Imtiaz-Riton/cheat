#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int M = 1e5 + 7;
ll a[M], tree[4 * M], lazy[4 * M];

ll merg(ll l, ll r){
    return l + r;
}

void relax(int node, int beg, int ed){
    tree[node] += lazy[node] * (ed - beg + 1);
    if(beg != ed){
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void updateRange(int node, int beg, int ed, int i, int j, int val){
    if(lazy[node]) relax(node, beg, ed);
    if(beg > j || ed < i) return;
    if(beg >= i && ed <= j){
        lazy[node] += val;
        relax(node, beg, ed);
        return;
    }
    int lft = 2 * node;
    int rgt = lft + 1;
    int mid = (beg + ed) / 2;
    updateRange(lft, beg, mid, i, j, val);
    updateRange(rgt, mid + 1, ed, i, j, val);
    tree[node] = merg(tree[lft], tree[rgt]);
}

ll query(int node, int beg, int ed, int i, int j){
    if(lazy[node]) relax(node, beg, ed);
    if(beg > j || ed < i) return 0;
    if(beg >= i && ed <= j){
        return tree[node];
    }
    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgt = lft + 1;
    ll p = query(lft, beg, mid, i, j);
    ll q = query(rgt, mid + 1, ed, i, j);
    return merg(p, q);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
        int n, q;
        scanf("%d %d", &n, &q);
        while(q--){
            int typ;
            scanf("%d", &typ);
            if(typ == 0){
                int p, q;
                ll val;
                scanf("%d %d %lld", &p, &q, &val);
                updateRange(1,1,n,p,q,val);
            }
            else{
                int p, q;
                scanf("%d %d", &p, &q);
                ll res = query(1,1,n,p,q);
                printf("%lld\n", res);
            }
        }
    }
    return 0;
}