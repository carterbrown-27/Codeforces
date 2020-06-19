#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define push_back pb
#define make_pair mp

void solve() {
	string s;
	cin >> s;
	
	string b;
	b += s[0];
	for(int i = 1; i < s.length()-1; i+=2){
		b += s[i];
	}
	b += s[s.length()-1];
	
	cout << b << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}