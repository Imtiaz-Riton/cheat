#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int M = 1e5 + 7;
ll dp[15][2][15][2];

vector < ll > num;

ll call(ll pos, ll isSmall, ll zCount, ll alreadyStarted){
    if(pos == num.size()) return zCount;

    if(dp[pos][isSmall][zCount][alreadyStarted] != -1) return dp[pos][isSmall][zCount][alreadyStarted];

    ll res = 0;

    ll lo = 0, hi = 9;

    if(isSmall == 0) hi = num[pos];

    for(ll i = lo; i <= hi; i++){

        ll nisSmall = (isSmall | (i < hi));
        ll nzCount = zCount + ((i == 0) & alreadyStarted);
        ll nalreadyStarted = alreadyStarted | (i != 0);

        ll p = call(pos + 1, nisSmall, nzCount, nalreadyStarted);
        res += p;
    }

    return dp[pos][isSmall][zCount][alreadyStarted] = res;
}

ll solve(ll n){
    num.clear();

    while(n > 0){
        num.push_back(n % 10);
        n /= 10;
    }

    reverse(num.begin(), num.end());

    memset(dp, -1, sizeof dp);

    ll res = call(0, 0, 0, 0) + 1;

    return res;
}

int main(){

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        ll m , n;
        scanf("%lld %lld", &m, &n);

        ll res = solve(n);

        if(m) res -= solve(m - 1);


        printf("Case %d: %lld\n", tc, res);
    }

    return 0;
}