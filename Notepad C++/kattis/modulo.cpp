#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

// trivial
int main() {
	ios::sync_with_stdio(false);
	
	const int MOD = 42, N = 10;
	set<int> st;
	
	for(int i = 0; i < N; i++){
		int v;
		cin >> v;
		st.insert(v%MOD);
	}
	
	cout << st.size() << endl;
	
	return 0;
}