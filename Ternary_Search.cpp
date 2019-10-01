#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 7;
long double h1, h2, d;

long double f(long double x){
    return (sqrtl((h1 * h1) + (x * x)) + sqrtl((h2 * h2) + ((d - x) * (d - x))));
}

long double Ternary(){
    long double l = 0, r = d, x;
    for(int i = 0; i < 200; i++){
        long double l1 = (2 * l + r) / 3.0;
        long double r1 = (l + 2 * r) / 3.0;
        if(f(l1) <= f(r1)){
            r = r1;
        }
        else
            l = l1;
        
    }
    x = l;
    return x;
}