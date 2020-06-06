void print(int pos, int val, int flag){

    if(pos == N) return;

    if(call(pos + 1, val, flag)) print(pos + 1, val, flag);

    else{

        cout << s[pos];

        res[cnt] += s[pos];

        print(pos + 1, ((val * 10) + (s[pos] - '0')) % 8, 1);
    }
}