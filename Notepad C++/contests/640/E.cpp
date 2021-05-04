#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

// two pointers = O(n), total = O(n^2)
bool cont(int n, ll* p, int len){
	int l = 0;
	int r = l+2;
	while(r<len){
		if(p[r] - p[l] == n){
			return true;
		}else if(p[r] - p[l] < n){
			r++;
		}else{
			l++;
			if(r<l+2) r = l+2;
		}
	}
	return false;
}
void solve() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	ll p[n+1];
	p[0] = 0;
	for(int i=0; i<n; i++){
		p[i+1] = p[i] + a[i];
	}
	
	int ans = 0;
	for(int i=0; i<n; i++){
		ans += cont(a[i], p, n+1);
	}
	
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}