#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	set<int> uset;
	for(int i = 0; i < n; i++){
		if(uset.find(a[i]) != uset.end()){
			uset.insert(a[i]+1);
		}else{
			uset.insert(a[i]);
		}
	}
	
	cout << uset.size() << "\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}