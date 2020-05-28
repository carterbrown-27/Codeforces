#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	int c[n];
	
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	int a = 0, b = 0, ap = 0, bp = n-1;
	
	int m = 1;
	int prev = c[0];
	a+=prev;
	ap++;
	while(ap<=bp){
		// bob move
		m++;
		int s = 0;
		while(s <= prev){
			if(bp<ap) break;
			s+=c[bp--];
		}
		prev = s;
		b+=s;
		
		if(bp<ap) break;

		// alice move
		m++;
		s = 0;
		while(s <= prev){
			if(ap>bp) break;
			s+=c[ap++];
		}
		
		prev = s;
		a+=s;
	}
	
	printf("%d %d %d\n", m, a, b);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}