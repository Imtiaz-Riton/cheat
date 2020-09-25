ll mul(ll a, ll b){

    return (a * b) % MOD;
}

ll exp(ll b, ll e){

    if(e == 0) return 1;
    ll half = exp(b, e / 2);

    if(e % 2 == 0) return mul(half, half);

    return mul(half, mul(half, b));
}