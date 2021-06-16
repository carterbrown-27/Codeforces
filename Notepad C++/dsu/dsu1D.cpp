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

struct DSU {
	int n;
	vector<int> p;
	vector<int> s;
	
	DSU(int n): n(n){
		for(int i = 0; i < n; i++)
			p.pb(i);
		s.assign(n, 1);
	}
	
	int get(int a){
		// treat these as trees (root will point to itself)
		if(a != p[a]){
			// follow path to root, update ptr to point to root
			p[a] = get(p[a]);
		}
		return p[a];
	}
	
	void uni(int a, int b){
		a = get(a);
		b = get(b);
		
		if(a == b) return;
		
		// size heuristic
		if(s[a] > s[b]) swap(a,b);
		
		// change pointer of a's root to b's root
		p[a] = b;
		s[b] += s[a];
	}
	
	bool sameSet(int a, int b){
		return get(a) == get(b);
	}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	DSU dsu(n+1);
	
	for(int i = 0; i < m; i++){
		int tmp;
		cin >> tmp >> tmp;
		// don't need them
	}
	
	string op[k];
	int u[k], v[k];
	
	for(int q = 0; q < k; q++){
		cin >> op[q] >> u[q] >> v[q];
	}
	
	vector<bool> ans;
	for(int q = k; q-- > 0;){
		if(op[q] == "cut"){
			dsu.uni(u[q],v[q]);
		}else if(op[q] == "ask"){
			ans.push_back(dsu.sameSet(u[q],v[q]));
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	for(bool b: ans){
		cout << (b ? "YES" : "NO") << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}