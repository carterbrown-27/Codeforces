#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	string a;
	cin >> a;
	int n = a.length();
	
	int ans = 0;
	for(int i = 1; i < n; i++){
		char tb = (i-2 >= 0) ? a[i-2] : 0;
		
		if(a[i-1] == a[i] || tb == a[i]){
			ans++;
			unordered_set<char> surr;
			for(int j = max(i-2,0); j <= min(i+2,n-1); j++){
				surr.insert(a[j]);
			}
			
			for(char c = 'a'; c <= 'z'; c++){
				if(surr.find(c) == surr.end()){
					a[i] = c;
					break;
				}
			}
		}
	}
	
	cout << ans << "\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}