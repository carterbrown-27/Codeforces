#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

string flip(string& s) {
	string t;
	for(int i = 0; i < s.length(); i++){
		t += (s[i] == '+' ? '*' : '+');
	}
	return t;
}

void solve() {
	int k;
	cin >> k;
	
	vector<vector<string>> v;
	v.pb(vector<string>{"+"});
	
	for(int i = 1; i <= k; i++){
		vector<string> cur;
		for(string s: v[i-1]){
			cur.pb(s+s);
			cur.pb(s+flip(s));
		}
		v.pb(cur);
	}
	
	for(string s: v[k]) cout << s << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}