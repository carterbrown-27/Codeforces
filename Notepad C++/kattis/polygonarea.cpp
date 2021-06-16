#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve(int n) {
	int x[n], y[n];
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	
	ll tmpSum = 0;
	for(int i = 0; i < n-1; i++){
		tmpSum += 1LL * (x[i+1] + x[i]) * (y[i+1] - y[i]);
	}
	tmpSum += 1LL * (x[0] + x[n-1]) * (y[0] - y[n-1]);
	
	
	printf("%s %.1f\n", (tmpSum > 0 ? "CCW" : "CW"), abs(0.5*tmpSum));
}

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	while(n != 0){
		solve(n);
		cin >> n;
	}
	return 0;
}