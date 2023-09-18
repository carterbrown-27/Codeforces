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

const int MOD = 998244353;

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];
	
	sort(b.begin(), b.end());
	
	vector<ll> times(n);
	for(int i = 0; i < n; i++){
		// 10^10 * 10^6 < 10^18
		times[i] = 1LL*(n-i)*(i+1) * a[i];
	}
	sort(times.begin(), times.end(), greater<ll>());
	
	ll ans = 0;
	for(int i = 0; i < n; i++){
		ans = (ans + (times[i] % MOD) * b[i]) % MOD;
	}
	
	cout << ans << endl;
	return 0;
}