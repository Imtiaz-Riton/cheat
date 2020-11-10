// 1 2 2 3 3 4 5
// increasing or equal
int LIS(){

    set < int > sx;

    for(int i = 0; i < n; i++){

        if(sx.lower_bound(a[i]) != sx.end()) sx.erase(sx.lower_bound(a[i]));

        sx.insert(a[i]);
    }

    return sx.size();
}

// 1 3 5 7
// strictly increasing
int LIS(){

    set < int > sx;

    for(int i = 0; i < n; i++){

        if(sx.upper_bound(a[i]) != sx.end()) sx.erase(sx.upper_bound(a[i]));

        sx.insert(a[i]);
    }

    return sx.size();
}