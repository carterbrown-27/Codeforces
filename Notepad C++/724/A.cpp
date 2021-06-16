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

void solve() {
	int n;
	cin >> n;
	
	vector<int> a;
	uset<int> st;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.pb(x);
		st.insert(x);
	}
	
	for(int i = 1; i < a.size(); i++){
		if(i==300){
			cout << "NO" << endl;
			return;
		}
		
		for(int j = 0; j < i; j++){
			int d = abs(a[i] - a[j]);
			if(st.find(d) == st.end()){
				a.pb(d);
				st.insert(d);
			}
		}
	}
	
	cout << "YES" << endl;
	cout << a.size() << endl;
	
	for(int x: a){
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}