#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll leftSum(int* m, int p, int n){
	ll sum = 0;
	int last = m[p];
	for(int i = p-1; i >= 0; i--){
		last = min(last,m[i]);
		sum += last;
	}
	return sum;
}

ll rightSum(int* m, int p, int n){
	ll sum = 0;
	int last = m[p];
	for(int i = p+1; i < n; i++){
		last = min(last,m[i]);
		sum += last;
	}
	return sum;
}

void solve() {
	int n;
	cin >> n;
	
	int m[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &m[i]);
	}
	
	// find middle index
	ll mx = 0;
	int mxi = -1;
	for(int i = 0; i < n; i++){
		ll s = m[i] + leftSum(m,i,n) + rightSum(m,i,n);
		if(s>mx){
			mx = s;
			mxi = i;
		}
	}
	
	// cout << mx << " " << mxi << endl;
	
	// curve from middle
	
	int r[n];
	r[mxi] = m[mxi];
	
	for(int i = mxi-1; i >= 0; i--){
		r[i] = min(r[i+1],m[i]);
	}
	
	for(int i = mxi+1; i < n; i++){
		r[i] = min(r[i-1],m[i]);
	}
	
	for(int i = 0; i < n; i++){
		cout << r[i] << " ";
	}
	
	cout << endl;
}

int main() {
	solve();
	return 0;
}