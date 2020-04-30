
int sum(int idx){
    int s = 0;
    while(idx > 0){
        s += tree[idx];
        idx -= idx & (-idx);
    }
    return s;
}

int binary_search(int v) // v is the value we are searching
{
	int l = 1, r = N;
	while(l != r)
	{
		int mid = (l+r) / 2;
		if(sum(mid) < v)
			l = mid+1;
		else
			r = mid;
	}
	return l;
}