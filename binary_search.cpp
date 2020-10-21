
bool good(){
    //imploment this fucntion according to 
    //the problem
}

int bs(){
    //000000011111111

    int l = 0, r = 1e9 

    while(l < r){

        int mid = (l + r) / 2;

        if(good(mid)) r = mid;

        else l = mid + 1;
    }

    //1111000000
    l = 0, r = 1e9;

    while(l < r){

        int mid = (l + r + 1) / 2;

        if(good(mid)) l = mid;

        else r = mid - 1;
    }
}