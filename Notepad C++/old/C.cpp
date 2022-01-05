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
	int n;
	cin >> n;
	
	string t, b;
	cin >> t >> b;
	
	int ans = 0;
	bool z = false, o = false;
	for(int i = 0; i < n; i++){
		if(t[i] == '1' || b[i] == '1') o = true;
		if(t[i] == '0' || b[i] == '0') z = true;
		
		if(z && o){
			ans += 2;
			z = false;
			o = false;
		}else if(z){
			if(i+1 < n && t[i+1] == '1' && b[i+1] == '1'){
				ans += 2;
				i++;
			}else{
				ans++;
			}
			z = false;
		}else{
			// 1s only
			continue;
		}
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