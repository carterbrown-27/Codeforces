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

void solve() {
	ll a, b, x, y;
	cin >> a >> b >> x >> y;
	
	auto works = [&] (ll v) -> bool {
		ll A = v/x, B = v/y, AnB = v/(x*y);
		ll AuB = A + B - AnB;
		ll d = (v - AuB) - (max(0LL, a-(B-AnB)) + max(0LL ,b-(A-AnB)));
		// cout << v << " " << d << endl;
		return d >= 0;
	};
	
	ll l = a+b, r = 3e9 + 5;
	while(l < r){
		ll m = (l+r)/2;
		// cout << l << "-" << r << " ";
		if(works(m)){
			r = m;
		}else{
			l = m+1;
		}
	}
	
	cout << r << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}