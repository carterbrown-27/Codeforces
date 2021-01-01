#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

const int d = 5;
const int f = 6;
const int t = 15;
const int top = 3;
vector<vector<int>> ans;
void solve(int p, int sum, int mn, vector<int> v) {
	// cout << sum << endl;
	if(sum > t || p > d) return;
	if(p == d && sum == t){
		ans.push_back(v);
		return;
	}
	for(int i = mn; i >= 1; i--){
		vector<int> t = v;
		t.push_back(i);
		solve(p+1, p < top ? sum + i : sum, min(mn,i), t);
	}
}

int main() {
	solve(0,0,f,vector<int>());
	cout << ans.size() << endl;
	ll fac[d+1];
	fac[0] = 1;
	for(int i = 1; i <= d; i++){
		fac[i] = fac[i-1] * i;
	}
	
	ll sum = 0;
	
	for(vector<int> v: ans){
		map<int,int> m;
		for(int x: v){
			// cout << x << " ";
			m[x]++;
		}
		// cout << endl;
		
		ll t = fac[d];
		
		for(auto const &p: m){
			t /= fac[p.second];
		}
		
		sum += t;
	}
	
	cout << sum << endl;
	return 0;
}