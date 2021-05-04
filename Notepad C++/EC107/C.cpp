#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int n, q;
	cin >> n >> q;
	
	vector<int> c(51);
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = n; i-- > 0;){
		c[a[i]] = i+1;
	}
	
	for(int i = 0; i < q; i++){
		int t;
		cin >> t;
		
		int a = c[t];
		cout << a << " ";
		
		for(int j = 1; j <= 50; j++){
			if(c[j] < a) c[j]++;
		}
		c[t] = 1;
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}