#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 7;
int a[M];

struct _info{
    int mx, smx;
    _info(){mx = 0, smx = 0;}
}tree[4 * M];

_info merg(_info l, _info r){
    _info res;
    vector < int > v;
    v.push_back(l.mx);
    v.push_back(l.smx);
    v.push_back(r.mx);
    v.push_back(r.smx);
    sort(v.begin(), v.end());
    res.mx = v[v.size() - 1];
    res.smx = v[v.size() - 2];
    return res;
}

void build(int node, int beg, int ed){
    if(beg == ed){
        tree[node].mx = a[beg];
        tree[node].smx = 0;
        return;
    }
    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgt = lft + 1;
    build(lft, beg, mid);
    build(rgt, mid + 1, ed);
    tree[node] = merg(tree[lft], tree[rgt]);
}

void update(int node, int beg, int ed, int i, int val){
    if(beg > i || ed < i) return;
    if((beg == ed) && (beg == i)){
        tree[node].mx = val;
        tree[node].smx = 0;
        return;
    }
    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgt = lft + 1;
    update(lft, beg, mid, i, val);
    update(rgt, mid + 1, ed, i, val);
    tree[node] = merg(tree[lft], tree[rgt]);
}

_info query(int node, int beg, int ed, int l, int r){
    if(beg > r || ed < l){
        _info dummy;
        return dummy;
    }
    if(beg >= l && ed <= r) return tree[node];
    int mid = (beg + ed) / 2;
    int lft = 2 * node;
    int rgt = lft + 1;
    _info p = query(lft, beg, mid, l, r);
    _info q = query(rgt, mid + 1, ed, l, r);
    return merg(p,q);
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    build(1,1,n);
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        char s[10];
        scanf("%s",s);
        int l,r;
        scanf("%d %d", &l, &r);
        if(s[0] == 'Q'){
            _info res = query(1,1,n,l,r);
            printf("%d\n", res.mx + res.smx);
        }
        else{
            update(1,1,n,l,r);
        }
    }

    return 0;
}