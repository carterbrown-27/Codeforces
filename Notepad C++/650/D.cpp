#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	string s;
	cin >> s;
	int m;
	cin >> m;
	
	int b[m];
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	
	int t[26] {0};
	for(char c: s){
		t[c-'a']++;
	}
	
	bool u[m] {false};
	char ans[m];
	int c = 0;
	int d[m]{0};
	int l = 25;
	
	// n^2
	while(c<m){
		set<int> g;
		for(int i = 0; i < m; i++){
			if(b[i] == d[i] && !u[i]){
				u[i] = true;
				g.insert(i);
			}
		}
		
		for(;l>=0;l--){
			if(t[l] >= g.size()){
				t[l] -= g.size();
				for(int p: g){
					ans[p] = 'a' + l;
				}
				l--;
				break;
			}
		}
		
		for(int i = 0; i < m; i++){
			for(int p: g){
				d[i] += abs(p-i);
			}
		}
		
		c += g.size();
	}
	
	for(int i = 0; i < m; i++){
		cout << ans[i];
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}