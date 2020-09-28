ll fact[M];
 
ll add(ll a, ll b){
 
    return (a + b) % MOD;
}
 
ll mul(ll a, ll b){
 
    return (a * b) % MOD;
}
 
ll exp(ll b, ll e){
 
    if(e == 0) return 1;
    ll half = exp(b, e / 2);
 
    if(e % 2 == 0) return mul(half, half);
 
    return mul(half, mul(half, b));
}
 
ll invMOd(ll x){
 
    return exp(x, MOD - 2) % MOD;
}
 
void calcFact(int n){
 
    fact[0] = 1;
    for(int i = 1; i <= 2 * n + 5; i++) fact[i] = mul(fact[i - 1], i) % MOD;
 
}
 
 
ll nck(int n, int k){
 
    return mul(fact[n] , invMOd(mul(fact[n - k] , fact[k]))) % MOD;
}