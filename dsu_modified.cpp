const int M = 1e5 + 7;
int par[M], rnk[M];
bool vis[M];
int res;

void make_set(int x){
    par[x] = x;
    rnk[x] = 0;
}

int get(int x){
    if(par[x] == x) return x;
    return par[x] = get(par[x]);
}

void make_union(int a, int b){
    a = get(a);
    b = get(b);

    if(a != b){

        if(rnk[a] == rnk[b]) rnk[a]++;

        if(rnk[a] > rnk[b]){
            par[b] = a;
        }
        else{
            par[a] = b;
        }
    }
}