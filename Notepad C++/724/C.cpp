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

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	// reduced D:K ratio -> count
	map<pair<int,int>, int> mp;
	int d = 0, k = 0;
	
	
	for(int i = 0; i < n; i++){
		if(s[i] == 'D'){
			d++;
		}else{
			k++;
		}
		
		int g = __gcd(d,k);
		pair<int,int> p = {d/g, k/g};
		
		int ans = 1;
		if(mp.find(p) != mp.end()){
			ans = ++mp[p];
		}else{
			mp[p] = 1;
		}
		
		cout << ans << " ";
	}
	cout << endl;
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