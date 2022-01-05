#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

const int MAXN = 2e5;

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

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> a(n);
	for(int& x: a){
		cin >> x;
	}
	
	sort(a.begin(), a.end());
	
	ll ans = 0;
	for(int i = 0; i < n; i++){
		auto l = a.begin() + i;
		auto r = upper_bound(l+1, a.end(), a[i] + k);
		if(r-l-1 >= m-1){
			ans = (ans + choose(r-l-1, m-1, MOD)) % MOD;
		}
	}
	
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	precmp_factorial();
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}