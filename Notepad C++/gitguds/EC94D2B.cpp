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

int take(int& q, int& c, int w){
	int res = min(q, c/w);
	q -= res;
	c -= res*w;
	return res;
}

int getAns(int cs, int cw, int s, int w, int p, int f){
	int ans = 0;
	ans += take(cw, p, w);
	ans += take(cs, f, s);
	ans += take(cw, f, w);
	return ans;
}

void solve() {
	int p, f, cs, cw, s, w;
	cin >> p >> f >> cs >> cw >> s >> w;
	
	// say swords are lte
	if(s > w){
		swap(s,w);
		swap(cs,cw);
	}
		
	int ans = 0;
	for(int i = 0; i <= cs && i*s <= p; i++){
		// take this many swords
		ans = max(ans, i + getAns(cs-i, cw, s, w, p-(i*s), f));
	}
	
	cout << ans << endl;
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