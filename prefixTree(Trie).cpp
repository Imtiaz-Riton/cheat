#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 7;

int tree[M][27];
int szT;

int newT() {
    return ++szT;
}
 
int n, k, root;
char s[M];
int cnt[M];

void addTrie(char * s) {
    int len = strlen(s);
    int v = root;
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (tree[v][c] == 0) tree[v][c] = newT();
        v = tree[v][c];
    }
    cnt[v]++;
}

int Search(char *s){
    int len = strlen(s);
    int v = root;

    for(int i = 0; i < len; i++){

        int c = s[i] - 'a';
        if(tree[v][c] == 0) return 0;

        v = tree[v][c];
    }

    return cnt[v];
}

int main()
{
    int q;
    scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++){

        scanf("%s", s);

        addTrie(s);
    }

    while(q--){
        scanf("%s", s);

        printf("%d\n", Search(s));
    }

    return 0;
}