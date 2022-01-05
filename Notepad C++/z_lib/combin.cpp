const int MAX_N = 2e5, MAX_K = 100;
int choose[MAX_N+1][MAX_K+1];

void pascal(){
	choose[0][0] = 1;
	for(int n = 1; n <= MAX_N; n++){
		choose[n][0] = 1;
		if(n <= MAX_K) choose[n][n] = 1;
		for(int k = 1; k < n && k <= MAX_K; k++){
			choose[n][k] = (choose[n-1][k-1] + choose[n-1][k]) % MOD;
		}
	}
}

ll binexp(ll a, ll b, ll m)
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
	return binexp(a, p-2, p);
}

ll fac[MAXN];
void precmp_factorial(int p){
	fac[0] = 1;
	for(int i = 1; i <= MAXN; i++){
		fac[i] = (fac[i-1] * i) % p;
	}
}

int choose(int n, int k, int p){
	return (fac[n] * mod_inv(fac[k]) * mod_inv(fac[n-k])) % p;
}