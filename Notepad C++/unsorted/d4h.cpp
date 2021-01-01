#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

ll gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}

int mod_pow(ll a, ll b, ll m){
	a %= m;
	ll res = 1;
	while(b > 0){
		if(b&1) res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

void solve() {
	int p = 1009, q = 3643;
	cin >> p >> q;
	int phi = (p-1)*(q-1);
	int n = p*q;
	
	int best = 1e9;
	ll sum = 0;
	
	// SOLUTION FROM EULER PROJECT 182
	for(int e = 2; e < phi; e++){
		if(gcd(e,phi) > 1) continue;
		
		ll num = (gcd(p-1, e-1) + 1) * (gcd(q-1, e-1) + 1);
		if(num == best){
			sum += e;
		}else if(num < best){
			best = num;
			sum = e;
		}
	}
	
	cout << sum << endl;
	// 399788195976
}

int main() {
	solve();
	return 0;
}