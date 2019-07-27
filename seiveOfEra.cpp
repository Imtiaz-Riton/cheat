#include <bits/stdc++.h>
using namespace std;

const int M = 1e6 + 7;
bool isPrime[M];

vector < int > primes;

void sieve(int n){
    isPrime[0] = isPrime[1] = true;
    for(int i = 2; i <= n; i++){
        if(isPrime[i]) continue;
        primes.push_back(i);
        for(int j = i + i; j <= n; j += i)
            isPrime[j] = true;
    }
}