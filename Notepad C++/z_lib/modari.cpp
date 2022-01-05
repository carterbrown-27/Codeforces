ll bin_exp(ll a, ll b, ll m)
{
	a%=m;
	ll res = 1;
	while(b > 0){
		if(b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b /= 2;
	}
	return res;
}

// p is prime
ll mod_inv(ll a, ll p)
{
	return bin_exp(a, p-2, p);
}

const int MOD = 1e9 + 7;
ll fac[MAXN+1];
void precmp_factorial(){
	fac[0] = 1;
	for(int i = 1; i <= MAXN; i++){
		fac[i] = (fac[i-1] * i) % MOD;
	}
}

ll choose(int n, int k, int p){
	return fac[n] * mod_inv(fac[k], p) % p * mod_inv(fac[n-k], p) % p;
}