#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

bool solve() {
	int n;
	cin >> n;
	if(n == -1) return false;
	
	int sum = 0, h = 0;
	for(int i = 0; i < n; i++){
		int s, t;
		cin >> s >> t;
		sum += s * (t-h);
		h = t;
	}
	
	cout << sum << " miles" << endl;
	return true;
}

int main() {
	bool go = true;
	while(go){
		go = solve();
	}
	return 0;
}