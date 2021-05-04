#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	
	for(int i = 0; i < n; i++){
		if(i%2 == 0){
			// alice
			cout << (s[i] == 'a' ? 'b' : 'a');
		}else{
			// bob
			cout << (s[i] == 'z' ? 'y' : 'z');
		}
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