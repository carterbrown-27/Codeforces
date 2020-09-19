#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int mx = 0;
	for(int i = 100; i <= 999; i++){
		for(int j = 100; j < i; j++){
			string s = to_string(i*j);
			bool isP = true;
			for(int k = 0; k < s.length()/2; k++){
				if(s[k] != s[s.length()-k-1]){
					isP = false;
					break;
				}
			}
			if(isP) mx = max(mx, i*j);
		}
	}
	
	cout << mx << endl;
}

int main() {
	solve();
	return 0;
}