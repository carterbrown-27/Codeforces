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
	string s;
	cin >> s;
	
	const int k = 2;
	const int C = 26;
	array<int,C> t = {0};
	
	for(char c: s)
		t[c-'a']++;
	
	int unique = 0;
	for(int x: t){
		unique += min(k, x);
	}
	
	int ans = unique / k;
	
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