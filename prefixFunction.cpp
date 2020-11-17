
int prefix[M];

void prefixFunction(){

    string s;
    cin >> s;

    for(int i = 1; i < s.size(); i++){

        int j = prefix[i - 1];

        while(j > 0 && s[i] != s[j]) j = prefix[j - 1];

        if(s[i] == s[j]) j++;

        prefix[i] = j;
    }

    //calculating number of occurences of each prefix

    vector<int> ans(n + 1);

    for (int i = 0; i < n; i++)
        ans[prefix[i]]++;
    for (int i = n-1; i > 0; i--)
        ans[prefix[i-1]] += ans[i];
    for (int i = 0; i <= n; i++)
        ans[i]++;        
}