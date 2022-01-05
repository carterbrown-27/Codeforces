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
	int x;
	cin >> x;
	
	string s;
	cin >> s;
	
	const int MOD = 1e9 + 7;
	ll len = s.size();
	
	for(int l = 1; l <= x; l++){
		int s_l = s[l-1]-'0'-1;
		
		if(s.size() < x){
			string c = s.substr(l, string::npos);
			for(int t = 0; t < s_l; t++)
				s += c;
			
			len = s.size();
		}else{
			len = ((len + (len - l) * s_l) + MOD) % MOD;
		}
		
		// cout << l << " " << len << endl;
	}
	
	cout << len << endl;
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