#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	// pos, flip
	int l[n+1][2], r[n+1][2];
	
	l[0][0] = l[0][1] = 1;
	for(int i = 1; i <= n; i++){
		l[i][false] = (s[i-1] == 'L' ? l[i-1][true] : 0) + 1;
		l[i][true] = (s[i-1] == 'R' ? l[i-1][false] : 0) + 1;
	}
	
	/*
	for(int i = 0; i <= n; i++){
		cout << l[i][false] << " ";
	}
	cout << endl;
	*/
	
	r[n][0] = r[n][1] = 1;
	for(int i = n-1; i >= 0; i--){
		r[i][false] = (s[i] == 'R' ? r[i+1][true] : 0) + 1;
		r[i][true] = (s[i] == 'L' ? r[i+1][false] : 0) + 1;
	}
	
	for(int i = 0; i <= n; i++){
		cout << l[i][false] + r[i][false] - 1 << " ";
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