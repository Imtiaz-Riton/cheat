for(int i = 0; i < size; ++i)
	F[i] = A[i];

for(int i = 0;i < bits; ++i) for(int mask = 0; mask < (1<<bits); ++mask){
	
    if(mask & (1<<i))
		F[mask] += F[mask^(1<<i)];
}