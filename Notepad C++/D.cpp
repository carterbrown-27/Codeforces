#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	ll n;
	int s;
	cin >> n >> s;
	
	vector<int> num;
	int c = 0;
	while(n > 0){
		int m = n%10;
		c += m;
		num.push_back(m);
		n/=10;
	}
	
	ll ans = 0;
	ll tenp = 1;
	
	for(int i = 0; i < num.size(); i++){
		// cout << c << " ";
		if(c <= s) break;
		
		int d = num[i];
		
		int diff = 10-d;
		
		ans += diff * tenp;
		tenp *= 10;
		c -= d;
		
		if(i < num.size()-1){
			c++;
			num[i+1]++; 
		}
	}
	
	cout << min(ans,tenp-n) << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}