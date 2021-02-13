int bin(int lo, int hi, int k){
    int mid;
    while(hi - lo > 5){
        mid = (lo + hi) / 2;
        if(cal(mid) <= k)
            lo = mid + 1;
        else hi = mid;
    }
    for(int i = lo; i <= hi; i++)
        if(cal(i) > k) return i;
    return hi + 1;
}