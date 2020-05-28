#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	sort(a, a+n);
	
	int yard = 0;
	int k = 0;
	for(int i = 0; i < n; i++){
		k++;
		if(a[i] <= yard+k){
			yard += k;
			k=0;
		}
	}
	
	cout << yard+1 << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}