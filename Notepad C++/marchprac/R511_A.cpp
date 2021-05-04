#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

// EDITORIAL USED

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}

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

uset<int> upfactorize(int n){
	uset<int> res;
	for(int x: primes){
		if(x*x > n) break;
		if(n%x == 0){
			res.insert(x);
			do{
				n/=x;
			}while(n%x == 0);
		} 
	}
	if(n>1) res.insert(n);
	return res;
}


void solve() {
	int n;
	cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int g = a[0];
	for(int i = 1; i < n; i++) g = gcd(g, a[i]);
	
	for(int i = 0; i < n; i++) a[i] /= g;
	
	genPrimes((int) sqrt(1.6*1e7));
	
	vector<uset<int>> facts;
	for(int i = 0; i < n; i++){
		facts.pb(upfactorize(a[i]));
		//cout << facts[i].size() << endl;
	}
	
	int mx = 0;
	for(int p: primes){
		int c = 0;
		for(int i = 0; i < n; i++){
			if(facts[i].find(p) != facts[i].end()) c++;
		}
		mx = max(mx, c);
	}
	
	cout << (mx > 0 ? n-mx : -1) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}