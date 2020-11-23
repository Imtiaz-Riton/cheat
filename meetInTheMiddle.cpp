void solve(){

    int n; cin >> n;

    ll t; cin >> t;

    vector < ll > a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    int d1 = n / 2;

    int d2 = n - d1;

    vector < ll > v;

    for(int mask = 0; mask < (1 << d2); mask++){

        ll s = 0;

        for(int i = 0; i < d2; i++){

            if((1 << i) & mask) s += a[i + d1]; 
        }

        v.push_back(s);
    }

    sort(v.begin(), v.end());

    ll res = 0;

    for(int mask = 0; mask < (1 << d1); mask++){

        ll s = 0;

        for(int i = 0; i < d1; i++){

            if((1 << i) & mask) s += a[i]; 
        }

        if(s > t) continue;

        int idx = upper_bound(v.begin(), v.end(), t - s) - v.begin();

        if(idx > 0) idx--;

        res = max(res, s + v[idx]);
    }

    cout << res << nl;
}
