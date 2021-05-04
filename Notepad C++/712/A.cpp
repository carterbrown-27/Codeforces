#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	
	bool allA = true;
	for(int i = 0; i < n; i++){
		if(s[i] != 'a'){
			allA = false;
		}
	}
	
	if(allA){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		// ans
		for(int i = 0; i <= n/2; i++){
			if(s[i] == 'a' && s[n-i-1] == 'a'){
				continue;
			}else if(s[i] != 'a'){
				cout << s + 'a' << endl;
				return;
			}else{
				cout << 'a' + s << endl;
				return;
			}
		}
	}
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