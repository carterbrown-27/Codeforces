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

int solve() {
	int n;
	cin >> n;
	
	vector<int> a, b;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		a.pb(v);
	}
	
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		b.pb(v);
	}
	
	int drop = n/4;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int as = 0, bs = 0;
	for(int i = drop; i < n; i++){
		as += a[i];
		bs += b[i];
	}
	
	reverse(b.begin(), b.end());
	

	// +10 = buffer
	for(int i = 1; i <= n; i++){
		if(as >= bs){
			return i-1;
		}
		int c = n+i;
		as += 100;
		a.pb(100);
		b.pb(0);
		
		// if not dropping an additional, bring back b's dropped
		if(c%4 == 0){
			as -= a[drop];
			// bs -= b[b.size()-drop];
		}else if(drop > 0){
			bs += b[b.size()-drop-1];
		}
		
		drop = c/4;
		// cout << "? " << i << " " << drop << " " << as << " " << bs << endl;
	}

	return n;
}
int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << solve() << endl;
	}
	return 0;
}