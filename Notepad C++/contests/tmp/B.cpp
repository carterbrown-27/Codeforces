#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	int a[2*n];
	for(int i = 0; i < 2*n; i++){
		cin >> a[i];
	}
	
	for(int i = 2; i <= 2000; i++){
		vector<int> t[i];
		bool ex[i] {0};
		for(int j = 0; j < 2*n; j++){
			t[a[j] % i].pb(j);
			ex[a[j]%i] = true;
		}
		
		vector<pair<int,int>> ans;
		for(int j = 1; j < i/2; j++){
			if(!ex[j] || !ex[i-j]) continue;
			
			while(!t[j].empty() && !t[i-j].empty()){
				ans.pb(mp(t[j][t[j].size()-1], t[i-j][t[i-j].size()-1]));
				t[j].pop_back();
				t[i-j].pop_back();
			}
		}
		
		if(ex[0]){
			for(int j = 0; j < t[0].size()-1; j+=2){
				ans.pb(mp(t[0][j], t[0][j+1]));
			}
		}
		
		if(i%2==0 && ex[i/2]){
			for(int j = 0; j < t[i/2].size()-1; j+=2){
				ans.pb(mp(t[i/2][j], t[i/2][j+1]));
			}
		}
		
		if(ans.size() >= n-1){
			for(int j = 0; j < n-1; j++){
				cout << ans[j].first + 1 << " " << ans[j].second + 1 << endl;
			}
			return;
		}
	}
	
	cout << "none" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}