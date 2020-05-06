#include <bits/stdc++.h>
#define MD 1000000007
using namespace std;

const int M = 1e5 + 7;

int m, d, dp[2005][2005][2][2];
string a, b;

int call(int pos, int rem, int isSmall, int isBig){
    if(pos == a.size()) return (rem == 0);

    if(dp[pos][rem][isSmall][isBig] != -1) return dp[pos][rem][isSmall][isBig];

    int res = 0;

    int lo = 0, hi = 9;

    if(isSmall == 0) hi = b[pos] - '0';

    if(isBig == 0) lo = a[pos] - '0';

    for(int i = lo; i <= hi; i++){
        if(pos % 2 == 0 && i == d) continue;
        if(pos % 2 == 1 && i != d) continue;

        int nisSmall = isSmall | (i < hi);
        int nisBig = isBig | (i > lo);

        res += call(pos + 1, (rem * 10 + i) % m, nisSmall, nisBig) % MD;
        res %= MD; 
    }

    return dp[pos][rem][isSmall][isBig] = res % MD;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    memset(dp, -1, sizeof dp);

    cin >> m >> d >> a >> b;

    cout << call(0, 0, 0, 0) << "\n";

    return 0;
}