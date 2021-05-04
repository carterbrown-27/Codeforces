#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int l[m], r[m], d[m];
	for(int i = 0; i < m; i++){
		cin >> l[i];
		l[i]--;
		cin >> r[i];
		r[i]--;
		cin >> d[i];
	}
	
	vector<int> ops(m+1);
	
	for(int i = 0; i < k; i++){
		int x,y;
		cin >> x >> y;
		ops[x-1]++;
		ops[y]--;
	}
	
	vector<ll> sums(n+1);
	
	ll opsSum = 0;
	for(int i = 0; i < m; i++){
		opsSum += ops[i];
		ll v = opsSum*d[i];
		
		sums[l[i]] += v;
		sums[r[i]+1] -= v;
	}
	
	ll sum = 0;
	for(int i = 0; i < n; i++){
		sum += sums[i];
		cout << sum + a[i] << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}