#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	int a[n];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	vector<int> seq;
	int l = 0;
	seq.push_back(a[0]);
	for(int i = 1; i < n; i++){
		if(i == n-1 || (a[i+1] > a[i]) != (a[i] > a[l])){
			seq.push_back(a[i]);
			l = i;
		}
	}
	
	cout << seq.size() << endl;
	for(int x: seq){
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}