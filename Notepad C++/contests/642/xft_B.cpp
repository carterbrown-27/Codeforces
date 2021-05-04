#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a;
	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		a.push_back(x);
	}
	vector<int> b;
	for(int i = 0; i < n; i++){
		cin >> x;
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int sum = 0;
	int i = 0;
	for(; i < n && k > 0 && a[i] < b[n-i-1]; i++){
		sum += b[n-i-1];
		k--;
	}
	
	while(i<n){
		sum+=a[i];
		i++;
	}
	
	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}