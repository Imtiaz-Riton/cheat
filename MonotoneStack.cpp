#include <bits/stdc++.h>
#define ll long long 
#define inf 1 << 29
#define ii pair < int, int > 
#define nl "\n"
using namespace std;

const int M = 5e5 + 7;

ll L[M], R[M], m[M], n;

void solve(){
    
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> m[i];

    vector < pair < ll, ll > > v;

    v.push_back({0, 0});

    ll s = 0;

    for(int i = 1; i <= n; i++){

        int num = 1;

        while(v.back().first >= m[i]){

            s -= v.back().first * v.back().second;

            num += v.back().second;

            v.pop_back();
        }

        s += m[i] * num;

        v.push_back({m[i], num});

        L[i] = s;
    }

    v.clear();
    s = 0;
    v.push_back({0, 0});

    for(int i = n; i >= 1; i--){

        int num = 1;

        while(v.back().first >= m[i]){

            s -= v.back().first * v.back().second;

            num += v.back().second;

            v.pop_back();
        }

        s += m[i] * num;

        v.push_back({m[i], num});

        R[i] = s;
    }

    ll mx = 0;
    int idx = -1;

    for(int i = 1; i <= n; i++){

        if(L[i] + R[i] - m[i] >= mx){

            idx = i;

            mx = L[i] + R[i] - m[i];
        }
    }

    for(int i = idx + 1; i <= n; i++) m[i] = min(m[i - 1], m[i]);

    for(int i = idx - 1; i >= 1; i--) m[i] = min(m[i], m[i + 1]);

    for(int i = 1; i <= n; i++) cout << m[i] << ' ';

    cout << nl;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);

    int t = 1;
    //cin >> t;

    while(t--){
        
        solve();
    }

    return 0;
}