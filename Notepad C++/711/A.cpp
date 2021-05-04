#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b, a%b);
}

int sumDigs(ll n){
	int ans = 0;
	while(n > 0){
		ans += n%10;
		n/=10;
	}
	return ans;
}

void solve() {
	ll n;
	cin >> n;
	
	while(true){
		if(gcd(n, sumDigs(n)) > 1){
			cout << n << endl;
			break;
		}
		n++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}