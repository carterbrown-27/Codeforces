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
	string n;
	cin >> n;
	
	vector<string> twos;
	for(int k = 0; (1LL << k) <= 1e18; k++)
	{
		twos.pb(to_string(1LL << k));
	}
	
	int mn = n.length()+1;
	for(string s: twos)
	{
		int p = 0;
		for(int i = 0; i < n.length(); i++){
			if(n[i] == s[p])
				p++;
		}
		mn = min(mn, (int) (n.length() + s.length() - 2*p));
	}

	cout << mn << endl;
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