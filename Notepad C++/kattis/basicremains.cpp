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

string solve(int b, string p, string ms) {
	ll m = 0, e = 1;
	for(int i = ms.length(); i-- > 0;){
		ll x = ms[i] - '0';
		m += x * e;
		e *= b;
	}
	
	if(m == 0) return p;
	
	// calculate p mod m
	e = 1;
	ll n = 0;
	for(int i = p.length(); i-- > 0;){
		ll x = p[i] - '0';
		n = (n + (x * e)) % m;
		e = (e * b) % m;
	}
	
	// cout << n << endl;
	if(n == 0) return "0";
	
	// convert to base b
	string ans;
	while(n > 0){
		ans += '0' + n%b;
		n /= b;
	}
	
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	
	int b;
	while(true){
		cin >> b;
		if(b == 0) break;
		
		string p, m;
		cin >> p >> m;
		cout << solve(b, p, m) << endl;
	}
	return 0;
}