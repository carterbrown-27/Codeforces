#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

set<int> primes;
void genPrimes(int B) {
	vector<bool> a(B+1, true);
	for(int i = 2; i*i <= B; i++){
		if(a[i]){
			for(int j = i*i; j <= B; j += i){
				a[j] = false;
			}
		}
	}
	
	for(int i = 2; i <= B; i++){
		if(a[i]) primes.insert(i);
	}
}

void solve() {
	int n;
	cin >> n;
	
	ll a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int mx = 1;
	for(ll p: primes){
		ll cur = a[0]%p;
		int c = 1;
		
		for(int i = 1; i < n; i++){
			ll r = a[i]%p;
			
			if(r == cur){
				mx = max(++c, mx);
			}else{
				cur = r;
				c = 1;
			}
		}
	}
	
	cout << mx << endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	genPrimes(10000);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}